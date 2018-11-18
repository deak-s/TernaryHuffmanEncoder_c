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

    Node *x = middleQueue->head;

    printf("test %c %c %c\n", x->left->character, x->right->character, x->left->left->character); 

    return middleQueue->head;


//    deleteQueue(middleQueue);
 //   free(middleQueue);
}


