/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:18:43 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/20 18:20:05 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

int main()
{
    Bureaucrat *daniel;
    try
    {
        daniel = new Bureaucrat("burro",141);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
            
    std::cout << *daniel << std::endl;
    daniel->gradedecrement();
    daniel->gradedecrement();
    daniel->gradedecrement();
    daniel->gradedecrement();
    daniel->gradedecrement();
    daniel->gradedecrement();
    daniel->gradedecrement();
    daniel->gradedecrement();
    daniel->gradedecrement();
    daniel->gradedecrement();
    daniel->gradedecrement();
    daniel->gradedecrement();
    std::cout << *daniel << std::endl;
    delete daniel;
}