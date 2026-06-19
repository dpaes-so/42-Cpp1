/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:51:58 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/06/19 17:37:47 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <iomanip>
# include <vector>
# include <sstream>
#include <fstream>
#include <algorithm>
#include <limits.h>
#include <ctime>

class PmergeMe
{
    private:
		std::vector<std::pair<int, int> > vp;
        bool straggler;
        int _straggler;
        clock_t _start_vector;
        void vector_mergin_recursive(std::vector<std::pair<int, int> > &vp,size_t left, size_t right);
        void mergin_sort(std::vector<std::pair<int, int> > &vp,size_t left, size_t middle,size_t right);
        std::vector<size_t> jacobas(size_t n);
        void binarysearch_start(std::pair<int,int> &pair,std::vector<int> &main);
    public:
        void vector_mergin();
        void Pmergevector();
        void print_vvp();
        bool parse_input(char *av[]);
};

#endif