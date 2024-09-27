#include "sandpiles.h"
#include <stdio.h>

void print_grid(int grid[3][3]);
int is_stable(int grid[3][3]);
void topple(int grid[3][3]);

/**
 * sandpiles_sum - Computes the sum of two 3x3 sandpiles
 * @grid1: First sandpile
 * @grid2: Second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    /* Add grid1 and grid2 */
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid1[i][j] += grid2[i][j];

    /* Stabilize the resulting sandpile */
    while (!is_stable(grid1))
    {
        print_grid(grid1);
        topple(grid1);
    }
}

/**
 * is_stable - Checks if a sandpile is stable
 * @grid: The 3x3 sandpile
 * Return: 1 if stable, 0 if not
 */
int is_stable(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (grid[i][j] > 3)
                return (0);
    return (1);
}

/**
 * topple - Topples a 3x3 sandpile
 * @grid: The 3x3 sandpile
 */
void topple(int grid[3][3])
{
    int i, j;
    int temp[3][3] = {0};

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                temp[i][j] -= 4;
                if (i - 1 >= 0)
                    temp[i - 1][j]++;
                if (i + 1 < 3)
                    temp[i + 1][j]++;
                if (j - 1 >= 0)
                    temp[i][j - 1]++;
                if (j + 1 < 3)
                    temp[i][j + 1]++;
            }
        }

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid[i][j] += temp[i][j];
}

/**
 * print_grid - Prints a 3x3 sandpile grid
 * @grid: The 3x3 grid to print
 */
void print_grid(int grid[3][3])
{
    int i, j;

    printf("=\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j > 0)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
