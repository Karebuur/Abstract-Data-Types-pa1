/**
 * Karen Cariaga
 * CruzID: kccariag
 * Assignment: pa1
*/

/** edge.h
* The purpose of this header file is to contain additional function declarations
* that are to be used amongst multiple files, which are not already declared in
* intVec.h This is so that the original intVec.h is not changed.
*/

#include "intVec.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED



/** doubleCap(IntVec myVec)
 * precondition: /sz/ == /cap/
 * postconditions:
 *    if adding a new value fills up the last memory byte available, reallocate
 *    to a new place in memory with double the capacity.
 *    intCapacity(myVec) = 2 * /cap/.
 *
 */
void doubleCap(IntVec myVec);

/**
* precondition: myVec has been constructed
* postcondition:
*       The contents of each individual vector is printed
*/
void printVector(IntVec myVec);

/**precondition: none
*  postconditions; Rids program of memory leaks
*       1.data in the current vector is freed
*           free(myVec->data
*       2.the vector itself is freed
*           free(myVec)
*/
void freeVector(IntVec myVec);

void printAdjList(IntVec adjList[],int n);


#endif
