/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:38:50 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/26 14:57:37 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

Form::Form(const std::string sname, int sgrade_sign_req,
	int sgrade_exec_req) : name(sname), grade_sign_req(sgrade_sign_req), grade_exec_req(sgrade_exec_req)
{
    this->sign = false;
	if (sgrade_sign_req > 150 || sgrade_exec_req > 150)
		throw GradeTooLowException();
	if (sgrade_sign_req < 1 || sgrade_exec_req < 1)
		throw GradeTooHighException();
	std::cout << "Default Form constructor" << std::endl;
}
Form::~Form()
{
	std::cout << "Default Form destrcutor" << std::endl;
}

Form::Form(Form const &source) : 
	name(source.getname()) ,grade_sign_req(source.get_grade_sign_req()), grade_exec_req(source.get_grade_exec_req())
{
	std::cout << "Copy constructor" << std::endl;
	this->sign = source.sign;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Too High!(Form)");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Too Low!(Form)");
}

std::string Form::getname() const
{
	if((void *)this == NULL)
		return (NULL);
	return (this->name);
}

bool Form::is_signed() const
{
	if((void *)this == NULL)
		return (false);
	return (this->sign);
}

int Form::get_grade_exec_req() const
{
	if((void *)this == NULL)
		return (0);
	return (this->grade_exec_req);
}

int Form::get_grade_sign_req() const
{
	if((void *)this == NULL)
		return (0);
	return (this->grade_sign_req);
}

void Form::beSigned(Bureaucrat &boss)
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
std::ostream &operator<<(std::ostream &stream, Form const &F)
{
	if((void *)&F == NULL)
		return(stream);
	stream << "Form name:" << F.getname() << "\nIs signed:" << F.is_signed() << std::endl;
	stream << "Grade required to sign:" << F.get_grade_sign_req() << "\nGrade required to exec" << F.get_grade_exec_req();
	return (stream);
}

Form &Form::operator=(Form const &source)
{
	if((void *)&source == NULL || (void *)this == NULL)
		return (*this);
	std::cout << "Copy assignment operator" << std::endl;
	if (this != &source)
	{
		std::cout << "wtv am i here\n";
		this->sign = source.sign;
	}
	return (*this);
}