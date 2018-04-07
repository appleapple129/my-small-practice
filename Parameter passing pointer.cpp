#include<stdio.h>
#include<stdlib.h>

typedef struct app
{
	int nu;
	char name[10];
	struct app *next;
}node;

/*  无法改变P的值,此函数结束后p依旧是NULL
void  add (node *p) //传入空指针，而不是空指针的地址
{  
	node *temp=NULL;/////////////
   
	while(1)
  {	node *newnode;
   newnode=(node*)malloc( sizeof(node ) );
   scanf("%d,",&newnode->nu);
    if(newnode->nu==-1)
	{   
		
		free(newnode);
		break ;
	}
	  scanf("%[^\n]",newnode->name);
	  newnode->next=NULL;

	  //newnode->next=(node *) malloc( sizeof(node* ) );
	    if(temp==NULL)
		{   temp=(node *) malloc( sizeof(node* ) );
			//newnode=(node *) malloc( sizeof(node ) );
       			temp=newnode;
				p=(node *) malloc( sizeof(node* ) ); ////////此时P已经换到其他地址了,原来传入的值已经丢失了
				p=temp;       //////////////////

		}
	   
		     
		  temp->next=newnode;
    	  	 
	       temp=newnode;


	}
	
} */  二级指针的一个用法，修改指针变量
void  add (node **p) //  指针指向空指针
{  
	node *temp=NULL;/////////////
   
	while(1)
  {	node *newnode;
   newnode=(node*)malloc( sizeof(node ) );
   scanf("%d,",&newnode->nu);
    if(newnode->nu==-1)
	{   
		
		free(newnode);
		break ;
	}
	  scanf("%[^\n]",newnode->name);
	  newnode->next=NULL;

	  //newnode->next=(node *) malloc( sizeof(node* ) );
	    if(temp==NULL)
		{   temp=(node *) malloc( sizeof(node* ) );
			//newnode=(node *) malloc( sizeof(node ) );
       			temp=newnode;
				*p=(node *) malloc( sizeof(node* ) ); /////// 指针指向的空指针开始有变化，但是指针一直指向变化的*p
				*p=temp;       //////////////////

		}
	   
		     
		  temp->next=newnode;
    	  	 
	       temp=newnode;


	}
	
}


void printall (node *p)
{     node *temp=p;
      
     while(temp!=NULL)
	 {    printf("%d %s\n",temp->nu,temp->name );
	      temp=temp->next;
	  }

}


int main(void)
{   node *p=NULL;
   //p=(node*)malloc( sizeof(node* ) );
  add (&p);
   printall (p);

}