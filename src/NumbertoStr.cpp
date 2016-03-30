/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str, int afterdecimal){

	int ipart = 0, t = 1;
	int fpart = 0, index = 0, lenght = 0, point = 0, temp = 0;
	if (number < 0)
	{
		str[0] = '-';
		str++;
		number = number*-1;
	}
	ipart = number;
	for (int i = 0; i < afterdecimal; i++)
	{
		t *= 10;
	}
	fpart = (number - ipart)*t;
	temp = ipart;
	while (temp)
	{
		lenght++;
		temp = temp / 10;
	}
	printf("%d\n", lenght);
	point = lenght;
	while (ipart)
	{
		index = lenght;
		str[index - 1] = ipart % 10 + '0';
		lenght--;
		ipart = ipart / 10;
	}
	if (fpart > 0)
	{

		str[point] = '.';
		index = point + afterdecimal;
		str[index + 1] = '\0';
		while (fpart)
		{
			str[index] = fpart % 10 + '0';
			index--;
			fpart = fpart / 10;
		}
	}
}

