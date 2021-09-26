#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#ifndef MAX
#define MAX(a,b)  (((a) > (b)) ? (a) : (b))
#endif



int MIN(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}


int main()
{
	/*
	int result[4][4] = {
		{0, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{0, 0, 1, 0}
	};
	int min;
	printf("\n");
	for (int j = 1 ; j < 4 ; j++){
		for(int i = 1 ;i < 4; i++){
			min = 1098;
			if (i > 0 && j > 0)
				min = MIN(result[j-1][i-1], min);
			if (j > 0)
				min = MIN(result[j-1][i], min);
			if (i > 0)
				min = MIN(result[j][i-1], min);
			if((i > 0 || j > 0) && result[j][i] != 0)
				result[j][i] = min + 1;
		}
	}

*/
int fd;

char buff[1024];

if(0 < (fd = open ("./example.txt", O_RDONLY)))
{
	write(fd, "bsq", strlen("bsq"));
	read(fd, buff, 1024);
	puts(buff);
	write(1, "success\n", 8);
	close(fd);
}


}
