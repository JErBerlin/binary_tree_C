//
// Created by jer on 18.03.20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM_NODES 1000

typedef struct node {
    char label;
    struct node *left;
    struct node *right;
} Node;

int traverse(Node *n) {
    return 0;
}

/* newNode() allocates a new node with the given label and NULL left and right children. */
Node *newNode(char label)
{
    // Allocate memory for new node
    Node *node = (Node*)malloc(sizeof(struct node));

    // Assign data to this node
    node->label = label;

    // Initialize left and right children as NULL
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int printGraph(Node *node) {
    printf("%c ", node->label);
    Node *left = node->left;
    Node *right = node->right;
    if(left != NULL) {
        printGraph(left);
    }
    if(right != NULL) {
        printGraph(right);
    }
}

int PreorderTraversal(char * strArr[]) {

    int level = 0;
    char parent = strArr[level];
    char nextLeft = strArr[level+1];
    char nextRight = strArr[level+2];

    /*create root*/
    Node *root = newNode(parent);
    root->left = newNode(nextLeft);
    root->right = newNode(nextRight);

    if(strArr[level+3] == '\0') return 0;

    level++;
    do {
        int ind;
        for (ind = 1<<level; ind < 1<<(level+1);ind +=2) {
            char nextLeft = strArr[(1 << level) + 1];
            char nextRight = strArr[level + 2];
            if (nextLeft != '#') {
                parent = nextLeft;

                char nextLeft = strArr[level + 1];
                char nextRight = strArr[level + 2];
            }
        }

        level++;
    } while (strArr[1<<level+1] != '\0');


    printGraph(root);
    printf("\n");


    return 0;
}

int main(void) {

    // keep this function call here
    /* Note: In C you first have to initialize an array and set
       it equal to the stdin to test your code with arrays. */

    char * A[] = {"5", "2", "6", "1", "9", "#", "8", "#", "#", "#", "#", "4", "#", "\0"};

    PreorderTraversal(A);

    return 0;
}