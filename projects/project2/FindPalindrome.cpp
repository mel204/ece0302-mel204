#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i]);
	}
}

// sentence to string funtion

std::string sentenceToString(string & value)
{
	convertToLowerCase(value);
	for (int i = 0; i < value.size(); i++)
	{
		if(value[i] == ' ')
		{
			value[i] = value[i+1];
		}
	}
	
	return value;
}

// vector to string function

std::string vectorToString(std::vector<std::string> stringVector)
{
	std::string longString = "";

	for (int i = 0; i < stringVector.size(); i++)
	{
		std::string thisString = stringVector.at(i);
		convertToLowerCase(thisString);
		longString += thisString;
	}


	return longString;
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	if(!cutTest2(candidateStringVector, currentStringVector)){}
	else if (currentStringVector.size() == 0)
	{
		// convert vector to string
		std::string temp = vectorToString(candidateStringVector);

		// check for palindrome
		if (isPalindrome(temp))
		{
			numPal++;
			solutions.push_back(candidateStringVector);
		}

	} else
	{
		/////////////////////////////////////////////////////////////////////////
		// TODO need to implement this recursive function!

		//iterate through to move current string

		for (int i = 0; i < currentStringVector.size(); i++)
		{
			// temp variables to keep values of current and candidate string vectors
			std::vector<std::string> tempCandidate = candidateStringVector;
			std::vector<std::string> tempCurrent = currentStringVector;

			// move first string to candidate vector
			tempCandidate.push_back(tempCurrent.at(i));

			// remove string moved to candidate
			tempCurrent.erase(tempCurrent.begin() + i);
			
			recursiveFindPalindromes(tempCandidate, tempCurrent);
			
		}

	}
	
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	// TODO need to implement this...
	clear();
}

FindPalindrome::~FindPalindrome()
{
	// TODO need to implement this...
	clear();
}

int FindPalindrome::number() const
{
	// TODO need to implement this...
	return numPal;
}

void FindPalindrome::clear()
{
	// TODO need to implement this...
	palindrome.clear();
	solutions.clear();
	numPal = 0;
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	// TODO need to implement this...
	// create temp string and array to hold test value

	std::string temp = vectorToString(stringVector);	
	int temparr[26];

	// initialize to zero

	for (int i = 0; i < 26; i++)
	{
		temparr[i] = 0;
	}

	// count amount of times each letter appears

	for (int i =  0; i < temp.length(); i++)
	{
		++temparr[temp[i] - 97]; // sub 97 makes lowercase a 0 in the array
	}

	// checking for odd indicies 

	int flag = 2;

	for (int i = 0; i < 26; i++)
	{
		// if there is an odd its fine but if there is another one then return false
		if(temparr[i] % 2 == 1) // one odd
		{
			if(!(--flag)) // two odd
			{
				return false;
			}
		}
	}

	return true;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	std::string lowerHalf;
	std::string upperHalf;
	std::string tempS1 = vectorToString(stringVector1);
	std::string tempS2 = vectorToString(stringVector2);

	// find the bigger string

	if(tempS1.length() <= tempS2.length())
	{
		lowerHalf = tempS1;
		upperHalf = tempS2;
	} else
	{
		lowerHalf = tempS2;
		upperHalf = tempS1;
	}

	// create temp arrays to hold integers of letters

	int temparr1[26];
	int temparr2[26];

	// initialize temp arrays to 0

	for(int i = 0; i < 26; i++)
	{
		temparr1[i] = 0;
		temparr2[i] = 0;
	}

	// count amount of times each letter appears in lower half

	for (int i =  0; i < lowerHalf.length(); i++)
	{
		++temparr1[lowerHalf[i] - 97]; // sub 97 makes lowercase a 0 in the array
	}

	// count amount of times each letter appears in upper half

	for (int i =  0; i < upperHalf.length(); i++)
	{
		++temparr2[upperHalf[i] - 97]; // sub 97 makes lowercase a 0 in the array
	}

	// check if letter appears more times in the lower half

	for (int i = 0; i < 26; i++)
	{
		if(temparr1[i] > temparr2[i]) // if appears more times in smaller half, then false
		{
			return false;
		}
	}

	// return true if it passes the test

	return true;
}

bool FindPalindrome::add(const string & value)
{
	//variable to check if parameter is valid
	bool valid = true;

	//temp string

	std::string str = "";

	// TODO need to implement this...
	for (int i = 0; i < value.length(); i++)
	{
		if ((value.at(i) >= 65 && value.at(i) <= 90) || (value.at(i) >= 97 && value.at(i) <= 122))
		{
			str += char(value.at(i));
		} else
		{
			return false;
		}
	}

	//check for duplicates

	for (int i = 0; i < palindrome.size(); i++)
	{
		std::string str2 = palindrome.at(i);
		convertToLowerCase(str2);
		if(str == str2)
		{
			return false;
		}
	}

	// if all letters are valid, make string vector equal to palindrome

	if(valid)
	{ palindrome.push_back(value); }

	// check to see if palindrome string vector is a palindrome every time a string is added

	palindrome.clear();
	numPal = 0;

	if (cutTest1(palindrome))
	{			
		std::vector<std::string> tempStringVector;
		recursiveFindPalindromes(tempStringVector, palindrome);
	}

	return valid;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	// test for valid cahracter
	// test for existing duplicates
	// test whether a word already exists in teh bag
	// if the vector of strings is valid, add to the vector (push_back())



	//variable to check if parameter is valid
	bool valid = true;
	//variable to store vector as string
	std::string value = vectorToString(stringVector);

	// TODO need to implement this...

	// validate characters
	for (int i = 0; i < stringVector.size(); i++)
	{
		if (value.at(i) < 'a' || value.at(i) > 'z')
		{
			return false;
		}
	}

	// check for duplicates

	for (int i = 0; i < stringVector.size(); i++)
	{
		for (int j = 0; j < stringVector.size(); j++)
		{
			std::string s1 = stringVector[i];
			std::string s2 = stringVector[j];

			convertToLowerCase(s1);
			convertToLowerCase(s2);

			if(s1 == s2)
			{
				return false;
			}

		}
	}

	for (int i = 0; i < palindrome.size(); i++)
	{
		for (int j = 0; j < stringVector.size(); j++)
		{
			std::string s1 = palindrome[i];
			std::string s2 = palindrome[j];

			convertToLowerCase(s1);
			convertToLowerCase(s2);


			if(s1 == s2)
			{
				return false;
			}
		}
	}

	palindrome.clear();
	numPal = 0;


	// if all letters are valid, make string vector equal to palindrome

	if(valid)
	{ 
		for (int i = 0; i < stringVector.size(); i++)
		{
			palindrome.push_back(stringVector.at(i));
		}
	}

	// check to see if palindrome string vector is a palindrome every time a vector is added

	std::vector<std::string> tempStringVector;

	if (cutTest1(palindrome))
	{
		recursiveFindPalindromes(tempStringVector, palindrome);
	}

	return valid;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	return solutions;
}

