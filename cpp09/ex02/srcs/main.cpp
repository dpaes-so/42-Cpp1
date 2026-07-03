/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finn <finn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/07/03 17:46:16 by finn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

void PmergeMe::sort_rec(std::vector<int> &vec,size_t lvl,size_t p_num)
{
	size_t	k = lvl - 1;
	size_t	j = lvl * 2 -1;
	size_t current_pair = 0;
	// std::cout << "lvl = " << lvl << std::endl;
	if(lvl == 1)
	{
		k = 0;
		j = 1;
	}
	// std::cout << "p_num = " << p_num << std::endl;
	while(current_pair < p_num)
	{
		// print_container(vec);
		// std::cout << "swapping this guy: " << vec.at(k) << " and this guy: " << vec.at(j) << " j = " << j << std::endl;
		if(vec.at(k) > vec.at(j))
		{
			for(size_t i = 0;i < lvl;i++)
			{
				std::swap(vec[k - i],vec[ j -i]);
			}
		}
		j += lvl * 2;
		k +=lvl * 2;
		current_pair++;
	}
}

size_t PmergeMe::find_bound(const std::vector<int> &vec,int pend_last,size_t block_size)
{
    size_t i = 0;

    while (i + block_size <= vec.size())
    {
        size_t last = i + block_size - 1;

        if (vec[last] == pend_last)
        {
            // No partner block
            if (i + block_size * 2 > vec.size())
                return std::string::npos;

            return i + block_size * 2 - 1;
        }

        i += block_size;
    }

    return std::string::npos;
}

size_t	PmergeMe::binarysearch(std::vector<int> &main_chain, std::vector<int> &pend, int to_compare, int n_per_pair, size_t right)
{
	(void)pend;
	size_t left = 0;
	while (left <= right)
	{
		size_t middle = (left + right) / 2;
		size_t index = middle * n_per_pair + (n_per_pair - 1);
		if(to_compare < main_chain[index])
		{
			if(middle == 0)
			{
				left = 0;
				break;
			}
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	// std::cout << "left: " << left << std::endl;
	return (left);
}

void	PmergeMe::use_jacobsthal(size_t &numbers_per_pair, std::vector<int> &main, std::vector<int> &pend,size_t	&p_num)
{
	std::vector<size_t> seq;
	size_t	order = 0;
	size_t	prev_order = 1;

	std::cout << "----------------------------STARTING JACOBING----------------------------" << std::endl;
	
	(void)main;
	(void)pend;
	(void)p_num;
	(void)numbers_per_pair;
	size_t pend_pairs = pend.size() / numbers_per_pair + 1;
	seq = jacobsthal(pend_pairs);
	std::cout << "jacobas  seq ->>>> ";
	print_container(seq);
	for(size_t i = 0; i < seq.size(); i++)
	{
		order = std::min(seq[i], pend_pairs);
		for(size_t j = order; j > prev_order; j--)
		{
			int	current_pair = j - 2;
			size_t right;
			size_t left;
			size_t idx = current_pair * numbers_per_pair + (numbers_per_pair - 1);
			size_t bound_idx = find_bound(vec, pend[idx], numbers_per_pair);
			if (bound_idx == std::string::npos)
				right = main.size() / numbers_per_pair - 1;
			else
			{
				int bound = vec[bound_idx];
				right = std::distance(main.begin(),std::find(main.begin(), main.end(), bound))/numbers_per_pair;
			}
			left = binarysearch(main, pend, pend[idx], numbers_per_pair, right);
			main.insert(main.begin() + left * numbers_per_pair, pend.begin() + idx - numbers_per_pair + 1, pend.begin() + idx + 1);
			print_container(main);
		}
		prev_order = order;
	}
}

void PmergeMe::vector_mergin_sort(size_t &numbers_per_pair,size_t	&p_num)
{
	std::vector<int> main;
	std::vector<int> pend;

	if(p_num == 2)
		return;
	size_t total_blocks = vec.size() / numbers_per_pair;
	for (size_t block = 0; block < total_blocks; block++)
	{
		size_t start = block * numbers_per_pair;
		size_t end = start + numbers_per_pair;

		if (block == 0 || block == 1 || block % 2 == 1)
			main.insert(main.end(),vec.begin() + start,vec.begin() + end);
		else
			pend.insert(pend.end(),vec.begin() + start,vec.begin() + end);
	}
	// std::cout << "n p papair: " << numbers_per_pair << " p num: " << p_num << std::endl;
	std::cout << "MAIN ->>> ";
	print_container(main);
	std::cout << "Pend ->>> ";
	print_container(pend);
	std::cout << "Vec ->>> ";
	print_container(vec);
	std::cout << std::endl;
	use_jacobsthal(numbers_per_pair,main,pend,p_num);
	for(size_t i = 0; i < main.size();i++)
		vec[i] = main[i];
	std::cout << "---------------------------------------------------------------------------------------------------------------------\n";
}

void PmergeMe::vector_mergin_recursive(std::vector<int> &vec,size_t numbers_per_pair)
{
	size_t		p_num;

	p_num = vec.size() / numbers_per_pair;
	if (p_num <= 1)
		return ;
	sort_rec(vec, numbers_per_pair,p_num/2);
	vector_mergin_recursive(vec, numbers_per_pair * 2);
	vector_mergin_sort(numbers_per_pair,p_num);
}

void PmergeMe::vector_mergin()
{
	if (vec.size() < 2)
		return ;
	vector_mergin_recursive(vec, 1);
}

std::vector<size_t> PmergeMe::jacobsthal(size_t n)
{
	size_t	num;
	std::vector<size_t> seq;
	seq.push_back(3);
	if (n <= 2)
		return (seq);
	seq.push_back(5);
	if (n <= 5)
		return (seq);
	for(int i = 2; i; i++)
	{
		num = seq[i - 1] + 2 * seq[i - 2];
		if (num >= n)
		{
			seq.push_back(num);
			break ;
		}
		seq.push_back(num);
	}
	return (seq);
}

void PmergeMe::Pmergevector()
{
	vector_mergin();
}

bool PmergeMe::parse_input(char *av[])
{
	std::string s;
	std::string bigstring;
	for (size_t i = 1; av[i]; i++)
	{
		s = av[i];
		if (s.find_first_of("\t\n\v\f\r ") != std::string::npos)
		{
			std::istringstream ss(av[i]);
			while (ss >> bigstring)
			{
				if (bigstring.find_first_not_of("0123456789") != std::string::npos)
					return (false);
				vec.push_back(atoi(bigstring.c_str()));
			}
			if (bigstring.empty())
				return (false);
			continue ;
		}
		if (s.find_first_not_of("0123456789") != std::string::npos || s.empty())
			return (false);
		vec.push_back(atoi(s.c_str()));
	}
	return (true);
}

int	main(int ac, char *av[])
{
	PmergeMe	cmerge;

	if (ac >= 2)
	{
		if (cmerge.parse_input(av))
		{
			cmerge.Pmergevector();
		}
		else
			std::cerr << "Error: Bad input\n";
	}
	else
		std::cerr << "Invalid amount of arguments\n";
}