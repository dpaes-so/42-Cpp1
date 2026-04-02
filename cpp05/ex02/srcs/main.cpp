/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:18:43 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/01 16:10:58 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/AForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/PresidentialPardonForm.hpp"
#include <ctime>

AForm *create_form(std::string target,char lvl)
{
    AForm *f;
    
    try
    {
        switch (lvl)
        {
            case 'S':
                f = new ShrubberyCreationForm(target);
                    return(f);
                break;
            case 'R':
                f = new RobotomyRequestForm(target);
                    return(f);
                break;
            case 'P':
                f = new PresidentialPardonForm(target);
                    return(f);
                break;
            default:
                std::cout << "Invalid form type" << std::endl;
                break;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return(NULL);
}

Bureaucrat *create_bureaucrat(std::string name,int grade)
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

void	delete_vars(Bureaucrat **bures, AForm **forms)
{
	int	i = 2;

	while(i >= 0)
	{
		if (bures[i])
			delete bures[i];
		if (forms[i])
			delete forms[i];
		i--;
	}
}

int main()
{
	srand(time(0));
	Bureaucrat	*bures[3];
	AForm		*forms[3];
	bures[0] = create_bureaucrat("Low", 120);
	bures[1] = create_bureaucrat("Mid", 30);
	bures[2] = create_bureaucrat("High", 1);
	forms[0] = create_form("fuck u", 'S');
	forms[1] = create_form("Robot", 'R');
	forms[2] = create_form("President", 'P');
	std::cout << "-----------------------------------------------------" << std::endl;
	
	bures[0]->signForm(*forms[0]);
	std::cout << std::endl;
	
    bures[0]->executeForm(*forms[0]);
	std::cout << *bures[0] << std::endl;
	std::cout << *forms[0] << std::endl;

	bures[1]->signForm(*forms[1]);
	std::cout << std::endl;

    bures[1]->executeForm(*forms[1]);
	std::cout << *bures[1] << std::endl;
	std::cout << *forms[1] << std::endl;

    bures[2]->signForm(*forms[2]);
	std::cout << std::endl;

    bures[2]->executeForm(*forms[2]);
	std::cout << *bures[2] << std::endl;
	std::cout << *forms[2] << std::endl;

	bures[2]->signForm(*forms[1]);//resign
    
	Bureaucrat *fail = create_bureaucrat("Failure", 0);
    
    std::cout << std::endl;
    std::cout << std::endl;
    delete fail;
    delete_vars(bures,forms);
    std::cout << "-----------------------------------------------------" << std::endl;
}