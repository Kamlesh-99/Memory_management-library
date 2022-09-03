#include "memlab.h"
int fibonaciProduct(int n)
{
    createMem(100000);

    createArr("f",n+2,1,1);
    assignArr("f",n+2,1,1,'c',1);



  assignArrindex("f",0,1,0,'c',1);



 //printf("f0 %d",getvalueintarr("f",0,1));
 //assignArrindex()
 assignArrindex("f",1,1,1,'c',1);
 //printf("%d",getvalueintarr("f",1,1));


  createVar("i",1,1);
  assignVar("i",1,2,'c',1);
  createVar("product",1,1);
  assignVar("product",1,1,'c',1);
 // printf("product");
  while(getvalueint("i",1,1)<=n)
  {  //assignArrindex()
      //int value=getvalueintarr("f",getvalueint("i",1,1)-1,1,1)+getvalueintarr("f",getvalueint("i",1,1)-2,1,1);
      //printf("value:%d\n",value);
      assignArrindex("f",getvalueint("i",1,1),1,getvalueintarr("f",getvalueint("i",1,1)-1,1,1)+getvalueintarr("f",getvalueint("i",1,1)-2,1,1),'c',1);
      assignVar("product",1,(getvalueint("product",1,1)*getvalueintarr("f",getvalueint("i",1,1),1,1)),'c',1);
      assignVar("i",1,1+getvalueint("i",1,1),'c',1);

      //printf("%d\n",getvalueint("product",1,1));

  }

  printf("product\n");
  printf("%d\n",getvalueint("product",1,1));
  freeElem(1);
  //printf("%d",isEmpty());


}

int main()
{
	int n;
	printf("Enter the number :");
	scanf("%d",&n);
	fibonaciProduct(n);
	return 0;
}
