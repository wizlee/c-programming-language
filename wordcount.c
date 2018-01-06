#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
/* count lines, words, and characters in input */
main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
            --nc; /* exclude newline in the character count */
        }
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("line count:\t\t\t%3d\nword count:\t\t\t%3d\ncharacter count:\t\t%3d\n\n", nl, nw, nc);
}
