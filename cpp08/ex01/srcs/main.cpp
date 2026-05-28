/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/28 15:05:31 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"
#include <vector>
#include <list>

int main(void)
{
	try
	{
		Span span(60);

		// span.addNumberrange(50, 80);
		// span.addNUmber(2);
		// span.addNUmber(4);
		span.addNUmber(34);
		span.addNUmber(42);
		span.addNUmber(54);
		span.addNUmber(64);
		span.addNUmber(84);
		span.addNUmber(750);
		span.addNUmber(753);
		// std::cout << span;
		std::cout << "shortest span is " << span.shortestSpan() << std::endl;
		std::cout << "longest span is " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}