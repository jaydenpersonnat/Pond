#include "ev.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h> 

char buffer[INT_SIZE];

expr create_int_node(enum types type, int val)
{
    expr int_exp; INT number; number.type = type; number.value = val; int_exp.integer = number;
    return int_exp; 
}
expr create_dec_node(enum types type, float val)
{
    expr dec_exp; DEC decimal; decimal.type = type; decimal.value = val; dec_exp.decimal = decimal;
    return dec_exp; 
}
expr create_bool_node(enum types type, bool val)
{
    expr bool_exp; BOOLEAN boolean; boolean.type = type; boolean.value = val; bool_exp.boolean = boolean;
    return bool_exp; 
}
expr create_str_node(enum types type, char *val)
{
    expr str_exp; STRING string; string.type = STR; strcpy(string.value, val); str_exp.string = string; 
    return str_exp; 
}


expr eval(expr expression)
{
    if (expression.integer.type == NUM) return expression; 
    else if (expression.decimal.type == DECIMAL) return expression; 
    else if (expression.boolean.type == BOOL) return expression; 
    else if (expression.string.type == STR) return expression; 
}

char *to_concrete(expr expression)
{
    if (expression.integer.type == NUM)
    {
        sprintf(buffer, "%d", expression.integer.value);
        return buffer;
    }
    else if (expression.decimal.type == DECIMAL)
    {
        gcvt(expression.decimal.value, MAX_FLOAT_SIZE, buffer);
        return buffer; 
    }
    else if (expression.boolean.type == BOOL)
    {
        if (expression.boolean.value)
        {
            strcpy(buffer, "true"); 
            return buffer; 
        }
        strcpy(buffer, "false"); 
        return buffer;
    }
    else if (expression.string.type == STR)
    {
        strcpy(buffer, expression.string.value);
        return buffer; 
    }
}

// int main(void)
// {
//     expr ex = create_str_node(STR, "hello");
//     printf("%s\n", to_concrete(eval(ex)));

// }