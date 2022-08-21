#include "ev.h"
#include "sym.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h> 
#include <math.h>

char *to_concrete(expr *expression);
expr *eval(expr *expression);

char buffer[INT_SIZE];

expr *create_int_node(enum types type, int val)
{
    expr *int_exp = malloc(sizeof(INT)); 
    INT number; number.type = type; number.value = val; int_exp->integer = number;
    return int_exp; 
}
expr *create_dec_node(enum types type, float val)
{
    expr *dec_exp = malloc(sizeof(DEC)); 
    DEC decimal; decimal.type = type; decimal.value = val; dec_exp->decimal = decimal;
    return dec_exp; 
}
expr *create_bool_node(enum types type, bool val)
{
    expr *bool_exp = malloc(sizeof(BOOLEAN)); 
    BOOLEAN boolean; boolean.type = type; boolean.value = val; bool_exp->boolean = boolean;
    return bool_exp; 
}
expr *create_str_node(enum types type, char *val)
{
    expr *str_exp = malloc(sizeof(STRING)); 
    STRING string; string.type = STR; strcpy(string.value, val); str_exp->string = string; 
    return str_exp; 
}

expr *create_varid_node(char *varidname)
{
    expr *var_exp = malloc(sizeof(VARID));
    VARID varid; varid.type = VAR; strcpy(varid.varidname, varidname); var_exp->varid = varid;
    return var_exp; 
}

expr *create_assign_node(char *varidname, expr *exp)
{
    expr *assign_exp = malloc(sizeof(ASSIGNM));
    ASSIGNM assign; assign.type = ASSIGNMENT, strcpy(assign.varidname, varidname); assign.exp = exp; 
    assign_exp->assign = assign;
    return assign_exp; 
}

expr *create_print_node(expr *exp)
{
    expr *print_exp = malloc(sizeof(PRINTI)); 
    PRINTI print; 
    print.type = PRINTING;
    print.exp = exp;
    print_exp->print = print;
    return print_exp; 
}

expr *create_eval_error(char *msg)
{
    expr *eval_error_exp = malloc(sizeof(EVALERROR));
    EVALERROR error;
    error.type = ERROR;
    strcpy(error.msg, msg); 
    eval_error_exp->error = error; 
    return eval_error_exp; 
}

// expr *append_expr_lst(expr *exp, exprlist *list)
// {
//     expr *list_exp = malloc(sizeof(exprlist)); 
//     exprlist explist;
//     expr_node *new_node = malloc(sizeof(expr_node));
//     new_node->next = NULL; 
//     new_node->node = exp; 

//     if (list == NULL)
//     {
//         explist.type = LIST; 
//         explist.head = new_node;
//         explist.tail = new_node; 
//         list_exp->exprlist = explist;

//         return list_exp;
//     }
//     else 
//     {
//         list->tail->next = new_node;
//         list->tail = new_node; 

//         list_exp->exprlist = *list; 
//         return list_exp; 

//     }
// }

expr *create_doloop_node(int iterations, expr *exp)
{
    expr *doloop_exp = malloc(sizeof(DOLOOP)); 
    DOLOOP doloop; 
    doloop.type = DOL; 
    doloop.exp = exp; 
    doloop.iterations = iterations; 
    doloop_exp->doloop = doloop; 
    return doloop_exp; 
}

expr *create_if_node(expr *cond, expr *body)
{
    expr *if_exp = malloc(sizeof(IF_S));
    IF_S conditional; 
    conditional.type = CONDITIONAL; conditional.cond = cond; conditional.body = body;
    if_exp->conditional = conditional;
    return if_exp; 
}

expr *create_unop_node(enum uops op, expr *exp)
{
    expr *unop_expr = malloc(sizeof(UNOP));
    UNOP unop; 
    unop.type = UNARYOP; 
    unop.op = op; 
    unop.exp = exp; 
    unop_expr->unop = unop; 
    return unop_expr; 
}

expr *create_binop_node(enum bops op, expr *left, expr *right)
{
    expr *binop_expr = malloc(sizeof(BINOP));
    BINOP binop; 
    binop.type = BINARYOP; 
    binop.op = op; 
    binop.left = left; 
    binop.right = right; 
    binop_expr->binop = binop;
    return binop_expr; 
}

expr *create_seq_node(expr *left, expr *right)
{
    expr *seq_expr = malloc(sizeof(SEQ));
    SEQ sequence; 
    sequence.type = SEQUENCE; 
    sequence.left = left; 
    sequence.right = right; 
    seq_expr->sequence = sequence;
    return seq_expr; 
}

