/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:51:58 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/06/23 15:27:52 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <iomanip>
# include <vector>
# include <deque>
# include <sstream>
#include <fstream>
#include <algorithm>
#include <limits.h>
#include <ctime>

class PmergeMe
{
    private:
		std::vector<std::pair<int, int> > vp;
        std::deque<std::pair<int, int> > dp;
        std::vector<int> vec;
        std::vector<int> sorted_vec;
        std::deque<int> sorted_deq;
        bool straggler;
        int _straggler;
        double _vec_duration;
        double _deq_duration;
        void vector_mergin_recursive(std::vector<std::pair<int, int> > &vp,size_t left, size_t right);
        void deque_mergin_recursive(std::deque<std::pair<int, int> > &dp,size_t left, size_t right);

        void vector_mergin_sort(std::vector<std::pair<int, int> > &vp,size_t left, size_t middle,size_t right);
        void deque_mergin_sort(std::deque<std::pair<int, int> > &dp,size_t left, size_t middle,size_t right);

        std::vector<size_t> jacobas(size_t n);
        
        void vector_binarysearch_start(std::pair<int,int> &pair,std::vector<int> &main);
        void deque_binarysearch_start(std::pair<int,int> &pair,std::deque<int> &main);

        void stop_timer_vec(std::vector<int> vec);
        void stop_timer_deq(std::deque<int> dec);
    public:
        void vector_mergin();
        void deque_mergin();

        void Pmergevector();
        void Pmergedeque();
        
        void print_output_vector();
        void print_vvp();
        bool parse_input(char *av[]);
};

#endif