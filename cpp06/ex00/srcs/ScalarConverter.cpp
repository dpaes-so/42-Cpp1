/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 16:04:01 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/08 16:48:19 by dpaes-so         ###   ########.fr       */
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

static int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}

static void char_output(int c)
{
	if(ft_isprint(c))
		std::cout << "char: " << static_cast<char>(c) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void int_output(double c,std::string original)
{
	(void)original;
	if(std::isnan(c))
	{
		std::cout << "int: Impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << c << std::endl;	
}

static void float_output(double c,std::string original)
{
	(void)original;
	std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(1);
	std::cout << "float: " << c << "f" <<  std::endl;	

}

static ret parse(std::string og)
{
	char *flag;
	flag = NULL;
	
	if(og.find(".") != std::string::npos)
		return (special);
	else
	{
		std::strtod(og.c_str(),&flag);
		if(*flag)
		{
			std::cout << "char: Impossible" << std::endl;
			std::cout << "int: Impossible" << std::endl;
			std::cout << "float: Impossible" << std::endl;
			std::cout << "double: Impossible" << std::endl;
			return (fail);
		}
		return(normal);
	}
	return fail;
}
void ScalarConverter::convert(std::string string)
{
	double val;
	
	std::cout << "Original: " << string << std::endl;
	ret r = parse(string);
	
	if(r == fail)
		return ;
		
	if (r == special)
		val = std::strtod(string.c_str(),NULL);
	else
		val = std::strtod(string.c_str(),NULL);
		
	char_output(val);
	int_output(val,string);
	float_output(val,string);
}