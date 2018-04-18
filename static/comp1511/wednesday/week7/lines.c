#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 4096


int main(int argc, char *argv[]) {
   /* code */

    char line[MAX_LINE];
    int  i;

    while (fgets(line, MAX_LINE, stdin) != NULL) {
        i = 0;
        while (line[i] != '\n' && line[i] != '\0') {
            i++;
        }

        printf("the line is %d characters long\n", i);
    }
    return 0;

}
