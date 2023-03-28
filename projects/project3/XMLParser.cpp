// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	tokenized = false;
	parsed = false;

	parseStack = new Stack<std::string>;
	elementNameBag = new Bag<std::string>;

}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
	clear();
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	// invalid if it doesn't start or end with a tag
	if(inputString.at(0) != '<' || inputString.at(inputString.length() - 1) != '>')
	{
		return false;
	}	

	// index to keep location in the input string
	size_t i = 0;
	size_t numStartTag = 0;
	while ( i < inputString.length() - 1)
	{
		// content temp token string
		std::string tokenC = "";

		// skip over spaces in content
		if(inputString.at(i) == ' ') { i++; }
		// if its not a start angle bracket then its content
		else if(inputString.at(i) != '<')
		{
			// create token struct object to store token
			TokenStruct content;
			content.tokenType = CONTENT;

			while(inputString.at(i) != '<')
			{
				if((inputString.at(i) == '>' || i == inputString.length()) && numStartTag == 0)
				{
					tokenizedInputVector.clear();
					return false;
				}
				// add characters to temp string
				tokenC += inputString.at(i);
				i++;
			}

			content.tokenString = tokenC;
			tokenizedInputVector.push_back(content);
		}
		else // if its not content then its markup which can be ( declaration, start tag or empty tag, or an end tag )
		{
			i++;
			// declaration temp token string
			std::string tokenD;

			// if theres a ? then its a declaration
			if(inputString.at(i) == '?')
			{
				TokenStruct declaration;
				declaration.tokenType = DECLARATION;

				i++;
				size_t findDeclaration;
				findDeclaration = inputString.find("?>", i);

				//if end of declaration doesn't exist then clear and return
				if(findDeclaration == -1)
				{
					tokenizedInputVector.clear();
					return false;
				}

				for( int j = i; j < findDeclaration; j++)
				{
					tokenD += inputString.at(j);
				}

				i = findDeclaration + 1;

				declaration.tokenString = tokenD;
				tokenizedInputVector.push_back(declaration);

			} else if(inputString.at(i) == '/')
			{
				TokenStruct endTag;
				endTag.tokenType = END_TAG;

				size_t findEndTag;
				findEndTag = inputString.find(">",i);

				//string for end tag
				std::string tokenEn;
				i++;

				// validate all characters

				for( int j = i; j < findEndTag; j++)
				{
					char valid = inputString.at(j);

					if( valid > 122 || valid == 96 || (valid > 90 && valid < 95) || (valid > 58 && valid < 65) || valid == 47 || valid < 45 )
					{
						// char is invalid
						tokenizedInputVector.clear();
						return false;
					}

					tokenEn += valid;

				}
				i = findEndTag + 1;

				endTag.tokenString = tokenEn;
				tokenizedInputVector.push_back(endTag);

				} else
				{
				//could be start or empty tag
				//find end of tag

				size_t findEnd = inputString.find(">", i);

				// also find spaces 
				size_t findSpace = inputString.find(" ", i);
				

				if(findEnd == -1)
				{
					tokenizedInputVector.clear();
					return false;
				}

				if(inputString.at(findEnd - 1) == '/')
				{
					TokenStruct emptyTag;
					emptyTag.tokenType = EMPTY_TAG;

					size_t findName = findEnd - 2; // for empty tag

					//temp string for empty tag
					std::string tokenEm;
					if(findSpace != -1 && findSpace < findEnd)
					{
						findName = findSpace - 1;
					}

					for ( int j = i; j <= findName; j++)
					{
						char valid = inputString.at(j); 
						if( valid > 122 || valid == 96 || (valid < 95 && valid > 99) || (valid < 65 && valid > 58) || valid == 47 || valid < 45)
						{
							tokenizedInputVector.clear();
							return false;
						}

						tokenEm += valid;
						
					}

					i = findEnd + 1;

					emptyTag.tokenString = tokenEm;
					tokenizedInputVector.push_back(emptyTag);

				} else 
				{

					TokenStruct startTag;
					startTag.tokenType = START_TAG;

					// temp string for start tag
					std::string tokenS = "";

					size_t findName = findEnd - 1;
					if(findSpace != -1 && findSpace < findEnd)
					{
						findName = findSpace - 1;
					}

					for (int j = i; j <= findName; j++)
					{
						char valid = inputString.at(j); 
						if( valid > 122 || valid == 96 || (valid < 95 && valid > 99) || (valid < 65 && valid > 58) || valid == 47 || valid < 45)
						{
							tokenizedInputVector.clear();
							return false;
						}

						tokenS += valid;
					}

					numStartTag++;
					i = findEnd + 1;

					startTag.tokenString = tokenS;
					tokenizedInputVector.push_back(startTag);
				}

			}

		}

	}
	tokenized = true;

	return tokenized;
}  // end

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	size_t numEndTags = 0;
	size_t numStartTags = 0;
	bool check;
	


	for(size_t i = 0; i < tokenizedInputVector.size() - 1; i++)
	{
		// if the type is content empty or end tag and there are no start tags then it fails
		if(tokenizedInputVector[i].tokenType == (CONTENT || EMPTY_TAG || END_TAG) && (numStartTags == 0))
		{
			return false;
		}
		// push start tags to stack and add element name to the bag
		if(tokenizedInputVector[i].tokenType == START_TAG)
		{
			parseStack->push(tokenizedInputVector[i].tokenString);
			elementNameBag->add(tokenizedInputVector[i].tokenString);
			numStartTags++;
		}
		// peek the end tag first to check if its the same as the corresponding start tag, else return false
		if(tokenizedInputVector[i].tokenType == END_TAG)
		{
			check = (tokenizedInputVector[i].tokenString == parseStack->peek());
			if(check)
			{
				parseStack->pop();
			} else
			{
				return false;
			}
		}

	}
	// if parse stack is empty then there were too many start tags
	if(!parseStack->isEmpty())
	{
		return false;
	}

	parsed = true;

	return parsed;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	tokenizedInputVector.clear();
	elementNameBag->clear();
	parseStack->clear();

	tokenized = false;
	parsed = false;
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	if(!tokenized || !parsed)
	{
		throw std::logic_error("Not tokenized or parsed");
	}
	
	return elementNameBag->contains(inputString);
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	if(!tokenized || !parsed)
	{
		throw std::logic_error("Not tokenized or parsed");
	}
	
	return elementNameBag->getFrequencyOf(inputString);
}

