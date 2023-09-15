#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge(int *array, int *left, int left_size, int *right, int right_size);
void merge_sort(int *array, size_t size);
#endif /* SORT_H */