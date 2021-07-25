/* Andre Augusto Giannotti Scota (a2gs)
 * https://sites.google.com/view/a2gs/
 * andre.scota@gmail.com
 *
 * Sudoku Simplifier
 *
 * MIT License
 *
 */

#include <stdio.h>

#define EMPTY (-1)

#define HEIGHT  (11)
#define LINES   (9)
#define COLUMNS (9)

#define PRINT_EMPTY(x) (x == EMPTY ? ' ' : 0x30 + x)

int printBoard(int board[LINES][COLUMNS])
{
	unsigned int line = 0;
	
	for(line = 0; line < LINES; line++){
		if(line != 0 && line % 3 == 0)
			printf("------+-------+------\n");

		printf("%c %c %c | %c %c %c | %c %c %c\n",
		       PRINT_EMPTY(board[line][0]), PRINT_EMPTY(board[line][1]), PRINT_EMPTY(board[line][2]),
		       PRINT_EMPTY(board[line][3]), PRINT_EMPTY(board[line][4]), PRINT_EMPTY(board[line][5]),
		       PRINT_EMPTY(board[line][6]), PRINT_EMPTY(board[line][7]), PRINT_EMPTY(board[line][8]));
	}

	return(0);
}

int printCube(int cube[HEIGHT][LINES][COLUMNS])
{
	unsigned height = 0, line = 0, col = 0;

	for(line = 0; line < LINES; line++){
		for(col = 0; col < COLUMNS; col++){
			printf("%c: ", PRINT_EMPTY(cube[0][line][col]));
			for(height = 1; height < HEIGHT && cube[height][line][col] != EMPTY; height++)
				printf("%c ", PRINT_EMPTY(cube[height][line][col]));

			printf("\n");
		}
	}

	return(0);
}

unsigned int howMuchNumbersInALine(int cube[LINES][COLUMNS], unsigned int line)
{
	unsigned int tot = 0, col = 0;
	for(tot = 0, col = 0; col <  COLUMNS; col++) if(cube[line][col] != EMPTY) tot++;

	return(tot);
}

unsigned int howMuchNumbersInAColumn(int cube[LINES][COLUMNS], unsigned int col)
{
	unsigned int tot = 0, line = 0;
	for(tot = 0, line = 0; line <  LINES; line++) if(cube[line][col] != EMPTY) tot++;

	return(tot);
}

/* only for 3x3 squares...

   Square Ids:

      |       |
   1  |   2   |   3
      |       |    
------+-------+------
      |       |      
   4  |   5   |   6  
      |       |      
------+-------+------
      |       |    
   7  |   8   |   9  
      |       |      

00 01 02 | 03 04 05 | 06 07 08
10 11 12 | 13 14 15 | 16 17 18
20 21 22 | 23 24 25 | 26 27 28
---------+----------+---------
30 31 32 | 33 34 35 | 36 37 38
40 41 42 | 43 44 45 | 46 47 48
50 51 52 | 53 54 55 | 56 57 58
---------+----------+---------
60 61 62 | 63 64 65 | 66 67 68
70 71 72 | 73 74 75 | 76 77 78
80 81 82 | 83 84 85 | 86 87 88
*/
int howMuchNumbersInASquare(int cube[LINES][COLUMNS], unsigned int square)
{
	#define DEFAULT_SUDOKU_SQUARE (9)
	unsigned int i = 0, tot = 0;
	int *pelem[DEFAULT_SUDOKU_SQUARE] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

	switch(square){ // SHAME!! SHAME!! SHAME!! ... but it works, and fast ...
		case 1:
			pelem[0] = &cube[0][0]; pelem[1] = &cube[0][1]; pelem[2] = &cube[0][2];
			pelem[3] = &cube[1][0]; pelem[4] = &cube[1][1]; pelem[5] = &cube[1][2];
			pelem[6] = &cube[2][0]; pelem[7] = &cube[2][1]; pelem[8] = &cube[2][2];
			break;
		case 2:
			pelem[0] = &cube[0][3]; pelem[1] = &cube[0][4]; pelem[2] = &cube[0][5];
			pelem[3] = &cube[1][3]; pelem[4] = &cube[1][4]; pelem[5] = &cube[1][5];
			pelem[6] = &cube[2][3]; pelem[7] = &cube[2][4]; pelem[8] = &cube[2][5];
			break;
		case 3:
			pelem[0] = &cube[0][6]; pelem[1] = &cube[0][7]; pelem[2] = &cube[0][8];
			pelem[3] = &cube[1][6]; pelem[4] = &cube[1][7]; pelem[5] = &cube[1][8];
			pelem[6] = &cube[2][6]; pelem[7] = &cube[2][7]; pelem[8] = &cube[2][8];
			break;
		case 4:
			pelem[0] = &cube[3][0]; pelem[1] = &cube[3][1]; pelem[2] = &cube[3][2];
			pelem[3] = &cube[4][0]; pelem[4] = &cube[4][1]; pelem[5] = &cube[4][2];
			pelem[6] = &cube[5][0]; pelem[7] = &cube[5][1]; pelem[8] = &cube[5][2];
			break;
		case 5:
			pelem[0] = &cube[3][3]; pelem[1] = &cube[3][4]; pelem[2] = &cube[3][5];
			pelem[3] = &cube[4][3]; pelem[4] = &cube[4][4]; pelem[5] = &cube[4][5];
			pelem[6] = &cube[5][3]; pelem[7] = &cube[5][4]; pelem[8] = &cube[5][5];
			break;
		case 6:
			pelem[0] = &cube[3][6]; pelem[1] = &cube[3][7]; pelem[2] = &cube[3][8];
			pelem[3] = &cube[4][6]; pelem[4] = &cube[4][7]; pelem[5] = &cube[4][8];
			pelem[6] = &cube[5][6]; pelem[7] = &cube[5][7]; pelem[8] = &cube[5][8];
			break;
		case 7:
			pelem[0] = &cube[6][0]; pelem[1] = &cube[6][1]; pelem[2] = &cube[6][2];
			pelem[3] = &cube[7][0]; pelem[4] = &cube[7][1]; pelem[5] = &cube[7][2];
			pelem[6] = &cube[8][0]; pelem[7] = &cube[8][1]; pelem[8] = &cube[8][2];
			break;
		case 8:
			pelem[0] = &cube[6][3]; pelem[1] = &cube[6][4]; pelem[2] = &cube[6][5];
			pelem[3] = &cube[7][3]; pelem[4] = &cube[7][4]; pelem[5] = &cube[7][5];
			pelem[6] = &cube[8][3]; pelem[7] = &cube[8][4]; pelem[8] = &cube[8][5];
			break;
		case 9:
			pelem[0] = &cube[6][6]; pelem[1] = &cube[6][7]; pelem[2] = &cube[6][8];
			pelem[3] = &cube[7][6]; pelem[4] = &cube[7][7]; pelem[5] = &cube[7][8];
			pelem[6] = &cube[8][6]; pelem[7] = &cube[8][7]; pelem[8] = &cube[8][8];
			break;
		default:
			return(-1);
			break;
	}

	for(i = 0, tot = 0; i < DEFAULT_SUDOKU_SQUARE; i++) if(*pelem[i] != EMPTY) tot++;

	return(tot);
}

