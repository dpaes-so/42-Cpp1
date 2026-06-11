/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finn <finn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/06/09 18:33:10 by finn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RPN.hpp"

bool calculator(std::string str,std::stack<int> &rpn)
{
	int b = rpn.top(); rpn.pop();
    int a = rpn.top(); rpn.pop();
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
				return false;
			}
			rpn.push(a / b);
			break;
		case '*':
			rpn.push(a * b);
			break;
		default:
			std::cout << "laranja\n";
			break;
	}
	return true;
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
				return false;
			}
			if(!calculator(str,rpn))
				return(false);
		}
		else if(isdigit(str[0]))
			rpn.push(str[0] - '0');
		else
		{
			std::cerr << "Error: Invalid argument\n";
			return false;
		}
	}
	return true;
}

int main(int ac, char *av[])
{
	if(ac == 2)
	{		
		std::stack<int> rpn;
		std::string input = av[1];
		if(input.empty())
			return(std::cerr << "Error: Empty input\n",1);
		if(read_input(input,rpn))
		{
			if(rpn.size() == 1)
				std::cout << rpn.top() << std::endl;
			else
				std::cerr << "Error: Extra numbers in the stack\n";
		}
	}
	else
		std::cerr << "Invalid amount of arguments(./RPN <arguments>)\n";
	return (0);
}
