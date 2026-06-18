/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/06/18 19:26:34 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

bool pair_snd_big_cmp(const std::pair<int,int>& a, const std::pair<int,int>& b)
{
    return a.second < b.second;
}

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
	seq.push_back(0);
	seq.push_back(1);
	if(3 > n )
	{
		for(size_t i = 0; i < seq.size(); i ++)
			std::cout << seq[i] << " ";
		std::cout << std::endl;
		return seq; 
	}
	for (int i = 2; i ; ++i)
	{
		size_t seq_number =seq[i - 1] + 2 * seq[i - 2];
		if(seq_number >= n )
		{
			seq.push_back(seq_number);
			for(size_t i = 0; i < seq.size(); i ++)
				std::cout << "order " <<seq[i] << " ";
			std::cout << std::endl;
			return seq; 
		}
   		seq.push_back(seq_number);
    }
	std::cout << std::endl;
	return seq;
}

void PmergeMe::binarysearch_start(std::pair<int,int> &pair,std::vector<int> &main)
{
	size_t right = std::distance(main.begin(),std::find(main.begin(),main.end(),pair.second));
	size_t left = 0;
	std::cout << "first: " << pair.first << " " << "right: " << right << "(" << *(std::find(main.begin(),main.end(),pair.second)) << ")" << std::endl;
	while (left <= right)
	{
		size_t middle = left + (right - left)/2;
		std::cout << "Middle = " << middle << std::endl;
		if(pair.first < main[middle])
			right = middle - 1;
		else
			left = middle + 1;
	}
	std::cout << "I LEFT " << left  << std::endl;
	main.insert(main.begin() + left,pair.first);
	for(size_t i = 0;i < main.size();i++)
		std::cout << main.at(i) << " ";
	std::cout << "-------------------------------------------------------------------------------------------------\n";

}
void PmergeMe::Pmergevector()
{
	std::vector<int> main;
	std::vector<std::pair<int,int> > pend;
	std::vector<size_t> seq;
	
	print_vvp();
	vector_mergin();
	// print_vvp();
	
	main.push_back(vp[0].first);
	main.push_back(vp[0].second);
	for (size_t i = 1; i < vp.size(); i++)
    	main.push_back(vp[i].second);
	std::cout << std::endl;
	for (size_t i = 1; i < vp.size(); i++)
    	pend.push_back(vp[i]);
	if(straggler == true)
		pend.push_back(std::make_pair(_straggler, __INT_MAX__));
	std::cout << "Main: ";
	for(size_t i = 0;i < main.size();i++)
		std::cout << main.at(i) << " ";
	std::cout << std::endl;
	std::cout << "Pend: ";
	for(size_t i = 0;i < pend.size();i++)
		std::cout << pend[i].first << " ";
	std::cout << std::endl;

	seq = jacobas(pend.size());
	size_t last_order = 0;
	for(size_t i= 0;i <seq.size();i++)
	{
		size_t order = seq[i];
		if(order > pend.size())
			order = pend.size();
		std::cout << "order: " << order << std::endl;
		while (order > last_order || i == 0)
		{
			binarysearch_start(pend[order],main);
			order--;
			if(i == 0)
				break;
		}
		last_order = seq[i];
	}
	std::cout << "Sorted: ";
	for(size_t i = 0;i < main.size();i++)
		std::cout << main.at(i) << " ";
	std::cout << std::endl;
}

void PmergeMe::parse_input(std::string s)
{
    std::istringstream ss(s);
	std::vector<int> vec;
	
    int x;
    while (ss >> x)
        vec.push_back(x);

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
	
}

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        PmergeMe cmerge;

        cmerge.parse_input(av[1]);
        cmerge.Pmergevector();
    }
    else
        std::cerr << "Invalid amount of arguments\n";
}
