#include<stdio.h>
#include<conio.h>

int leap(int year)
{
    if (year%4==0 || year%400==0) {return 1;}
    else if (year%100==0 && year%400!=0) {return 0;}
    else {return 0;}
}

int days(int m, int y)
{
    if (m<=7)
    {
        if (m%2==0 && m!=2)
        {return 30;}
        else if (m==2)
        {
            if(leap(y)==1) {return 29;}
            else {return 28;}
        }
        else {return 31;}
    }
    else 
    {
        if (m%2==0)
        {return 31;}
        else {return 30;}
    }
}

char* month(int m)
{
    switch(m)
    {
        case 1:return "January"; break;
        case 2:return"February"; break;
        case 3:return"March"; break;
        case 4:return"April"; break;
        case 5:return"May"; break;
        case 6:return"June"; break;
        case 7:return"July"; break;
        case 8:return"August"; break;
        case 9:return"September"; break;
        case 10:return"October"; break;
        case 11:return"November"; break;
        case 12:return"December"; break;
    }
}

char* day(int d)
{
    switch(d)
    {
        case 1:return "Mon"; break;
        case 2:return "Tue"; break;
        case 3:return "Wed"; break;
        case 4:return "Thu"; break;
        case 5:return "Fri"; break;
        case 6:return "Sat"; break;
        case 7:return "Sun"; break;
    }
}

int NoDay(int m, int y)
{
    int total=0;
    for (int i=1; i<=y; i++)
    {
        for (int j=1; j<=12; j++)
        {
            if (i==y && j==m) {break;}
            total+=days(j, i);
        }
    }

    return (total%7);
}

void sp(int d)
{
    int sp=(5*(d-1));
    for (int i=1; i<=sp; i++)
    {
        printf(" ");
    }
}

void cal(int dat, int m, int y)
{
    printf("%s %d:\n", month(m), y);
    for (int i=1; i<=7; i++)
    {printf("%s  ", day(i));}
    printf("\n");
    sp(NoDay(m, y));
    int d=NoDay(m, y);
    if (d!=0) {d-=1;}
    for (int i=1; i<=days(m, y); i++)
    {
        if(d==7) {printf("\n"); d=0;}
        if (i<10) 
        {
            if(i!=dat) {printf(" %d   ", i);}
            else {printf("'%d'  ", i);}
        }
        else 
        {
            if(i!=dat) {printf(" %d  ", i);}
            else {printf("'%d' ", i);}
        }
        d++;
    }
    printf("\nUP arrow key: Same day, previous week.\nDOWN arrow key: Same day, next week.\nRIGHT arrow key: Next day.\nLEFT arrow key: Previous day.\nESC key: Exit calendar.\n");
}

int getKey()
{
    int ch;
    ch = getch();
    if (ch==0)
    {
        ch=getch();
        return ch;
    }
    return ch;
}

int main()
{
    int dat, m, y; 
    for (int i=0;;)
    {
        printf("Enter the date: "); scanf("%d%d%d", &dat, &m, &y);
        if (dat<1 || dat>days(m, y))
        {printf("Wrong date, please try again!!\n");}
        else if(m<1 || m>12)
        {printf("Wrong month, please try again!!\n");}
        else {break;}
    }
    cal(dat, m, y);
    for (int i=0;;)
    {
        if(getKey()==27) {break;}
        switch (getKey())
        {
        case 72:if(dat>7) {dat-=7; cal(dat, m, y);}
                else if (dat==7) {dat=days(m-1, y); m-=1; cal(dat, m, y);}
                else 
                {
                    if (m>1) {dat=days(m-1, y)-(7-dat); m-=1; cal(dat, m, y);}
                    else {dat=days(12, y-1)-(7-dat); m=12; y-=1; cal(dat, m, y);}
                }
                break;

        case 80:if((days(m, y)-dat)>=7) {dat+=7; cal(dat, m, y);}
                else
                {
                    if (m<12) {dat=7-(days(m, y)-dat); m+=1; cal(dat, m, y);}
                    else {dat=7-(days(12, y)-dat); m=1; y+=1; cal(dat, m, y);}
                }
                break;
                
        case 75:/*if(m>1) 
            {
                if(dat==1) {dat=days(m-1, y); m-=1; cal(dat, m, y);}
                else {dat-=1; cal(dat, m, y);}
            }
            else 
            {
                if(dat==1) { m=12; y-=1; dat=days(m, y); cal(dat, m, y);}
                else {dat-=1; m=1; cal(dat, m, y);}
            }
            break;*/
            if (dat == 1) 
            {
                if (m > 1) 
                {
                    m -= 1;
                    dat = days(m, y);
                } 
                else 
                {
                    m = 12;
                    y -= 1;
                    dat = days(m, y);
                }
            } 
            else 
            {
                    dat -= 1;
            }
            cal(dat, m, y);
            break;

        case 77:if (m<12)
            {
                if(dat==days(m, y)) {dat=1; m+=1; cal(dat, m, y);}
                else {dat+=1; cal(dat, m, y);}
            }  
            else 
            {
                if(dat==days(12, y)) {dat=1; y+=1; cal(dat, 1, y);}
                else {dat+=1; m=12; cal(dat, m, y);}
            }
            break;

            default:break;
        }
    }
    return 0;
}