#include  "calcmarks.h"    // local header file provides declarations

// calcmarks, version 14, released Fri Jun 5 01:55:54 AWST 2020

int readmarks(FILE *fp)
{
    char     line[BUFSIZ];
    int      nmarks = 0;

    double   thisproj;
    double   thisexam;

    //  READ A LINE FROM THE FILE, CHECKING FOR END-OF-FILE OR AN ERROR
    while( fgets(line, sizeof line, fp) != NULL ) {

        sscanf(line, "%lf %lf", &thisproj, &thisexam);

        projmarks[nmarks]   = thisproj;   // update global array
        exammarks[nmarks]   = thisexam;

        ++nmarks;

        if(verbose)       // access global variable
            printf("read student %d\n", nmarks);
    }
    return nmarks;
}
