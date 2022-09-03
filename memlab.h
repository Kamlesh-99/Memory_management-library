#ifndef MEMLAB_H
#define MEMLAB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>

#define ss 50
#define max_size 500000

enum var{

user_int=1,

medium_int=2,

user_char=3,

boolean=4

};

typedef struct sn{
char arr[40];
int val;
int id;


}snode;

struct Stack {
    int top;
    unsigned capacity;
    snode* array;
};

typedef struct Queue {
  void* arr[max_size]; // array to store queue elements
  int capacity; // maximum capacity of the queue
  int front; // front points to the front element in the queue (if any)
  int rear; // rear points to the last element in the queue
  int count;
  }Queue;
  // current size of the queue
typedef struct Node {
    void* pointer;
    char arr[40];
    int id;
    int type;
    struct Node* next; // Pointer to next node in DLL
    struct Node* prev; // Pointer to previous node in DLL
}node
;
  
void createStack(unsigned capacity);
int isFull();
int isEmpty();
void push( snode item);
snode pop();
void createStack2(unsigned capacity);
int isFull2();
int isEmpty2();
void push2( snode item);
snode pop2();
void* create(int size);
void dequeue(Queue* Q) ;
void insert(Queue* Q,void* value);
void* peek1(Queue* Q);
void append(struct Node** head_ref, void* new_data,struct Node*ptr1,int type,char arr[],int id);
void deleteNode(struct Node** head_ref, struct Node* del);
struct Node* traversal(struct Node* head1,char name[],int type,int id);
void gc_initialize();
void createMem(int m);
void createVar(char name[],int val,int id);
void assignVar(char name[],int val,int value,char c,int id);
void* getPr(char name[],int val,int id);
void deletevar(char name[],int val,int id);
void concat(char s1[], char s2[]);
void createArr(char name[],int arsize,int type,int id);
void assignArr(char name[],int arsize,int type,int value,char c,int id);
void assignArrindex(char name[],int index,int type,int value,char c,int id);
int getvalueint(char name[],int val,int id);
int getvalueintarr(char name[],int index,int val,int id);
char getvaluechar(char name[],int val,int id);
void deletearray(char name[],int arraysize,int val,int id);
void freeElem(int id);
void* gc_run(void*arg);
void gc_initialize();
void compaction();
char getvaluechararr(char name[],int index,int val,int id);
void deleteelements(snode present,snode next);


void createVar1(char name[],int val,int id);
void deleteelementsarr(node* pr,node* nn);
void assignVar1(char name[],int val,int value,char c,int id);



















#endif
