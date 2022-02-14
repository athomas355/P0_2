#include "buildTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
//new node function
struct node *newNode(char* data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->lastChar = data[strlen(data) - 1];
    temp->left = NULL;
    temp->right = NULL;
    *temp->stringList = strndup(data, 10);
    return temp;
} 

//https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
//insert function
struct node* insert(struct node *node, char* data) {
    char lChar;
    lChar = data[strlen(data) - 1];

    //checks if tree is empty
    if(node == NULL) {
        return newNode(data);
    }

    //checks if node already exists
    if(lChar == node->lastChar) {
        strcat(*node->stringList, " ");
        strcat(*node->stringList, data);

        return node;
    }

    //recursion down the tree
    if(lChar < node->lastChar) {
        node->left = insert(node->left, data);
    }
    else {
        node->right = insert(node->right, data);
    }

    return node;
}

//build tree function from file input
struct node *buildTreeFile(FILE * file) {

    //declarations
    char str[STRINGLENGTH];
    char lChar;
    struct node* root = NULL;

    //does file exist
    if(file) {
        while(fscanf(file, "%s", str) != EOF) {
            
            //last character of string
            lChar = str[strlen(str) - 1];

            //if empty tree
            if(root == NULL) {
                root = insert(root, str);
            }
            else {
                insert(root, str);
            }
        }

        fclose(file);
    }
    else {
        printf("ERROR: File was not able to open\n");
        exit(-1);
    }

    return root;
}

// //build tree function from keyboard input
struct node *buildTreeKey(char* input) {

    //declarations
    char str[STRINGLENGTH];
    struct node* root = NULL;
    char delim[] = " \n";

    char *ptr = strtok(input, delim);

    while(ptr != NULL) {
        if(root == NULL) {
            root = insert(root, ptr);
            ptr = strtok(NULL, delim);
        }
        else {
            insert(root, ptr);
            ptr = strtok(NULL, delim);
        }
    }
    
    return root;
}


