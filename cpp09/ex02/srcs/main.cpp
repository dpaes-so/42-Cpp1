/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finn <finn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/07/06 02:18:32 by finn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

void PmergeMe::sort_rec_deq(std::deque<int> &deq, size_t lvl, size_t p_num)
{
	size_t	k = lvl - 1;
	size_t	j = lvl * 2 - 1;
	size_t	current_pair = 0;

	if (lvl == 1)
	{
		k = 0;
		j = 1;
	}
	while (current_pair < p_num)
	{
		if (deq.at(k) > deq.at(j))
		{
			for (size_t i = 0; i < lvl; i++)
				std::swap(deq[k - i], deq[j - i]);
		}
		j += lvl * 2;
		k += lvl * 2;
		current_pair++;
	}
}

size_t PmergeMe::find_bound_deq(const std::deque<int> &deq, int pend_last,size_t block_size)
{
	size_t i = 0;

	while (i + block_size <= deq.size())
	{
		size_t last = i + block_size - 1;

		if (deq[last] == pend_last)
		{
			if (i + block_size * 2 > deq.size())
				return std::string::npos;
			return (i + block_size * 2 - 1);
		}
		i += block_size;
	}
	return (std::string::npos);
}

size_t	PmergeMe::binarysearch_deq(std::deque<int> &main_chain,std::deque<int> &pend,int to_compare,int n_per_pair,size_t right)
{
	(void)pend;

	size_t left = 0;

	while (left <= right)
	{
		size_t middle = (left + right) / 2;
		size_t index = middle * n_per_pair + (n_per_pair - 1);

		if (to_compare < main_chain[index])
		{
			if (middle == 0)
			{
				left = 0;
				break;
			}
			right = middle - 1;
		}
		else
			left = middle + 1;
	}
	return (left);
}

void	PmergeMe::use_jacobsthal_deq(size_t &numbers_per_pair,std::deque<int> &main,std::deque<int> &pend,size_t &p_num)
{
	std::vector<size_t> seq;
	size_t	order = 0;
	size_t	prev_order = 1;

	(void)main;
	(void)pend;
	(void)p_num;
	(void)numbers_per_pair;
	size_t pend_pairs = pend.size() / numbers_per_pair + 1;
	seq = jacobsthal(pend_pairs);
	for (size_t i = 0; i < seq.size(); i++)
	{
		order = std::min(seq[i], pend_pairs);

		for (size_t j = order; j > prev_order; j--)
		{
			int current_pair = j - 2;
			size_t right;
			size_t left;
			size_t idx = current_pair * numbers_per_pair +(numbers_per_pair - 1);
			size_t bound_idx = find_bound_deq(deq,pend[idx],numbers_per_pair);
			if (bound_idx == std::string::npos)
				right = main.size() / numbers_per_pair - 1;
			else
			{
				int bound = deq[bound_idx];

				right = std::distance(main.begin(),std::find(main.begin(), main.end(), bound))/ numbers_per_pair;
			}
			left = binarysearch_deq(main,pend,pend[idx],numbers_per_pair,right);
			main.insert(main.begin() + left * numbers_per_pair,pend.begin() + idx - numbers_per_pair + 1,pend.begin() + idx + 1);
		}
		prev_order = order;
	}
}

void PmergeMe::deque_mergin_sort(size_t &numbers_per_pair, size_t &p_num)
{
	std::deque<int> main;
	std::deque<int> pend;

	if (p_num == 2)
		return;
	size_t total_blocks = deq.size() / numbers_per_pair;
	for (size_t block = 0; block < total_blocks; block++)
	{
		size_t start = block * numbers_per_pair;
		size_t end = start + numbers_per_pair;

		if (block == 0 || block == 1 || block % 2 == 1)
			main.insert(main.end(), deq.begin() + start, deq.begin() + end);
		else
			pend.insert(pend.end(), deq.begin() + start, deq.begin() + end);
	}
	use_jacobsthal_deq(numbers_per_pair, main, pend, p_num);
	for (size_t i = 0; i < main.size(); i++)
		deq[i] = main[i];
}

