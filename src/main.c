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

#include "canonicalCodeBook.h"

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

    int h = heightOfTree(root);

    CodeBook *testCodeBook = initializeCodeBook();

    int *code = (int *)calloc(h, sizeof(int));

    //printTree(root);
    printf("---------after tree print\n");
    iterateThroughEncodings(root, 1, code, &testCodeBook);

    printf("------finished encodings\n");


    //printf("right most");
    //printf(" %c: %d\n", root->right->right->right->character, root->right->right->right->frequency); 

    //printf("root %c %d\n", root->character, root->frequency);

    //printCodeSet(testCodeBook->head);
    //printCodeBook(testCodeBook);


    convertToCanonical(testCodeBook);



    printf("\n\n\n\n\n");
    deleteTree(root);

    deleteCodeBook(testCodeBook);
    //free(testCodeBook);
    free(code);

    deleteQueue(lQueue);
    free(lQueue);

    free(tList->pairList);
    free(tList);

    return 0;
}
