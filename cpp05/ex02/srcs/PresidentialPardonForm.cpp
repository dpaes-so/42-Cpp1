/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:38:50 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/31 15:50:04 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include "../incs/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm_default",
	145, 137)
{
	this->target = target;
	std::cout << "default PresidentialPardonForm Form constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm",
	145, 137)
{
	this->target = target;
	std::cout << "PresidentialPardonForm Form constructor" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Default PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &source) : AForm("PresidentialPardonForm",
	145, 137)
{
	std::cout << "Copy PresidentialPardonForm  constructor" << std::endl;
	this->target = source.target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if ((void *)&executor == NULL || (void *)this == NULL)
		return ;
	if(executor.getgrade() > this->get_grade_exec_req())
		throw GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, PresidentialPardonForm const &F)
{
	if ((void *)&F == NULL)
		return (stream);
	stream << "Form name:" << F.getname() << "\nIs signed:" << F.is_signed() << std::endl;
	stream << "Grade required to sign:" << F.get_grade_sign_req() << "\nGrade required to exec" << F.get_grade_exec_req();
	return (stream);
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &source)
{
	if ((void *)&source == NULL || (void *)this == NULL)
		return (*this);
	std::cout << "PresidentialPardonForm Copy assignment operator" << std::endl;
	if (this != &source)
	{
		this->target = source.target;
	}
	return (*this);
}