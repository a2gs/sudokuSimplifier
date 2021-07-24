/* Andre Augusto Giannotti Scota (a2gs)
 * https://sites.google.com/view/a2gs/
 * andre.scota@gmail.com
 *
 * Sudoku Simplifier test
 *
 * MIT License
 *
 */

#include <stdio.h>

#define EMPTY (-1)
#define MAX (20)

int remove_n(int n, int x[MAX])
{
	if(x[MAX-1] == n)
		x[MAX-1] = EMPTY;
	else{
		unsigned int i = 0;
		int flag = 0;

		for(flag = 0, i = 0; i < MAX && x[i] != EMPTY; i++){
			if(flag == 0 && x[i] == n) flag = 1;
			if(flag == 1) x[i] = x[i+1];
		}
		x[i-1] = EMPTY;
	}

	return(0);
}


int main(int argc, char *argv[])
{
	int x[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

	remove_n(20, x);
	printf("%d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d\n", x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7], x[8], x[9], x[10], x[11], x[12], x[13], x[14], x[15], x[16], x[17], x[18], x[19]);

	remove_n(10, x);
	printf("%d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d\n", x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7], x[8], x[9], x[10], x[11], x[12], x[13], x[14], x[15], x[16], x[17], x[18], x[19]);

	remove_n(5, x);
	printf("%d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d\n", x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7], x[8], x[9], x[10], x[11], x[12], x[13], x[14], x[15], x[16], x[17], x[18], x[19]);

	remove_n(15, x);
	printf("%d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d\n", x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7], x[8], x[9], x[10], x[11], x[12], x[13], x[14], x[15], x[16], x[17], x[18], x[19]);

	remove_n(1, x);
	printf("%d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d  %d\n", x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7], x[8], x[9], x[10], x[11], x[12], x[13], x[14], x[15], x[16], x[17], x[18], x[19]);

	return(0);
}
