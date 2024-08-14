#include  "calcmarks.h"

// calcmarks, version 14, released Fri Jun 5 01:55:54 AWST 2020

int main(int argc, char *argv[])
{
    int nmarks = 0;

    if(argc == 1) {
         nmarks += readmarks(stdin);
    }
    else {
        for(int a=1 ; a<argc ; ++a) {
            FILE *fp = fopen(argv[a], "r");

            if(fp == NULL) {
                fprintf(stderr, "Cannot open %s\n", argv[a]);
                exit(EXIT_FAILURE);
            }
            nmarks += readmarks(fp);
	    fclose(fp);
        }
    }
    correlation(nmarks);
    return(0);
}
