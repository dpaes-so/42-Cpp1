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
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <limits>
#include <cstdlib>
#include <algorithm>



template <typename container>
void    print_container(container &cont)
{
    typename container::iterator it;
    it = cont.begin();
    while(it != cont.end())
    {
        // std::cout << " (" << it->first << ", " << it->second << ") ";
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}


class PmergeMe
{
    private:
        std::vector<int> vec;

        void    sort_rec(std::vector<int> &vec, size_t lvl, size_t p_num);
        void    vector_mergin_recursive(std::vector<int> &vec,size_t numbers_per_pair);
        void    vector_mergin_sort(size_t &numbers_per_pair,size_t &p_num);

        void    use_jacobsthal(size_t &numbers_per_pair, std::vector<int> &main, std::vector<int> &pend,size_t    &p_num);
        // Old functions (still declared if you still use them elsewhere)
        void    vector_mergin_recursive(std::vector<std::pair<int, int> > &vp,size_t left, size_t right);
        void    mergin_sort(std::vector<std::pair<int, int> > &vp,size_t left, size_t middle, size_t right);

        size_t    binarysearch(std::vector<int> &main_chain, std::vector<int> &pend, int to_compare, int n_per_pair, size_t right);
        std::vector<size_t> jacobsthal(size_t n);
        size_t find_bound(const std::vector<int> &vec,int pend_last,size_t block_size);


    public:
        void    vector_mergin();
        void    Pmergevector();
        void    print_vvp();
        void    print_output_vector();
        bool    parse_input(char *av[]);
};
#endif