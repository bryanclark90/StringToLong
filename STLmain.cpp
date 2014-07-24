//Programmer: Bryan K Clark
//Email: bryan.clark@email.wsu.edu
//Phone: (509)294-4161

#include <iostream>
#include <stdio.h>
#include "StringtoLong.h"
using namespace std;

int main(void)
{
	//char* string = "0";
	long value;
	 
	//arbitray value to convert
	value = stringToLong("123");
	if(value != -1)
	{
		cout << "123 was converted to " << value << endl;
	}
	//arbitray value to convert
	value = stringToLong("5892");
	if(value != -1)
	{
		cout << "5892 was converted to " << value << endl;
	}
	//value outside parameters for a LONG
	value = stringToLong("2147483648");
	if(value > -1)
	{
		cout << "2147483648 was converted to " << value << endl;
	}
	cout << "Press enter to exit!" << endl;
	cin.get();
	return 0;
}

//returns a long from an input string
long stringToLong(const char* s)
{
	//a key to check string inputs against
	const char* values = "0123456789";
	//final output
	int result = 0;
	int digits = 0;
	//for each character in the string
	for(; *s; ++s)
	{
		//find the associated value of the digit
		for(digits = 0; values[digits]; ++digits)
		{
			//once you find the location break the loop
			if(values[digits] == *s)
			{
				break;
			}
		}
		//if a # between 0-9
		if(values[digits])
		{
			//starting at left most position you would
			//multiply by 10 and add the new number to get
			//the current value
			result = 10 * result + digits;
			//throw exception if not a valid LONG
			if((result > 2147483647)||(result < -2147483647))
			{
				cout << "ERROR: A long cannot be that big!\n" << endl;
				result = -1;
				break;
			}
		}

	}
	return result;
}
