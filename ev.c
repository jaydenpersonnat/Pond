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


char buffer[MAX_STRING_SIZE];

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

expr_node *cons(expr *exp, expr_node *list)
{
    expr_node *new_node = malloc(sizeof(expr_node));
    new_node->node = exp; 
    new_node->next = list; 

    return new_node; 
}

expr *create_list_node(expr_node *list)
{
    expr *list_exp = malloc(sizeof(exprlist));
    expr_node *ptr = list; 

    exprlist explist;
    explist.type = EXPLIST; 
    explist.list = list; 
    list_exp->explist = explist; 

    return list_exp; 
}

expr *create_app_node(char *name, expr_node *list)
{
    expr *app_exp = malloc(sizeof(APP));
    APP app;
    app.type = FUNCAPP; 
    strcpy(app.name, name);
    app.list = list;
    app_exp->app = app; 

    return app_exp; 
}

expr *create_return_node(expr *exp)
{
    expr *return_exp = malloc(sizeof(RETURN));
    RETURN return_t; 
    return_t.type = RETURN_t;
    return_t.exp = exp; 
    return_exp->return_t = return_t;

    return return_exp; 
}

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

expr *create_if_node(expr *cond, expr *body, expr *else_c)
{
    expr *if_exp = malloc(sizeof(IF_S));
    IF_S conditional; 
    conditional.type = CONDITIONAL; conditional.cond = cond; conditional.body = body;
    conditional.else_c = else_c; 
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

varid_node *cons_var(char *varidname, varid_node *n)
{
    varid_node *new_node = malloc(sizeof(varid_node));
    strcpy(new_node->varid, varidname);
    new_node->next = n; 

    return new_node; 
}

expr *create_func_node(char *name, varid_node *varidnames, expr *body)
{
    expr *func_exp = malloc(sizeof(FUNC));
    FUNC fun; 
    fun.type = FUNCTION;
    strcpy(fun.name, name);
    fun.list = varidnames; 
    fun.body = body;
    func_exp->function = fun; 

    return func_exp; 
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
        expr *l = b_exp.left;
        expr *r = b_exp.right; 
        // Add associative for all operators 
        case PLUS :
        {
            if (l->integer.type == NUM && r->integer.type == NUM) 
                return create_int_node(NUM, l->integer.value + r->integer.value);
            else if (l->integer.type == NUM && r->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, l->integer.value + r->decimal.value);
            else if (l->decimal.type == DECIMAL && r->integer.type == NUM) 
                return create_dec_node(DECIMAL, l->decimal.value + r->integer.value);
            else if (l->decimal.type == DECIMAL && r->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, l->decimal.value + r->decimal.value);
            else 
            {
                return create_eval_error("Evaluation Error: could not add values - type mismatch");
            }
        }
        case MINUS : 
        {
            if (l->integer.type == NUM && r->integer.type == NUM) 
                return create_int_node(NUM, l->integer.value - r->integer.value);
            else if (l->integer.type == NUM && r->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, l->integer.value - r->decimal.value);
            else if (l->decimal.type == DECIMAL && r->integer.type == NUM) 
                return create_dec_node(DECIMAL, l->decimal.value - r->integer.value);
            else if (l->decimal.type == DECIMAL && r->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, l->decimal.value - r->decimal.value);
            else
            {
                return create_eval_error("Evaluation Error: could not subtract values - type mismatch");
            }
        }
        case TIMES : 
        {
            if (l->integer.type == NUM && r->integer.type == NUM) 
                return create_int_node(NUM, l->integer.value * r->integer.value);
            else if (l->integer.type == NUM && r->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, l->integer.value * r->decimal.value);
            else if (l->decimal.type == DECIMAL && r->integer.type == NUM) 
                return create_dec_node(DECIMAL, l->decimal.value * r->integer.value);
            else if (l->decimal.type == DECIMAL && r->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, l->decimal.value * r->decimal.value); 
            else
            {
                return create_eval_error("Evaluation Error: could not multiply values - type mismatch");
            }           
        }
        case DIVIDE : 
        {
            // Handle divide by zero error
            if (r->integer.value == 0 || r->decimal.value == 0.0)
            {
                // add in error type
                return create_eval_error("EvalError: Division by Zero");
            }
            if (l->integer.type == NUM && r->integer.type == NUM) 
                return create_int_node(NUM, l->integer.value / r->integer.value);
            else if (l->integer.type == NUM && r->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, l->integer.value / r->decimal.value);
            else if (l->decimal.type == DECIMAL && r->integer.type == NUM) 
                return create_dec_node(DECIMAL, l->decimal.value / r->integer.value);
            else if (l->decimal.type == DECIMAL && r->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, l->decimal.value / r->decimal.value);  
            else
            {
                return create_eval_error("Evaluation Error: could not divide values - type mismatch");
            }
        }
        case MODULO :
        {
            if (l->integer.type == NUM && r->integer.type == NUM) 
                return create_int_node(NUM, l->integer.value % r->integer.value);
            else return create_eval_error("Evaluation Error: could not mod values - type mismatch");
        }
        case POWER : 
        {
            if (l->integer.type == NUM && r->integer.type == NUM) 
                return create_int_node(NUM, pow(l->integer.value, r->integer.value));
            else if (l->integer.type == NUM && r->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, pow(l->integer.value, r->decimal.value));
            else if (l->decimal.type == DECIMAL && r->integer.type == NUM) 
                return create_dec_node(DECIMAL, pow(l->decimal.value, r->integer.value));
            else if (l->decimal.type == DECIMAL && r->decimal.type == DECIMAL) 
                return create_dec_node(DECIMAL, pow(l->decimal.value, r->decimal.value));  
            else
            {
                return create_eval_error("Evaluation Error: could not exponentiate values - type mismatch");
            }

        }
        case EQUALTO : 
            return create_bool_node(BOOL, l->integer.value == r->integer.value? true: false);
        case NOTEQUALTO : 
            return create_bool_node(BOOL, l->integer.value != r->integer.value? true: false); 
        case GREATERTHAN:
            return create_bool_node(BOOL, l->integer.value > r->integer.value? true: false);
        case LESSTHAN:
            return create_bool_node(BOOL, l->integer.value < r->integer.value? true: false);
        case GREATERTHANEQUAL: 
            return create_bool_node(BOOL, l->integer.value >= r->integer.value? true: false);
        case LESSTHANEQUAL: 
            return create_bool_node(BOOL, l->integer.value <= r->integer.value? true: false);
        case ANDOP: 
            return create_bool_node(BOOL, l->boolean.value && r->boolean.value? true: false);
        case OROP: 
            return create_bool_node(BOOL, l->boolean.value || r->boolean.value? true: false);
        case SJOIN:
        {
            return create_str_node(STR, (strcat(l->string.value, r->string.value)));
        
        }
        case LJOIN:
        {
        
            expr_node *head = l->explist.list;
            expr_node *ptr1 = l->explist.list; 
            expr_node *ptr2 = r->explist.list; 

            if (ptr1 == NULL)
            {
                return create_list_node(ptr2);
            }

            while (ptr1->next != NULL)
            {
                ptr1 = ptr1->next; 
            }
            ptr1->next = ptr2; 
            return create_list_node(head); 
        }
        case INDEX:
        {
            int pos = l->integer.value; 

            if (l->integer.type == NUM && r->explist.type == EXPLIST)
            {
                expr_node *ptr1 = r->explist.list; 
                int counter = 0;
                while (counter != pos)
                {
                    ptr1 = ptr1->next; 
                    counter++; 
                }
                return ptr1->node; 
            }
            else if (l->integer.type == NUM && r->string.type == STR)
            {
                char tmp[2]; 
                tmp[0] = r->string.value[pos];
                tmp[1] = '\0';

                return create_str_node(STR, tmp);
            }
        }
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
    else if (expression->return_t.type == RETURN_t)
    {
        expr *return_exp = create_return_node(eval(expression->return_t.exp));
        return return_exp; 

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
        if (left_eval->return_t.type == RETURN_t)
        {
            return left_eval;
        }
        expr *right_eval = eval(expression->sequence.right); 
        return right_eval; 
    }
    else if (expression->doloop.type == DOL)
    {
        for (int i = 0; i < expression->doloop.iterations; i++)
        {
            expr *eval_exp = eval(expression->doloop.exp);
            if (eval_exp->breakt.type == BREAK)
            {
                return expression; 
            }
            if (eval_exp->return_t.type == RETURN_t)
            {
                return eval_exp; 
            }
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
            if (eval_exp->return_t.type == RETURN_t)
            {
                return eval_exp; 
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
            if (eval_body->return_t.type == RETURN_t)
            {
                return eval_body; 
            }
        }
        else
        {
            expr *eval_else = eval(expression->conditional.else_c);
            if (eval_else->breakt.type == BREAK)
            {
                return create_break_node(); 
            }
            if (eval_else->return_t.type == RETURN_t)
            {
                return eval_else; 
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
            if (eval_exp->return_t.type == RETURN_t)
            {
                return eval_exp; 
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
        scanf("%s", value);
        return create_str_node(STR, value);
        // char value[MAX_STRING_SIZE];
        // printf("%s", expression->getstr.prompt);
        // fgets(value, 500, stdin);

        // if ((strlen(value) > 0) && (value[strlen (value) - 1] == '\n'))
        //     value[strlen (value) - 1] = '\0';

        // return create_str_node(STR, value);
    }
    else if (expression->explist.type == EXPLIST)
    {
        expr_node *ptr = malloc(sizeof(expr_node));
        expr *new_list = create_list_node(expression->explist.list);

        ptr = new_list->explist.list; 
        while (ptr != NULL)
        {
            ptr->node = eval(ptr->node);
            ptr = ptr->next; 
        }

        return new_list; 

    }
    else if (expression->function.type == FUNCTION)
    {
        insert(expression->function.name, expression);
        return expression; 
    }
    else if (expression->app.type == FUNCAPP)
    {
        expr_node *ptr1 = expression->app.list;
        expr *def = lookup(expression->app.name);
        varid_node *ptr2 = def->function.list; 

        while (ptr1 != NULL && ptr2 != NULL)
        {
            eval(create_assign_node(ptr2->varid, ptr1->node));
            ptr1 = ptr1->next;
            ptr2 = ptr2->next; 
        }

        expr *eval_body = eval(def->function.body);

        if (eval_body->return_t.type == RETURN_t)
        {
            expr *output = eval(eval_body->return_t.exp);

            // delete all local variables from sym table
            varid_node *ptr3 = def->function.list; 
            while (ptr3 != NULL)
            {
                delete_node(ptr3->varid);
                ptr3 = ptr3->next; 
            }

            return output;
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
        char string_list[MAX_STRING_SIZE] = "";
        expr_node *cursor = expression->explist.list; 
        // strcpy(buffer, list_to_string(expression->explist.list));
        while (cursor != NULL)
        {
            char element[MAX_STRING_SIZE];
            sprintf(element, "%s,", to_concrete(cursor->node));
            strcat(string_list, element);
            cursor = cursor->next; 
        }

        string_list[strlen(string_list) - 1] = '\0';
        sprintf(buffer, "[%s]", string_list);

        return buffer; 
    }
    else
    {
        strcpy(buffer, "");
        return buffer; 
    } 
}

char *remove_double_quotes(char *input)
{
    char *tmp = malloc(strlen(input) + 1); 
    strcpy(tmp, input);
    tmp[strlen(tmp) - 1] = '\0';
    memmove(tmp, tmp + 1, strlen(tmp));

    return tmp; 
    
}