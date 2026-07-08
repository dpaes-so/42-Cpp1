#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <climits>

template <typename Container>
void print_container(Container &cont)
{
    typename Container::iterator it = cont.begin();

    while (it != cont.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int>		deq;

        void	sort_rec(std::vector<int> &vec, size_t lvl, size_t p_num);
        void	sort_rec_deq(std::deque<int> &deq, size_t lvl, size_t p_num);

        void	vector_mergin_recursive(std::vector<int> &vec,size_t numbers_per_pair);
        void	deque_mergin_recursive(std::deque<int> &deq,size_t numbers_per_pair);

        void	vector_mergin_sort(size_t &numbers_per_pair,size_t &p_num);
        void	deque_mergin_sort(size_t &numbers_per_pair,size_t &p_num);

        void use_jacobsthal(size_t &numbers_per_pair, std::vector<int> &main, std::vector<int> &pend, std::vector<size_t> &main_id, std::vector<size_t> &pend_id, size_t &p_num);
        void use_jacobsthal_deq(size_t &numbers_per_pair, std::deque<int> &main, std::deque<int> &pend, std::deque<size_t> &main_id, std::deque<size_t> &pend_id, size_t &p_num);


        size_t	binarysearch(std::vector<int> &main_chain,int to_compare,int n_per_pair,size_t right);
        size_t	binarysearch_deq(std::deque<int> &main_chain,int to_compare,int n_per_pair,size_t right);

        size_t find_bound_id(const std::vector<size_t> &main_id, size_t pend_id);
        size_t find_bound_id_deq(const std::deque<size_t> &main_id, size_t pend_id);


        std::vector<size_t>jacobsthal(size_t n);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe();
        bool parse_input(char *av[]);
        void Pmergevector();
        void Pmergedeque();
        void vector_mergin();
        void deque_mergin();

};

#endif