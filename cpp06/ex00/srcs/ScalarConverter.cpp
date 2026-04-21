/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 16:04:01 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/21 15:44:57 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScalarConverter.hpp"
#include <string>
#include <sstream>

//defautl stuff
ScalarConverter::ScalarConverter()
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalar)
{
	*this = scalar;
}

ScalarConverter::~ScalarConverter()
{
	
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalar)
{
	(void)scalar;
	return(*this);
}

//aux
static int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}

//output
static void char_output(char c)
{
	if(ft_isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;	
	std::cout << "float: " << static_cast<float>(c) << "f" <<  std::endl;	
	std::cout << "double: " << static_cast<double>(c) << std::endl;	

}

static void int_output(std::string og)
{
	int val = std::strtod(og.c_str(),NULL);
	if(ft_isprint(val))
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << (val) << std::endl;
	std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(1);
	std::cout << "float: "  << static_cast<float>(val) << "f\n";
	std::cout << "double: "  << static_cast<double>(val) << "\n";
}

static void float_output(std::string og)
{
	float val = std::strtod(og.c_str(),NULL);
	if(ft_isprint(val))
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(val) << std::endl;	
	std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(1);
	std::cout << "float: " << (val) << "f" <<  std::endl;	
	std::cout << "double: " << static_cast<double>(val) << std::endl;		
}

static void double_output(std::string og)
{
	double val = std::strtod(og.c_str(),NULL);
	if(ft_isprint(val))
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(val) << std::endl;	
	std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(val) << "f" <<  std::endl;	
	std::cout << "double: " << (val) << std::endl;		
}

//parse
static int count_char(std::string s,char c) {
  int count = 0;

  for (size_t i = 0; i < s.size(); i++)
  {
    if (s[i] == c)
		count++;
  }
  return count;
}

static ret parse(std::string og)
{
	double val;
	char *flag;
	flag = NULL;
	
	if(og.length() == 1 && !isdigit(og.at(0)))
	{
		std::cout << "if u read this and u were not expectig soetings is really wrong" << std::endl;
		return(CHAR);
	}
	else if(og.find(".") != std::string::npos)
	{
		std::cout << "else if " << std::endl;
		if(og.find_first_not_of("1234567890.-f") != og.npos || count_char(og,'-') > 1 || count_char(og,'.') > 1 || count_char(og,'f') > 1)
			return(FAIL);
		if(og[og.length() - 1]== '.' || og[og.find('.')+ 1 ]== 'f')
			return(FAIL);
		if(og.find('-') != std::string::npos && og.find('-') != 0)
			return(FAIL);
		if(og.find('f') != std::string::npos)
			return(FLOAT);
		else
			return(DOUBLE);
	}
	else
	{
		std::cout << "else" << std::endl;
		val = std::strtod(og.c_str(),&flag);
		if(*flag || std::isinf(val) || std::isnan(val))
			return (FAIL);
		return(INT);
	}
	return (FAIL);
}

void ScalarConverter::convert(std::string string)
{
	double val;
	std::cout << "Original: " << string << std::endl;
	ret r = parse(string);
	
	if(r != FAIL)
	{
		val = std::strtod(string.c_str(),NULL);
		if(val > 2147483647)
			r = FAIL;
	}
	switch (r)
	{
		case (CHAR):
			std::cout << "cool guy" << std::endl;
			char_output(string.at(0));
			break;
		case (INT):
			std::cout << "int guy" << std::endl;
			int_output(string);
			break;
		case (FLOAT):
			std::cout << "float guy" << std::endl;
			float_output(string);
			break;
		case (DOUBLE):
			std::cout << "double guy" << std::endl;
			double_output(string);
			break;
		case (FAIL):
			std::cout << "char: Impossible" << std::endl;
			std::cout << "int: Impossible" << std::endl;
			std::cout << "float: Impossible" << std::endl;
			std::cout << "double: Impossible" << std::endl;
			break;
		default:
			break;
	}
}