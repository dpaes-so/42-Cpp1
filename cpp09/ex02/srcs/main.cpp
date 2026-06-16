/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finn <finn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/06/16 15:36:46 by finn             ###   ########.fr       */
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
void PmergeMe::Pmergevector()
{
	std::vector<int> main;
	std::vector<std::pair<int,int> > pend;
	
	print_vvp();
	std::sort(vp.begin(), vp.end(), pair_snd_big_cmp);
	print_vvp();
	
	main.push_back(vp[0].first);
	main.push_back(vp[0].second);
	for (size_t i = 1; i < vp.size(); i++)
    	main.push_back(vp[i].second);
	for(size_t i = 0;i < main.size();i++)
	{
		std::cout << main.at(i) << " ";
	}
	std::cout << std::endl;
	for (size_t i = 1; i < vp.size(); i++)
    	pend.push_back(vp[i]);
	if(straggler == true)
		pend.push_back(std::make_pair(_straggler, __INT_MAX__));
	
	for (size_t i = 0; i < pend.size(); i++)
	{
		int value = pend[i].first;
		int boundValue = pend[i].second;

		size_t limit = main.size();

		if (boundValue != __INT_MAX__)
		{
			for (size_t j = 0; j < main.size(); j++)
			{
				if (main[j] == boundValue)
				{
					limit = j;
					break;
				}
			}
		}
		size_t pos = std::lower_bound(main.begin(),main.begin() + limit,value) - main.begin();
		main.insert(main.begin() + pos, value);
	}
	for(size_t i = 0;i < main.size();i++)
	{
		std::cout << main.at(i) << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::parse_input(std::string s)
{
    std::istringstream ss(s);

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
