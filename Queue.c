#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#define namesize 15

typedef struct queue  //Queue
{   int  number[MAXSIZE];
    char name[MAXSIZE][namesize];
    char address[MAXSIZE][namesize];
    int front;	
	int rear;  //0��ʼ 
	
}SeqSQueue;


int judge (SeqSQueue *seq)
{   int i=0;
  if( seq->rear%MAXSIZE > MAXSIZE-1  )   //����Ӧ���Ǵ��ڷ���   ��������47�е�seq->real++ ,=��ʱ����ʵ����������һ�� 
 	    { 
			printf("full");
			//for(;i<=MAXSIZE;i++)
			// seq->address[i] =realloc(seq->address[i]),2*MAXSIZE*namesize); 
			// give the ����ü ���� value space 
			return 1;
		}
	else 
	return -1;	
}


SeqSQueue input(SeqSQueue *seq )  //pop
{ 

	while(1)
	{
		if( judge (seq ) == 1 )
		{  printf("full");   return *seq;  }
		//  
		scanf("%d,%s%[^\n]",&seq->number[ seq->rear%MAXSIZE ],&seq->name[seq->rear%MAXSIZE ],&seq->address[seq->rear%MAXSIZE] );
		if(seq->number[ (seq->rear)%MAXSIZE ]==-2)  //ע��������� %MAXSIZE �����е������Ӧ�ü���%MAXSIZE �������ж� 
		{  seq->rear--;
		   
		   return *seq;  
		}
		
		seq->rear++;  ///////////////////////////////////////////////////////////
		fflush(stdin);
		//�������ʣ�����scanf�ġ������м����,�ʹ�
		
		 
	}

}



SeqSQueue push(SeqSQueue *seq,int n )
{  int i=1;
  
 for(;i<=n;i++)
 {	printf("<%d,%s,%s> ",seq->number[seq->front],&seq->name[seq->front],&seq->address[seq->front] );
    if(seq->front == seq ->rear)  
       {  printf("is empty");
	      return *seq;
	   }

	  seq->front++;
	 
	 

 }  return *seq;
}


void putout(SeqSQueue *seq)
{   
	int i=0; 
	for(i=seq->front;i<=seq->rear;i++)
		printf("<%d,%s,%s>",seq->number[i%MAXSIZE] ,&seq->name[i%MAXSIZE] ,&seq->address[i%MAXSIZE] ); //&seq->address[i]


	printf("\n");
}





int main (void)
{   struct queue work;
      work.front=0;
      work.rear=0;
      
     printf(" if you want to over input,input -2 \n\n");
    input( &work );  //1
	printf("\n\n");
     putout(&work);  //1
	 printf("\n\n");
	push(&work,3);  //2
    printf("\n\n please input ");
	input( &work );  //3
	printf("\n\n");
	putout(&work);
	printf("\n\n");
	push(&work,6);   //4
	printf("\n\n");
	 putout(&work);  //5
	printf("\n");
}
