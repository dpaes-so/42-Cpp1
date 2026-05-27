/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/19 18:59:00 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"
#include <vector>
#include <list>

int main(void)
{
	try
	{
		Span span(10);

		span.addNumberrange(0,50);
		std::cout << span;
		// std::cout << "shortest span is " << span.shortestSpan() << std::endl;
		// std::cout << "shortest span is " << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}