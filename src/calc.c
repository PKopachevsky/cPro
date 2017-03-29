#include <stdio.h>
#include "parse.c"

void parse(char *expr, char *output);

void main() {
    int operands[100];

    char op = 0;
    char oper = 0;

    char input[100] = "3 + 5 * 4 - (3 +1)/2 -3*4";
    char expr[100];

    parse(input, expr);

    char c;
    int i = 0;
    int d = 0;
    char digit;
    int op1, op2, result;
    while((c = expr[i++]) != '\0') {
        if (c >= '0' && c <= '9') {
            d = d * 10 + c - '0';
            digit = 1;
        } else {
            if (digit) {
                operands[op++] = d;
                d = 0;
                digit = 0;
            }
            if (c != ' ') {
                op1 = operands[--op];
                op2 = operands[--op];
                 switch(c) {
                    case '+':
                        result = op1 + op2;
                        printf("%d + %d = %d\n",op1, op2, result);
                        break;

                    case '*':
                        result = op1 * op2;
                        printf("%d * %d = %d\n",op1, op2, result);
                        break;

                    case '-':
                        result = op2 - op1;
                        printf("%d - %d = %d\n",op2, op1, result);
                        break;

                    case '/':
                        result = op2 / op1;
                        printf("%d / %d = %d\n",op2, op1, result);
                        break;
                }
                operands[op++] = result;
            }
        }    
    }

    printf("result: %d\n", operands[0]);
}