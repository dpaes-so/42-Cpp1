/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:38:50 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/26 17:08:50 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/Bureaucrat.hpp"
#include "../incs/AForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm_default",145,137)
{
	this->target = target;
	std::cout << "default ShrubberyCreationForm Form constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm",145,137)
{
	this->target = target;
	std::cout << "ShrubberyCreationForm Form constructor" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default ShrubberyCreationForm destrcutor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &source) : AForm("ShrubberyCreationForm",145,137)
{
	std::cout << "Copy ShrubberyCreationForm  constructor" << std::endl;
	this->target = source.target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout << "laranjas" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, ShrubberyCreationForm const &F)
{
	if((void *)&F == NULL)
		return(stream);
	stream << "Form name:" << F.getname() << "\nIs signed:" << F.is_signed() << std::endl;
	stream << "Grade required to sign:" << F.get_grade_sign_req() << "\nGrade required to exec" << F.get_grade_exec_req();
	return (stream);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &source)
{
	if((void *)&source == NULL || (void *)this == NULL)
		return (*this);
	std::cout << "ShrubberyCreationForm Copy assignment operator" << std::endl;
	if (this != &source)
	{
		this->target = source.target;
	}
	return (*this);
}