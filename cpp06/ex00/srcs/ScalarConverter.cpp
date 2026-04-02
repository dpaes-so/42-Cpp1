/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 16:04:01 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/02 18:00:15 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScalarConverter.hpp"
#include <string>
#include <sstream>

ScalarConverter::ScalarConverter()
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalar)
{
	(void)scalar;
}

ScalarConverter::~ScalarConverter()
{
	
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalar)
{
	(void)scalar;
	return(*this);
}

static void char_output(char c)
{
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::convert(std::string string)
{
	std::cout << "Original: " << string << std::endl;

	std::stringstream ss(string);
	int val;

	ss >> val;
	char_output(string.at(0));
	std::cout << "charr: " << val << std::endl;
}