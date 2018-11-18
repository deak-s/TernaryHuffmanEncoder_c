/*
 * @file listfinalMain.c
 * @author Sophia Deak
 * @date Nov 9th 2018
 * @brief main running huffman encoder (no debugging text)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nodeQueue.h"
#include "helpers.h"
#include "frequencyList.h"
#include "ternaryHuffmanTree.h"


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
// printQueue(lQueue);


createTree(&lQueue);




	

	return 0;
}
