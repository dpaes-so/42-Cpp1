/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:51:58 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/27 15:05:33 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <limits.h>


class Span
{
	private:
		std::vector<int> v;
		size_t _size;
	public:
		Span();
		Span(size_t size);
		Span(const Span &obj);
		Span &operator=(const Span &obj);
		~Span();
		void addNumberrange(size_t n,size_t N);
		void addNUmber(int n);
		std::vector<int> getSpan() const ;
		int shortestSpan();
		int longestSpan();
};

std::ostream &operator<<(std::ostream &os,const Span &v);
#endif