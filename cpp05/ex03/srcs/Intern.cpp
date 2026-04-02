/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:38:50 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/31 15:50:04 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include "../incs/Intern.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/PresidentialPardonForm.hpp"

AForm *create_form(std::string target,char lvl);

Intern::Intern()
{
	std::cout << "default Intern constructor" << std::endl;
}

Intern::Intern(std::string target)
{
	(void)target;
	std::cout << "Intern constructor" << std::endl;
}
Intern::~Intern()
{
	std::cout << "Default Intern destructor" << std::endl;
}

Intern::Intern(Intern const &source)
{
	(void)source;
	std::cout << "Copy Intern  constructor" << std::endl;
}
AForm *Intern::makeForm(std::string form_req,std::string target)
{
	std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *F;
	int type = 999;

	for(int i = 0;i < 3;i++)
	{
		if(form_req == types[i])
		{
			type = i;
			break ;
		}
	}
	F = NULL;
	switch (type)
	{
		case 0:
			F = new ShrubberyCreationForm(target);
			break;
		case 1:
			F = new RobotomyRequestForm(target);
			break;
		case 2:
			F = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Wrong form type" << std::endl;
			break;
	}
	return(F);
}

Intern &Intern::operator=(Intern const &source)
{
	if ((void *)&source == NULL || (void *)this == NULL)
		return (*this);
	std::cout << "Intern Copy assignment operator" << std::endl;
	return (*this);
}