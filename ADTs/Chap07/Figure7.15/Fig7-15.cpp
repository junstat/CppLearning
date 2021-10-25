#include <iostream>
#include <string>
#include <cassert>
#include <cctype>

using namespace std;
/*
NOTE: Enter # for infix expression to stop.

Infix expression? alpha + beta
Postfix expression is  alpha beta +

Infix expression? alpha * beta + 123
Postfix expression is  alpha beta * 123 +

Infix expression? alpha * (beta + 123)
Postfix expression is  alpha beta 123 + *

Infix expression? (a + b) * (c / (d - e))
Postfix expression is  a b + c d e - / *

Infix expression? a - (b - (c - (d - (e - f ))))
Postfix expression is  a b c d e f - - - - -

Infix expression? a - b - c - d - e - f
Postfix expression is  a b - c - d - e - f -

Infix expression? (a * (b - c)
Postfix expression is  *** Error in infix expression ***
 a b c - *

Infix expression? #
 */
#include "DStack.h"

string postfix(string exp);

int main()
{
  string infixExp;
  cout << "NOTE: Enter # for infix expression to stop.\n";
  for (;;)
  {
    cout << "\nInfix expression? ";
    getline(cin, infixExp);

    if (infixExp == "#") break;

    cout << "Postfix expression is " << postfix(infixExp) << endl;
  }
}

string postfix(string exp)
{
  char token,         // character in exp
  topToken;      // token on top of opStack
  Stack opStack;      // stack of operators
  string postfixExp;    // postfix expression
  const string BLANK = " ";
  for (int i = 0; i < exp.length(); i++)
  {
    token = exp[i];
    switch (token)
    {
      case ' ':
        break;
      case '(':
        opStack.push(token);
        break;
      case ')':
        for (;;)
        {
          assert(!opStack.empty());
          topToken = opStack.top();
          opStack.pop();
          if (topToken == '(') break;
          postfixExp.append(BLANK + topToken);
        }
        break;
      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
        for (;;)
        {
          if (opStack.empty() ||
              opStack.top() == '(' ||
              (token == '*' || token == '/' || token == '%') &&
              (opStack.top() == '+' || opStack.top() == '-'))
          {
            opStack.push(token);
            break;
          }  // end of if
          else
          {
            topToken = opStack.top();
            opStack.pop();
            postfixExp.append(BLANK + topToken);
          } // end of else
        }  // end of for
        break;
      default: // operand
        postfixExp.append(BLANK + token);
        for (;;)
        {
          if (!isalnum(exp[i + 1])) break;    // end of identifier
          i++;
          token = exp[i];
          postfixExp.append(1, token);
        }
    }  // end of switch
  }
  // pop remaining operators on the stack
  for (;;)
  {
    if (opStack.empty()) break;
    topToken = opStack.top();
    opStack.pop();
    if (topToken != '(')
      postfixExp.append(BLANK + topToken);
    else
    {
      cout << " *** Error in infix expression ***\n";
      break;
    }
  }
  return postfixExp;
}