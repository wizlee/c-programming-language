/* <Exercise 1.14> 
count lenth of words and represent them in histogram 
*/

#include <stdio.h>

#define IN 0
#define OUT 1
#define MAX_WORD_LENGTH 255
main()
{
	int c, i, j, wordScope, currWordCount;
	int wordLength[MAX_WORD_LENGTH]; 
	for (i = 0; i < MAX_WORD_LENGTH; ++i)
		wordLength[i] = 0;

	// display the table header...
        printf("%s%13s%17s\n","Element/index", "Value", "Histogram");
	currWordCount = 0;
	while ((c = getchar()) != EOF)
	{
		/*
			This checking omits control and other special characters
			Those characters will be considered as part of the word
		*/
		if (c == ' ' || c == '\n' || c == '\t')
		{
			wordScope = OUT;	
		}
		else
		{
			wordScope = IN;
			currWordCount++; 
		}

		if (wordScope == OUT)
		{
			/*
				the last array category is for count of all words with length > 254
			*/
			if (currWordCount > MAX_WORD_LENGTH)
				++wordLength[MAX_WORD_LENGTH];
			else if(currWordCount > 0)
				++wordLength[currWordCount];
			
			currWordCount = 0;
		}
	}
	// do the iteration...
    // the outer for loop, read row by row...
    for(i=0; i < MAX_WORD_LENGTH; i++)
    {
		if (wordLength[i] <= 0)
			continue;
        printf("%9d%15d       ", i, wordLength[i]);
        // the inner for loop, for every row, read column by column and print the bar... total of 3 bars for better visual
        for(j = 1; j<= wordLength[i]; j++)
        {
                // print the bar...repeat...
                printf("#");
        }
        printf("\n                               ");
        for(j = 1; j<= wordLength[i]; j++)
        {
                // print the bar...repeat...
                printf("#");
        }
        printf("\n                               ");
        for(j = 1; j<= wordLength[i]; j++)
        {
                // print the bar...repeat...
                printf("#");
        }
        // go to new line for new row...repeats...
        printf("\n");
		printf("\n");
	}
}
