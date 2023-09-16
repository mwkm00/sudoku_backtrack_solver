#include <stdio.h>
#include <stdlib.h>

int find_space(int *x, int *y, int board[9][9])
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++){
            if (board[i][j] == 0){
                *x = i;
                *y = j;
                return 1;
            }
        }
    return 0;
}

int check_valid(int x, int y, int number, int board[9][9]){
    for (int i = 0; i < 9; i++) //row and col
    {
        if (board[i][y] == number && x != i)
            return 0;
        if (board[x][i] == number && y != i)
            return 0;
    }

    for (int i = (x/3)*3; i < ((x/3)*3)+3; i++) //check 3x3 box
        for (int j = (y/3)*3; j < ((y/3)*3)+3; j++){
            if (board[i][j] == number && (i != y && j != x)){
                return 0;
            }
        }
    return 1;
}

void print_sudoku(int board[9][9]){
    int i, j;
    printf("---------------------------\n");
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++){
            if (j%3 == 0){
                printf(" | ");
            }
            printf("%i ", board[i][j]);
        }
        printf("|");
        if (i%3 == 2){
            printf("\n---------------------------\n");
        }
        else{
            printf("\n");
        }
    }
    printf("\n");
    return;
}

int solve(int board[9][9]){
    int x, y;
    int found = find_space(&x, &y, board);
    if (!found){
        return 1;
    }
    for (int i = 1; i < 10; i++)
    {
        if (check_valid(x,y,i,board)){
            board[x][y] = i;
            if (solve(board))
                return 1;
            board[x][y] = 0;
        }
    }
    return 0;
}

int main(int argc, char *argv[]){
    int board[9][9] = { //example hard board
        {0,0,0,0,0,0,0,1,0},
        {4,0,0,0,0,0,0,0,0},
        {0,2,0,0,0,0,0,0,0},
        {0,0,0,0,5,0,4,0,7},
        {0,0,8,0,0,0,3,0,0},
        {0,0,1,0,9,0,0,0,0},
        {3,0,0,4,0,0,2,0,0},
        {0,5,0,1,0,0,0,0,0},
        {0,0,0,8,0,6,0,0,0}
    };
    solve(board);
    print_sudoku(board);
    return 0;
}