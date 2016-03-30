/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

int space_positions(char*, int*);
int compare(char*, char*, int, int, int, int);
char ** commonWords(char *str1, char *str2) {
	int len1[10], len2[10], i, j = 0, l1, l2, check, k, p = 0, q, count = 0;
	char **ptr;
	ptr = (char**)malloc(SIZE*sizeof(char));
	for (i = 0; i < 10; i++)
		ptr[i] = (char*)malloc(SIZE*sizeof(char));
	if (str1 == '\0' || str2 == '\0')
		return NULL;
	l1 = space_positions(str1, len1);
	l2 = space_positions(str2, len2);
	for (i = 0; i<l1; i++)
	{
		for (j = 0; j < l2; j++)
		{
			if (str1[len1[i]] == str2[len2[j]])
			{
				check = compare(str1, str2, len1[i], len1[i + 1], len2[j], len2[j + 1]);
				if (check == 1)
				{
					count++;
					q = 0;
					for (k = len1[i]; k < len1[i + 1] - 1; k++)
					{
						ptr[p][q] = str1[k];
						q++;
					}
					ptr[p][q] = '\0';
					p++;
				}
			}
		}
	}
	if (count == 0)
		return NULL;
	return ptr;
}
int space_positions(char *str, int *l)
{
	int i, k = 0;
	l[k] = 0;
	k++;
	for (i = 1; str[i] != '\0'; i++)
	{
		if (str[i] == 32)
		{
			l[k] = i + 1;
			k++;
		}
	}
	l[k] = i + 1;
	//k++;
	return k;
}
int compare(char *str1, char *str2, int a, int b, int i, int j)
{
	if ((b - a) == (j - i))
	{
		while (a < b - 1)
		{
			if (str1[a] == str2[i])
			{
				i++;
				a++;
			}
			else
				return -1;
		}
		return 1;
	}
	else
		return -1;
}