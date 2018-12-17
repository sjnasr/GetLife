#pragma once
#include <iostream>

#define row 8
#define col 8

char input(std::istream& in = std::cin) {
	char x;
	in >> x;
	return x;
}

//Create a function to check neighbors
//return number of neighbors
//should take in a parameter which is the the cell
//r + 1, r - 1
int checkNeighbors(char gameBoard[row][col], int indexRow, int indexCol) {
	//start center
	//[indexRow][indexCol]
	int count = 0;
	for (int i = -1; i <= 1; i++) { //row
		for (int j = -1; j <= 1; j++) { //col
			//if game board [indexRow + i] [indexCol + j] == alive count++
			//indexRow[i]
			//It'll end up checking [0][0], the origin, at some point, use if statement to count against it
			if (!(i == 0 && j == 0)) {
				if (gameBoard[indexRow + i][indexCol + j] == '*')
					count++;
			}
		}
	}

	return count;
}