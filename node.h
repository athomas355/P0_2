#ifndef NODE_H
#define NODE_H
#include <stdio.h>
#include <stdlib.h>

#define STRINGLENGTH 1024

//https://www.geeksforgeeks.org/binary-tree-set-1-introduction/
struct node {
    char lastChar;
    struct node *left;
    struct node *right;   
    char *stringList[STRINGLENGTH];
};

#endif