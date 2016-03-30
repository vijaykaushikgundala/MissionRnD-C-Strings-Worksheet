/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void reverse(char *, int, int);
void str_words_in_rev(char *input, int len)
{
	int f = 0, l = len - 1, i;
	reverse(input, f, l);
	for (i = 0; i < len; i++)
	{
		if (input[i] == ' ')
		{
			l = i - 1;
			if (f != l)
			{
				reverse(input, f, l);
			}
			i++;
			f = i;
			l = i;
			break;
		}
	}
	if (i == len)
	{
		reverse(input, f, l);
	}
	while (i<len)
	{
		while (input[l] != ' '&&input[l] != '\0')
		{
			l++;
		}
		if (f != l)
		{
			reverse(input, f, l - 1);
		}
		l++;
		f = l;
		i = l;
	}
}
void reverse(char *str, int f, int l)
{
	int i = f, j = l, temp;
	while (i<j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}
}
