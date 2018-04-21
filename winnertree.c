#include <stdio.h>
#include <stdlib.h>

int winner_tree[8];
typedef struct {
	int	which;  /* 记录是哪个子数组 */
	int	index;  /* 记录是上个标记数组的第几个元素了 */
	int	data;
}element;

int array[8][14];

element arrayt[16];
/* int count = 0; */
int output_array[800];

int count = 0;

void initialize_data()
{
	int i = 0;
	for ( i = 0; i < 13; i++ )
		scanf( "%d", &array[0][i] );
	array[0][13] = -1;
	for ( i = 0; i < 13; i++ )
		scanf( "%d", &array[1][i] );
	array[1][13] = -1;
	for ( i = 0; i < 13; i++ )
		scanf( "%d", &array[2][i] );
	array[2][13] = -1;
	for ( i = 0; i < 13; i++ )
		scanf( "%d", &array[3][i] );
	array[3][13] = -1;
	for ( i = 0; i < 13; i++ )
		scanf( "%d", &array[4][i] );
	array[4][13] = -1;

	for ( i = 0; i < 12; i++ )
		scanf( "%d", &array[5][i] );
	array[5][12] = -1;

	for ( i = 0; i < 12; i++ )
		scanf( "%d", &array[6][i] );
	array[6][12] = -1;

	for ( i = 0; i < 12; i++ )
		scanf( "%d", &array[7][i] );
	array[7][12] = -1;

	for ( i = 0; i < 8; i++ )
	{
		arrayt[i].which = i;
		arrayt[i].index = 0;
	}
}


void initialize_WT()
{
	int i = 8; int j = 0;
	for (; i < 16; i++, j++ )
	{
		arrayt[i].data	= array[j][0];
		arrayt[i].index = 0;
		arrayt[i].which = j;
	}
	for ( i = 0; i < 8; i++, j++ )
	{
		arrayt[i].index = 0;
	}


	for ( i = 4; i < 8; i++ )
	{
		if ( arrayt[2 * i].data < arrayt[2 * i + 1].data )
		{
			arrayt[i].data	= arrayt[2 * i].data;
			arrayt[i].which = arrayt[2 * i].which;
		} else{ arrayt[i].data	= arrayt[2 * i + 1].data;
			arrayt[i].which = arrayt[2 * i].which; }
	}


	for ( i = 2; i < 4; i++ )
	{
		if ( arrayt[2 * i].data < arrayt[2 * i + 1].data )
		{
			arrayt[i].data	= arrayt[2 * i].data;
			arrayt[i].which = arrayt[2 * i].which;
		}else   {
			arrayt[i].data	= arrayt[2 * i + 1].data;
			arrayt[i].which = arrayt[2 * i + 1].which;
		}
	}

	for ( i = 1; i < 2; i++ )
	{
		if ( arrayt[2 * i].data < arrayt[2 * i + 1].data )
		{
			arrayt[i].data	= arrayt[2 * i].data;
			arrayt[i].which = arrayt[2 * i].which;
		}  else{ arrayt[i].data		= arrayt[2 * i + 1].data;
			 arrayt[i].which	= arrayt[2 * i + 1].which; }
	}
}


int setup_WT( int parent, int left_run_id, int right_run_id )
{
	if ( left_run_id == -1 && right_run_id == -1 )
	{
		parent = -1;
	}

	if ( left_run_id == -1 )
	{
		parent = right_run_id;
	}
	if ( left_run_id == -1 )
	{
		parent = left_run_id;
	}


	if ( left_run_id > right_run_id )
		parent = right_run_id;
	else
		parent = left_run_id;

	return(parent);
}


void get_top_WT()
{
	int c = arrayt[1].which + 8;    /* 叶 */
	output_array[count++] = arrayt[1].data;

	arrayt[c].index++;              /* Run的节点 */
	arrayt[c].data = array[arrayt[1].which][arrayt[c].index];

	c		/= 2;
	arrayt[c].data	= setup_WT( arrayt[c].data, arrayt[c * 2].data, arrayt[c * 2 + 1].data );

	if ( arrayt[c * 2].data > arrayt[c * 2 + 1].data )
	{
		arrayt[c].index = arrayt[c * 2 + 1].index;
		arrayt[c].which = arrayt[c * 2 + 1].which;
	}else                                              {
		arrayt[c].index = arrayt[c * 2].index;
		arrayt[c].which = arrayt[c * 2].which;
	}
	c		/= 2;
	arrayt[c].data	= setup_WT( arrayt[c].data, arrayt[c * 2].data, arrayt[c * 2 + 1].data );
	if ( arrayt[c * 2].data > arrayt[c * 2 + 1].data )
	{
		arrayt[c].index = arrayt[c * 2 + 1].index;
		arrayt[c].which = arrayt[c * 2 + 1].which;
	}else                                         {
		arrayt[c].index = arrayt[c * 2].index;
		arrayt[c].which = arrayt[c * 2].which;
	}

	c		= 1;
	arrayt[c].data	= setup_WT( arrayt[c].data, arrayt[c * 2].data, arrayt[c * 2 + 1].data );
	if ( arrayt[c * 2].data > arrayt[c * 2 + 1].data )
	{
		arrayt[c].index = arrayt[c * 2 + 1].index;
		arrayt[c].which = arrayt[c * 2 + 1].which;
	}else                                         {
		arrayt[c].index = arrayt[c * 2].index;
		arrayt[c].which = arrayt[c * 2].which;
	}
}


int main( void )
{
	int q = 0;
	initialize_data();

	initialize_WT();
	while ( arrayt[1].data != -1 )
	{
		get_top_WT();
	}


	for (; q < count - 1; q++ )
	{
		printf( "%d ", output_array[q] );
	}
}


/* test date(scanf)
 * 0 15 16 31 32 47 48 63 64 79 80 95 96
 * 1 14 17 30 33 46 49 62 65 78 81 94 97
 * 2 13 18 29 34 45 50 61 66 77 82 93 98
 * 3 12 19 28 35 44 51 60 67 76 83 92 99
 * 4 11 20 27 36 43 52 59 68 75 84 91 100
 * 5 10 21 26 37 42 53 58 69 74 85 90
 * 6 9 22 25 38 41 54 57 70 73 86 89
 * 7 8 23 24 39 40 55 56 71 72 87 88
 */