/*
 * @file ternaryHuffmanTree.h
 * @author Sophia Deak
 * @date Nov 17th
 * @brief header file outlining wrapper functions for ternary huffman tree and codebook
 */

#ifndef TERNARYHUFFMANTREE_H
#define TERNARYHUFFMANTREE_H

#include "nodeQueue.h"
#include "helpers.h"


typedef struct htree {
    Node * root;
} THTree;


Node * createTree(Queue **leafQueue);

void grabEncoding(Node *root, int height, int *code);

void printTree(Node *theRoot);


#endif