int cleanFixedNumbers(int cube[HEIGHT][LINES][COLUMNS])
{
	unsigned height = 0, line = 0, col = 0;

	for(line = 0; line < LINES; line++){
		for(col = 0; col < COLUMNS; col++){
			if(cube[0][line][col] != EMPTY){
				for(height = 1; height < HEIGHT; height++)
					cube[height][line][col] = EMPTY;
			}
		}
	}

	return(0);
}

int remove_n(int n, int vertical[HEIGHT][LINES][COLUMNS], unsigned int line, unsigned int col)
{
	if(vertical[HEIGHT-1][line][col] == n)
		vertical[HEIGHT-1][line][col] = EMPTY;
	else{
		unsigned int i = 0;
		int flag = 0;

		for(flag = 0, i = 0; i < HEIGHT && vertical[i][line][col] != EMPTY; i++){
			if(flag == 0 && vertical[i][line][col] == n) flag = 1;
			if(flag == 1) vertical[i][line][col] = vertical[i+1][line][col];
		}
		vertical[i-1][line][col] = EMPTY;
	}

	return(0);
}

/* Line and Column CleanUp
   The most simple cleanup: remove possible numbers (in height) in lines or columns where there is fixed numbers.
	Called every time one number is discovered.

	Future version: receive a line and column discovered. So, we do not scan all the cube. Just one especific fixed number (specificNumberLineColumnCleanUp()).
*/
int lineColumnCleanUp(int cube[][LINES][COLUMNS])
{
	unsigned /*height = 0,*/ line = 0, col = 0;

	for(line = 0; line < LINES; line++){
		for(col = 0; col < COLUMNS; col++){
			if(cube[0][line][col] != EMPTY){

				/* a function here: specificNumberLineColumnCleanUp(line, col, cube[0][line][col]) */
				{
					unsigned auxline = 0, auxcol = 0;
					int fixedNumber = EMPTY;

					fixedNumber = cube[0][line][col];

					for(auxcol  = 0, auxline = line; auxcol < COLUMNS; auxcol++) remove_n(fixedNumber, cube, auxline, auxcol);
					for(auxline = 0, auxcol  = col; auxline < LINES;  auxline++) remove_n(fixedNumber, cube, auxline, auxcol);
				}

			}
		}
	}
	return(0);
}

