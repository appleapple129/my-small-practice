#include<stdio.h>
#include<stdlib.h>

typedef struct app
{
	int nu;
	char name[10];
	struct app *next;
}node;

/*  �޷��ı�P��ֵ,�˺���������p������NULL
void  add (node *p) //�����ָ�룬�����ǿ�ָ��ĵ�ַ
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
				p=(node *) malloc( sizeof(node* ) ); ////////��ʱP�Ѿ�����������ַ��,ԭ�������ֵ�Ѿ���ʧ��
				p=temp;       //////////////////

		}
	   
		     
		  temp->next=newnode;
    	  	 
	       temp=newnode;


	}
	
} */  ����ָ���һ���÷����޸�ָ�����
void  add (node **p) //  ָ��ָ���ָ��
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
				*p=(node *) malloc( sizeof(node* ) ); /////// ָ��ָ��Ŀ�ָ�뿪ʼ�б仯������ָ��һֱָ��仯��*p
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