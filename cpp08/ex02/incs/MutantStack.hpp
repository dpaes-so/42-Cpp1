/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:51:58 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/27 15:07:26 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>
#include <deque>

template <typename T,typename Container = std::deque<T> >
class MutantStack : public std::stack<T,Container>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &src);
		MutantStack<T,Container> &operator=(const MutantStack &src);
		~MutantStack();
		typedef typename std::stack<T,Container>::container_type::iterator it;
		typedef typename std::stack<T,Container>::container_type::const_iterator c_it;
		it begin()
		{
			return (this->c.begin());
		}
		it end()
		{
			return (this->c.end());
		}
		c_it cbegin() const
		{
			return (this->c.begin());
		}
		c_it cend() const
		{
			return (this->c.end());
		}
};
#include "MutantStack.tpp"

#endif