/* Statistical CleanUp
   Count how much number there is in a line, and if it is 8, set the remaining number.
	Count how much number there is in a column, and if it is 8, set the remaining number.
	Count how much number there is in a square (3x3), and if it is 8, set the remaining number.

	Return if a number was fixed (discovered).

	Future version: return the lines and columns (may be more than 1 number discovered). This can be a hint to a more perfomatic version of lineColumnCleanUp() (to not scan all cube: specificNumberLineColumnCleanUp()).
*/
int statisticalCleanUp(int cube[][LINES][COLUMNS])
{
	return(0);
}

int triangularizationCleanUp(int cube[][LINES][COLUMNS])
{
	return(0);
}

int main(int argc, char *argv[])
{
	int flag = 0;
	int cube[HEIGHT][LINES][COLUMNS] = {
		{{5, 3, EMPTY, EMPTY, 7, EMPTY, EMPTY, EMPTY, EMPTY}, {6, EMPTY, EMPTY, 1, 9, 5, EMPTY, EMPTY, EMPTY}, {EMPTY, 9, 8, EMPTY, EMPTY, EMPTY, EMPTY, 6, EMPTY}, {8, EMPTY, EMPTY, EMPTY, 6, EMPTY, EMPTY, EMPTY, 3}, {4, EMPTY, EMPTY, 8, EMPTY, 3, EMPTY, EMPTY, 1}, {7, EMPTY, EMPTY, EMPTY, 2, EMPTY, EMPTY, EMPTY, 6}, {EMPTY, 6, EMPTY, EMPTY, EMPTY, EMPTY, 2, 8, EMPTY}, {EMPTY, EMPTY, EMPTY, 4, 1, 9, EMPTY, EMPTY, 5}, {EMPTY, EMPTY, EMPTY, EMPTY, 8, EMPTY, EMPTY, 7, 9}},
		{{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}},
		{{1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1}},
		{{2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2, 2, 2, 2}},
		{{3, 3, 3, 3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3, 3, 3, 3}},
		{{4, 4, 4, 4, 4, 4, 4, 4, 4}, {4, 4, 4, 4, 4, 4, 4, 4, 4}, {4, 4, 4, 4, 4, 4, 4, 4, 4}, {4, 4, 4, 4, 4, 4, 4, 4, 4}, {4, 4, 4, 4, 4, 4, 4, 4, 4}, {4, 4, 4, 4, 4, 4, 4, 4, 4}, {4, 4, 4, 4, 4, 4, 4, 4, 4}, {4, 4, 4, 4, 4, 4, 4, 4, 4}, {4, 4, 4, 4, 4, 4, 4, 4, 4}},
		{{5, 5, 5, 5, 5, 5, 5, 5, 5}, {5, 5, 5, 5, 5, 5, 5, 5, 5}, {5, 5, 5, 5, 5, 5, 5, 5, 5}, {5, 5, 5, 5, 5, 5, 5, 5, 5}, {5, 5, 5, 5, 5, 5, 5, 5, 5}, {5, 5, 5, 5, 5, 5, 5, 5, 5}, {5, 5, 5, 5, 5, 5, 5, 5, 5}, {5, 5, 5, 5, 5, 5, 5, 5, 5}, {5, 5, 5, 5, 5, 5, 5, 5, 5}},
		{{6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 6, 6, 6, 6, 6, 6, 6, 6}, {6, 6, 6, 6, 6, 6, 6, 6, 6}},
		{{7, 7, 7, 7, 7, 7, 7, 7, 7}, {7, 7, 7, 7, 7, 7, 7, 7, 7}, {7, 7, 7, 7, 7, 7, 7, 7, 7}, {7, 7, 7, 7, 7, 7, 7, 7, 7}, {7, 7, 7, 7, 7, 7, 7, 7, 7}, {7, 7, 7, 7, 7, 7, 7, 7, 7}, {7, 7, 7, 7, 7, 7, 7, 7, 7}, {7, 7, 7, 7, 7, 7, 7, 7, 7}, {7, 7, 7, 7, 7, 7, 7, 7, 7}},
		{{8, 8, 8, 8, 8, 8, 8, 8, 8}, {8, 8, 8, 8, 8, 8, 8, 8, 8}, {8, 8, 8, 8, 8, 8, 8, 8, 8}, {8, 8, 8, 8, 8, 8, 8, 8, 8}, {8, 8, 8, 8, 8, 8, 8, 8, 8}, {8, 8, 8, 8, 8, 8, 8, 8, 8}, {8, 8, 8, 8, 8, 8, 8, 8, 8}, {8, 8, 8, 8, 8, 8, 8, 8, 8}, {8, 8, 8, 8, 8, 8, 8, 8, 8}},
		{{9, 9, 9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9, 9, 9, 9, 9, 9}},
	};

	printBoard(cube[0]);

	cleanFixedNumbers(cube);

	do{
		flag = 0;
		lineColumnCleanUp(cube);
		flag = statisticalCleanUp(cube);
		flag = triangularizationCleanUp(cube);
	}while(flag == 1);

	printCube(cube);

	return(0);
}
