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

int digit_allowed(int digit, int row, int column, int grid[9][9])
{
    /* this function returns 1 if the proposed digit
    is allowed at position [row][column] in grid, 
    and returns 0 if it is not.
    As inputs it takes the digit to check, the grid, 
    and the row and column location that the digit 
    should be checked for.
    */

    // check row and column
    for (int position = 0; position <= 9; position++)
    {
        // row
        if ((grid[position][column] == digit) && (position != row))
        {
            return (0);
        }
        // column
        if ((grid[row][position] == digit) && (position != column))
        {
            return (0);
        }
    }

    // find indices at which row and column of the box to check start
    int box_row_start = (row / 3) * 3;
    int box_column_start = (column / 3) * 3;
    for (int box_row = 0; box_row <= 3; box_row++)
    {
        for (int box_column = 0; box_column <= 3; box_column++)
        {
            if (
                (grid[box_row_start + box_row][box_column_start + box_column] == digit)
                && (box_row_start + box_row != row)
                && (box_column_start + box_column != column))
                {
                    return (0);
                }
        }
    }

    // all checks passed
    return (1);
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

    // TEMP: check if digit_allowed() works
    printf("%d\n", digit_allowed(9, 8, 8, board));
    



    // this "uses" parameter argc so file compiles
    printf("\nDUMMY VARIABLE %d\n", argc);

    return (0);
}