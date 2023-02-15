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

  std::stack<string> s;
 
 for (int i = 0; i < postLength; i++)
  
  if (isoperator(postfix[i]))
  {
    //pop two operands
    std::string op1 = s.top();
    s.pop();
    std::string op2 = s.top();
    s.pop();

    std::string temp = postfix[i] + op1 + op2;

    //push string back to stack

    s.push(temp);

  } else
  {
    s.push(string(1, postfix[i]));
  }

  while (!s.empty())
  {
    prefix += s.top();
    s.pop();
  }

}
