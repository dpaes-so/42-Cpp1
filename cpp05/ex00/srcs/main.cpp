/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:18:43 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/24 15:50:44 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

Bureaucrat *create_Bureaucrat(std::string name,int grade)
{
    Bureaucrat *b;
    
    try
    {
        b = new Bureaucrat(name,grade);
        return(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return(NULL);
}

int main()
{
    Bureaucrat *daniel;

    daniel = create_Bureaucrat("burro",170);
    std::cout << *daniel << std::endl;
    Bureaucrat *diogo = create_Bureaucrat("smort",130);
    
    *diogo = *daniel;
    *daniel=*diogo;
    diogo->gradedecrement();
    daniel->getname();
    // daniel->gradedecrement();
    // daniel->gradedecrement();
    // daniel->gradedecrement();
    // daniel->gradedecrement();
    // daniel->gradedecrement();
    // daniel->gradedecrement();
    // daniel->gradedecrement();
    // daniel->gradedecrement();
    // daniel->gradedecrement();
    // daniel->gradedecrement();
    // daniel->gradedecrement();
    // daniel->gradedecrement();
    std::cout << *daniel << std::endl;
    delete daniel;
    delete diogo;

}


// int main()
// {
//     Bureaucrat daniel("daniel",110);

//     // daniel = create_Bureaucrat("burro",140);
//     // std::cout << *daniel << std::endl;
//     Bureaucrat diogo("diogo",140);
    
//     daniel = diogo;
//     diogo.gradedecrement();
//     daniel.gradedecrement();
//     daniel.gradedecrement();
//     daniel.gradedecrement();
//     daniel.gradedecrement();
//     daniel.gradedecrement();
//     daniel.gradedecrement();
//     daniel.gradedecrement();
//     daniel.gradedecrement();
//     daniel.gradedecrement();
//     daniel.gradedecrement();
//     daniel.gradedecrement();
//     daniel.gradedecrement();
//     std::cout << daniel << std::endl;
//     // delete daniel;
//     // delete diogo;
// }