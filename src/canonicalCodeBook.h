/*
 * @file canonicalCodeBook.h
 * @author Sophia Deak
 * @date May 2nd 2019
 * @brief header file for functions relating to a canonical huffman ternary codebook 
 */

#ifndef CANONICALCODEBOOK_H
#define CANONICALCODEBOOK_H

typedef struct canonCodeBook CanonCodeBook;

struct canonCodeBook {

};

#include "codeBook.h"

int codeToInt(int *code, int length);


/**
 * @brief converts a linkedlist codebook into canonical associative array
 */
void *convertToCanonical(CodeBook *oldBook);



#endif
