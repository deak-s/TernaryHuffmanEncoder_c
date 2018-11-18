/*
 * @file codeBook.c
 * @author Sophia Deak
 * @date Nov 18th 2018
 * @brief implemtation of a codeBook data structure for ternary huffman tree
 */

#include <stdio.h>
#include <stdlib.h>

#include "codeBook.h"

CodeSet *createCodeSet(char character, int *code, int length){

	CodeSet *newCodeSet = (CodeSet *)malloc(sizeof(CodeSet));
	newCodeSet->character = character;
	newCodeSet->code = code;
	newCodeSet->length = length;

	return newCodeSet;
}

int compareCodeSets(CodeSet *A, CodeSet *B){

	//A > B = 1
	//A < B = -1
	//A = B = 0

	if(A->length > B->length){
		return 1;
	}

	else if(A->length < B->length){
		return -1;
	}

	else{
		if(A->character > B->character){
			return 1;
		}

		else if(A->character < B->character){
			return -1;
		}
		else{
			return 99;
		}
	}
	return 44;
}

CodeBook *initializeCodeBook(size_t bookSize){

	CodeBook *newBook = (CodeBook *)malloc(sizeof(CodeBook));

//	newBook->codeList = (CodeSet *)malloc(sizeof(CodeSet) * bookSize);

	newBook->head = NULL;
	newBook->length = bookSize;

	return newBook;
};



void addToCodeBook(CodeBook *theBook, char character, int *code, int length){

	CodeSet *newCodeSet = createCodeSet(character, code, length);


	if (theBook->head == NULL){
		theBook->head = newCodeSet;
		return;
	}

	CodeSet *tempSet = theBook->head;
	
	if(compareCodeSets(newCodeSet, tempSet) == -1){

		tempSet->prev = newCodeSet;
		newCodeSet->next = tempSet;
		theBook->head = newCodeSet;
		return;
	}

	while(tempSet != NULL){

		if(compareCodeSets(newCodeSet, tempSet) == -1){
			tempSet->prev->next = newCodeSet;
			newCodeSet->prev = tempSet->prev;
			newCodeSet->next = tempSet;
			tempSet->prev = newCodeSet;
		}

		else if(compareCodeSets(newCodeSet, tempSet) == 1 && tempSet->next == NULL){
		tempSet->next = newCodeSet;
		newCodeSet->prev = tempSet;
		return;
		}
	
		else{
			tempSet = tempSet->next;
		}

	}
}
