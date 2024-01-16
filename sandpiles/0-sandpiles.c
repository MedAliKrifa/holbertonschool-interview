/**
 * distribute_sand - Helper function to distribute sand grains to
 * @grid: Grid to process
 * @i: Row index
 * @j: Column index
 *
 * Return: No Return
 */
void distribute_sand(int grid[3][3], int i, int j)
{
int limit = 3, wall = 2;

if (grid[i][j] > limit)
{
(i - 1) >= 0 ? grid[i - 1][j]++ : 0;
(i + 1) <= wall ? grid[i + 1][j]++ : 0;
(j - 1) >= 0 ? grid[i][j - 1]++ : 0;
(j + 1) <= wall ? grid[i][j + 1]++ : 0;

grid[i][j] -= 4;
}
}

/**
 * toppling - Distributes sand grains
 * @grid: Grid to process
 *
 * Return: No Return
 */
void toppling(int grid[3][3])
{
int i, j, limit = 3;

int grid_tmp[3][3] = {
{0, 0, 0},
{0, 0, 0},
{0, 0, 0}};

for (i = 0; i < limit; i++)
{
for (j = 0; j < limit; j++)
{
distribute_sand(grid_tmp, i, j);
}
}

grid_sum(grid, grid_tmp);
}