expr *create_forloop_node(char *varidname, expr *start, expr *end, expr *incr, expr *exp, expr *counter)
{
    expr *forloop_expr = malloc(sizeof(FORLOOP));
    FORLOOP forloop; 
    forloop.type = FORL;
    strcpy(forloop.varidname, varidname);
    forloop.start = start;
    forloop.end = end; 
    forloop.incr = incr; 
    forloop.counter = counter; 
    forloop.exp = exp; 
    forloop_expr->forloop = forloop;
    return forloop_expr; 
}


expr *unopeval(UNOP u_exp)
{
    switch(u_exp.op)
    {
        case ABSV :
        {
            int value = u_exp.exp->integer.value; 
            return create_int_node(NUM, value >= 0? value: -1 * value);
        }
        case NEGATIVE:
        {
            return create_int_node(NUM, -1 * u_exp.exp->integer.value);
        }
        case FACTORIAL: 
            return create_int_node(NUM, tgamma(u_exp.exp->integer.value + 1));
        case NOTOP: 
            return create_bool_node(BOOL, !u_exp.exp->boolean.value); 
    }
}
expr *binopeval(BINOP b_exp)
{
    // add in error checking later - wildcard match
    switch (b_exp.op)
    {
        // Add associative for all operators 
        case PLUS :
        {
            if (b_exp.left->integer.type == NUM && b_exp.right->integer.type == NUM) 
                return create_int_node(NUM, b_exp.left->integer.value + b_exp.right->integer.value);
            else if (b_exp.left->integer.type == NUM && b_exp.right->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, b_exp.left->integer.value + b_exp.right->decimal.value);
            else if (b_exp.left->decimal.type == DECIMAL && b_exp.right->integer.type == NUM) 
                return create_dec_node(DECIMAL, b_exp.left->decimal.value + b_exp.right->integer.value);
            else if (b_exp.left->decimal.type == DECIMAL && b_exp.right->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, b_exp.left->decimal.value + b_exp.right->decimal.value);
        }
        case MINUS : 
        {
            if (b_exp.left->integer.type == NUM && b_exp.right->integer.type == NUM) 
                return create_int_node(NUM, b_exp.left->integer.value - b_exp.right->integer.value);
            else if (b_exp.left->integer.type == NUM && b_exp.right->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, b_exp.left->integer.value - b_exp.right->decimal.value);
            else if (b_exp.left->decimal.type == DECIMAL && b_exp.right->integer.type == NUM) 
                return create_dec_node(DECIMAL, b_exp.left->decimal.value - b_exp.right->integer.value);
            else if (b_exp.left->decimal.type == DECIMAL && b_exp.right->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, b_exp.left->decimal.value - b_exp.right->decimal.value);
        }
        case TIMES : 
        {
            if (b_exp.left->integer.type == NUM && b_exp.right->integer.type == NUM) 
                return create_int_node(NUM, b_exp.left->integer.value * b_exp.right->integer.value);
            else if (b_exp.left->integer.type == NUM && b_exp.right->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, b_exp.left->integer.value * b_exp.right->decimal.value);
            else if (b_exp.left->decimal.type == DECIMAL && b_exp.right->integer.type == NUM) 
                return create_dec_node(DECIMAL, b_exp.left->decimal.value * b_exp.right->integer.value);
            else if (b_exp.left->decimal.type == DECIMAL && b_exp.right->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, b_exp.left->decimal.value * b_exp.right->decimal.value);            
        }
        case DIVIDE : 
            {
            // Handle divide by zero error
            if (b_exp.left->integer.type == NUM && b_exp.right->integer.value == 0)
            {
                // add in error type
                return create_eval_error("EvalError: Division by Zero");
            }
            return create_int_node(NUM, b_exp.left->integer.value / b_exp.right->integer.value); 
            }
        case MODULO :
            return create_int_node(NUM, b_exp.left->integer.value % b_exp.right->integer.value); 
        case POWER : 
            return create_int_node(NUM, pow(b_exp.left->integer.value, b_exp.right->integer.value));
        case EQUALTO : 
            return create_bool_node(BOOL, b_exp.left->integer.value == b_exp.right->integer.value? true: false);
        case NOTEQUALTO : 
            return create_bool_node(BOOL, b_exp.left->integer.value != b_exp.right->integer.value? true: false); 
        case GREATERTHAN:
            return create_bool_node(BOOL, b_exp.left->integer.value > b_exp.right->integer.value? true: false);
        case LESSTHAN:
            return create_bool_node(BOOL, b_exp.left->integer.value < b_exp.right->integer.value? true: false);
        case GREATERTHANEQUAL: 
            return create_bool_node(BOOL, b_exp.left->integer.value >= b_exp.right->integer.value? true: false);
        case LESSTHANEQUAL: 
            return create_bool_node(BOOL, b_exp.left->integer.value <= b_exp.right->integer.value? true: false);
    }
}


