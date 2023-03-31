#include <stack>
#include <string>
#include <iostream>

bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int get_precedence(char c)
{
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else return 0;
}

std::string infix_to_postfix(const std::string &infix)
{
    std::stack<char> stack;
    std::string postfix = "";
    for (char c : infix)
        {
        if (isdigit(c)) postfix += c;
        else if (is_operator(c))
        {
            while (!stack.empty() && stack.top() != '(' && get_precedence(stack.top()) >= get_precedence(c))
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
        else if (c == '(') stack.push(c);
        else if (c == ')')
        {
            while (!stack.empty() && stack.top() != '(')
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        }
    }
    while (!stack.empty())
    {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}

int evaluate_postfix(const std::string &postfix)
{
    std::stack<int> stack;
    for (char c : postfix)
    {
        if (isdigit(c)) stack.push(c - '0');
        else if (is_operator(c))
        {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            if (c == '+') stack.push(a + b);
            else if (c == '-') stack.push(a - b);
            else if (c == '*') stack.push(a * b);
            else if (c == '/') stack.push(a / b);
        }
    }
    return stack.top();
}

int main()
{
    std::string infix1 = "2*2-3*4+2-3*3";
    std::string infix2 = "(2*2-3)*4+(2-3)*3";
    std::string infix3 = "(2*(2-3))*4+(2-3)*3";
    std::string infix4 = "(2*2-3)*(4+(2-3)*3)";
    std::string infix5 = "(2*2-3)*(4+(2-3))*3";
    std::string postfix1 = infix_to_postfix(infix1);
    std::string postfix2 = infix_to_postfix(infix2);
    std::string postfix3 = infix_to_postfix(infix3);
    std::string postfix4 = infix_to_postfix(infix4);
    std::string postfix5 = infix_to_postfix(infix5);
    std::cout << "Infix 1: " << infix1 << std::endl;
    std::cout << "Postfix 1: " << postfix1 << std::endl;
    std::cout << "Result 1: " << evaluate_postfix(postfix1) << std::endl<< std::endl;
    std::cout << "Infix 2: " << infix2 << std::endl;
    std::cout << "Postfix 2: " << postfix2 << std::endl;
    std::cout << "Result 2: " << evaluate_postfix(postfix2) << std::endl<< std::endl;
    std::cout << "Infix 3: " << infix3 << std::endl;
    std::cout << "Postfix 3: " << postfix3 << std::endl;
    std::cout << "Result 3: " << evaluate_postfix(postfix3) << std::endl<< std::endl;
    std::cout << "Infix 4: " << infix4 << std::endl;
    std::cout << "Postfix 4: " << postfix4 << std::endl;
    std::cout << "Result 4: " << evaluate_postfix(postfix4) << std::endl<< std::endl;
    std::cout << "Infix 5: " << infix5 << std::endl;
    std::cout << "Postfix 5: " << postfix5 << std::endl;
    std::cout << "Result 5: " << evaluate_postfix(postfix5) << std::endl<< std::endl;
    return 0;
}
