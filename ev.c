#include "ev.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h> 
#include <math.h>

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
    expr *str_exp = malloc(sizeof(BOOLEAN)); 
    STRING string; string.type = STR; strcpy(string.value, val); str_exp->string = string; 
    return str_exp; 
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
    else if (expression->binop.type == BINARYOP)
    {
        expression->binop.left = eval(expression->binop.left);
        expression->binop.right  = eval(expression->binop.right);
        return binopeval(expression->binop);
    }
}

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
   
}

// int main(void)
// {
//     expr *num1 = create_int_node(NUM, 10); 
//     expr *num2 = create_int_node(NUM, 5); 
//     expr *num3 = create_int_node(NUM, 5); 
//     expr *ex = create_binop_node(PLUS, num1, create_binop_node(PLUS, num2, num3));
//     printf("%s\n", to_concrete(eval(ex)));

// }