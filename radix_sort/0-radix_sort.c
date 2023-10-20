#include "sort.h"
/**
 * getMax - function to get maximum value in arr
 * @array: arry to be sorted.
 * @n: size of array
 * Return: max
 */
int getMax(int *array, int n)
{
int mx = array[0];
int i;

for (i = 1; i < n; i++)
if (array[i] > mx)
mx = array[i];
return (mx);
}
/**
 * countSort - to do counting sort of arr
 * @array: arry to be sorted.
 * @n: size of array
 * @div: expectued number
 */
void countSort(int *array, int n, int div)
{

int *freq;
int *temp;
int init, count, u, t, f;

freq = malloc(sizeof(int) * (10));
if (!freq)
return;
for (init = 0; init < 10; init++)
freq[init] = 0;
for (count = 0; count < n; count++)
freq[(array[count] / div) % 10]++;
for (u = 1; u < 10; u++)
freq[u] += freq[u - 1];
temp = malloc(sizeof(int) * (n));
if (!temp)
{
free(freq);
return;
}
/* Building the temporary array. */
for (t = n - 1; t > -1; t--)
{
temp[freq[(array[t] / div) % 10] - 1] = array[t];
freq[(array[t] / div) % 10]--;
}
/* Updating the elements in array. */
for (f = 0; f < n; f++)
array[f] = temp[f];
free(temp);
free(freq);
}
/**
 * radix_sort - function that sorts an array of integers in ascending order
 * @array: arry to be sorted.
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
int exp;
int m = getMax(array, size);

if (!array || size < 2)
return;

for (exp = 1; m / exp > 0; exp *= 10)
{
countSort(array, size, exp);
print_array(array, size);
}
}
