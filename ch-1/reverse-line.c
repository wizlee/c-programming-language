/*
Exercise 1.19 : Write a function reverse(s) that reverses the character string s . Use it to
write a program that reverses its input a line at a time.

Mystery solved: can't use ·(\u00B7) to replace the space as it is of length 2. Can't really find out why it is two byte 
as 8 bits is still 1 byte. My guess will be because after including null terminator \0 ?
<code>
printf("length of · = %ld\n", strlen(twobyte));
printf("length of * = %ld\n", strlen(onebyte));
<console output>
length of · = 2
length of * = 1

<reference>
https://stackoverflow.com/questions/10017328/unicode-stored-in-c-char
*/

#include <stdio.h>
#include <string.h>

#define MAXLINE 10000

int reverse(char line[], int limit);

int main()
{
    char input[MAXLINE];

    while (reverse(input, MAXLINE) > 0)
        printf("%s\n", input);

    return 0;
}

int reverse(char s[], int lim)
{
    char temp[lim];
    int c, i, j, k;

    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < lim - 1; ++i)
    {
        if (c == ' ')
            c = '`';
        temp[i] = c;
    }
    
    if (c == '\n')
    {
        for (j = 0, k = i - 1; j < i; ++j, --k)
        {
            s[j] = temp[k];
        }
        s[i++] = '\n';
    }
    else
    {
        for (j = 0, k = i - 1; j < i; ++j, --k)
        {
            s[j] = temp[k];
        }
    }
    s[j] = '\0';

    return i;
}
