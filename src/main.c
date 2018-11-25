/*
 * @file main.c
 * @author Sophia Deak
 * @date Nov 18th 2018
 * @brief main function for example for ternary encoder
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nodeQueue.h"
#include "helpers.h"
#include "frequencyList.h"
#include "ternaryHuffmanTree.h"

//#include "codeBook.h"

int main(){


    char shortInput[] = "Lorem ipsum dolor sit amet, vim affert alterum ";

    size_t size= 127;
 FrequencyList *tList = initializeEmptyList(size);


 calculateFrequencies(shortInput, &tList);

 sortSmallToLarge(&tList);

int x =  countUnusedChars(&tList);

 Queue *lQueue = initializeEmptyQueue();

 fillQueueFromArray(&tList->pairList[x], lQueue, (tList->length - x));

 printf("printing lQueue\n");
 printQueue(lQueue);


Node *root = createTree(&lQueue);


printTree(root);

CodeBook *testCodeBook = initializeCodeBook();

int code[1] = {0};

printTree(root);
iterateThroughEncodings(root, 1, code, &testCodeBook);

printf("------finished encodings\n");

//printf("right most");
//printf(" %c: %d\n", root->right->right->right->character, root->right->right->right->frequency); 


//printf("root %c %d\n", root->character, root->frequency);

//printCodeSet(testCodeBook->head);
//printCodeBook(testCodeBook);



int tester[4] = {1, 1, 0, 2};

leftShift(tester, 4);

printf("\n\n");
deleteTree(root);

deleteCodeBook(testCodeBook);
//free(testCodeBook);

deleteQueue(lQueue);
free(lQueue);

free(tList->pairList);
free(tList);


return 0;
}
