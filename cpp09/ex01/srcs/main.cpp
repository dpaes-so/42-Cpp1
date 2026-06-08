/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finn <finn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/06/07 20:57:34 by finn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RPN.hpp"

void calculator(std::string str,std::stack<int> &rpn)
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
			rpn.push(a / b);
			break;
		case '*':
			rpn.push(a * b);
			break;
		default:
			std::cout << "laranja\n";
			break;
	}
}
void read_input(std::string input,std::stack<int> &rpn)
{
	std::istringstream in(input);
	std::string str;
	(void)rpn;
	while(in >> str)
	{
		if(strchr("+*/-",str[0]))
			calculator(str,rpn);
		else if(isdigit(str[0]))
		{
			rpn.push(str[0] - '0');
			std::cout << rpn.size() << std::endl;
		}
		else
		{
			std::cout << "Error: Invalid argument\n";
		}
	}
}

int main(int ac, char *av[])
{
	if(ac == 2)
	{		
		std::stack<int> rpn;
		std::string input = av[1];
		read_input(input,rpn);
		std::cout << "Result = " << rpn.top() << std::endl;
	}
	else
		std::cerr << "Invalid amount of arguments(./RPN <arguments>)\n";
	return (0);
}
