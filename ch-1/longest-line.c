/*
Section 1.9: Character Array
print the longest input line
*/

#include <stdio.h>
#define MAXLINE 100000 /* maximum input line length */
#define PRINTLINETHRESHOLD 80 /* print line if more than this number */

int customgetline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    
    max = 0;
    while ((len = customgetline(line, MAXLINE)) > 0)
    {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
        if (len > PRINTLINETHRESHOLD)
            printf("> Printing line more than 80 characters... Character count = %d :\n%s", len, line);
    }

    if (max > 0) /* there was a line */
        printf("\n>>> The longest line is %d characters. The full line is as shown below:\n%s", max, longest);
        
    return 0;
}

/* 
customgetline: 
1. read a line into s
2. remove trailing white spaces and tabs
3. return length regardless if the lim had been reach
<note> 
renamed from getline to customgetline as the name conflicts with the stdio.h 's function getline().
This will not be an issue in c++ as c++ supports function overload but in c this is a compiler error
*/
int customgetline(char s[],int lim)
{
    int c, i, j, k;
    for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (i < lim-1)
        {
            s[j] = c;
            ++j;
        }
    }

    for (k = j; k < 0 ; ++k)
    {
        if (s[k] != ' ' && s[k] != '\t')
        {
            break;
        }
        else
        {
            s[k] = NULL;
            --j;
            --i;
        }
    }
    
    if (c == '\n') 
    {
        if(i <= lim - 1)
        {
            s[j++] = c;
        }
        ++i;
    }
    
    s[j] = '\0';
    return i;
}

/* copy: 
1. copy 'from' into 'to'; assume to is big enough 
2. remove blank line
*/
void copy(char to[], char from[])
{
    if (from[0] == '\n')
    {
        from[0] = NULL;
        return;
    }

    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}