#include <stdio.h>
#define MAX 36
#define SZ 100

char syms[MAX] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void append(char *, char);
char *strRev(char *);

int main()
{
    long pbase = 10;
    long dec, tmp, base, r;
    char any[SZ] = "";
    printf("enter a decimal number: ");
    scanf("%ld", &dec);
    printf("enter base to convert to (<=36): ");
    scanf("%ld", &base);
    
    tmp = dec;
    
    while (tmp != 0)
    {
        r = tmp % base;
        tmp /= base;
        
        append(any, syms[r]);
    }
    printf("(%ld)%ld = (%s)%ld\n", dec, pbase, strRev(any), base);

    return 0;
}

void append(char *str, char c)
{
    int len;
    for (len = 0; str[len] != '\0'; len++);
    if (len + 2 < SZ)
    {
        str[len] = c;
        str[len+1] = '\0';
    }
    else return;
}

char *strRev(char *s)
{
    int l, i;
    for (l = 0; s[l] != '\0'; l++)
        ;
    for (i = 0; i < l / 2; i++)
    {
        char c = s[i];
        s[i] = s[l - i - 1];
        s[l - i - 1] = c;
    }
    return s;
}
