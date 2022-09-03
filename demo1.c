#include "memlab.h"


void array_create1(int id,int val)
{
int sum=0;
createArr("a",50000,1,id);
assignArr("a",50000,1,val,'c',id);



 
  for(int i=0;i<50000;i++)
  {
      sum+=getvalueintarr("a",i,1,id);

  }
  printf("%d\n",sum);

 freeElem(id);
 
}


void array_create2(int id,int val)
{
int sum=0;
createArr("a",50000,2,id);
assignArr("a",50000,2,val,'c',id);
  for(int i=0;i<50000;i++)
  {
      sum+=getvalueintarr("a",i,2,id);

  }
  printf("%d\n",sum);
 freeElem(id);
 printf("done\n");
}

void array_create4(int id,int val)
{
int sum=0;
createArr("a",50000,4,id);
assignArr("a",50000,4,val,'c',id);
  for(int i=0;i<50000;i++)
  {
      sum+=getvalueintarr("a",i,4,id);

  }
  printf("%d\n",sum);
 freeElem(id);
 printf("done\n");
}


void array_create3(int id,char c)
{
int sum=0;
createArr("a",50000,3,id);
assignArr("a",50000,3,1,c,id);
  for(int i=0;i<50000;i++)
  {   char cc=getvaluechararr("a",i,3,id);
      printf("%c",cc);

  }
 // printf("%d\n",sum);
 freeElem(id);
 printf("done\n");
}


/*void array_create(int id)
{
int sum=0;
createArr("a",50000,1,id);
assignArr("a",50000,1,1,'c',id);
  for(int i=0;i<50000;i++)
  {
      sum+=getvalueintarr("a",i,1,id);

  }
  printf("%d\n",sum);
 clear_stack(id);
 printf("done\n");
}

void array_create(int id)
{
int sum=0;
createArr("a",50000,1,id);
assignArr("a",50000,1,1,'c',id);
  for(int i=0;i<50000;i++)
  {
      sum+=getvalueintarr("a",i,1,id);

  }
  printf("%d\n",sum);
 clear_stack(id);
 printf("done\n");
}

void array_create(int id)
{
int sum=0;
createArr("a",50000,1,id);
assignArr("a",50000,1,1,'c',id);
  for(int i=0;i<50000;i++)
  {
      sum+=getvalueintarr("a",i,1,id);

  }
  printf("%d\n",sum);
 clear_stack(id);
 printf("done\n");
}

void array_create(int id)
{
int sum=0;
createArr("a",50000,1,id);
assignArr("a",50000,1,1,'c',id);
  for(int i=0;i<50000;i++)
  {
      sum+=getvalueintarr("a",i,1,id);

  }
  printf("%d\n",sum);
 clear_stack(id);
 printf("done\n");
}*/




int main()
{
      createMem(1000*250*1024);
   
    
    
      
      array_create1(1,2);
      array_create1(2,3);
      array_create4(3,0);      
      array_create4(4,1);
      array_create4(5,1);
      array_create1(6,6);
      array_create2(7,5);
      array_create2(8,2);
      array_create3(9,'c');
      array_create3(10,'e');
      
      


	return 0;
}
