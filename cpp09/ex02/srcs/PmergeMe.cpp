/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:25:02 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/07/09 13:44:22 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	std::cout << "copy PmergeMe constructor\n";
	*this = obj;
}


PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	std::cout << "PmergeMe copy assignment overload\n";
	if(this != &obj)
	{
		this->vec = obj.vec;
		this->deq = obj.deq;
	}
	return(*this);
}

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

size_t	PmergeMe::binarysearch_deq(std::deque<int> &main_chain,int to_compare,int n_per_pair,size_t right)
{
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

size_t PmergeMe::find_bound_id_deq(const std::deque<size_t> &main_id, size_t pend_id)
{
	for (size_t i = 0; i < main_id.size(); i++)
	{
		if (main_id[i] == pend_id + 1)
			return (i);
	}
	return (std::string::npos);
}

void	PmergeMe::use_jacobsthal_deq(size_t &numbers_per_pair, std::deque<int> &main, std::deque<int> &pend, std::deque<size_t> &main_id, std::deque<size_t> &pend_id)
{
	std::vector<size_t> seq;
	size_t	order = 0;
	size_t	prev_order = 1;

	size_t pend_pairs = pend.size() / numbers_per_pair + 1;
	seq = jacobsthal(pend_pairs);
	for (size_t i = 0; i < seq.size(); i++)
	{
		order = std::min(seq[i], pend_pairs);

		for (size_t j = order; j > prev_order; j--)
		{
			size_t current_pair = j - 2;
			size_t right;
			size_t left;
			size_t idx = current_pair * numbers_per_pair +(numbers_per_pair - 1);
			size_t bound_idx = find_bound_id_deq(main_id, pend_id[current_pair]);
			if (bound_idx == std::string::npos)
				right = main.size() / numbers_per_pair - 1;
			else
				right = bound_idx;
			left = binarysearch_deq(main,pend[idx],numbers_per_pair,right);
			std::deque<int>::iterator pos = main.begin() + left * numbers_per_pair;
			size_t first = idx - numbers_per_pair + 1;
			size_t last = idx + 1;
			for (size_t i = first; i < last; i++)
			{
				pos = main.insert(pos, pend[i]);
				++pos;
			}
			main_id.insert(main_id.begin() + left,pend_id[current_pair]);
		}
		prev_order = order;
	}
}

void PmergeMe::deque_mergin_sort(size_t &numbers_per_pair, size_t &p_num)
{
	std::deque<int> main;
	std::deque<int> pend;
	std::deque<size_t> main_id;
	std::deque<size_t> pend_id;
	size_t id = 0;
	if (p_num == 2)
		return;
	size_t total_blocks = deq.size() / numbers_per_pair;
	for (size_t block = 0; block < total_blocks; block++)
	{
		size_t start = block * numbers_per_pair;
		size_t end = start + numbers_per_pair;

		if (block == 0 || block == 1 || block % 2 == 1)
		{
			main.insert(main.end(), deq.begin() + start, deq.begin() + end);
			main_id.push_back(id);
		}
		else
		{
			pend.insert(pend.end(), deq.begin() + start, deq.begin() + end);
			pend_id.push_back(id);
		}
		id++;
	}
	use_jacobsthal_deq(numbers_per_pair,main,pend,main_id, pend_id);
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
	size_t test = 1;
	deque_mergin_recursive(deq, test);
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

size_t	PmergeMe::binarysearch(std::vector<int> &main_chain,int to_compare, int n_per_pair, size_t right)
{
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

void PmergeMe::use_jacobsthal(size_t &numbers_per_pair, std::vector<int> &main, std::vector<int> &pend, std::vector<size_t> &main_id, std::vector<size_t> &pend_id)
{
	std::vector<size_t> seq;
	size_t	order = 0;
	size_t	prev_order = 1;
	
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
			size_t bound_idx = find_bound_id(main_id, pend_id[current_pair]);
			if (bound_idx == std::string::npos)
				right = main.size() / numbers_per_pair - 1;
			else
				right = bound_idx;
			left = binarysearch(main, pend[idx], numbers_per_pair, right);
			main.insert(main.begin() + left * numbers_per_pair, pend.begin() + idx - numbers_per_pair + 1, pend.begin() + idx + 1);
			main_id.insert(main_id.begin() + left, pend_id[current_pair]);
		}
		prev_order = order;
	}
}

size_t PmergeMe::find_bound_id(const std::vector<size_t> &main_id, size_t pend_id)
{
	for (size_t i = 0; i < main_id.size(); i++)
	{
		if (main_id[i] == pend_id + 1)
			return (i);
	}
	return (std::string::npos);
}

void PmergeMe::vector_mergin_sort(size_t &numbers_per_pair,size_t	&p_num)
{
	std::vector<int> main;
	std::vector<int> pend;

	if(p_num == 2)
		return;
	std::vector<size_t> main_id;
	std::vector<size_t> pend_id;
	size_t id = 0;
	size_t total_blocks = vec.size() / numbers_per_pair;
	for (size_t block = 0; block < total_blocks; block++)
	{
		size_t start = block * numbers_per_pair;
		size_t end = start + numbers_per_pair;

		if (block == 0 || block == 1 || block % 2 == 1)
		{
			main.insert(main.end(),vec.begin() + start,vec.begin() + end);
			main_id.push_back(id);
		}
		else
		{
			pend.insert(pend.end(),vec.begin() + start,vec.begin() + end);
			pend_id.push_back(id);
		}
		id++;
	}
	use_jacobsthal(numbers_per_pair, main, pend, main_id, pend_id);
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
	std::cout << "Before: ";
	print_container(vec);
	std::cout << std::endl;
	vector_mergin();
	std::cout << "After: ";
	print_container(vec);
	std::cout << std::endl;
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
		value = std::strtol(s.c_str(), &end, 10);
		if (*end != '\0' || value < 0 || value > INT_MAX)
			return (false);
		vec.push_back(static_cast<int>(value));
		deq.push_back(static_cast<int>(value));
	}
	return (true);
}
