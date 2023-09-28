#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void lines_to_grid(int n_row, char line[9], int grid[9][9])
{
    /* the file gets 9 lines of 9 chars as input, where
    a . represents an empty box. to keep the grid in the 
    file a grid of int's, an empty box is represented 
    with a 0. after running this function on all lines,
    the object board contains the input lines and is 
    ready to use.
    */
    for (int i = 0; i < 9; i++)
    {
        // check if digit
        if ((line[i] > '0') && (line[i] <= '9'))
        {
            grid[n_row][i] = line[i] - 48; 
        }
        else 
        {
            grid[n_row][i] = 0;
        }
    }
}

void print_sudoku(int grid[9][9])
{
    /* this debugging function loops over all present 
    indices and prints them in grid form, for 
    debugging
    */
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            ft_putchar(grid[row][column] + 48);
            ft_putchar(' ');
        }
        ft_putchar('\n');
    }
}

int grid_filled(int grid[9][9])
{
    /* this function checks if there are any open
    spaces left in the provided (9x9) grid. If no
    open spaces are found it returns 1, else 0. 
    */
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                return (0);
            }
        }
    }
    return (1);
}

int solve_sudoku(int grid[9][9])
{
    if (grid_filled(grid) == 1)
    {
        return (1);
    }

    //TODO
}

/* TO RUN COMPILED FILE NAMED "sudoku" (no .out or .exe) PASTE:
./sudoku "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......."
 */
int main(int argc, char **argv)
{
    // initialise array of ints that will serve as board
    int board[9][9];

    // convert all lines that were passed as input to 
    // rows on board
    for (int row = 0; row < 9; row++)
    {
        lines_to_grid(row, argv[row + 1], board);
    }   

    // TEMP: see if input converts correctly
    print_sudoku(board);

    // loop while board is not filled
    while (grid_filled(board) == 0)
    {

    }




    // this "uses" parameter argc so file compiles
    printf("\nDUMMY VARIABLE %d\n", argc);

    return (0);
}