expr *eval(expr *expression)
{
    if (expression->integer.type == NUM) return expression; 
    else if (expression->decimal.type == DECIMAL) return expression; 
    else if (expression->boolean.type == BOOL) return expression; 
    else if (expression->string.type == STR) return expression; 
    else if (expression->varid.type == VAR)
    {
        return lookup(expression->varid.varidname); 
    }
    else if (expression->unop.type == UNARYOP)
    {
        expression->unop.exp = eval(expression->unop.exp);
        return unopeval(expression->unop); 
    }
    else if (expression->binop.type == BINARYOP)
    {
        expression->binop.left = eval(expression->binop.left);
        expression->binop.right  = eval(expression->binop.right);
        return binopeval(expression->binop);
    }
    else if (expression->assign.type == ASSIGNMENT)
    {
        expression->assign.exp =  eval(expression->assign.exp);
        insert(expression->assign.varidname, expression->assign.exp); 
        return expression; 
    }
    else if (expression->print.type == PRINTING)
    {
        printf("> %s\n", to_concrete(eval(expression->print.exp)));
        return expression; 
    }
    else if (expression->sequence.type == SEQUENCE)
    {
        eval(expression->sequence.left);
        eval(expression->sequence.right); 
        return expression; 
    }
    else if (expression->doloop.type == DOL)
    {
        // fix do loop later
        for (int i = 0; i < expression->doloop.iterations; i++)
        {
            eval(expression->doloop.exp);
        }
        return expression; 
    }
    else if (expression->forloop.type == FORL)
    {
        eval(create_assign_node(expression->forloop.varidname, expression->forloop.counter));
        int start = atoi(to_concrete(eval(expression->forloop.start)));
        int end = atoi(to_concrete(eval(expression->forloop.end)));
        int counter = atoi(to_concrete(eval(expression->forloop.counter)));
        int incr = atoi(to_concrete(eval(expression->forloop.incr)));
        
        if (end > start && incr > 0 && counter > end)
        {
            return expression; 
        }
        else if (start > end && incr < 0 && counter < end)
        {
            return expression; 
        }
        else if (start == end || incr == 0 || (incr < 0 && start < end) || (incr > 0 && start > end))
        {
            return expression; 
        }
        else
        {
            eval(expression->forloop.exp);
            expr *new_loop = create_forloop_node(expression->forloop.varidname, expression->forloop.start, expression->forloop.end, expression->forloop.incr, expression->forloop.exp, create_int_node(NUM, counter + incr));
            eval(new_loop); 
        }

    }
    else if (expression->conditional.type == CONDITIONAL)
    {
        char *cond = to_concrete(eval(expression->conditional.cond));
        if (strcmp(cond, "TRUE") == 0)
        {
            eval(expression->conditional.body);
        }
        
        return expression;
    }
    else if (expression->error.type == ERROR)
    {
        return expression; 
    }
    // else if (expression->forloop.type == FOR)
    // {
    //     // create_assign_node(node,)
    // }
    
    else
    {
        return expression;
    }
}

// in else case to handle assignment and functions print nothing
char *to_concrete(expr *expression)
{
    if (expression->integer.type == NUM)
    {
        sprintf(buffer, "%d", expression->integer.value);
        // free(expression); 
        return buffer;
    }
    else if (expression->decimal.type == DECIMAL)
    {
        gcvt(expression->decimal.value, MAX_FLOAT_SIZE, buffer);
        // free(expression);
        return buffer; 
    }
    else if (expression->boolean.type == BOOL)
    {
        if (expression->boolean.value)
        {
            strcpy(buffer, "TRUE"); 
            // free(expression);
            return buffer; 
        }
        strcpy(buffer, "FALSE"); 

        // free(expression); 
        return buffer;
    }
    else if (expression->string.type == STR)
    {
        strcpy(buffer, expression->string.value);

        // free(expression); 
        return buffer; 
    }
    else if (expression->error.type == ERROR)
    {
        strcpy(buffer, expression->error.msg);
        return buffer; 
    }
    else
    {
        strcpy(buffer, "");
        return buffer; 
    }
   
}

