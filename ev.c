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

expr *cons(expr *exp, expr_node *list)
{
    expr *list_exp = malloc(sizeof(expr_node)); 
    expr_node element; 
    element.next = list;
    element.node = exp;
    list_exp->explist = element; 

    return list_exp; 

    // expr *list_exp = malloc(sizeof(exprlist));
    // exprlist explist;
    // expr_node *new_node = malloc(sizeof(expr_node)); 
    // new_node->next = NULL; 
    // new_node->node = exp; 

    // if (list == NULL)
    // {
    //     new_node->index = 0;
    //     explist.type = EXPLIST;
    //     explist.head = new_node;
    //     explist.tail = new_node; 
    //     explist.length = 1; 
    //     list_exp->explist = explist;

    //     return list_exp; 
    // }
    // else
    // {
    //     list->tail->next = new_node;
    //     list->tail = new_node; 
    //     list->length = list->length++; 
    //     list_exp->explist = *list; 
    //     return list_exp; 
    // }
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

expr *create_break_node(void)
{
    expr *break_exp = malloc(sizeof(BREAK_t));
    BREAK_t break_t;
    break_t.type = BREAK; 
    break_exp->breakt = break_t; 
    return break_exp; 

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

expr *create_while_node(expr *cond, expr *exp)
{
    expr *while_exp = malloc(sizeof(WHILELOOP));
    WHILELOOP whileloop; 
    whileloop.type = WHILEL; 
    whileloop.cond = cond;
    whileloop.exp = exp; 
    while_exp->whileloop = whileloop; 
    return while_exp; 
}

expr *create_getnum_node(char *prompt)
{
    expr *getnum_exp = malloc(sizeof(GETNUM_f));
    GETNUM_f getnum;
    getnum.type = GETNUM;
    strcpy(getnum.prompt, prompt);
    getnum_exp->getnum = getnum;
    return getnum_exp; 
}

expr *create_getfloat_node(char *prompt)
{
    expr *getfloat_exp = malloc(sizeof(GETFLOAT_f));
    GETFLOAT_f getfloat; 
    getfloat.type = GETFLOAT;
    strcpy(getfloat.prompt, prompt);
    getfloat_exp->getfloat = getfloat; 
    return getfloat_exp; 
}

expr *create_getstr_node(char *prompt)
{
    expr *getstr_exp = malloc(sizeof(GETSTR_f));
    GETSTR_f getstr; 
    getstr.type = GETSTR; 
    strcpy(getstr.prompt, prompt);
    getstr_exp->getstr = getstr;
    return getstr_exp; 
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
            else 
            {
                return create_eval_error("Incorrect types being added");
            }
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
        case ANDOP: 
            return create_bool_node(BOOL, b_exp.left->boolean.value && b_exp.right->boolean.value? true: false);
        case OROP: 
            return create_bool_node(BOOL, b_exp.left->boolean.value || b_exp.right->boolean.value? true: false);
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
    else if (expression->breakt.type == BREAK)
    {
        return expression; 
    }
    else if (expression->unop.type == UNARYOP)
    {
        expr *unop_node = create_unop_node(expression->unop.op, eval(expression->unop.exp));
        return unopeval(unop_node->unop); 
    }
    else if (expression->binop.type == BINARYOP)
    {
        expr *new_binop = create_binop_node(expression->binop.op, eval(expression->binop.left), eval(expression->binop.right));
        return binopeval(new_binop->binop);
    }
    else if (expression->assign.type == ASSIGNMENT)
    {
        // expression->assign.exp =  eval(expression->assign.exp);
        insert(expression->assign.varidname, eval(expression->assign.exp)); 
        return expression; 
    }
    else if (expression->print.type == PRINTING)
    {
        printf("%s\n", to_concrete(eval(expression->print.exp)));
        return expression; 
    }
    else if (expression->sequence.type == SEQUENCE)
    {
        expr *left_eval = eval(expression->sequence.left);
        if (left_eval->breakt.type == BREAK)
        {
            return create_break_node();
        }
        expr *right_eval = eval(expression->sequence.right); 
        return right_eval; 
    }
    else if (expression->doloop.type == DOL)
    {
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
            expr *eval_exp = eval(expression->forloop.exp);
            if (eval_exp->breakt.type == BREAK)
            {
                return expression; 
            }
            expr *new_loop = create_forloop_node(expression->forloop.varidname, expression->forloop.start, expression->forloop.end, expression->forloop.incr, expression->forloop.exp, create_int_node(NUM, counter + incr));
            eval(new_loop); 
        }
    }
    else if (expression->conditional.type == CONDITIONAL)
    {
        char *cond = to_concrete(eval(expression->conditional.cond));
        if (strcmp(cond, "TRUE") == 0)
        {
            expr *eval_body = eval(expression->conditional.body);
            if (eval_body->breakt.type == BREAK)
            {
                return create_break_node(); 
            }
        }
        
        return expression;
    }
    else if (expression->whileloop.type == WHILEL)
    {
        char *cond = to_concrete(eval(expression->whileloop.cond));

        if (strcmp(cond, "TRUE") == 0)
        {
            expr *eval_exp = eval(expression->whileloop.exp);
            if (eval_exp->breakt.type == BREAK)
            {
                return expression; 
            }
            eval(create_while_node(expression->whileloop.cond, expression->whileloop.exp));
        }

        return expression; 
    }
    else if (expression->getnum.type == GETNUM)
    {
        int value; 
        printf("%s", expression->getnum.prompt);
        scanf("%d", &value);
        return create_int_node(NUM, value);

    }
    else if (expression->getfloat.type == GETFLOAT)
    {
        float value; 
        printf("%s", expression->getfloat.prompt);
        scanf("%f", &value);
        return create_dec_node(DECIMAL, value);
    }
    else if (expression->getstr.type == GETSTR)
    {
        char value[MAX_STRING_SIZE];
        printf("%s", expression->getstr.prompt);
        fgets(value, 500, stdin);

        if ((strlen(value) > 0) && (value[strlen (value) - 1] == '\n'))
            value[strlen (value) - 1] = '\0';
        return create_str_node(STR, value);
    }
    else if (expression->explist.type == EXPLIST)
    {
        expr_node *ptr = malloc(sizeof(expr_node));
        ptr = &(expression->explist); 
        while (ptr != NULL)
        {
            ptr->node = eval(ptr->node);
            ptr = ptr->next; 
        }

        return expression; 

    }
    else if (expression->error.type == ERROR)
    {
        return expression;  
    }
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
    else if (expression->explist.type == EXPLIST)
    {
        // char string_list[MAX_STRING_SIZE];
        // expr_node *cursor = expression->explist; 
        // while (cursor != NULL)
        // {
        //     strcat(buffer, "world");
        //     cursor = cursor->next; 
        // }
        strcpy(buffer, "test"); 

        return buffer; 
    }
    else
    {
        strcpy(buffer, "");
        return buffer; 
    }
   
}

