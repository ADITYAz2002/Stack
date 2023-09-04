#include<iostream>
#include<map>
#include<stack>
#include<string>
using namespace std;

class Conversion 
{
    private:
        int top;
        int capacity;
        char* array;
        string output;
        map<char, int> precedence;
    public:
        Conversion(int capacity) 
        {
            top = -1;
            this->capacity = capacity;
            array = new char[capacity];
            output = "";
            precedence['+'] = 1;
            precedence['-'] = 1;
            precedence['*'] = 2;
            precedence['/'] = 2;
            precedence['^'] = 3;
        }

        bool isEmpty()
            return (top == -1);

        char peek()
            return array[top];
            
        char pop() 
        {
            if (!isEmpty()) 
            {
                top--;
                return array[top + 1];
            }

            else
                return '$';
        }

        void push(char op) 
        {
            top++;
            array[top] = op;
        }

        bool isOperand(char ch)
            return isalpha(ch);

        bool notGreater(char i) 
        {
            map<char, int>::iterator a, b;
            a = precedence.find(i);
            b = precedence.find(peek());
            if (a != precedence.end() && b != precedence.end())
                return (a->second <= b->second);

            else
                return false;
        }

        void infixToPostfix(string exp) 
        {
            for (int i = 0; i < exp.length(); i++) 
            {
                if (isOperand(exp[i]))
                    output += exp[i];

                else if (exp[i] == '(')
                    push(exp[i]);

                else if (exp[i] == ')') 
                {
                    while (!isEmpty() && peek() != '(') 
                    {
                        char a = pop();
                        output += a;
                    }

                    if (!isEmpty() && peek() != '(') 
                    {
                        cout << "Invalid expression" << endl;
                        return;
                    }

                    else
                        pop();
                }

                else 
                {
                    while (!isEmpty() && notGreater(exp[i])) 
                    {
                        char a = pop();
                        output += a;
                    }
                    push(exp[i]);
                }
            }

            while (!isEmpty()) 
            {
                char a = pop();
                output += a;
            }
            cout << output << endl;
        }
};

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    Conversion obj(exp.length());
    obj.infixToPostfix(exp);
    return 0;
}