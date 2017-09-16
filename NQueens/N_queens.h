//
//  hint.h
//  N Queens Problem
//
//  Created by Ramavarapu Sreenivas on 8/23/16.
//  Written by Zelin Li on 9/7/16
//

#ifndef N_queens
#define N_queens
using namespace std;
class Board
{
    
    // private data member: size of the board
    int size;
    
    // pointer-to-pointer initialization of the board
    int **chess_board;
    
    // private member function:  returns 'false' if
    // the (row, col) position is not safe.
    bool is_this_position_safe(int row, int col)
    {
        // write the appropriate code on your own that returns
        // "true" if the (row,col) position is safe.  If it is
        // unsafe (i.e. some other queen can threaten this position)
        // return "false"
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if((i-j == row - col || i+j == row + col) && chess_board[i][j]==1 && i != row){
                    return false;//check diagonal
                }
                if (chess_board[i][col] == 1 && i != row) {
                    return false;//check column
                }
                if (chess_board[row][j] == 1 && j != col) {
                    return false;//check row
                }
            }
        }
        return true;
    }
    
    // private member function: initializes the (n x n) chessboard
    void initialize(int n)
    {
        size = n;
        chess_board = new int*[size];

        for(int i = 0; i < size; i++){
            chess_board[i] = new int[size];
            for (int j = 0; j < size ; j++) {
                chess_board[i][j] = 0;
            }
        }
        // write the appropriate code that uses the pointer-to-pointer
        // method to initialize the (n x n) chessboard.  Once initialized,
        // put zeros in all entries.  Later on, if you placed a queen in
        // the (i,j)-th position, then chessboard[i][j] will be 1.
    }
    
    // private member function: prints the board position
    void print_board()
    {
        std::cout << size << "-Queens Problem Solution" << std::endl;
        for (int k = 0; k < size; k++) {
            cout<< "---";
        }
        cout<<"\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; ++j) {
                chess_board[i][j] == 0?cout<<" - ":cout<<" Q ";
            }
            cout<<"\n";
        }
        for (int k = 0; k < size; k++) {
            cout<< "---";
        }
        cout<<"\n";
        // write the appropriate code here to print out the solved
        // board as shown in the assignment description
        
    }
    
    // private member function: recursive backtracking
    bool solve(int col)
    {
        // implement the recursive backtracking procedure described in
        // pseudocode format in figure 1 of the description of the first
        // programming assignment
        if(col >= size){
            return true;
        }
        else{
            for (int i = 0; i < size; i++) {
                if(is_this_position_safe(i, col)){
                    chess_board[i][col] = 1;
                    if(solve(col+1)){
                        return true;
                    }
                    else{
                        chess_board[i][col] = 0;
                    }
                }
            }
        }
        return false;
    }
    
public:
    // Solves the n-Queens problem by (recursive) backtracking
    void nQueens(int n)
    {
        initialize(n);
        
        if (solve(0))
            print_board();
        else
            std::cout << "There is no solution to the " << n << "-Queens Problem" << std::endl;
    }
};
#endif
