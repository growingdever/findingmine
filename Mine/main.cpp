
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

int map[SIZE][SIZE];
int mine[SIZE][2];

int main()
{
	srand( (unsigned)(time)(NULL) );

	int sx, sy;
	printf("What's size? Input x and y. ex) 10 10\n");
	scanf("%d %d", &sx, &sy);

	int i, j;
	for( i=0; i<sy; i++ )
		for( j=0; j<sx; j++ )
			map[i][j] = 0;

	int nMine;
	printf("How many mine? : ");
	scanf("%d", &nMine);

	int x, y;
	for( i=0; i<nMine; i++ )
	{
		x = rand()%sx;
		y = rand()%sy;
		 
		mine[i][0] = x;
		mine[i][1] = y;

		// Mine's code is -1
		map[y][x] = -1;
	}


	int cnt = 0;
	for( y=0; y<sy; y++ )
	{
		for( x=0; x<sx; x++ )
		{
			if( map[y][x] == -1 )
				continue;

			cnt = 0;

			if( y-1 >= 0 && x-1 >=0 && map[y-1][x-1] == -1 )
				cnt ++;
			if( y-1 >= 0 && map[y-1][x] == -1 )
				cnt ++;
			if( y-1 >= 0 && x+1 < sx && map[y-1][x+1] == -1 )
				cnt ++;
			if( x-1 >= 0 && map[y][x-1] == -1 )
				cnt ++;
			if( x+1 < sx && map[y][x+1] == -1 )
				cnt ++;
			if( y+1 < sy && x-1 >= 0 && map[y+1][x-1] == -1 )
				cnt ++;
			if( y+1 < sy && map[y+1][x] == -1 )
				cnt ++;
			if( y+1 < sy && x+1 < sx && map[y+1][x+1] == -1 )
				cnt ++;

			map[y][x] = cnt;
		}
	}

	for( i=0; i<SIZE; i++ )
	{
		for( j=0; j<SIZE; j++ )
		{
			if( map[i][j] == -1 )
				printf(" бс");
			else
				printf("%3d", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}