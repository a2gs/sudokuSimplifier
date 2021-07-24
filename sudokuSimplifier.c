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
			for(height = 1; height < HEIGHT && cube[height][line][col] != EMPTY; height++){
				printf("%c ", PRINT_EMPTY(cube[height][line][col]));
			}
			printf("\n");
		}
	}

	return(0);
}

unsigned int howMuchNumbersInALine(int cube[LINES][COLUMNS], unsigned int line)
{
	unsigned int tot = 0, col = 0;
	for(tot = 0, col = 0; col <  COLUMNS; col++) if(cube[line][col]) tot++;

	return(tot);
}

unsigned int howMuchNumbersInAColumn(int cube[LINES][COLUMNS], unsigned int col)
{
	unsigned int tot = 0, line = 0;
	for(tot = 0, line = 0; line <  LINES; line++) if(cube[line][col]) tot++;

	return(tot);
}

/* Square Ids:

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
*/
unsigned int howMuchNumbersInASquare(int cube[][LINES][COLUMNS], unsigned int square)
{
	return(0);
}

int cleanFixedNumbers(int cube[][LINES][COLUMNS])
{
	unsigned height = 0, line = 0, col = 0;

	for(line = 0; line < LINES; line++){
		for(col = 0; col < COLUMNS; col++){
			if(cube[0][line][col] != EMPTY){
				for(height = 1; height < HEIGHT; height++){
					cube[height][line][col] = EMPTY;
				}
			}
		}
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
					unsigned auxheight = 0, auxline = 0, auxcol = 0;
					int fixedNumber = EMPTY;

					fixedNumber = cube[0][line][col];

					auxline = line;
					for(auxcol = 0; auxcol < COLUMNS; auxcol++){
						for(auxheight = 1; auxheight < HEIGHT && cube[auxheight][auxline][auxcol] != EMPTY; auxheight++){
							if(cube[auxheight][auxline][auxcol] == fixedNumber){
								/* down size here */
							}
						}
					}

					auxcol = col;
					for(auxline = 0; auxline < LINES; auxline++){
						for(auxheight = 1; auxheight < HEIGHT && cube[auxheight][auxline][auxcol] != EMPTY; auxheight++){
							if(cube[auxheight][auxline][auxcol] == fixedNumber){
								/* down size here */
							}
						}
					}

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

int main(int argc, char *argv[])
{
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

	lineColumnCleanUp(cube);

	statisticalCleanUp(cube);

	printCube(cube);

	return(0);
}
