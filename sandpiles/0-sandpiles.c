#include "sandpiles.h"
/**
 * printSandpile - function to print the sandpile
 * @grid: 2D array 3*3
 *
 */
void printSandpile(int grid[3][3])
{
printf("Sandpile:\n");
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
printf("%d ", grid[i][j]);
}
printf("\n");
}
printf("\n");
}


/**
 * isStable - function to check if the sandpile is stable
 * @grid: 2D array 3*3
 * Return: 0
 */
int isStable(int grid[3][3])
{
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
if (grid[i][j] > 3)
{
return (0);
}
}
}
return (1);
}

/**
 * topple - function to topple the sandpile
 * @grid: 2D array 3*3
 *
 */
void topple(int grid[3][3])
{
int temp[3][3];
memcpy(temp, grid, sizeof(temp));
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
if (temp[i][j] > 3)
{
grid[i][j] -= 4;
if (i - 1 >= 0)
{
grid[i - 1][j]++;
}
if (i + 1 < 3)
{
grid[i + 1][j]++;
}
if (j - 1 >= 0)
{
grid[i][j - 1]++;
}
if (j + 1 < 3)
{
grid[i][j + 1]++;
}
}
}
}
}

/**
 * sandpiles_sum - function to compute the sum of two sandpiles
 * @grid1: 2D array 3*3
 * @grid2: 2D array 3*3
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
grid1[i][j] += grid2[i][j];
}
}


while (!isStable(grid1))
{
printSandpile(grid1);
topple(grid1);
}
printSandpile(grid1);
}
