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

#include "codeBook.h"

typedef struct htree {
    Node * root;
} THTree;


Node * createTree(Queue **leafQueue);

void printTree(Node *theRoot);

void iterateThroughEncodings(Node *root, int height, int *code, CodeBook **theBook);

void deleteTree(Node *root);

#endif
