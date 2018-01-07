/* <Exercise 1.14> 
count lenth of words and represent them in histogram 
*/
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_CHAR_TYPE CHAR_MAX-1
main()
{
    int c, i, j, wordScope, currWordCount;
    int charFreq[MAX_CHAR_TYPE]; 
    for (i = 0; i < MAX_CHAR_TYPE; ++i)
        charFreq[i] = 0;

    // display the table header...
    printf("%s%13s%17s\n","Character    ", "Value", "Histogram");
    currWordCount = 0;
    while ((c = getchar()) != EOF)
    {
        if (charFreq[c] >= 0 && 'c' < CHAR_MAX)
        {
            ++charFreq[c];
        }
    }
    // do the iteration...
    // the outer for loop, read row by row...
    for(i=0; i < MAX_CHAR_TYPE; i++)
    {
        if (charFreq[i] <= 0)
            continue;

        // handle the special case of tab, newline and space
        char str[13] = { (char)i, '\0' };
        switch(str[0])
        {
            case '\n':
                strcpy(str, "newline");
                break;

            case '\t':
                strcpy(str, "tab");
                break;

            case ' ':
                strcpy(str, "space");
                break;
        }

        printf("%9s%15d       ", str, charFreq[i]);
        // the inner for loop, for every row, read column by column and print the bar... total of 3 bars for better visual
        for(j = 1; j<= charFreq[i]; j++)
        {
                // print the bar...repeat...
                printf("#");
        }
        printf("\n                               ");
        for(j = 1; j<= charFreq[i]; j++)
        {
                // print the bar...repeat...
                printf("#");
        }
        printf("\n                               ");
        for(j = 1; j<= charFreq[i]; j++)
        {
                // print the bar...repeat...
                printf("#");
        }
        // go to new line for new row...repeats...
        printf("\n");
        printf("\n");
    }
}
