#include <stdio.h>
#define MAXLINE   1000 /* maximum input line size */
#define MINLENGTH 80   /* minimum length that a line need to have 
                          to be printed */

int get_line(char line[], int maxline);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > MINLENGTH)
            printf("%s\n", line);
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

