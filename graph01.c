/**
 * Karen Cariaga
 * CruzID: kccariag
 * Assignment: pa1
*/
#include "intVec.h"
#include "edge.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int from;
    int to;
    double weight;
} Edge;

Edge parseEdge(char line[], int nodes)
{
    Edge newE;
    int numFields;

    numFields = sscanf(line, "%d %d %lf %*s", &newE.from, &newE.to, &newE.weight);
    if (numFields < 2 || numFields > 3 || newE.from > nodes || newE.to > nodes || newE.from <= 0 || newE.to <= 0)
    {
        printf("Bad edge\t(from) (to) (weight):\n\t\t %s \n\n", line);

        exit(1);
    }
    if (numFields == 2)
        newE.weight = 0.0;

    return newE;

}
int main(int argc, char* argv[]){
    int i; /*for loop counter*/
    int n; /*Number of nodes aka elements in the "array of intVecs" */
    int edgeCount = 0;/*counts number of edges*/

    FILE *fp;
    char * fgetsRet;
    char line[1024];

    fp = fopen(argv[1], "r");
    fgetsRet = fgets(line, 1024, fp);

    if (argc < 2 || argc > 2){
        printf("Error: No file received.\n");
        exit(1);
    }

    sscanf(line, "%d", &n);
    IntVec adjList[n];

    if (fp != NULL ) {

        /*Makes an array of empty vectors*/
        for (i= 0; i <= n; i++){
            adjList[i] = intMakeEmptyVec();
        }
        fgets(line,1024,fp);/*Read first line*/
        /*Read the rest of the file and assign values to edges*/
        while (fgetsRet == line)
{
            Edge e = parseEdge(line, n);
            edgeCount +=1;
            intVecPush(adjList[e.from], e.to);
            fgetsRet = fgets(line, 1024, fp);
        }
        fclose(fp);
    }

    /* Loads the graph and prints output*/
    printf("n = %d\n",n);
    printf("m = %d\n",edgeCount);


    for(i = 1; i<=n; i++){

        printf("%d\t",i);
        printVector(adjList[i]);
        printf(
               "\n");

    }
    /*Frees space from every vector*/
    for(i = 0; i <= n; i++){
        freeVector(adjList[i]);
    }

    return 0;
}
