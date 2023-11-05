#include "stacktype.cpp"
#include <string>
#include <iostream>

using namespace std;

string infixToPostfix(string);
double evaluatePostfix(string);

bool isDigit(char);
bool isOperator(char);
int operatorPrecedence(char);
double calculate(double, char, double);

int main()
{
    cout << "Enter an infix arithmatical expression: ";
    string infix;
    getline(cin >> ws, infix);

    try
    {
        cout << evaluatePostfix((infixToPostfix(infix))) << endl;
    }
    catch (EmptyStack& e)
    {
        cout << "Invalid expression"<< endl;
    }
    catch (exception& e)
    {
        cout << "Invalid expression"<< endl;
    }

    return 0;
}

string infixToPostfix(string infix)
{
    string postFix = "";
    StackType<char> opStack;
    char symbol;

    for (int i = 0; infix[i]; ++i)
    {
        symbol = infix[i];

        if (symbol == ' ')
        {
            continue;
        }
        else if (isDigit(infix[i]))
        {
            while (isDigit(infix[i + 1]))
            {
                postFix += infix[i];
                symbol = infix[++i];
            }

            postFix += infix[i];
            postFix += ' ';
        }
        else if (symbol == '(')
        {
            opStack.Push(infix[i]);
        }
        else if (symbol == ')')
        {
            while (opStack.Top() != '(')
            {
                postFix += opStack.Top();
                postFix += ' ';
                opStack.Pop();
            }

            opStack.Pop();
        }
        else if (isOperator(symbol))
        {

            while (!opStack.IsEmpty() && opStack.Top() != '('
                   && operatorPrecedence(opStack.Top()) >= operatorPrecedence(symbol))
            {
                postFix += opStack.Top();
                postFix += ' ';
                opStack.Pop();
            }

            opStack.Push(symbol);
        }
        else
        {
            throw exception();
        }

    }


    while (!opStack.IsEmpty())
    {

        if (opStack.Top() == '(')
            throw exception();

        postFix += opStack.Top();
        postFix += ' ';
        opStack.Pop();
    }

    return postFix;
}

double evaluatePostfix(string postfix)
{
    double result;
    StackType<double> numStack;

    char symbol;
    double num;

    for (int i = 0; postfix[i]; ++i)
    {
        symbol = postfix[i];
        num = 0;

        if (symbol == ' ')
        {
            continue;
        }

        else if (isDigit(symbol))
        {

            while (isDigit(postfix[i + 1]))
            {
                num = num * 10 + (symbol - 48);
                symbol = postfix[++i];
            }

            num = num * 10 + (symbol - 48);
            numStack.Push(num);
        }

        else if (isOperator(symbol))
        {
            num = numStack.Top();
            numStack.Pop();
            result = calculate(numStack.Top(), symbol, num);
            numStack.Pop();
            numStack.Push(result);
        }
        else
        {
            throw exception();
        }

    }

    result = numStack.Top();
    numStack.Pop();


    if (!numStack.IsEmpty())
        throw exception();

    return result;
}

bool isDigit(char symbol)
{
    return ('0' <= symbol && symbol <= '9');
}

bool isOperator(char symbol)
{
    return (symbol == '/' || symbol == '*' || symbol == '+' || symbol == '-');
}

int operatorPrecedence(char op)
{
    if (op == '-')
        return 0;

    if (op == '+')
        return 1;

    if (op == '*')
        return 2;

    if (op == '/')
        return 3;

    return 4;
}

double calculate(double num1, char op, double num2)
{
    switch (op)
    {
        case '+':
            return num1 + num2;

        case '-':
            return num1 - num2;

        case '*':
            return num1 * num2;

        case '/':
            return num1 / num2;

        default:
            throw exception();
    }
}
