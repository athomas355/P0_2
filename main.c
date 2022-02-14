#include "node.h"
#include "traversal.h"
#include "buildTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    struct node *root = NULL;
    char *text = calloc(STRINGLENGTH + 1, 1);
    char input[STRINGLENGTH];
    FILE * preorderFile;
    FILE * postorderFile;
    FILE * levelorderFile;
    preorderFile = fopen("treetraversal.preorder", "w");
    postorderFile = fopen("treetraversal.postorder", "w");
    levelorderFile = fopen("treetraversal.levelorder", "w");


    //process command line arguments and make sure file is readable, error otherwise
    if(argv[1]) {
        FILE * file = fopen(argv[1], "r");

        if(!file) {
            printf("File unable to open\n");
            exit(-1);
        }
        
        root = buildTreeFile(file);

        
        traversalPreOrder(root, 0, preorderFile);
        printf("Created treetraversal.preorder\n");
        
        traversalPostOrder(root, 0, postorderFile);
        printf("Created treetraversal.postorder\n");

        traversalLevelOrder(root, levelorderFile);
        printf("Created treetraversal.levelorder\n");
    }
    
    //setup keyboard processing so that below the input method is not relevant
    else {
        printf("Enter input:\n");
        
        while(fgets(input, STRINGLENGTH, stdin)) {  /* break with ^D or ^Z */
            text = realloc(text, strlen(text) + 1 + strlen(input));
            strcat(text, input);
        }    

        root = buildTreeKey(text);

        traversalPreOrder(root, 0, preorderFile);
        printf("Created treetraversal.preorder\n");
        
        traversalPostOrder(root, 0, postorderFile);
        printf("Created treetraversal.postorder\n");

        traversalLevelOrder(root, levelorderFile);
        printf("Created treetraversal.levelorder\n");
    }

    fclose(preorderFile);

    return 0;
}