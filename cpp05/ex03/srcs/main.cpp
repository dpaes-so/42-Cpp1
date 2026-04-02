/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:18:43 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/01 16:18:36 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/Intern.hpp"
#include "../incs/AForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/Bureaucrat.hpp"

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
	Intern	tester;
	AForm	*form;
	Bureaucrat smart("Daniel", 1);
    
	form = tester.makeForm("robotomy request","shrub");
	smart.executeForm(*form);
	smart.signForm(*form);
	delete form;
}