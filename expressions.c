#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int prece(char c)
{
    if (c == '(') {return 0;}
    else if (c == '^') {return 3;}
    else if (c == '*' || c == '/') {return 2;}
    else if (c == '+' || c == '-') {return 1;}
    else {return -1;}
}

void postfix(char exp[])
{
    int l = strlen(exp), i = 0;
    char ans[l+1]; int j = 0;
    char stack[l]; int top = -1;
    
    for (i = 0; i < l; i++)
    {
        char c = exp[i];
        if (isalnum(c)) {ans[j++] = c;}
        else
        {
            if (c == '(') {stack[++top] = c;}
            else if (c == ')')
            {
                while (top != -1 && stack[top] != '(')
                {
                    ans[j++] = stack[top--];
                }
                if (top != -1) {top--;}
            }
            else
            {
                /*if (prece(c)<0) 
                {
                    printf("Invalid operator at %d.\n", i);
                    return;
                }*/

                while (top != -1 && prece(c) <= prece(stack[top]))
                {ans[j++] = stack[top--];}
                stack[++top] = c;
            }
        }
    }

    while (top != -1)
    {
        ans[j++] = stack[top--];
    }
    ans[j] = '\0';

    printf("The postfix expresion is as follows:\n");
    printf("%s\n", ans);
}

int main()
{
    char exp[50];
    printf("Enter the expression: ");
    fgets(exp, 50, stdin);
    postfix(exp);

    return 0;
}