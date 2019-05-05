
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "codeBook.h"

#include "canonicalCodeBook.h"

int codeToInt(int *code, int length){

    int answer = 0;
    //i starts at end of code
    //for(int i = (length - 1); i >=0; i--){
    for(int i = 0; i < length; i++){

        printf("b4 answer %d\n", answer);

        answer *= 10;
        answer += code[i];

        printf("--code %d\n", code[i]);
        printf("--answer %d\n", answer);

    };

        printf("FINAL answer %d\n", answer);
        //printf("BIT answer %d\n", answer);

        //TODO implement trit array shifting

        return answer;
};


void *convertToCanonical(CodeBook *oldBook){

    if(oldBook->head == NULL){
        printf("book empty\n");
        return;
    }


    codeToInt(oldBook->head->code, oldBook->head->length);

    //set up for the l00p
    CodeSet *temp = oldBook->head;
    CodeSet *next;
    printCodeSet(temp);

    
    //l00p thru old codebook
    while(temp->next != NULL){
        temp = temp->next;
        printCodeSet(temp);

        //TODO: this should not be necessary
        //potential issue - 001 becomes 1
        int regularCode = codeToInt(temp->code, temp->length);

        //if first code in book
        if(temp == oldBook->head){


        }

    }

    void *a;

    return a;
};


