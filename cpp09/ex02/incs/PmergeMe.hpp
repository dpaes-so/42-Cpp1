/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finn <finn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:51:58 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/06/16 15:25:18 by finn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
# include <vector>
# include <sstream>
#include <fstream>
#include <algorithm>
#include <limits.h>


class PmergeMe
{
    private:
        std::vector<int> vec;
		std::vector<std::pair<int, int> > vp;
        bool straggler;
        int _straggler;
    public:
        void Pmergevector();
        void print_vvp();
        void parse_input(std::string s);
};

#endif