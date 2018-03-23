#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


typedef struct que {
     int num;
	 	
	
 }element;
struct que *que = NULL;
int MAXSIZE=10; 
int front=0,rear=0;

element*  full(element *qu)
{
  	element *qu_1;
 int i=0;int reco; reco=MAXSIZE*2;
qu_1= (element*)realloc(qu,MAXSIZE*2*sizeof(element)) ;
if ( front>rear)
{   printf("判断成立");
 
	for(i=MAXSIZE-1;i>=MAXSIZE-front ;i--)    
{	qu[reco--].num =qu[i].num;
printf("---%d--",qu[reco].num);
}

front+=MAXSIZE;
}		  



MAXSIZE*=2; //MAX是全局变量
return qu_1;

}


element input(element *qu )
{   
	
	while (1)        
	{
		if( ( rear+1)%MAXSIZE ==front%MAXSIZE)  /////////////
	{   printf("队满加空间");
		 full(qu);
	}
		
		
		scanf("%d",&qu[rear].num );  //这里用数组的方式表达，所以不是指针，不能用->   如果用指针就是 （qu+top）->number
	  if(qu[rear].num==-2)
  	{   //rear=(rear+1)%MAXSIZE;  //-2的位子就为rear的位子，比有实际数值的往后一格
		return *qu; }

	   rear=(rear+1)%MAXSIZE;
	
	}      	 
}


element push(element *qu )   // 前进先出
{      if(front==rear)
{   printf("empty\n");
return *qu;
}        

front=  (front+1)%MAXSIZE;
printf("%d-",front);


}



  void printfall(element *qu )   // 前进先出
  {   int i=0;
  if(front==rear)
  {   printf("empty\n");
  return ;
  }        
  else if(front<rear )
  { printf("rear%d\n",rear);
  for(i=front;i<rear;i++  )
	 
	  printf(" %d ",qu[i].num);
  }            
  else
  {  printf(" 2");
  for(i=front;i<=MAXSIZE;i++)
	  printf(" %d",qu[i].num);

  for(i=0;i<rear;i++)
	  printf(" %d",qu[i].num);

  }



  }

 void print(element *qu)
 {  //  printf("1  ");  
	// int i=0;
   // for(;i<top;i++)  
	 printf("%d %d", front,rear); 
        
 
 }
 
 int main(void)
 {
 	que = (element*)malloc(sizeof(element) *MAXSIZE ); 	
 	input(que  );
	printf("\n\n");
	
	//push( que );push( que );push( que );push( que );push( que );push( que );push( que );
	//input(que  );

	printf("\n\n");
	print(que );
	printf("\n\n");
	 printfall(que);
		 printf("\n");

 }