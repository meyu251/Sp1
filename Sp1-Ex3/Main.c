#pragma once

#include "StrList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char* getWord(){
    char* word = (char*)malloc(10*sizeof(char));
    if(word==NULL){
        printf("out of memory\n");
        return NULL;
    }
    int wordLen=10;
    char c;
    int j=0;
    c = getchar();

    if(j==0 && (c==' ' || c=='\n')){
        c = getchar();
    }

    do{
        if(j==wordLen-1){
            wordLen += 10;
            word = realloc(word, wordLen*sizeof(char));
            if(word==NULL){
                printf("out of memory\n");
                return NULL;
            }
        }
        word[j++] = c;
    }while((c = getchar())!=' ' && c!='\n');

    word[j]='\0';
    return word;
}

int main() {

    StrList* list = StrList_alloc();
    int choose;
    int index;
    char* word;

    while (1){

        if(scanf("%d",&choose) != 1){
            printf("Invalid input. Please enter a number\n");
            while (getchar() != '\n');      // clears the input buffer
            continue;
        }

        if(choose==0){
            StrList_free(list);
            break;
        }

        switch (choose){
          case 1:
            int numOfWords;

            // printf("Enter the number of words you want to write:\n");
            if(scanf("%d", &numOfWords) != 1){
                printf("invalid input for num of words\n");
                break;
            }
            // printf("Enter the words:\n");

            for (int i = 0; i < numOfWords; i++){
                word = getWord();
                if(word==NULL){
                    printf("something is wrong\n");
                    break;
                }
                StrList_insertLast(list, word);
                free(word);
            }
            break;

          case 2:
            // printf("enter the index:\n");
            if(scanf("%d", &index) != 1){
                printf("invalid input for index\n");
                // printf("press '2' to start this option again\n");
                break;
            }

            // printf("enter the word you want to write:\n");
            word = getWord();
            if(word==NULL){
                printf("something is wrong\n");
                break;
            }
            StrList_insertAt(list, word, index);
            free(word);
            break;

          case 3:
            StrList_print(list);
            break;
            
          case 4:
            printf("%zu\n", StrList_size(list));
            break;

          case 5:
            // printf("enter the index:\n");
            if(scanf("%d", &index) != 1){
                printf("invalid input for index\n");
                // printf("press '5' to start this option again\n");
                break;
            }

            StrList_printAt(list, index);
            break;
          
          case 6:
            printf("%d\n", StrList_printLen(list));
            break;
          
          case 7:
            // printf("enter the word you want to count:\n");
            word = getWord();
            if(word==NULL){
                printf("something is wrong\n");
                break;
            }
            printf("%d\n", StrList_count(list, word));
            free(word);
            break;
          
          case 8:
            // printf("enter the word you want to remove:\n");
            word = getWord();
            if(word==NULL){
                printf("something is wrong\n");
                break;
            }
            StrList_remove(list, word);
            free(word);
            break;
          
          case 9:
            // printf("enter the index:\n");
            if(scanf("%d", &index) != 1){
                printf("invalid input for index\n");
                // printf("press '9' to start this option again\n");
                break;
            }

            StrList_removeAt(list, index);
            break;
          
          case 10:
            StrList_reverse(list);
            break;
          
          case 11:
            StrList_free(list);
            list = StrList_alloc();
            break;
          
          case 12:
            StrList_sort(list);
            break;
          
          case 13:
            printf(StrList_isSorted(list) ? "true\n" : "false\n");
            break;
          
          default:
            // printf("invalid number,\n");
            // printf("choose number between 0-13\n");
            break;
        }
    }

    return 0;
}