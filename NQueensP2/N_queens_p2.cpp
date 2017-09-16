// N Queens Problem via (Backtracking, which is implemented by) Recursion Part II
// Created by Prof. Sreenivas
// Written by Zelin Li for IE523: Financial Computing

#include <iostream>
#include "N_queens_p2.h"

int main (int argc, char * const argv[])
{
    Board x;

    int board_size;
    sscanf (argv[1], "%d", &board_size);

    x.nQueens(board_size);

    return 0;
}