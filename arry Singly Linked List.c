#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
typedef  struct node 
{   
char name[20];
char add[20];
int   nu;

int next ;   

}Newnode; 

int coun=0;int first;
////////////////////////
Newnode sort( Newnode *q )
{    int c;int mark=0;int qq=0;int i,ii; int temp;
	int min=q[0].nu;
	for  (c=0;c<coun;c++)
 	 {   if(q[c].nu<min)
	     {  min=q[c].nu;
        	mark=c; }
       }
      first=mark;
	  q[first].next=0;
      temp=first;
	  
	  
		for(ii=0;ii<coun-1;ii++)
  {	    min=300;
	   for(i=0;i< coun;i++)
	  {   
	  if(q[i].next==-1&&q[i].nu<min )   
	  {      min= q[i].nu;
	         mark=i;
	     
	  }
	  }  
	    q[mark].next=0;
		q[temp].next=mark; ///////////////
		temp=q[temp].next;
		}
		q[mark].next=-1; //×îºó
   return *q;       

}    

//////////////////////////
Newnode add( Newnode *q )
{ 


while(1)
{    
	
       scanf("%d," ,&q[coun].nu);
	if( q[coun].nu==-2    )  //-2½áÊø
	        {
			    return *q;
			}
	
	  scanf("%[^,],%[^\n]",q[coun].name,q[coun].add);
	  q[coun].next=-1;
	//fflush(stdin);
    //gets(newnode->add);
    coun++;    
	
    
}
       return *q;
}

//////////////////////////////

void search(int num,Newnode *q )
{  int temp=first;
    while( 1 )
{    
	
	
//	printf("11111");
	
	if(q[temp].nu==num)
    {    printf("%d %s %s",q[temp].nu,q[temp].name,q[temp].add ); 
     
	 return;
    }

	if(q[temp].next==-1)
	    break;
   
	temp=q[temp].next; 


	}

	

	printf("\nthere is no\n");

 }
///////////////////////////////

Newnode delate(int num,Newnode *q )
{ 
	 int temp=first;
	  
	 if(q[temp].nu==num)
		{ first= q[first].next;  
	   return *q;
	 }
	 while( 1 )
{     
	
	
//	printf("11111");
	
	if(q[q[temp].next].nu==num && q[q[temp].next].next==-1)
    {         q[temp].next=-1;
	        	 return *q;
    }
	





	if(q[q[temp].next].nu==num)
	{     q[temp].next=q[q[temp].next].next;
	
                 return *q;	
	}
   
	
	temp=q[temp].next; 
	if(temp==-1)
		break;

	}

	

	printf("\nthere is no\n");

}
/////////////////////////////////
void printall( Newnode *q )
{   
    int temp=first;
      
	    
     	printf("%d %s %s %d _%d_\n",q[temp].nu,q[temp].name,q[temp].add,q[temp].next,temp);
	
	while(1)
	{    temp= q[temp].next;	     
		printf("%d %s %s %d _%d_\n",q[temp].nu,q[temp].name,q[temp].add,q[temp].next,temp);
	  	        
		if(q[temp].next==-1 )
         break;
    	
	}

	//printf("%d %s %s %d _%d_\n",q[1].nu,q[1].name,q[1].add,q[1].next,temp);
	


}
////////////////////////

int main(void)
{  int nuu=2;
	char inpu;int inpu2;
  //init  
  Newnode n1[30];
 
  
  


  while(1) 
  {  scanf("%c",&inpu);
     switch(inpu)
	 {  case 'i':printf("add\n");
	           add( n1 );sort( n1);
			   continue;
	    case 'd':  
			  printf("delate\n");
			  scanf("%d",&inpu2);
			 
               delate(inpu2,n1 );
  
			 continue;

	    case 'f': printf("search\n"); 
			     scanf("%d",&inpu2);
			      search(inpu2,n1 );
				  continue;

	    case 'r':  printall( n1);
			      continue;

	    case 'q': return 0;
	 
	 } 
  }
	
	
	
}
