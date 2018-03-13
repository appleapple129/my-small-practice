#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 100
#define _CRT_SECURE_NO_WARNINGS

typedef struct app{
float ceof;
int expon;
}polynomial;


int COMPARE (int x,int y)  
{ if(x>y) return 1;
  if(x==y)  return 0;
  if(x<y)  return -1;

}
 int count_v=1;int *count1;

int print_MULattach( float ceof1,int expon1,float ceof2,int expon2,polynomial *terms,int *avail,int count,int *count1 )
 {     
     if( *avail >MAX_TERMS )
      { printf("error");
         exit(0);			   }	   
 	   terms[*avail].ceof = ceof1*ceof2;
 	   terms[*avail].expon=expon1+expon2;
 	     if(*count1==count)
 	       printf("%fX%d",terms[*avail].ceof,terms[*avail].expon);
		 else
		  {
		   printf("%.1fX%d",terms[*avail].ceof,terms[*avail].expon,*count1,count);}
      	
		  *avail++; 
      	(*count1)++;
 }

int print_MUL ( int startA,int finishA,int startB,int finishB,polynomial *terms,int *avail )
{   
    count1=&count_v;
   int startB1;   int count;count=(finishB-startB)*(finishA-startA+1); printf("\nproduct:");
   for(  ; startA<finishA+1 ;startA++ )   
  	  {    
		  for( startB1=startB ; startB1<finishB ;startB1++ ) 
		   print_MULattach( terms[startA].ceof,terms[startA].expon,terms[startB1].ceof,terms[startB1].expon,terms,avail,count,count1 );
  }
}




void print_poly(int startA,int finishA,int startB,int finishB,polynomial *arry)
{ 
     printf("A=");
   for( ;startA<=finishA;startA++)
   { 
        if(startA==finishA)
         printf("%.fx%d", arry[startA].ceof , arry[startA].expon);
       else
	     {
		   if(arry[startA].expon !=0 )
		   printf("%.fx%d + ", arry[startA].ceof , arry[startA].expon);
		    else 
		    printf("%.f + ", arry[startA].ceof );
		 }
    }
    
   printf("\n");

    printf("B=");
  for( ;startA<finishB;startA++)
   { 
        if(startA==finishB-1)
         printf("%.fx%d", arry[startA].ceof , arry[startA].expon);
       else
	     {
		   if(arry[startA].expon !=0 )
		   printf("%.fx%d + ", arry[startA].ceof , arry[startA].expon);
		    else 
		    printf("%.f + ", arry[startA].ceof );

		    
		 }
    }



}
////////////////////////////////////////////////////////////////////////////

void attach(float coef,int exon,polynomial *terms,int *avail )
{    
	//printf(" %d ",*avail);
   if( *avail > MAX_TERMS )
     { printf("error");  exit(EXIT_FAILURE); }
     terms[ *avail].ceof = coef;
     terms[ (*avail)++].expon=exon;
	  //printf("%.fx %d",terms[*avail-1].ceof,terms[*avail-1].expon);
	 
}

/////////////////////////////////////////////////////////////////////////////
void padd(int startA,int finishA,int startB,int finishB,polynomial *terms,int startD,int finishD,int *avail )
{    int count=0;
        startD = *avail;
      while ( startA<=finishA && startB<= finishB)
      {
      	  switch(   COMPARE(  terms[startA].expon   , terms[startB].expon     )       )
		  {  case 1:   attach(terms[startA].ceof   , terms[startA].expon,terms,avail ); startA++;break;
           	   case 0:   count=terms[startA].ceof+terms[startB].ceof;
           	            attach(count , terms[startB].expon,terms,avail );startA++;startB++; break;
			   case -1:  attach(terms[startB].ceof  , terms[startB].expon,terms,avail ); startB++; break;
		   }
		
		       	  }

       for(;startA<=finishA;startA++)
		   attach(terms[startA].ceof   , terms[startA].expon,terms,avail );
    
	   for(;startB<=finishB;startB++)
		   attach(terms[startB].ceof   , terms[startB].expon,terms,avail );
	  
	    finishD= (*avail)-1; //此时avail已经发生了变化
     printf("\n");

	 for(; startD <finishD;startD ++)
   {    printf(" %.fx%d + ", terms[startD].ceof , terms[startD].expon);
   }


       
      
	  
}


//////////////////////////////////////////////////////////////////////////////// 


int main(void)
{  //avail=  (float *)malloc(sizeof(float )); 
int startA,finishA,startB,finishB;
int i=0;
int j=0; //counter 
int startD=0 ;
int finishD=0;
polynomial terms[MAX_TERMS];
int *avail=NULL; 
 avail=(int *)malloc(sizeof(int));


// A   startA 0....
startA=0;
printf("please input 2 polynomials， use “0 0 ”to finish  every polynomial input\n input formal: coefficient exponent \n"); 


for (i=0;i < MAX_TERMS ;  )
{  scanf("%f %d", &terms[i].ceof,&terms[i].expon);
 //  printf("%f %d", terms[i].ceof,terms[i].expon);
 if (terms[i].ceof == 0)  
	{ 
	printf("A over");
	goto LOOP1 ;
	}
   i++;
}   
    LOOP1:	
	finishA=i-1;
    startB=i;
    printf("\n");
for (j=startB;j< MAX_TERMS ;  )
{  scanf("%f %d", &terms[j].ceof,&terms[j].expon);

     if (terms[j].ceof == 0) 
	 {printf("B over\n"); goto LOOP2; }
	 j++;
}
LOOP2:
finishB=j;
*avail=j+1;

print_poly(startA,finishA,startB,finishB,terms);

padd(startA,finishA,startB,finishB,terms,startD,finishD,avail );

print_MUL ( startA,finishA,startB,finishB,terms,avail );

}
