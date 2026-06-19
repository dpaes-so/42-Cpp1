/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/06/19 17:37:58 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

void PmergeMe::print_vvp()
{
	for (size_t i = 0; i < vp.size(); i++)
    {
        std::cout << "x = (" << vp[i].first << ", " << vp[i].second << ")\n";
    }
	if(straggler == true)
		std::cout << "Straggler = " << _straggler << std::endl;
}

void PmergeMe::mergin_sort(std::vector<std::pair<int, int> > &vp,size_t left, size_t middle,size_t right)
{
	std::vector<std::pair<int, int > > temp;
	
	size_t i = left;
	size_t j = middle + 1;
	while(i <= middle && j <= right)
	{
		if(vp[i].second >= vp[j].second)
			temp.push_back(vp[j++]);
		else
			temp.push_back(vp[i++]);
	}

	while (i <= middle)
		temp.push_back(vp[i++]);//in u cant make a full pair with leftovers
	while (j <= right)
		temp.push_back(vp[j++]);
	
	for(size_t i = 0;i<temp.size();i++)
		vp[left + i] = temp[i];
}
void PmergeMe::vector_mergin_recursive(std::vector<std::pair<int, int> > &vp,size_t left, size_t right)
{
	if(left >= right)
		return ;
	size_t middle = left + (right - left)/2;
	vector_mergin_recursive(vp,left,middle);//left side of vector
	vector_mergin_recursive(vp, middle + 1, right);//right side of vector
	mergin_sort(vp,left,middle,right);
}

void PmergeMe::vector_mergin()
{
	if(vp.size() < 2)
	 	return ;
	vector_mergin_recursive(vp,0,vp.size() - 1);
}

std::vector<size_t> PmergeMe::jacobas(size_t n)
{
	std::vector<size_t> seq;
	std::vector<size_t> true_seq;
	seq.push_back(0);
	seq.push_back(1);
	if(3 > n )
		return seq; 
	for (int i = 2; i ; ++i)
	{
		size_t seq_number =seq[i - 1] + 2 * seq[i - 2];
		if(seq_number >= n )
		{
			seq.push_back(seq_number);
			break;
		}
   		seq.push_back(seq_number);
    }
	for(size_t i = 0; i < seq.size();i++)
	{
		if(seq[i] == 0)
			true_seq.push_back(0);
		else if(seq[i] == 1)
			continue;
		else
			true_seq.push_back(seq[i] - 1);
	}
	return true_seq;
}


void PmergeMe::binarysearch_start(std::pair<int,int> &pair,std::vector<int> &main)
{
	size_t right;
	if(pair.second != INT_MAX)
		right = std::distance(main.begin(),std::find(main.begin(),main.end(),pair.second));
	else
		right = main.size() - 1;
	size_t left = 0;
	while (left <= right)
	{
		size_t middle = left + (right - left)/2;
		if(pair.first < main[middle])
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
	main.insert(main.begin() + left,pair.first);
}
void PmergeMe::Pmergevector()
{
	std::vector<int> main;
	std::vector<std::pair<int,int> > pend;
	std::vector<size_t> seq;
	

	_start_vector = clock();
	if(vp.size() == 0)
	{
		main.push_back(_straggler);
		std::cout << "Sorted: ";
		for(size_t i = 0;i < main.size();i++)
			std::cout << main.at(i) << " ";
		std::cout << std::endl;
		return;
	}
	vector_mergin();
	main.push_back(vp[0].first);
	main.push_back(vp[0].second);
	for (size_t i = 1; i < vp.size(); i++)
    	main.push_back(vp[i].second);
	for (size_t i = 1; i < vp.size(); i++)
    	pend.push_back(vp[i]);
	if(straggler == true)
		pend.push_back(std::make_pair(_straggler, __INT_MAX__));
	seq = jacobas(pend.size());
	size_t last_order = 0;
	for(size_t i= 0;i <seq.size();i++)
	{
		if(pend.empty())
			break;
		size_t order = seq[i];
		if(order >= pend.size())
			order = pend.size() - 1;
		while (order > last_order || i == 0)
		{
			binarysearch_start(pend[order],main);
			order--;
			if(i == 0)
				break;
		}
		last_order = seq[i];
	}
	clock_t duration = clock() - _start_vector;
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Duration: " << ((float)duration / CLOCKS_PER_SEC) *1000000.0 << " microseconds\n";
	std::cout << "Sorted: ";
	for(size_t i = 0;i < main.size();i++)
		std::cout << main.at(i) << " ";
	std::cout << std::endl;
}

bool PmergeMe::parse_input(char *av[])
{
	std::vector<int> vec;
	std::string s;
	std::string bigstring;
	for(size_t i = 1;av[i];i++)
	{
		s = av[i];
		if(s.find_first_of("\t\n\v\f\r ") != std::string::npos)
		{
			std::istringstream ss(av[i]);
			while(ss >> bigstring)
			{
				if(bigstring.find_first_not_of("0123456789") != std::string::npos) 
					return(false);
				vec.push_back(atoi(bigstring.c_str()));
			}
			if(bigstring.empty())
				return(false);
			continue;
		}
		if(s.find_first_not_of("0123456789") != std::string::npos ||  s.empty())
			return(false);
		vec.push_back(atoi(s.c_str()));
	}
    size_t i = 0;
    while (i + 1 < vec.size())
    {
        int a = vec[i];
        int b = vec[i + 1];

        if (a > b)
            std::swap(a, b);

        vp.push_back(std::make_pair(a, b));
        i += 2;
    }
	if(vec.size() % 2 != 0)
	{
		straggler = true;
		_straggler = vec.back();
	}
	else
		straggler = false;
	return(true);
}

int main(int ac, char *av[])
{
    if (ac >= 2)
    {
        PmergeMe cmerge;
        if(cmerge.parse_input(av))
       		cmerge.Pmergevector();
		else
			std::cerr << "Error: Bad input\n";
    }
    else
        std::cerr << "Invalid amount of arguments\n";
}
