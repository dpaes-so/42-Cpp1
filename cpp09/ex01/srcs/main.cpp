/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/07/09 13:52:18 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RPN.hpp"

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
				std::cerr << "Error: Wrong amount of numbers remaining in the stack\n";
		}
	}
	else
		std::cerr << "Invalid amount of arguments(./RPN <arguments>)\n";
	return (0);
}
