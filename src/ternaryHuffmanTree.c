/*
 * @file ternaryHuffmanTree.c
 * @author Sophia Deak
 * @date Nov 17th 2018
 * @brief wrapper functions for building ternary huffman tree and generating codebook
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ternaryHuffmanTree.h"
#include "nodeQueue.h"
#include "helpers.h"
//#include "codeBook.h"


Node * createTree(Queue **leafQueue){

    Queue *middleQueue = initializeEmptyQueue();

    while((*leafQueue)->head != NULL || middleQueue->head->next != NULL){

        Node *A; 
        Node *B;
    	Node *C;

        assignLowestNodes(&A, &B, &C, *leafQueue, middleQueue);

        Node *M = createMiddleNode(A, B, C);
        enqueue(middleQueue, M);

        printf("loop happened\n");
        printQueue(*leafQueue);
        printf("mid queue\n");
        printQueue(middleQueue);
    }


    printf("printing final midqueue\n");

    printQueue(middleQueue);


    Node *root = dequeue(middleQueue);

    printQueue(*leafQueue);
    deleteQueue(*leafQueue);


    printQueue(middleQueue);
    deleteQueue(middleQueue);
    free(middleQueue);

    return root;
}

void printTree(Node *root){

    Node *theNode = root;

    if(theNode->character != '*'){
        printf("Node %c : %d \n", theNode->character, theNode->frequency);
        return;
    }
        printTree(theNode->left);
        printTree(theNode->middle);
        printTree(theNode->right);
}

int heightOfTree(Node *root){

    if(root == NULL){
        return 0;
    }

    int left = heightOfTree(root->left);
    int middle = heightOfTree(root->middle);
    int right = heightOfTree(root->right);

    if(left >= right && left >= middle){
        return left + 1;
    }
    else if(right >= middle){
        return right + 1;
    }
    else{
        return middle + 1;
    }
}


void iterateThroughEncodings(Node *root, int height, int *code, CodeBook **theBook){

    Node *theNode = root;

    if(theNode->character != '*'){
        
        printf("Node %c : %d \n", theNode->character, theNode->frequency);

        for(int j = 0; j < height -1 ; j++){
            printf("%d", code[j]);
        }

        addToCodeBook(*theBook, theNode->character, code, height -1);
        printf("\n");
        return;
    }

       code[height - 1] = 0;

       iterateThroughEncodings(
               theNode->left, 
               height + 1, 
               code, 
               theBook);


       code[height - 1] = 1;

        iterateThroughEncodings(theNode->middle, 
                height + 1 , code, theBook);


        code[height -1 ] = 2;

       iterateThroughEncodings(theNode->right, height + 1, code, theBook );
}


void deleteTree(Node *root){

    Node *theNode = root;

    if(theNode == NULL){
        return;
    }

    printf("deleting %c %d\n", theNode->character, theNode->frequency);
    deleteTree(theNode->left);
    deleteTree(theNode->middle);
    deleteTree(theNode->right);

    free(theNode);
    return;
}
