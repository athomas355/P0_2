#ifndef TRAVERSALS_H
#define TRAVERSALS_H
#include "node.h"

int treeHeight(struct node*);
void printCurrentLevel(struct node*, int, FILE * file);
void traversalLevelOrder(struct node*, FILE *);
void traversalPreOrder(struct node*, int, FILE *);
void traversalPostOrder(struct node*, int, FILE *);

#endif