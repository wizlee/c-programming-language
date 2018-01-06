/* <Exercise 1.20> 
Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
n will be a variable
*/

#include <stdio.h>

#define TABSTOP 2

int main()
{
    if (TABSTOP <= 0)
    {
        printf("Tabstop cannot be less or equal to zero. Exiting program...\n");
        return 1;
    }
    char c;
    int currCharCnt = 0;
    while((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            currCharCnt = 0;
        }
        if (c == '\t')
        {
            int replaceBlank, i;
            replaceBlank = TABSTOP - (currCharCnt % TABSTOP);
            for (i = 0; i < replaceBlank; ++i)
            {
                putchar(' ');
                currCharCnt++;
            }
        }
        else
        {
            putchar(c);
            currCharCnt++;
        }
    }
    return 0;
}