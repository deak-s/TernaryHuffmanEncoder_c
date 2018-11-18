/*
 * helpers.c
 * @author Sophia Deak
 * @date Nov 17th 2018
 * @brief helper functions for creation of ternary huffman tree
 */

#include <stdio.h>
#include <stdlib.h>



int compareNodes(Node *A, Node *B){
    printf("starting compare\n");

    //A > B  = 1
    //A < B = -1
    //A = B = 0

    if(A == NULL && B == NULL){
        return 99;
    }

    else if(B == NULL){
        return -1;
    }
    else if(A == NULL){
        return 1;
    }
    else if (A->frequency <= B->frequency){
        return -1;
    }
    else if(A->frequency > B->frequency){
        return 1;
    }
}

void assignLowestNodes(Node **A, Node **B, Node **C, Queue *leafQueue, Queue *middle){

 //--------assigning A-------------
    //if A <= C OR C is null
    if(compareNodes(leafQueue->head, middleQueue->head) == -1){
        printf("a gets leaf\n");
            *A = dequeue(leafQueue);
            printf("a got leaf\n");
    }
    else{
        printf("a gets mid\n");
        *A = dequeue(middleQueue);
    }

    //------assigning B-----------

    //if A <= C OR C is null
    if(compareNodes(leafQueue->head, middleQueue->head) == -1){
        printf("b gets leaf\n");
        *B = dequeue(leafQueue);
    }
    
    else{
        printf("b gets mid\n");
        *B = dequeue(middleQueue);
    }

    //-------assigning C--------

    if(compareNodes(leafQueue->head, middleQueue->head) == -1){
        printf("b gets leaf\n");
        *C = dequeue(leafQueue);
    }

    else{
        printf("b gets mid\n");
        *C = dequeue(middleQueue);
    }

    return;
}

Node *createMiddleNode(Node *A, Node *B, Node *C){
    int combinedFrequency = (A->frequency + B->frequency + C->frequency);
    Node *newMiddle = createNode( '*', combinedFrequency);

    newMiddle->left = A;
    newMiddle->middle = B;
    newMiddle->right = C;
    return newMiddle;
}
