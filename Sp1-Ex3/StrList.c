#pragma once

#include "StrList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char* data;
    struct Node* next;
} Node;

typedef struct _StrList{
    Node* head;
    size_t size;
} StrList;

/*
 *allocate new Node
 *consider data != NULL
 */
Node* Node_alloc(const char* data, Node* next){
    Node* newNode = (Node*) malloc(sizeof(Node));

    if (newNode != NULL){               // make sure malloc didn't fail
        newNode->data = strdup(data);
        if(newNode->data==NULL){        // if strdup failed
            free(newNode);          
            return NULL;
        }
        newNode->next = next;

        return newNode;
    }
    else{                               // if malloc failed
        return NULL;
    }
}

void Node_free(Node* node){
    if(node==NULL){return;}

    free(node->data);
    free(node);
}

/*
 *Allocates a new empty StrList
 */
StrList* StrList_alloc(){
    
    StrList* list = (StrList*) malloc(sizeof(StrList));
    
    if(list!=NULL){
        list->head = NULL;
        list->size = 0;

        return list;
    }
    else{
        return NULL;
    }
}

void StrList_free(StrList* list){
    if(list==NULL){return;}

    Node* head = list->head;
    Node* current;

    while(head){
       current = head;
       head = head->next;
       Node_free(current);
    }

    free(list);
}

size_t StrList_size(const StrList* list){
    return list->size;
}

// void StrList_insertFirst(StrList* list, const char* data){
//     Node* newNode = Node_alloc(data, NULL);  // create the new Node
//     if(newNode == NULL){                     // if allocate failed
//         printf("out of memory\n");
//         return;
//     }   

//     if(list->head==NULL){                    // case this list is empty
//         list->head = newNode;
//         return;
//     }
    
//     newNode->next = list->head;
//     list->head = newNode;
//     list->size++;
// }

void StrList_insertLast(StrList* list, const char* data){
   Node* newNode = Node_alloc(data, NULL);  // create the new Node
   if(newNode == NULL){                     // if allocate failed
    printf("out of memory\n");
    return;
    }

   if(list->head==NULL){                    // case this list is empty
        list->head = newNode;
    }
   else{
       Node* p1 = list->head;
       while (p1->next){
           p1 = p1->next;
       }
       p1->next = newNode;                  // insert the element at the end of the list
    }

    list->size ++;
}

void StrList_insertAt(StrList* list, const char* data, int index){
    if(index < 0 || index > list->size){return;}       // if the input is elegal

    int counter = 0;
    Node* newNode = Node_alloc(data, NULL);
    if(newNode == NULL){return;}

    if(index==0){
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
        return;
    }

    Node* p1 = list->head;
    while(counter < index-1){             // get to the node before the given index
        p1 = p1->next;
        counter++;
    }

    newNode->next = p1->next;
    p1->next = newNode;

    list->size++;
}

char* StrList_firstData(const StrList* list){
    if(list == NULL || list->head == NULL) {return NULL;}

    return list->head->data;
}

void StrList_print(const StrList* list){
    if(list == NULL){
        // printf("this list is undefined\n");
        return;
    }
    if(list->head==NULL){
        // printf("this list is empty\n");
        return;
    }

    Node* p1 = list->head;

    while (p1){
        printf("%s ", p1->data);
        p1 = p1->next;
    }
    printf("\n");
}

void StrList_printAt(const StrList* list,int index){
    if(list == NULL){
        // printf("this list is undefined\n");
    }
    if(list->head==NULL){
        // printf("this list is empty\n");
    }
    if(index < 0 || index > list->size){
        // printf("this index is elegal\n");
    }
    
    Node* p1 = list->head;
    for(int i=0; i<index; i++){
        p1 = p1->next;
    }
    printf("%s\n", p1->data);
}

int StrList_printLen(const StrList* list){
    if(list == NULL){return -1;}
    if(list->head == NULL){return 0;}

    int len = 0;
    Node* p1 = list->head;
    
    while(p1){
        len += strlen(p1->data);
        p1 = p1->next;
    }

    return len;
}

