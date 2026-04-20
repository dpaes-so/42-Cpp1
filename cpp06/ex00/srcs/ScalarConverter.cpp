/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 16:04:01 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/20 18:15:53 by dpaes-so         ###   ########.fr       */
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
static void char_output(double c)
{
	if(std::isnan(c) || std::isinf(c))
	{
		std::cout << "char: Impossible" << std::endl;
		return ;
	}
	if(ft_isprint(c))
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void int_output(double c,std::string original)
{
	(void)original;
	if(std::isnan(c) || std::isinf(c))
	{
		std::cout << "int: Impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(c) << std::endl;	
}

static void float_output(double c,std::string original)
{
	(void)original;
	std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(1);
	std::cout << "float: " << c << "f" <<  std::endl;	

}

static void double_output(double c,std::string original)
{
	(void)original;
	std::cout << "double: " << c <<  std::endl;	

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
	char *flag;
	flag = NULL;
	
	if(og.find(".") != std::string::npos)
	{
		if(og.find_first_not_of("1234567890.-f") != og.npos || count_char(og,'-') > 1 || count_char(og,'.') > 1 || count_char(og,'f') > 1)
			return(fail);
		if((og[og.length() - 1]== '.' )|| (og[og.length() - 2] == '.' && og[og.length() -1] == 'f'))
			return(fail);
		return (normal);
	}
	else
	{
		std::strtod(og.c_str(),&flag);
		if(*flag)
			return (fail);
		return(normal);
	}
	return (fail);
}
void ScalarConverter::convert(std::string string)
{
	double val;
	
	std::cout << "Original: " << string << std::endl;
	ret r = parse(string);
	
	if(r == fail)
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: Impossible" << std::endl;
		std::cout << "double: Impossible" << std::endl;
		return ;
	}
	val = std::strtod(string.c_str(),NULL);
	char_output(val);
	int_output(val,string);
	float_output(val,string);
	double_output(val,string);
}