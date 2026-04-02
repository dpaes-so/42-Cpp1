/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:38:50 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/31 15:50:04 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/AForm.hpp"
#include "../incs/Bureaucrat.hpp"
#include "../incs/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm_default",
	72, 45)
{
	this->target = target;
	std::cout << "default RobotomyRequestForm Form constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm",
	72, 45)
{
	this->target = target;
	std::cout << "RobotomyRequestForm Form constructor" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Default RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &source) : AForm("RobotomyRequestForm",
	72, 45)
{
	std::cout << "Copy RobotomyRequestForm  constructor" << std::endl;
	this->target = source.target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if ((void *)&executor == NULL || (void *)this == NULL)
		return ;
	if(executor.getgrade() > this->get_grade_exec_req())
		throw GradeTooLowException();
	int res;
	res = rand() % 2;
	if (res == 0)
		std::cout << "tik… whirr… ZZZZZT… ding (drilling noises)" << std::endl;
	else
		std::cout << "tik… whirr… ZZZZZT… err (dying noises)" << std::endl;

}

std::ostream &operator<<(std::ostream &stream, RobotomyRequestForm const &F)
{
	if ((void *)&F == NULL)
		return (stream);
	stream << "Form name:" << F.getname() << "\nIs signed:" << F.is_signed() << std::endl;
	stream << "Grade required to sign:" << F.get_grade_sign_req() << "\nGrade required to exec" << F.get_grade_exec_req();
	return (stream);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &source)
{
	if ((void *)&source == NULL || (void *)this == NULL)
		return (*this);
	std::cout << "RobotomyRequestForm Copy assignment operator" << std::endl;
	if (this != &source)
	{
		this->target = source.target;
	}
	return (*this);
}