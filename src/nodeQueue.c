/*
 * @file nodeQueue.c
 * @author Sophia Deak
 * @date Nov 17th 2018
 * @brief queue data struct for ternary huffman tree nodes
*/



#include <stdio.h>
#include <stdlib.h>

#include "nodeQueue.h"



Node * createNode(char c, int f) {      
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->character = c;
    newNode->frequency = f;             
    newNode->next = NULL;
    newNode->prev = NULL;
    
    newNode->left = NULL;
    newNode->middle = NULL;
    newNode->right = NULL;               
    return newNode;
}   
    
Node *copyNode(Node *original){         
    Node  *newNode = createNode(original->character, original->frequency);
    newNode->next = original->next;     
    newNode->prev = original->prev;

    newNode->right = original->right;   
    newNode->middle = original->middle;
    newNode->left = original->left;     
    return newNode;                     
}   
 

Queue *initializeEmptyQueue () {        
    Queue *newQueue;                    
    newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->head = NULL;
    newQueue->tail = NULL;              
    return newQueue;
}





void fillQueueFromArray(Pair *array, Queue *theQueue, size_t length){

    printf("length %ld\n", length);

    //start at head of queue
    Pair *tempPair = &array[0];

    theQueue->head = createNode(tempPair->character, tempPair->frequency);

    Node *currentNode = theQueue->head;

    for (int k = 1; k < length; k++){
        Pair *tempPair = &array[k];

        Node *tempNode = createNode(tempPair->character, tempPair->frequency);
        currentNode->next = tempNode;
        tempNode->prev = currentNode;
   
        currentNode = currentNode->next;
    }
return;
}




void enqueue(Queue *theQueue, Node *theNode){
    //case: first node
    if(theQueue->head == NULL){
        printf("Q   first element added\n");
        theQueue->head = theNode;
        return;
    }
   
    Node *currentNode = theQueue->head;
    while(currentNode->next != NULL){
        currentNode = currentNode->next;
    }

    currentNode->next = theNode;
    theNode->prev = currentNode;
};

Node *dequeue(Queue *theQueue){

    Node *tempNode = copyNode(theQueue->head);

    if(tempNode->next != NULL){
        theQueue->head = tempNode->next;
        free(theQueue->head->prev);
    }

    else if(theQueue->head->next == NULL){

        printf("last queue element\n");
        //free(theQueue->head);
        theQueue->head = NULL;
    }

    return tempNode;
};


void printQueue(Queue *theQueue){

    if(theQueue->head == NULL){
        printf("queue empty");
        return;
    }
    
    Node *tempNode = theQueue->head;
    printf(" %c : %d \n", tempNode->character, tempNode->frequency);
     while(tempNode->next != NULL){
        tempNode = tempNode->next;

        printf(" %c : %d \n", tempNode->character, tempNode->frequency);
     }
};


void deleteQueue(Queue *theQueue){

     if(theQueue->head == NULL){
        printf("queue empty");
        return;
    }

    Node *tempNode = theQueue->head;
        printf("deleting  %c : %d \n", tempNode->character, tempNode->frequency);

         while(tempNode->next != NULL){
            tempNode = tempNode->next;
            free(tempNode->prev);

            printf("deleting %c : %d \n", tempNode->character, tempNode->frequency);
         }

         free(tempNode);
}
