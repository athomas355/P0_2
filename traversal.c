#include "traversal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int current = 0;

//https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
//Preorder traversal function
void traversalPreOrder(struct node *root, int level, FILE * file) {

    if(file == NULL) {
        printf("ERROR: Unable to create file\n");
        exit(-1);
    }

    if(root != NULL) {

        //process root node
        for(int i = 0; i < level * 4; i++) {
            fprintf(file, " ");
        }

        //prints node and the list of strings the node has
        fprintf(file, "%d. %c: ", level + 1, root->lastChar);
        fprintf(file, "%s\n", *root->stringList);

        //process left child
        if(root->left != NULL) {
            traversalPreOrder(root->left, level + 1, file);
        }

        //process right child
        if(root->right != NULL) {
            traversalPreOrder(root->right, level + 1, file);
        }
    }
}

//Postorder traversal function
void traversalPostOrder(struct node *root, int level, FILE * file) {
    if(root != NULL) {

        //process left child
        if(root->left != NULL) {
            traversalPostOrder(root->left, level + 1, file);
        }

        //process right child
        if(root->right != NULL) {
            traversalPostOrder(root->right, level + 1, file);
        }

        //process root node
        for(int i = 0; i < level * 4; i++) {
            fprintf(file, " ");
        }

        //prints node and the list of strings the node has
        fprintf(file, "%d. %c: ", level + 1, root->lastChar);
        fprintf(file, "%s\n", *root->stringList);

    }
}

//https://www.geeksforgeeks.org/level-order-tree-traversal/
//Level Order traversal functions
void traversalLevelOrder(struct node *root, FILE * file) {
    int h = treeHeight(root);
    for(int i = 1; i <= h; i++) {
        printCurrentLevel(root, i, file);
        current++;
    }
}

//print the current level function
void printCurrentLevel(struct node *root, int level, FILE * file) {
    if(root == NULL) {
        return;
    }
    if(level == 1) {
        //process root node
        for(int i = 0; i < current * 4; i++) {
            fprintf(file, " ");
        }

        //prints node and the list of strings the node has
        fprintf(file, "%d. %c: ", current + 1, root->lastChar);
        fprintf(file, "%s\n", *root->stringList);
    }
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1, file);
        printCurrentLevel(root->right, level - 1, file);
    }
}

//tree height function
int treeHeight(struct node *root) {
    if(root != NULL) {
        int lHeight = treeHeight(root->left);
        int rHeight = treeHeight(root->right);

        if(lHeight > rHeight) {
            return (lHeight + 1);
        }
        else {
            return (rHeight + 1);
        }
    }
}

