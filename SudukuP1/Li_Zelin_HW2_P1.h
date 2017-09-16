/*
 *  sudoku.h
 *  Sudoku
 *  Created by Prof. Ramavarapu Sreenivas 
 *  Inspired by: http://web.eecs.utk.edu/courses/spring2012/cs140/Notes/Sudoku/index.html
 *  Written by Zelin Li
*/

#ifndef sudoku
#define sudoku

#include <vector>
#include <fstream>
#include <set>//use set to implement the concept of Hashtable
using std::vector;
using namespace std;
class Sudoku 
{ 
	// Private
	int puzzle[9][9];
	
	// Private member function that checks if the named row is valid
	bool row_valid(int row)
	{
		// write code that checks if "row" is valid
		//using the concept of Hashset in Java
		set<int>s;//create a set
        int count = 0;

		for (int i = 0; i < 9; ++i) {
            if(puzzle[row][i] != 0) {
                s.insert(puzzle[row][i]);
                count++;
            }
		}
		return s.size()==count;//set will not contain any duplicate element
	}
	
	// Private member function that checks if the named column is valid
	bool col_valid(int col)
	{
		// check validity of "col"
		set<int>s;
        int count = 0;

		for (int i = 0; i < 9; ++i) {
            if(puzzle[i][col] != 0) {
                s.insert(puzzle[i][col]);
                count++;
            }
		}
		return s.size()==count;
	}
	
	// Private member function that checks if the named 3x3 block is valid
	bool block_valid(int row, int col)
	{
		// check 3 x 3 block validity
		set<int>s;
        int count = 0;
        int m = row/3*3;
        int n = col/3*3;

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
                if(puzzle[m+i][n+j] != 0) {
                    s.insert(puzzle[m+i][n+j]);
                    count++;
                }
			}
		}
		return s.size()==count;

	}
	
public:
	// Public member function that reads the incomplete puzzle
	// we are not doing any checks on the input puzzle -- that is,
	// we are assuming they are indeed valid
	void read_puzzle(int argc, char * const argv[])
	{
		// write code that reads the input puzzle using the 
		// guidelines of figure 23 of the bootcamp material
		vector <int> read;
		int read_value;

		ifstream input(argv[1]);
		if(input.is_open()){
			while(input >> read_value){
				read.push_back(read_value);
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				puzzle[i][j] = read[i*9+j];
			}
		}
        cout<<"Input File Name: "<<argv[1]<<endl;
	}
	
	// Public member function that prints the puzzle when called
	void print_puzzle()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				// check if we have a legitimate integer between 1 and 9
				if ((puzzle[i][j] >= 1) && (puzzle[i][j] <= 9))
				{
					// printing initial value of the puzzle with some formatting
					std::cout << puzzle[i][j] << " ";
				}
				else {
					// printing initial value of the puzzle with some formatting
					std::cout << "X ";
				}
			}
			std::cout << std::endl;
		}
	}
	
	// Public member function that (recursively) implements the brute-force 
	// search for possible solutions to the incomplete Sudoku puzzle
	bool Solve(int row, int col)
	{
		// this part of the code identifies the row and col number of the 
		// first incomplete (i.e. 0) entry in the puzzle.  If the puzzle has
		// no zeros, the variable row will be 9 => the puzzle is done, as 
		// each entry is row-, col- and block-valid...
		
		// use the pseudo code of figure 3 of the description
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {//bug occurs here
				if((i > row || (i == row && j > col) || (i == 0 && j == 0)) && puzzle[i][j] == 0){//find 0 entry after i, j.
                    //Be careful! The (0,0) entry can be 0!
					for (int k = 1; k <= 9; ++k) {
						puzzle[i][j] = k;
						if(row_valid(i) && col_valid(j) && block_valid(i, j) && Solve(i, j)){
							return true;
						}
					}
                    puzzle[i][j] = 0;
                    return false;
				}

			}
		}
		return true;
	}
};

#endif