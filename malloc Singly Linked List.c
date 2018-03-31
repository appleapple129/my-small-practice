#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
typedef  struct node 
{   
char name[20];
char add[20];
int   nu;

struct node *next;

}Newnode; 

////////////////////////
Newnode sort( Newnode *q,Newnode *inser,int num )
{   Newnode *temp=q;    
    while(temp->next->nu<num  )
	{
		
		if(temp->next->next==NULL &&temp->next->nu<num   )
		{	  temp->next->next = inser;
	       	inser->next=NULL;
		    return *q; 
		}
	
		temp=temp->next;
  }
	inser->next=temp->next;
	temp->next=inser; 
      return *q;

}    

//////////////////////////
Newnode add( Newnode *q )
{int coun=0; 
Newnode *temp=q;

while(1)
{    coun++;
	Newnode *newnode;
	newnode=(Newnode * )malloc( sizeof(Newnode )   ); 
	scanf("%d,",&newnode->nu);
	if( newnode->nu==-1    )
			{
			    return *q;
			}
	
	scanf("%[^,],%[^\n]",newnode->name,newnode->add);
	//fflush(stdin);
    //gets(newnode->add);
    
	if(coun<=2)
	 {temp->next=newnode;
    newnode->next=NULL;
	temp=newnode;}
	 
	if(coun >2)
	 *q=sort( q,newnode,newnode->nu  );

    
}
       return *q;
}

//////////////////////////////
void search(int num,Newnode *q )
{ Newnode *temp=q;
while(temp->next!=NULL)
{    if(temp->nu==num)
{    printf("%d %s %s",temp->nu,temp->name,temp->add ); 
     
	 return;
}  temp=temp->next;
 }
    printf("\nthere is no\n");

}
///////////////////////////////
Newnode delate(int num,Newnode *q )
{   
	Newnode *temp=q;	Newnode *t;
while(temp->next!=NULL)
{   	if(temp->next->next==NULL &&temp->next->nu==num)
	{  temp->next=NULL;
printf("\n2222222\n");
	     return *q;
	}  


	if(temp->next->nu==num)
	{   
		
	
		t=temp->next;
		temp->next=temp->next->next; 
	    free(t);
		printf("\ndelating\n"); 
	  
	 return *q;
}   
  temp=temp->next;
} 
    printf("\nthere is no\n");
	return *q;

}
/////////////////////////////////
void printall( Newnode *q )
{  Newnode *temp=q->next;
	while(temp->next!=NULL) 
{   printf("%d %s %s\n",temp->nu,temp->name,temp->add);   
	temp=temp->next; 
}
	printf("%d %s %s\n",temp->nu,temp->name,temp->add);

}
////////////////////////

int main(void)
{  char inpu;int inpu2;
  //init  
  Newnode n1;
  Newnode *p;p=&n1;   
  p->next=NULL;
  while(1) 
  {  scanf("%c",&inpu);
     switch(inpu)
	 {  case 'i':printf("add\n");
	          add( p ); continue;
	    case 'd':  
			  printf("delate\n");
			 scanf("%d",&inpu2);
			 delate(inpu2,p );
			 continue;

	    case 'f': printf("search\n"); 
			     scanf("%d",&inpu2);
			      search(inpu2,p );
				  continue;

	    case 'r': printall( p );
			      continue;

	    case 'q': return 0;
	 
	 } 
  }
	
	
	
}
