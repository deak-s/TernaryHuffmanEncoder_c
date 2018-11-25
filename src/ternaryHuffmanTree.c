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
//    Node *x = middleQueue->head;

 //   printf("test %c %c %c\n", x->left->character, x->right->character, x->left->left->character); 

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


void iterateThroughEncodings(Node *root, int height, int *code, CodeBook **theBook){

    Node *theNode = root;

    if(theNode->character != '*'){
        
        printf("Node %c : %d \n", theNode->character, theNode->frequency);

        for(int j = 0; j < height -1 ; j++){
            printf("%d", code[j]);
        }
        printf("at height %d\n", height);

        addToCodeBook(*theBook, theNode->character, code, height -1);

        printf("\n");
        return;
    }


    if(height == 1){
        code[0] = 0;
        iterateThroughEncodings(theNode->left, height  + 1, code, theBook);
        code[0] = 1;
        iterateThroughEncodings(theNode->middle, height + 1 , code, theBook);
        code[0] = 2;
        int *testRight = (int *)calloc(1, sizeof(int));
        testRight[0] = 2;
        iterateThroughEncodings(theNode->right, height + 1, code, theBook);
    }


    else{

        printf("--------- at node %c : %d ---------------\n", root->character, root->frequency);

        printf("----code from parent ");

       for(int j = 0; j < height - 1 ; j++){
            printf("%d", code[j]);
        }
   

       printf("\n");

        //code[height - 1] = 0;
        int *newCode = (int *)calloc(height + 1, sizeof(int *));
        memmove(newCode, code, height + 1);

        printf("--new code\n");
        newCode[height -1] = 0;

       for(int j = 0; j <= height ; j++){
            printf("%d", newCode[j]);
        }

       printf("\n");


       //lft node
       iterateThroughEncodings(
               theNode->left, 
               height + 1, 
               newCode, 
               theBook);


        int *midCode = (int *)calloc(height + 1, sizeof(int *));
        memmove(midCode, code, height + 1 );

        midCode[height -1  ] = 1;
        iterateThroughEncodings(theNode->middle, 
                height + 1 , midCode, theBook);


        int *rightCode = (int *)calloc(height + 1, sizeof(int *));
        memmove(rightCode, code, height + 1);

        printf("old code     ->"); 
       for(int j = 0; j < height ; j++){
            printf("%d", code[j]);
        }
       printf("\n");

        printf("right code b4     ->"); 
       for(int j = 0; j < height ; j++){
            printf("%d", rightCode[j]);
        }
       printf("\n");

        rightCode[height -1 ] = 2;


        printf("right code     ->"); 
       for(int j = 0; j < height ; j++){
            printf("%d", rightCode[j]);
        }
       printf("\n");

       printf("height %d\n", height);
       iterateThroughEncodings(theNode->right, height + 1, rightCode, theBook );
     }
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
