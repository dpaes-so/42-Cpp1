/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/27 15:22:00 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << "Main as mutantstack" << std::endl;
		MutantStack<int,std::list<int> > mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "top of the stack: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "stack size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int,std::list<int> >::it it = mstack.begin();
		MutantStack<int,std::list<int> >::it ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		const MutantStack<int,std::list<int> > copied(mstack);
		MutantStack<int,std::list<int> >::c_it c_it = copied.cbegin();
		MutantStack<int,std::list<int> >::c_it c_ite = copied.cend();
		std::cout << "Const iterators" << std::endl;
		while (c_it != c_ite)
		{
			std::cout << *c_it << std::endl;
			++c_it;
		}
	}
	{
		std::cout << "=============================================================\n";
		std::cout << "Main as list" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << "top of the stack: " << mstack.front() << std::endl;
		mstack.pop_front();
		std::cout << "stack size: " << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		const std::list<int> copied(mstack);
		std::list<int>::const_iterator c_it = copied.begin();
		std::list<int>::const_iterator c_ite = copied.end();
		std::cout << "Const iterators" << std::endl;
		while (c_it != c_ite)
		{
			std::cout << *c_it << std::endl;
			++c_it;
		}
		return 0;
	}
}