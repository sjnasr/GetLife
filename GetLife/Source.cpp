/*int *arr[][]
**Status = alive or dead
**enum{DEAD, ALIVE}
**Starting grid/configuration
**for each cell call check neighbors  function
**Check neighbors function
***Check if neighbors are horizonal, vertical or diagonally
***return number of neighbors
**Create new blank board
**Check rules, depends on number of neighbors
***Update new board
**

Step 1:
load in our seed

Step 2:
Create new board for next generation

Step 3:
Loop through old board
Check each cell for neighbors
Apply the rules
Update the new board

Step 4:
Check if board is empty or stablize

Step 5:
Copy over new board to old board

Pause between each board

Loop back to step 2



**Checking neighbors function
***[row] [column]
***example [10][10], we're at [4][5]
***1 2 3 4 5 6 7 8 9 10
***[3][5] Vertical Up
***[5][5] Vertical Down
***[4][6] Horizontal right
***[4][4] Horizontal left
***[5][6] Diagonal right down
***[3][4] Diagonal left up
***[3][6] Diagonal right up
***[5][4] Diagonal left down
***+1, -1, 0, cycling
***pivot point
***order pair
***outer loop row
***inner loop column
****add 1, subtract 1, 0
row + 1, row - 1, col + 1, col - 1

0 1 2
3 4 5
6 7 8

make matrix 2 large than it has to be, 2 extra rows and 2 extra columns
extra row and column at each side
int index = 0;
top left [0][0]
top top [0][1]
*/

#include "GetLife.h"
#include <thread> 
#include <chrono>  

using namespace std;

/*Test Seed:
(*) = alive
. = Dead


......
..**..
.*..*.
..**..
......
.*...*

*/

int main() {

	//board deminisions 6x6
	char board[row][col];

	//Step 1
	//Load in our seed

	//Create a grid board, rows and columns
	for (auto i = 1; i < row - 1; i++) { //number of rows
		for (auto j = 1; j < col - 1; j++) { //number of columns
			board[i][j] = input();
		}
	}

	//Step 2
	//Create new board
	char newBoard[row][col]; //new board for the next generation

	//Step 3
	//Loop through the old board;

	/*While loop*/
	//call check neighbor
	//do I need to pass in every cell?
	//Function to initialize new board
	//Function to copy over data from new board to old board
	//Have it print new array
	
	int neighborCount = 0;
	while (true) {
		for (auto i = 0; i < row; i++) {
			for (auto j = 0; j < col; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}

		/*Get the starting origin then pass them into checkNeighbor*/
		/*Use a for loop to loop through the board start with 0, 0
		**A nested loop, i, j to pass in*/

		for (int i = 1; i < row - 1; i++) { //row
			for (int j = 1; j < col - 1; j++) { //col
				neighborCount =  checkNeighbors(board, i, j);
				
				/*Add rules here?
				Any live cell with fewer than two live neighbors dies, as if by underpopulation.
				Any live cell with two or three live neighbors lives on to the next generation.
				Any live cell with more than three live neighbors dies, as if by overpopulation.
				Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.*/
				//update the new board
				if (neighborCount < 2) 
				{
					//dead
					newBoard[i][j] = '.';
				}
				else if (neighborCount == 2 || neighborCount == 3)
				{
					//Alive
					newBoard[i][j] = '*';
				}
				else if (neighborCount > 3) 
				{
					//Dead
					newBoard[i][j] = '.';
				} 

			}
		}
		//Step 4:
		//Check if board is empty or stablize
		for (int i = 1; i < row - 1; i++)
		{
			for (int j = 1; j < col - 1; j++)
			{
				//if 
			}
		}

		//Step 5:
		//Copy over new board to old board
		for (int i = 1; i < row - 1; i++)
		{
			for (int j = 1; j < col - 1; j++)
			{
				board[i][j] = newBoard[i][j];
			}
		}

		this_thread::sleep_for(chrono::seconds(2));
		//break;

	}
	return 0;
}