#include "../incs/RPN.hpp"

bool calculator(std::string str,std::stack<int> &rpn)
{
    int a = rpn.top();
	rpn.pop();
	int b = rpn.top();
	rpn.pop();
	switch (str[0])
	{
		case '+':
			rpn.push(a + b);
			break;
		case '-':
			rpn.push(a - b);
			break;
		case '/':
			if(b == 0)
			{
				std::cerr << "Error: Division by 0\n";
				return (false);
			}
			rpn.push(a / b);
			break;
		case '*':
			rpn.push(a * b);
			break;
		default:
			break;
	}
	return (true);
}

bool read_input(std::string input,std::stack<int> &rpn)
{
	std::istringstream in(input);
	std::string str;
	
	while(in >> str)
	{
		if(str.length() != 1)
		{
			std::cerr << "Error: Bad character in input\n";
			return(false);
		}
		if(strchr("+*/-",str[0]))
		{
			if(rpn.size() < 2)
			{
				std::cerr << "Error: Impossible to make at least one operation\n";
				return (false);
			}
			if(!calculator(str,rpn))
				return(false);
		}
		else if(isdigit(str[0]))
			rpn.push(str[0] - '0');
		else
		{
			std::cerr << "Error: Invalid argument\n";
			return (false);
		}
	}
	return (true);
}