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


struct IntVecNode
    {
    int * data;
    int sz;
    int capacity;
    }IntVecNode;

/*constructor*/
IntVec intMakeEmptyVec(void){
    IntVec newVec;
    newVec = calloc(1u, sizeof(struct IntVecNode));
    newVec->data = calloc(intInitCap, sizeof(int));
    newVec->sz = 0;
    newVec->capacity = intInitCap;
    return newVec;
}

/*Access Functions*/
int intTop(IntVec myVec){
    int ret = 0; /*set the top = 0 as a default unless the sz > 0*/
    if (myVec->sz > 0)
    {
        ret = myVec->data[myVec->sz];
    }

    return ret;
}

int intData(IntVec myVec, int i){
    myVec->data[myVec->sz] = i;
    return i;
}

int intSize(IntVec myVec){
    return myVec->sz;
}

int intCapacity(IntVec myVec){
    return myVec->capacity;
}

/*Manipulation Procedures*/

void intVecPush(IntVec myVec, int newE){
    /* if the capacity is full, then implement array doubling */
    int newSz = intSize(myVec) + 1;
    int cap = intCapacity(myVec);
    myVec->sz = newSz;

    /* if (sz + 1) > cap then double array capacity*/
    if(newSz >= cap){
        doubleCap(myVec);
    }

    /*append new value onto the vector*/
    myVec->data[myVec->sz] = newE;
    intData(myVec, newE);

}

void intVecPop(IntVec myVec){
    int sz = intSize(myVec) - 1;
    int newTop;

    myVec->sz = sz;

    newTop = myVec->data[myVec->sz];
    intData(myVec, newTop);

}

/*Additional Functions*/

void doubleCap(IntVec myVec){
    int  newCap;
    int * newData;
    newCap = 2 * myVec->capacity;
    newData = realloc(myVec->data, newCap * sizeof(int));

    if( newData != myVec->data){
       myVec->data = newData;
    }

    myVec->capacity = newCap;

}
/*
void printVector(IntVec myVec){
    int top = intTop(myVec);
    int i;

    if (top == 0){
        printf("null");
    }
    else{
        printf("[");
        for (i = myVec->sz; i != 0; i--){
            printf(" %d ", myVec->data[i]);
            if(myVec->data[i] != 0 && myVec->sz >1){
                printf(", ");
            }
        }
        printf("]");
    }
}
*/
void printVector(IntVec myVec){
    int top = intTop(myVec);

    if (top == 0){
        printf("null");
    }
    else{
        printf("[");
        for (int i = myVec->sz; i != 0; i--){
            printf(" %d ", myVec->data[i]);
            if(i > 1){
                printf(",");
            }

        }
        printf("]");
    }
}

void freeVector(IntVec myVec){
    free(myVec->data);
    free(myVec);

}




