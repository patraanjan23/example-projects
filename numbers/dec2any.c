#include <stdio.h>
#include <stdlib.h>
#define MAX 36
#define SZ 100

char syms[MAX] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void append(char *, char);
char *strRev(char *);

int main(int argc, char *argv[]) {
  long pbase = 10;
  long dec, tmp, base, r;
  char any[SZ] = "";

  if (argc != 2) {
    printf("usage: ./dec2any <base>\n");
    return 0;
  }

  base = atoi(argv[1]);
  if (base < 2 || base > 36) {
    printf("base must be between [2, 36]\n");
    return 0;
  }

  printf("enter a decimal number: ");
  scanf("%ld", &dec);

  tmp = dec;

  while (tmp != 0) {
    r = tmp % base;
    tmp /= base;

    append(any, syms[r]);
  }
  printf("(%ld)%ld = (%s)%ld\n", dec, pbase, strRev(any), base);

  return 0;
}

void append(char *str, char c) {
  int len;
  for (len = 0; str[len] != '\0'; len++)
    ;
  if (len + 2 < SZ) {
    str[len] = c;
    str[len + 1] = '\0';
  } else
    return;
}

char *strRev(char *s) {
  int l, i;
  for (l = 0; s[l] != '\0'; l++)
    ;
  for (i = 0; i < l / 2; i++) {
    char c = s[i];
    s[i] = s[l - i - 1];
    s[l - i - 1] = c;
  }
  return s;
}

/* OUTPUT
-------------------------------
▶ ./dec2any.out 2
enter a decimal number: 21
(21)10 = (10101)2
-------------------------------
▶ ./dec2any.out 8
enter a decimal number: 258
(258)10 = (402)8
-------------------------------
▶ ./dec2any.out 16
enter a decimal number: 287
(287)10 = (11F)16
-------------------------------
▶ ./dec2any.out 25
enter a decimal number: 5648
(5648)10 = (90N)25
-------------------------------
▶ ./dec2any.out 36
enter a decimal number: 3666
(3666)10 = (2TU)36
-------------------------------
 */