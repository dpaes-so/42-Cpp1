/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:38:50 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/26 15:29:51 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/Bureaucrat.hpp"
#include "../incs/AForm.hpp"

AForm::AForm(const std::string sname, int sgrade_sign_req,int sgrade_exec_req) : 
	name(sname), grade_sign_req(sgrade_sign_req), grade_exec_req(sgrade_exec_req)
{
    this->sign = false;
	if (sgrade_sign_req > 150 || sgrade_exec_req > 150)
		throw GradeTooLowException();
	if (sgrade_sign_req < 1 || sgrade_exec_req < 1)
		throw GradeTooHighException();
	std::cout << "AForm constructor" << std::endl;
}
AForm::~AForm()
{
	std::cout << "AForm destrcutor" << std::endl;
}

AForm::AForm(AForm const &source) : 
	name(source.getname()) ,grade_sign_req(source.get_grade_sign_req()), grade_exec_req(source.get_grade_exec_req())
{
	std::cout << "AForm Copy constructor" << std::endl;
	this->sign = source.sign;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Too High!(Form)");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Too Low!(Form)");
}

std::string AForm::getname() const
{
	if((void *)this == NULL)
		return (NULL);
	return (this->name);
}

bool AForm::is_signed() const
{
	if((void *)this == NULL)
		return (false);
	return (this->sign);
}

int AForm::get_grade_exec_req() const
{
	if((void *)this == NULL)
		return (0);
	return (this->grade_exec_req);
}

int AForm::get_grade_sign_req() const
{
	if((void *)this == NULL)
		return (0);
	return (this->grade_sign_req);
}

void AForm::beSigned(Bureaucrat &boss)
{
	if((void *)&boss == NULL)
		return ;
	try
	{
		if (this->grade_sign_req >= boss.getgrade())
		{
            this->sign = true;
		}
        else
            throw GradeTooLowException();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
std::ostream &operator<<(std::ostream &stream, AForm const &F)
{
	if((void *)&F == NULL)
		return(stream);
	stream << "Form name:" << F.getname() << "\nIs signed:" << F.is_signed() << std::endl;
	stream << "Grade required to sign:" << F.get_grade_sign_req() << "\nGrade required to exec" << F.get_grade_exec_req();
	return (stream);
}

AForm &AForm::operator=(AForm const &source)
{
	if((void *)&source == NULL || (void *)this == NULL)
		return (*this);
	std::cout << "AForm Copy assignment operator" << std::endl;
	if (this != &source)
	{
		this->sign = source.sign;
	}
	return (*this);
}