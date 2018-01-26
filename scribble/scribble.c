/**
 * copy stdin to stdout, write random bytes over random locations
 *
 * Default: write over 1% of input bytes with random data
 *
 * Takes an optional command line argum
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MAX_LINE_LENGTH 9999

int main(int argc, char **argv)
{
        char line[MAX_LINE_LENGTH];
        int j, n;
        float p;
        float prob = 0.01; /* Proportion of bytes to write over*/

        if(argc > 1)
                prob = atof(argv[1]);

        if(prob < 0 || prob > 1){
                fprintf(stderr, "Error: probability must be in range [0-1].i\n");
                return 1;
        }

        srand(time(NULL));

        while(NULL != fgets(line, MAX_LINE_LENGTH, stdin)){
                n = strlen(line);
                for(j = 0; j < n - 1; j++){
                        p = (float) rand() / RAND_MAX;
                        if(p <= prob) line[j] = (char) rand();
                }
                fputs(line, stdout);
        }
        return 0;
}

