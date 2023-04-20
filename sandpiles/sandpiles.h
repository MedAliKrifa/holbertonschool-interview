#ifndef __SANDPILES__LIB__
#define __SANDPILES__LIB__
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void printSandpile(int grid[3][3]);
int isStable(int grid[3][3]);
void topple(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
#endif