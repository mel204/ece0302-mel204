#include <string>
using std::string;

#include <iostream>
#include <stack>
#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);
  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) {

  // TODO
  // length of post string
  size_t postLength = postfix.length();
  
  if (!isoperator(postfix[postLength - 1])) // check if last char is an operator
  {
    prefix = postfix[postLength - 1] + prefix; // if it is not an operator add the number to the front
  } else
  {
    char op = postfix[postLength - 1]; // char to store the operand 

    if (!postfix.empty())
      postfix.pop_back(); // pop the operand from postfix

    convert(postfix, prefix); // recursive call to check the next number


    if (!postfix.empty())
      postfix.pop_back(); // pop a second time to account for two operators in a row

    convert(postfix, prefix); // recursive call to check for any more items in the string

    prefix = op + prefix; // add the operand to make it prefix
  }

}
