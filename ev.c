#include "ev.h"
#include "sym.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h> 
#include <math.h>

char *to_concrete(expr *expression);

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
    }
}
expr *binopeval(BINOP b_exp)
{
    // add in error checking later - wildcard match
    switch (b_exp.op)
    {
        // Add associative for all operators 
        case PLUS :
            return create_int_node(NUM, b_exp.left->integer.value + b_exp.right->integer.value);
        case MINUS : 
            return create_int_node(NUM, b_exp.left->integer.value - b_exp.right->integer.value);
        case TIMES : 
            return create_int_node(NUM, b_exp.left->integer.value * b_exp.right->integer.value);
        case DIVIDE : 
            // Handle divide by zero error
            return create_int_node(NUM, b_exp.left->integer.value / b_exp.right->integer.value); 
        case MODULO :
            return create_int_node(NUM, b_exp.left->integer.value % b_exp.right->integer.value); 
        case POWER : 
            return create_int_node(NUM, pow(b_exp.left->integer.value, b_exp.right->integer.value));
        case EQUALTO : 
            return create_bool_node(BOOL, b_exp.left->integer.value == b_exp.right->integer.value? true: false);
        case GREATERTHAN:
            return create_bool_node(BOOL, b_exp.left->integer.value > b_exp.right->integer.value? true: false);
        case LESSTHAN:
            return create_bool_node(BOOL, b_exp.left->integer.value < b_exp.right->integer.value? true: false);
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
        expression->assign.exp = eval(expression->assign.exp);
        insert(expression->assign.varidname, expression->assign.exp); 
        return expression; 
    }
    else if (expression->conditional.type == CONDITIONAL)
    {
        if (strcasecmp(to_concrete(eval(expression->conditional.cond)), "TRUE") == 0) 
        {
            return eval(expression->conditional.body);
        }
    }
}

// in else case to handle assignment and functions print nothing
char *to_concrete(expr *expression)
{
    if (expression->integer.type == NUM)
    {
        sprintf(buffer, "%d", expression->integer.value);
        free(expression); 
        return buffer;
    }
    else if (expression->decimal.type == DECIMAL)
    {
        gcvt(expression->decimal.value, MAX_FLOAT_SIZE, buffer);
        free(expression);
        return buffer; 
    }
    else if (expression->boolean.type == BOOL)
    {
        if (expression->boolean.value)
        {
            strcpy(buffer, "TRUE"); 
            free(expression);
            return buffer; 
        }
        strcpy(buffer, "FALSE"); 

        free(expression); 
        return buffer;
    }
    else if (expression->string.type == STR)
    {
        strcpy(buffer, expression->string.value);

        free(expression); 
        return buffer; 
    }
    else
    {
        strcpy(buffer, "");
        return buffer; 
    }
   
}

int main(void)
{
    expr *num1 = create_int_node(NUM, 10); 
    expr *num2 = create_int_node(NUM, 5); 
    expr *num3 = create_int_node(NUM, 5); 
    // expr *ex = create_if_node(create_binop_node(GREATERTHAN, num1, num2), );
    printf("%s\n", to_concrete(eval(ex)));

}