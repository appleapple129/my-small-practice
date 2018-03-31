#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#define namesize 15
#define SWAP(x,y,temp)   ((temp)= (x),(x)=(y),(y)=(temp) )





void function(char *arry,int j,int n)  //n
{char temp;	 int i=0;int q;
	if( j==n)   
   {     for(q=0;q<n;q++)
        printf("%c",arry[q]);


	    printf("\n");

   }
	else{  

		for(i=j;i<n;i++)
		{
			SWAP(arry[i],arry[j],temp);
		
			function(arry,j+1,n ); 
		
			SWAP(arry[i],arry[j],temp);
		}
}    

	
	
 } 



int main(void)
{
	char ary[4]={'a','b','c','d'};
	 char brry[4];
	 
	function(ary,0,4); 
    	
	
	
}

int main(void)
{
	char ary[4]={'a','b','c','d'};
	 char brry[4];
	 
	function(ary,brry,0,4); 
    	
	
	
}
