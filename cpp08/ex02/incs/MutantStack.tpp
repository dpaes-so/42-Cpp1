/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:32:10 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/27 14:36:59 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T,typename Container>
MutantStack<T,Container>::MutantStack()
{
	std::cout << "Default mutantstack constructor\n";
}
template <typename T,typename Container>
MutantStack<T,Container>::MutantStack(const MutantStack &src) : std::stack<T,Container>(src) //upcast
{
		
}

template <typename T,typename Container>
MutantStack<T,Container> &MutantStack<T,Container>::operator=(const MutantStack &src)
{
		if(this != &src)
		{
			this->c = src.c;
		}
		return(*this);
}


template <typename T,typename Container>
MutantStack<T,Container>::~MutantStack()
{
	std::cout << "Default mutantstack constructor\n";
}
