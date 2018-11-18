*
 * @file nodeQueue.c
 * @author Sophia Deak
 * @date Nov 17th 2018
 * @brief queue for nodes
 */

#ifndef NODEQUEUE_H
#define NODEQUEUE_H

typedef struct node Node;
typedef struct queue Queue;


//nodes are the same for queue and tree
struct node {
    char character;
    int frequency;

    Node * left;
    Node * middle;
    Node * right;

    Node *prev;
    Node *next;
};


struct queue {
    Node *head;
    Node *tail;
};


typedef struct pair {
   char character;
   int frequency;
}


Node * createNode(char c, int f);

Node *copyNode(Node *original);

Queue *initializeEmptyQueue ();

Queue *fillQueueFromArray(Pair *array, Queue *theQueue, size_t length);

void  enqueue(Queue *theQueue, Node *theNode);

Node *dequeue(Queue *theQueue);


void printQueue(Queue *theQueue);
void deleteQueue(Queue *theQueue);


#endif

