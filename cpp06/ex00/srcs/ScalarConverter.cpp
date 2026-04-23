/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 16:04:01 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/23 14:12:47 by dpaes-so         ###   ########.fr       */
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

static int count_char(std::string s,char c) 
{
  int count = 0;

  for (size_t i = 0; i < s.size(); i++)
  {
    if (s[i] == c)
		count++;
  }
  return count;
}

static ret is_special(std::string str)
{
	if(str == "inf" || str == "inff" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return(INF);
	if (std::isnan(std::strtod(str.c_str(),NULL)))
		return(NaN);
	return(INT);
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

static void special_output(std::string num)
{
	ret check;

	check = is_special(num);
	
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	if(check == INF)
	{
		if(count_char(num,'f') > 1)
		{
			std::cout << "float: " << num << std::endl;
			std::cout << "double: " << num.substr(0,num.length() - 1) << std::endl;
		}
		else
		{
			std::cout << "float: " << num << "f" << std::endl;
			std::cout << "double: " << num << std::endl;
		}
	}
	if(check == NaN)
	{
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
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
	if(std::strtod(og.c_str(),NULL) > INT_MAX || std::strtod(og.c_str(),NULL) < INT_MIN)
		std::cout << "int: " << "Impossible" << std::endl;	
	else
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
	if(val > INT_MAX || val < INT_MIN)
		std::cout << "int: " << "Impossible" << std::endl;	
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;	
	std::cout << std::fixed;
    std::cout << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(val) << "f" <<  std::endl;	
	std::cout << "double: " << (val) << std::endl;		
}

//parse
static ret parse(std::string og)
{
	double val;
	char *flag;
	
	flag = NULL;
	if(og.length() == 1 && !isdigit(og.at(0)))
		return(CHAR);
	else if(og.find(".") != std::string::npos)
	{
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
		if(is_special(og) != INT)
			return(SPECIAL);
		val = std::strtod(og.c_str(),&flag);
		if(val > 2147483647 || val < -2147483647)
			return(DOUBLE);
		if(*flag)
			return (FAIL);
		return(INT);
	}
	return (FAIL);
}

void ScalarConverter::convert(std::string string)
{
	// double val;
	std::cout << "Original: " << string << std::endl;
	ret r = parse(string);
	
	switch (r)
	{
		case (CHAR):
			char_output(string.at(0));
			break;
		case (INT):
			int_output(string);
			break;
		case (FLOAT):
			float_output(string);
			break;
		case (DOUBLE):
			double_output(string);
			break;
		case (SPECIAL):
			special_output(string);
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
