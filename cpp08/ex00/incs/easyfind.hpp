/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:51:58 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/08 18:29:57 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &cont,int n)
{
	typename T::iterator it;
	
	it = std::find(cont.begin(),cont.end(),n);
	if(it != cont.end() && *it == n)
		return(it);
	throw std::out_of_range("couldn't find the element in the container");
}

#endif