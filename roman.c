#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int value(char c)
{
    switch (c)
    {
        case 'I': return 1; break;
        case 'V': return 5; break;
        case 'X': return 10; break;
        case 'L': return 50; break;
        case 'C': return 100; break;
        case 'D': return 500; break;
        case 'M': return 1000; break;

        default: return 0; break;
    }
}

int checkNum(char *c, int r, int i, int c1)
{
    if (r>3) {return 0;}
    if (c1==strlen(c)-r) {return 1;}

    if (c[i]==c[i+1]) {r++; checkNum(c, r+1, i+1, c1);}
    else 
    {
        if (c[i]!='I')
        {
            if (value(c[i])>=value(c[i+1])) { return checkNum(c, 1, i+1, c1+1); }
            else {return 0;}
        }
        else
        {
            if (c[i+1]=='V' || c[i+1]=='X') { return checkNum(c, 1, i+1, c1+1);}
            else {return 0;}
        }
    }
}

int main()
{
    char *num;
    for (;;)
    {
        printf("Enter the roman numeral: ");
        scanf("%s", num);

        if (checkNum(num, 0, 0, 0)==1) {break;}
        else {printf("Wrong numeral, try again!!\n");}
    }
        long v=0;
    for (int i=0; i<strlen(num); i++)
    {
        if (i<strlen(num) && value(num[i])<value(num[i+1])) { v-=value(num[i]); }
        else { v+=value(num[i]);}
    }

    if (v<=3999) {printf("The value of %s is %d.\n", num, v);}
    else {printf("Value out of bounds of roman numerals!!\n");}
    return 0;
}