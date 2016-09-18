//============================================================================
// Name        : StringCompression.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : compress string
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


string compString(string str)
{
	//count string.
	string temp;
	int countChar = 0;
	char currentChar = str.at(0);

	for(int i = 0; i < str.size(); i++)
	{
		if(currentChar == str.at(i) )
		{
			countChar++;

			if(i == (str.size() -1) )
			{
				temp.insert(temp.size(), string(1, currentChar) );
				temp.insert(temp.size(), std::to_string(countChar) );
			}

		}
		else
		{
			temp.insert(temp.size(), string(1, currentChar) );
			temp.insert(temp.size(), std::to_string(countChar) );

			//reset currentChar
			currentChar = str.at(i);

			//reset countChar;
			countChar = 1;
		}
	}

	//compare size of string
	if(str.size() > temp.size())
	{
		return temp;
	}
	else
	{
		return str;
	}
}


int main()
{

	//string myStr = "aabcccccaaa";
	string myStr = "aabbccaa";

	cout << compString(myStr) << endl;

	return 0;
}
