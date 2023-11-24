#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * allWordsCovered - Helper function to check if all words are covered in the substring
 * @wordCount: Array containing the count of each word
 * @nb_words: Number of words in the array
 * Return: 1 if all words are covered, 0 otherwise
 */
int allWordsCovered(int *wordCount, int nb_words)
{
for (int i = 0; i < nb_words; i++)
{
if (wordCount[i] > 0)
{
return 0;
}
}
return 1;
}

/**
 * find_substring - Find all possible substrings containing a list of words within a given string
 * @s: The string to scan
 * @words: Array of words all substrings must be a concatenation arrangement of
 * @nb_words: Number of elements in the array words
 * @n: Address at which to store the number of elements in the returned array
 *
 * Return: Allocated array storing each index in s at which a substring was found,
 *         or NULL if no solution is found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
if (!s || !words || nb_words <= 0)
{
return NULL;
}

int wordLength = strlen(words[0]);
int totalLength = strlen(s);
int *result = NULL;
int resultSize = 0;

int *wordCount = (int *)calloc(nb_words, sizeof(int));
if (!wordCount)
{
return NULL; // Memory allocation failed
}

int *prevWordCount = (int *)calloc(nb_words, sizeof(int));
if (!prevWordCount)
{
free(wordCount);
return NULL; // Memory allocation failed
}

for (int i = 0; i <= totalLength - nb_words * wordLength; i++)
{
memcpy(prevWordCount, wordCount, nb_words * sizeof(int));

int j;
for (j = 0; j < nb_words; j++)
{
int wordIndex = i + j * wordLength;
char *currentWord = (char *)malloc((wordLength + 1) * sizeof(char));
strncpy(currentWord, s + wordIndex, wordLength);
currentWord[wordLength] = '\0';

int k;
for (k = 0; k < nb_words; k++)
{
if (strcmp(currentWord, words[k]) == 0)
{
if (prevWordCount[k] == 0)
{
break;
}
else
{
break;
}
}
}

free(currentWord);

if (k == nb_words || prevWordCount[k] > 0)
{
break;
}

wordCount[k]++;
}

if (j == nb_words && allWordsCovered(prevWordCount, nb_words))
{
result = (int *)realloc(result, (resultSize + 1) * sizeof(int));
result[resultSize] = i;
resultSize++;
}
}

free(wordCount);
free(prevWordCount);

*n = resultSize;

return result;
}
