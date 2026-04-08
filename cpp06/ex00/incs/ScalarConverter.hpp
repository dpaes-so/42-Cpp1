/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:49:22 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/08 16:30:16 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP

# define SCALARCONVERT_HPP
 

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits.h>
#include <cmath>

class ScalarConverter 
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &scalar);
		ScalarConverter &operator=(const ScalarConverter &scalar);

	public:
		static void convert(std::string string);
	
};


enum ret {
  special,
  normal,
  fail
};

#endif