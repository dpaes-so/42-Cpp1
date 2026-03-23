/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:18:43 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/23 14:18:50 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

Bureaucrat *create_Bureaucrat(std::string name,int grade)
{
    Bureaucrat *b;
    
    try
    {
        b = new Bureaucrat(name,grade);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return(b);
}

int main()
{
    Bureaucrat *daniel;

    daniel = create_Bureaucrat("burro",141);
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