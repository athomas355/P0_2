#ifndef BUILDTREE_H
#define BUILDTREE_H
#include "node.h"

struct node *newNode(char*);
void *newListNode(struct node *, char*);
struct node *insert(struct node *, char*);
struct node *buildTreeFile(FILE *);
struct node *buildTreeKey(char*);
#endif