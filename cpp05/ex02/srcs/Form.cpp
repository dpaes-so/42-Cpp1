/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:38:50 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/24 18:20:35 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/Bureaucrat.hpp"
#include "../incs/AForm.hpp"

AForm::AForm(const std::string sname, int sgrade_sign_req,
	int sgrade_exec_req) : name(sname), grade_sign_req(sgrade_sign_req), grade_exec_req(sgrade_exec_req)
{
    this->sign = false;
	if (sgrade_sign_req > 150 || sgrade_exec_req > 150)
		throw GradeTooLowException();
	if (sgrade_sign_req < 1 || sgrade_exec_req < 1)
		throw GradeTooHighException();
	std::cout << "Default Form constructor" << std::endl;
}
AForm::~AForm()
{
	std::cout << "Default Form destrcutor" << std::endl;
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