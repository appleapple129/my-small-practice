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
{   printf("�жϳ���");
 
	for(i=MAXSIZE-1;i>=MAXSIZE-front ;i--)    
{	qu[reco--].num =qu[i].num;
printf("---%d--",qu[reco].num);
}

front+=MAXSIZE;
}		  



MAXSIZE*=2; //MAX��ȫ�ֱ���
return qu_1;

}


element input(element *qu )
{   
	
	while (1)        
	{
		if( ( rear+1)%MAXSIZE ==front%MAXSIZE)  /////////////
	{   printf("�����ӿռ�");
		 full(qu);
	}
		
		
		scanf("%d",&qu[rear].num );  //����������ķ�ʽ�����Բ���ָ�룬������->   �����ָ����� ��qu+top��->number
	  if(qu[rear].num==-2)
  	{   //rear=(rear+1)%MAXSIZE;  //-2��λ�Ӿ�Ϊrear��λ�ӣ�����ʵ����ֵ������һ��
		return *qu; }

	   rear=(rear+1)%MAXSIZE;
	
	}      	 
}


element push(element *qu )   // ǰ���ȳ�
{      if(front==rear)
{   printf("empty\n");
return *qu;
}        

front=  (front+1)%MAXSIZE;
printf("%d-",front);


}



  void printfall(element *qu )   // ǰ���ȳ�
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