void PmergeMe::deque_mergin_recursive(std::deque<int> &deq,size_t numbers_per_pair)
{
	size_t p_num;

	p_num = deq.size() / numbers_per_pair;
	if (p_num <= 1)
		return;
	sort_rec_deq(deq, numbers_per_pair, p_num / 2);
	deque_mergin_recursive(deq, numbers_per_pair * 2);
	deque_mergin_sort(numbers_per_pair, p_num);
}

void PmergeMe::deque_mergin()
{
	if (deq.size() < 2)
		return;
	deque_mergin_recursive(deq, 1);
}

void PmergeMe::Pmergedeque()
{
	deque_mergin();
	// std::cout << "Deque: ";
	// print_container(deq);
	// std::cout << std::endl;
}
//DIVIDING
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

//DIVIDING
void PmergeMe::sort_rec(std::vector<int> &vec,size_t lvl,size_t p_num)
{
	size_t	k = lvl - 1;
	size_t	j = lvl * 2 -1;
	size_t current_pair = 0;
	if(lvl == 1)
	{
		k = 0;
		j = 1;
	}
	while(current_pair < p_num)
	{
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
	return (left);
}

void	PmergeMe::use_jacobsthal(size_t &numbers_per_pair, std::vector<int> &main, std::vector<int> &pend,size_t	&p_num)
{
	std::vector<size_t> seq;
	size_t	order = 0;
	size_t	prev_order = 1;
	
	(void)main;
	(void)pend;
	(void)p_num;
	(void)numbers_per_pair;
	size_t pend_pairs = pend.size() / numbers_per_pair + 1;
	seq = jacobsthal(pend_pairs);
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
	use_jacobsthal(numbers_per_pair,main,pend,p_num);
	for(size_t i = 0; i < main.size();i++)
		vec[i] = main[i];
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

void PmergeMe::Pmergevector()
{
	vector_mergin();
	// std::cout << "Vector: ";
	// print_container(vec);
	// std::cout << std::endl;
}

bool PmergeMe::parse_input(char *av[])
{
	std::string s;
	std::string bigstring;
	long value;
	char *end;

	for (size_t i = 1; av[i]; i++)
	{
		s = av[i];
		if (s.find_first_of("\t\n\v\f\r ") != std::string::npos)
		{
			std::istringstream ss(av[i]);
			while (ss >> bigstring)
			{
				value = std::strtol(bigstring.c_str(), &end, 10);

				if (*end != '\0' || value < 0 || value > INT_MAX)
					return (false);
				if (std::find(vec.begin(), vec.end(), value) != vec.end())
					return (false);
				vec.push_back(static_cast<int>(value));
				deq.push_back(static_cast<int>(value));
			}
			if (bigstring.empty())
				return (false);
			continue;
		}
		value = std::strtol(s.c_str(), &end, 10);
		if (*end != '\0' || value < 0 || value > INT_MAX)
			return (false);
		if (std::find(vec.begin(), vec.end(), value) != vec.end())
			return (false);

		vec.push_back(static_cast<int>(value));
		deq.push_back(static_cast<int>(value));
	}
	return (true);
}

int	main(int ac, char *av[])
{
	PmergeMe	cmerge;
	clock_t start;
	clock_t end;

	if (ac >= 2)
	{
		if (cmerge.parse_input(av))
		{
			start = clock();
			cmerge.Pmergedeque();
			end = clock();
			double vector_time = static_cast<double>(end - start)* 1000000.0 / CLOCKS_PER_SEC;
			
			start = clock();
			cmerge.Pmergedeque();
			end = clock();
			double deque_time = static_cast<double>(end - start)* 1000000.0 / CLOCKS_PER_SEC;
			std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << vector_time << " us" << std::endl;
			std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << deque_time << " us" << std::endl;
		}
		else
			std::cerr << "Error: Bad input\n";
	}
	else
		std::cerr << "Invalid amount of arguments\n";
}