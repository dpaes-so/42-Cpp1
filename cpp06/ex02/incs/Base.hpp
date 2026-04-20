/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:49:22 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/09 14:43:05 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BASE_HPP

# define BASE_HPP

#include <stdint.h>
#include <iostream>
#include <ctime>
#include <cstdlib>


class Base 
{
	private:

	public:
		virtual ~Base();
};

class A:public Base
{
	private:

	public:
};

class B:public Base
{
	private:

	public:
};

class C:public Base
{
	private:

	public:
};
Base * generate(void);
void identify(Base* p);
void identify(Base& p);
#endif