int StrList_count(StrList* list, const char* data){
    if(list == NULL){return -1;}
    if(list->head == NULL){return 0;}

    int count = 0;
    Node* p1 = list->head;
    while(p1){
        if(!strcmp(data, p1->data)){
           count++; 
        }
        p1 = p1->next;
    }

    return count;
}

void StrList_remove(StrList* list, const char* data){
    if(list == NULL || list->head == NULL){return;}

    Node *p1, *p2;

    while(!strcmp(data, list->head->data)){
        p2 = list->head;
        list->head = list->head->next;
        Node_free(p2);
        list->size--;
        return;
    }

    p1 = list->head;
    while(p1->next){
        while(!strcmp(data, p1->next->data)){
            p2 = p1->next;
            p1->next = p1->next->next;
            Node_free(p2);
            list->size--;
        }
        p1 = p1->next;
    }
}

void StrList_removeAt(StrList* list, int index){
    if(list == NULL){
        // printf("this list is undefined\n");
    }
    if(list->head==NULL){
        // printf("this list is empty\n");
    }
    if(index < 0 || index > list->size){
        // printf("this index is elegal\n");
    }

    if(index==0){
        list->head = list->head->next;
        list->size--;
        return;
    }

    Node* p1 = list->head;
    for(int i=0; i<index-1; i++){
        p1 = p1->next;
    }

    Node* p2 = p1->next;
    p1->next = p1->next->next;
    Node_free(p2);
    list->size--;
}

int StrList_isEqual(const StrList* list1, const StrList* list2){
    if(list1 == NULL || list2 == NULL){
        // printf("one of the lists (maybe both) is undefined\n");
        return -1;
    }

    if(list1->size != list2->size){
        return 0;
    }

    Node *p1, *p2;
    p1 = list1->head;
    p2 = list2->head;

    while(p1){
        if(strcmp(p1->data, p2->data) != 0){        // strcmp returns 0 if the strings are equal
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return 1;
}

StrList* StrList_clone(const StrList* list){
    if(list == NULL){
        // printf("this list is undefined\n");
        return NULL;
    }
    if(list->head == NULL){
        return StrList_alloc();
    }

    StrList* newList = StrList_alloc();
    if(newList==NULL){
        printf("out of memory\n");
        return NULL;
    }
    Node* p1 = list->head;

    while(p1){
        char* data = strdup(p1->data);
        if(data==NULL){
            printf("out of memory\n");
            StrList_free(newList);
            return NULL;
        }
        StrList_insertLast(newList, data);
        p1 = p1->next;
    }

    return newList;
}

void StrList_reverse(StrList* list){
    if(list->size < 2){return;}

    Node* prev = NULL;
    Node* next = NULL;
    Node* cuurent = list->head;

    while(cuurent!=NULL){
        next = cuurent->next;
        cuurent->next = prev;
        prev = cuurent;
        cuurent = next;
    }

    list->head = prev;
}

int compare(const void* a, const void* b){
    return strcmp(*(char**)a, *(char**)b);
}

void StrList_sort(StrList* list){
    if(list->size < 2){return;}

    Node* current = list->head;
    size_t size = list->size;
    char* myArr[size];

    for(int i=0; i<size; i++){
        // strcpy(myArr[i], current->data);
        myArr[i] = current->data;
        current = current->next;
    }

    qsort(myArr, size, sizeof(*myArr), compare);

    current = list->head;
    for(int i=0; i<size; i++){
        current->data = myArr[i];
        current = current->next;
    }
}

int StrList_isSorted(StrList* list){
    if(list->size < 2){return 1;}

    Node* p1 = list->head;
    while(p1->next){
        if(strcmp(p1->data, p1->next->data) > 0){
            return 0;
        }
        p1 = p1->next;
    }

    return 1;
}