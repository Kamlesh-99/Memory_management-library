
#include "memlab.h"



void* ptr;

void*Cptr;
pthread_mutex_t buffer_lock;
void* fptr;

//void *value_val;




struct Stack* stack;
struct Stack* stack2;

// function to create a stack of given capacity. It initializes size of
// stack as 0
void createStack(unsigned capacity)
{  printf("createStack  called  :  stack1 is created\n");
    stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (snode*)malloc(stack->capacity * sizeof(snode));

}

// Stack is full when top is equal to the last index
int isFull()
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty()
{
    return stack->top == -1;
}

// Function to add an item to stack.  It increases top by 1
void push( snode item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;

}

// Function to remove an item from stack.  It decreases top by 1
snode pop()
{
    return stack->array[stack->top--];
}

void createStack2(unsigned capacity)
{   printf("createStack2  called  :  stack2 is created\n");
    stack2 = (struct Stack*)malloc(sizeof(struct Stack));
    stack2->capacity = capacity;
    stack2->top = -1;
    stack2->array = (snode*)malloc(stack2->capacity * sizeof(snode));

}

// Stack is full when top is equal to the last index
int isFull2()
{
    return stack2->top == stack2->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty2()
{
    return stack2->top == -1;
}

// Function to add an item to stack.  It increases top by 1
void push2( snode item)
{
    if (isFull(stack2))
        return;
    stack2->array[++stack2->top] = item;

}

// Function to remove an item from stack.  It decreases top by 1
snode pop2()
{
    return stack2->array[stack2->top--];
}













Queue*Q;

void* create(int size)
{
  Q->capacity = size;
  Q->front = -1;
  Q->rear = -1;
  Q->count = 0;


}

// Utility function to dequeue the front element
void dequeue(Queue* Q) {
  // check for queue underflow
  if (Q->front == -1)
    {
        printf("\nQueue is Empty");
       return;
    }


    if (Q->front == Q->rear)
    {
        Q->front = -1;
        Q->rear = -1;
    }
    else if (Q->front == Q->capacity-1)
        Q->front = 0;
    else
        Q->front++;
        Q->count--;


}

// Utility function to add an item to the queue
void insert(Queue* Q,void* value) {
  if ((Q->front == 0 && Q->rear == Q->capacity-1) ||
            (Q->rear == (Q->front-1)%(Q->capacity-1)))
    {
        printf("\nQueue is Full");
        return;
    }

    else if (Q->front == -1) /* Insert First Element */
    {
        Q->front = Q->rear = 0;
        Q->arr[Q->rear] = value;
    }

    else if (Q->rear == Q->capacity-1 && Q->front != 0)
    {
        Q->rear = 0;
        Q->arr[Q->rear] = value;
    }

    else
    {
        Q->rear++;
        Q->arr[Q->rear] = value;
    }
    Q->count++;
}



// Utility function to return the front element of the queue
void* peek1(Queue* Q) {
  if (Q->count==0) {

    exit(EXIT_FAILURE);
  }
  return (Q->arr[Q->front]);
}





void append(struct Node** head_ref, void* new_data,struct Node*ptr1,int type,char arr[],int id)
{
    /* 1. allocate node */
    struct Node* new_node = ptr1;

    struct Node* last = *head_ref; /* used in step 5*/

    /* 2. put in the data  */

    new_node->pointer = new_data;
    new_node->type=type;
    new_node->id=id;
    strcpy(new_node->arr,arr);

    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new
          node as head */
          //printf("Symbol table updated/added\n");
    if (*head_ref == ptr1||(*head_ref==NULL)) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prev = last;

    return;
}

void deleteNode(struct Node** head_ref, struct Node* del)
{
    /* base case */
    if (*head_ref == NULL || del == NULL)
        return;

    /* If node to be deleted is head node */
    if (*head_ref == del)
        *head_ref = del->next;

    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;

    /* Change prev only if node to be deleted is NOT the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;
        
        printf("Symbol table updated/deleted\n");

    /* Finally, free the memory occupied by del*/

    return;
}

struct Node* traversal(struct Node* head1,char name[],int type,int id)
{  
   pthread_mutex_lock(&buffer_lock);
   //printf("Traversal function called\n");
    struct Node* head=head1;


    while((head!=NULL))
    {
        if((head->type==type)&&(strcmp(name,head->arr)==0)&&(id==head->id))
        {   pthread_mutex_unlock(&buffer_lock);
            return head;
            
            }



        head++;
    }
    pthread_mutex_unlock(&buffer_lock);
    return NULL;
};

node*CN;

node*N;

void gc_initialize();

void compaction(char name[],int val,int id)
{    
     node*head1=N;
     void* temptr=ptr;
     
  
     pthread_mutex_lock(&buffer_lock);
 
     while(head1!=NULL)
     {    
         if(head1->type==3)
         {
             char value=*((char*)head1->pointer);
             head1->pointer=temptr;
              *((char*) head1->pointer)=value;



         }
         else
         {      int value=*((int*)head1->pointer);
             head1->pointer=temptr;
              *((int*) head1->pointer)=value;


         }
         head1=head1->next;
         temptr+=4;
         


     }
     Cptr=temptr;
     pthread_mutex_unlock(&buffer_lock);
     printf("Compaction done \n");

}

void createMem(int m)
{
    
    ptr=malloc(m);
    Cptr=ptr;
    fptr=ptr+m;
    Q=malloc(sizeof(Queue));
    N=malloc(500000*sizeof(node));
    createStack(200000);
    //create(500000);
    createStack2(200000);
    CN=N;
    //value_val=malloc(sizeof(int));
    //*((int*)value_val)=0;
    gc_initialize();
    //long long int value=500000*sizeof(node)+sizeof(Queue);
    printf("Memory allocated for user : %d bytes\n",m);
    printf("Memory allocated for bookkeeping\n");
    //printf("Memory allocated for bookkeeping: %lld bytes\n",value);
    
    
   




}


void createVar1(char name[],int val,int id)
{ //printf("create_var\n");   
pthread_mutex_lock(&buffer_lock);
if(Cptr>fptr)
printf("No more space\n");
else{ 
    if(val==1)
    {
       

        append(&N,Cptr,CN,1,name,id);
        snode sss;
        sss.id=id;
        sss.val=val;
        strcpy(sss.arr,name);
        push(sss);
        CN++;
        Cptr+=4;




    




    }
    else if (val==2)
    {
        
        append(&N,Cptr,CN,2,name,id);
        snode sss;
        sss.id=id;
        sss.val=val;
        strcpy(sss.arr,name);
        push(sss);
        CN++;
        Cptr+=4;




    }


    
    else if (val==3)
    {
       
        append(&N,Cptr,CN,3,name,id);
        snode sss;
        sss.id=id;
        sss.val=val;
        strcpy(sss.arr,name);
        push(sss);
        CN++;
        Cptr+=4;




    

    }
    else if (val==4)
    {
       
        append(&N,Cptr,CN,4,name,id);
        snode sss;
        sss.id=id;
        sss.val=val;
        strcpy(sss.arr,name);
        push(sss);
        CN++;
        Cptr+=4;




    

    }}//printf("create)var1\n");
    pthread_mutex_unlock(&buffer_lock);
    //printf("create)var2\n");
    



}

void createVar(char name[],int val,int id)
{ //printf("create_var\n");   
pthread_mutex_lock(&buffer_lock);
printf("createVar function called\n");
if(Cptr>fptr)
printf("No more space\n");
else
{
    if(val==1)
    {
       
        append(&N,Cptr,CN,1,name,id);
        printf("Symbol table updated/added\n");
        snode sss;
        sss.id=id;
        sss.val=val;
        strcpy(sss.arr,name);
        push(sss);
        printf("pushed in Stack\n");
        CN++;
        Cptr+=4;
        printf("Accesing 4 bytes of data every time for word alignment\n");




    




    }
    else if (val==2)
    {
        
        append(&N,Cptr,CN,2,name,id);
         printf("Symbol table updated/added\n");
        snode sss;
        sss.id=id;
        sss.val=val;
        strcpy(sss.arr,name);
        push(sss);
        printf("pushed in Stack\n");
        CN++;
        Cptr+=4;
        printf("Accesing 4 bytes of data every time for word alignment\n");




    


    }
    else if (val==3)
    {
        
        append(&N,Cptr,CN,3,name,id);
         printf("Symbol table updated/added\n");
        snode sss;
        sss.id=id;
        sss.val=val;
        strcpy(sss.arr,name);
        push(sss);
        printf("pushed in Stack\n");
        CN++;
        Cptr+=4;
        printf("Accesing 4 bytes of data every time for word alignment\n");




    

    }
    else if (val==4)
    {
        
        append(&N,Cptr,CN,4,name,id);
         printf("Symbol table updated/added\n");
        snode sss;
        sss.id=id;
        sss.val=val;
        strcpy(sss.arr,name);
        push(sss);
        printf("pushed in Stack\n");
        CN++;
        Cptr+=4;
        printf("Accesing 4 bytes of data every time for word alignment\n");




    

    }//printf("create)var1\n");
    printf("Variable created with name %s data type %d\n",name,val);
    }
    pthread_mutex_unlock(&buffer_lock);
    
    



}



void assignVar(char name[],int val,int value,char c,int id)
{   //pthread_mutex_lock(&buffer_lock);
      printf("assignVar function called\n");
      printf("Accesing 4 bytes of data every time for word alignment\n");
    node*head1=N;
    if(val==1)
    {   
        struct Node* nn=traversal(head1,name,val,id);
        void* to_assn_ptr=nn->pointer;
        *((int*) nn->pointer)=value;
        
        printf("Value assigned %d \n",value);



    }
    else if (val==2)
    {
        struct Node* nn=traversal(head1,name,val,id);
        void* to_assn_ptr=nn->pointer;
        if(value<(1<<24))
        {
        *((int*) nn->pointer)=value;
         printf("Value assigned %d \n",value);
        }
        else
        printf("Wrong value for medium int");

    }
    else if (val==3)
    {
        struct Node* nn=traversal(head1,name,val,id);

        *((char*) nn->pointer)=c;
         printf("Value assigned %c \n",c);

    }
    else if (val==4)
    {
        struct Node* nn=traversal(head1,name,val,id);
        void* to_assn_ptr=nn->pointer;
        if((value==0)||(value==1))
        {
        *((int*) nn->pointer)=value;
         printf("Value assigned %d \n",value);
        }
         else
        printf("Wrong value for boolean");

    }
    
    //pthread_mutex_unlock(&buffer_lock);



}

void assignVar1(char name[],int val,int value,char c,int id)
{   //pthread_mutex_lock(&buffer_lock);
      //printf("createVar function called\n");
    node*head1=N;
    if(val==1)
    {   
        struct Node* nn=traversal(head1,name,val,id);
        void* to_assn_ptr=nn->pointer;
        *((int*) nn->pointer)=value;



    }
    else if (val==2)
    {
        struct Node* nn=traversal(head1,name,val,id);
        void* to_assn_ptr=nn->pointer;
        if(value<(1<<24))
        *((int*) nn->pointer)=value;
        else
        printf("Wrong value for medium int");

    }
    else if (val==3)
    {
        struct Node* nn=traversal(head1,name,val,id);

        *((char*) nn->pointer)=c;

    }
    else if (val==4)
    {
        struct Node* nn=traversal(head1,name,val,id);
        void* to_assn_ptr=nn->pointer;
        if((value==0)||(value==1))
        *((int*) nn->pointer)=value;
         else
        printf("Wrong value for boolean");

    }
    //pthread_mutex_unlock(&buffer_lock);



}

void* getPr(char name[],int val,int id)
{   //pthread_mutex_lock(&buffer_lock);
    node* head1=N;
    if(val==1)
    {
        struct Node* nn=traversal(head1,name,val,id);
        return nn->pointer;



    }
    else if (val==2)
    {
        struct Node* nn=traversal(head1,name,val,id);
        return nn->pointer;

    }
    else if (val==3)
    {
        struct Node* nn=traversal(head1,name,val,id);
        return nn->pointer;

    }
    else if (val==4)
    {
        struct Node* nn=traversal(head1,name,val,id);
        return nn->pointer;
    }
   // pthread_mutex_unlock(&buffer_lock);



}
void deletevar(char name[],int val,int id)
{   
    printf("delete_var\n");
    pthread_mutex_lock(&buffer_lock);
    node*head1=N;
    if(val==1)
    {    pthread_mutex_unlock(&buffer_lock);
        struct Node* nn=traversal(head1,name,val,id);
        pthread_mutex_lock(&buffer_lock);
        void* to_assn_ptr=nn->pointer;
        pthread_mutex_unlock(&buffer_lock);
        deleteNode(&head1,nn);
        compaction(name,val,id);
        pthread_mutex_lock(&buffer_lock);
       


    }
    else if (val==2)
    {
       pthread_mutex_unlock(&buffer_lock);
        struct Node* nn=traversal(head1,name,val,id);
        pthread_mutex_lock(&buffer_lock);
        void* to_assn_ptr=nn->pointer;
        pthread_mutex_unlock(&buffer_lock);
        deleteNode(&head1,nn);
        compaction(name,val,id);
        pthread_mutex_lock(&buffer_lock);
    }
    else if (val==3)
    {
       pthread_mutex_unlock(&buffer_lock);
        struct Node* nn=traversal(head1,name,val,id);
        pthread_mutex_lock(&buffer_lock);
        void* to_assn_ptr=nn->pointer;
        pthread_mutex_unlock(&buffer_lock);
        deleteNode(&head1,nn);
        compaction(name,val,id);
        pthread_mutex_lock(&buffer_lock);
    }
    else if (val==4)
    {
        pthread_mutex_unlock(&buffer_lock);
        struct Node* nn=traversal(head1,name,val,id);
        pthread_mutex_lock(&buffer_lock);
        void* to_assn_ptr=nn->pointer;
        pthread_mutex_unlock(&buffer_lock);
        deleteNode(&head1,nn);
       compaction(name,val,id);
        pthread_mutex_lock(&buffer_lock);
    }
    pthread_mutex_unlock(&buffer_lock);
   
  



}
void concat(char s1[], char s2[])
  {

 //pthread_mutex_lock(&buffer_lock);
  int length, j;
  length = 0;

  while (s1[length] != '\0') {
    length++;
  }

  j=0;
  while(s2[j]!='\0')
  {
  s1[length]=s2[j];
  length++;
  j++;

  }
  //pthread_mutex_unlock(&buffer_lock);



  }

void createArr(char name[],int arsize,int type,int id)
{  
 pthread_mutex_lock(&buffer_lock);
  printf("CreateArr called  \n");
  printf("Accesing 4 bytes of data every time for word alignment\n");
    for(int i=0;i<arsize;i++)
    {    char snum[10]={};
        sprintf(snum, "%d", i);
        char final_name[30];
        for(int i=0;i<30;i++)
            final_name[i]='\0';
        concat(final_name,name);
        concat(final_name,snum);
        pthread_mutex_unlock(&buffer_lock);
        createVar1(final_name,type,id);
        pthread_mutex_lock(&buffer_lock);
    }
    printf("Array created with name %s data type  %d and size %d\n",name,type,arsize);
    printf("Symbol table updated/added %d elements\n",arsize);
    printf("Pushed %d elements into stack1\n",arsize);
    pthread_mutex_unlock(&buffer_lock);
    
}

void assignArr(char name[],int arsize,int type,int value,char c,int id)
{  
pthread_mutex_lock(&buffer_lock);
printf("assignArr called  \n");
printf("Accesing 4 bytes of data every time for word alignment\n");
    for(int i=0;i<arsize;i++)
    {    char snum[10]={};
        sprintf(snum, "%d", i);
        char final_name[30];
        for(int i=0;i<30;i++)
            final_name[i]='\0';
        concat(final_name,name);
        concat(final_name,snum);
        pthread_mutex_unlock(&buffer_lock);
        assignVar1(final_name,type,value,c,id);
        pthread_mutex_lock(&buffer_lock);
    }
    printf("Array of name %s data type  %d and size %d assigned\n",name,type,arsize);
    printf("Symbol table updated for %d elements\n",arsize);
   
    pthread_mutex_unlock(&buffer_lock);
}
void assignArrindex(char name[],int index,int type,int value,char c,int id)
{        
        pthread_mutex_lock(&buffer_lock);
        printf("assignArrindex called  \n");
        printf("Accesing 4 bytes of data every time for word alignment\n");
        char snum[10]={};
        sprintf(snum, "%d", index);
        char final_name[30];
        for(int i=0;i<30;i++)
            final_name[i]='\0';
        concat(final_name,name);
        concat(final_name,snum);
        pthread_mutex_unlock(&buffer_lock);
        assignVar(final_name,type,value,c,id);
        

}
int getvalueint(char name[],int val,int id)
{   //pthread_mutex_lock(&buffer_lock);
    void*pr=getPr(name,val,id);
    int value=*((int*)pr);
    //pthread_mutex_unlock(&buffer_lock);
    if(val==1)
    return value;
    else if(val==2)
    {
        int ans=0;
        for(int i=0;i<24;i++)
        {
            if(value&(1<<i))
                ans+=1<<i;
        }
        return ans;
    }
    else if(val==4)
    {
        if((1<<0)&value)
            return 1;
        else
            return 0;
    }

}
int getvalueintarr(char name[],int index,int val,int id)

{         pthread_mutex_lock(&buffer_lock);
         char snum[10]={};
        sprintf(snum, "%d", index);
        char final_name[30];
        for(int i=0;i<30;i++)
            final_name[i]='\0';
        concat(final_name,name);
        concat(final_name,snum);
        pthread_mutex_unlock(&buffer_lock);
    
    int value=getvalueint(final_name,val,id);
  
    return value;
}
char getvaluechar(char name[],int val,int id)
{    //pthread_mutex_lock(&buffer_lock);
    void*pr=getPr(name,val,id);
    char value=*((char*)pr);
    //pthread_mutex_unlock(&buffer_lock);
    return value;
}
char getvaluechararr(char name[],int index,int val,int id)
{   pthread_mutex_lock(&buffer_lock);
         char snum[10]={};
        sprintf(snum, "%d", index);
        char final_name[30];
        for(int i=0;i<30;i++)
            final_name[i]='\0';
        concat(final_name,name);
        concat(final_name,snum);
        pthread_mutex_unlock(&buffer_lock);
    //printf("2");
    char value=getvaluechar(final_name,val,id);
  
    return value;
}


void deletearray(char name[],int arraysize,int val,int id)
{  pthread_mutex_lock(&buffer_lock);
    for(int i=0;i<arraysize;i++)
    {
        char snum[10]={};
        sprintf(snum, "%d", i);
        char final_name[30];
        for(int i=0;i<30;i++)
            final_name[i]='\0';
        concat(final_name,name);
        concat(final_name,snum);
         pthread_mutex_unlock(&buffer_lock);
        deletevar(final_name,val,id);
        pthread_mutex_lock(&buffer_lock);
    }
    pthread_mutex_unlock(&buffer_lock);

}

void freeElem(int id)
{  
    int state=1;
   pthread_mutex_lock(&buffer_lock);
   printf("freeElem called\n");
    while(!isEmpty()&&state)
    {
        snode item=pop();
        if(item.id==id)
        {
            push2(item);

        }
        else
        {
            state=0;
            push(item);
        }

    }
    printf("Stack1 and Stack2 updated\n");
    printf("Data variables and array deleted  from stack1\n");
    pthread_mutex_unlock(&buffer_lock);
    

    //*((int*)value_val)=1;
     
    
}



/*void* gc_run(void*arg)
{
    while(1)
    {

    pthread_mutex_lock(&buffer_lock);
    while(!isEmpty2())
    {
        snode item=pop2();
        deletevar(item.arr,item.val,item.id);


    }
    pthread_mutex_unlock(&buffer_lock);
    //usleep(5*1000);
    }

}*/

void* gc_run(void*arg)
{printf("gc_run called\n");
 //printf("gc_run\n");
 while(1)
 {  
 //printf("gc_run2\n");
 sleep(1);
 pthread_mutex_lock(&buffer_lock);
    snode present;
    snode next;
    int state=1;
    int i=0;
    int id;
    int c=0;
    double time_spent = 0.0;
    clock_t begin;
    
    
   
    while(!isEmpty2()&&state)
    {  
    
    if(c==0)
    {   
      begin = clock();
     }
    
        c++;
        snode item=pop2();
        if(i==0)
        id=item.id;

        i++;
        if(item.id==id)
        {
             if(i==1)
        {
            present=item;

        }
        next=item;
        //deletevar(item.arr,item.val,item.id);


        }
        else
        {
            state=0;
            push2(item);
        }

    }
    if(c)
    {
     clock_t end = clock();
     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The running  time for garbage collection is %f seconds\n", time_spent);
    
    
    printf("garbage collection\n");
    pthread_mutex_unlock(&buffer_lock);
    deleteelements(present,next);
    pthread_mutex_lock(&buffer_lock);
    
    
    }
     pthread_mutex_unlock(&buffer_lock);
    }
    
}




void gc_initialize()
{      printf("gc_initialize called\n");
        pthread_t ptid;

        // Creating a new thread
        pthread_create(&ptid, NULL, &gc_run,NULL);



}
void deleteelements(snode present,snode next)
{   pthread_mutex_lock(&buffer_lock); 
    printf("deleteelements function called\n");  
    node* head1=N;
    pthread_mutex_unlock(&buffer_lock);
    node*pr=traversal(head1,present.arr,present.val,present.id);
    node*nn=traversal(head1,next.arr,next.val,next.id);
    pthread_mutex_lock(&buffer_lock);
    node*temp=pr->next;
    if(pr!=nn)
    {


   
    pr->next=nn;
    nn->prev=pr;
    pthread_mutex_unlock(&buffer_lock);
    //deletevar(pr->arr,pr->type,pr->id);
    //deletevar(nn->arr,nn->type,nn->id);
    
    deleteNode(&N,nn);
    compaction("a",1,1);
    deleteNode(&N,pr);
    compaction("a",1,1);
    pthread_mutex_lock(&buffer_lock);


    }
    else
    {   pthread_mutex_unlock(&buffer_lock);
        deleteNode(&N,nn);
        compaction("a",1,1);
        pthread_mutex_lock(&buffer_lock);

    }
     pthread_mutex_unlock(&buffer_lock);

}






