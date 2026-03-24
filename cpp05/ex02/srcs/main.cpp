/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:18:43 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/24 18:21:16 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/AForm.hpp"


AForm *create_Form(std::string name,int rsign,int rexec)
{
    AForm *f;
    
    try
    {
        f = new AForm(name,rsign,rexec);
        return(f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return(NULL);
}

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
    AForm *F;
    F = create_Form("Form",145,2);
    daniel = create_Bureaucrat("daniel",150);
    std::cout << *daniel << std::endl;
    daniel->signForm(*F);
    std::cout  << "---------------------------------------------------" << std::endl;
    Bureaucrat *diogo;
    diogo = create_Bureaucrat("diogo",141);
    std::cout << *diogo << std::endl;
    diogo->signForm(*F);
    delete daniel;
    delete diogo;
    delete F;
}