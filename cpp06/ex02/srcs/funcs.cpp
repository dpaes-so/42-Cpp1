/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:57:45 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/20 18:43:49 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Base.hpp"

Base * generate(void)
{
	Base *randy;
	int res = (rand() * 1.0 / RAND_MAX * 3) + 1;
	switch (res)
	{
		case 1:
			randy = new A;
			break;
		case 2:
			randy = new B;
			break;
		case 3:
			randy = new C;
			break;
		default:
			randy = NULL;
	}
	std::cout << res << std::endl;
	return(randy);
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "im A" << std::endl;
	if(dynamic_cast<B*>(p))
		std::cout << "im B" << std::endl;
	if(dynamic_cast<C*>(p))
		std::cout << "im C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		Base cast = dynamic_cast<A&>(p);
		std::cout << "im A&" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			Base cast = dynamic_cast<B&>(p);
			std::cout << "im B&" << std::endl;

		}
		catch(const std::exception& e)
		{
			try
			{
				Base cast = dynamic_cast<C&>(p);
				std::cout << "im C&" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}
