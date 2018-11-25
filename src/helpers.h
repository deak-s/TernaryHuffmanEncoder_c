/*
 * @file helpers.h
 * @author Sophia Deak
 * @date Nov 17th 2018
 * @brief helper functions for creation of ternary huffman tree
 */


#include "nodeQueue.h"

#ifndef HELPERS_H
#define HELPERS_H

void assignLowestNodes(Node **A, Node **B, Node **C,  Queue *leafQueue, Queue *middleQueue);


Node *createMiddleNode(Node *A, Node *B, Node *C);

int *leftShift(int *input, int length);
#endif 
