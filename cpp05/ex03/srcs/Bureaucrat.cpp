/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:38:50 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/02 15:10:35 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/AForm.hpp"

Bureaucrat::Bureaucrat(void) : name("default")
{
	std::cout << "default Bureaucrat constructor" << std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string sname, int sgrade) : name(sname)
{
	std::cout << "Bureaucrat constructor" << std::endl;
	if (sgrade > 150)
		throw GradeTooLowException();
	if (sgrade < 1)
		throw GradeTooHighException();
	this->grade = sgrade;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &source) : name(source.getname())
{
	std::cout << "Bureaucrat Copy constructor" << std::endl;
	this->grade = source.getgrade();
	
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too High!(Bureaucrat)");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Too Low!(Bureaucrat)");
}


void Bureaucrat::gradeincrement()
{
	if ((void *)this == NULL)
		return ;
	try
	{
		if (grade < 2)
		{
			throw GradeTooHighException();
		}
		this->grade--;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::gradedecrement()
{
	if ((void *)this == NULL)
		return ;
	try
	{
		if (grade > 149)
		{
			throw GradeTooLowException();
		}
		this->grade++;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

std::string Bureaucrat::getname() const
{
	if((void *)this == NULL)
		return ("\0");
	return (this->name);
}

int Bureaucrat::getgrade() const
{
	if((void *)this == NULL)
		return (0);
	return (this->grade);
}

void Bureaucrat::signForm(AForm &F)
{
	if((void *)&F == NULL || (void *)this == NULL)
		return ;
	try
	{
		if(F.is_signed())
			throw AForm::AlreadySignedException();
		F.beSigned(*this);
		if(F.is_signed())
			std::cout << this->getname() << " signed " << F.getname() << std::endl;
		else
			std::cout << this->getname() << " couldn’t sign " << F.getname() << " because " << "grade is too low!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	if((void *)&form == NULL || (void *)this == NULL)
		return ;
	
	try
	{
		if(!form.is_signed())
			throw AForm::NotSignedException();
		try
		{
			form.execute(*this);
			std::cout << this->getname() << " excuted " << form.getname() << std::endl; 

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	catch(const std::exception& e)
	{
		std::cerr  << this->getname() << " couldn’t execute " << form.getname() << " because " << e.what() << '\n';
	}
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bure)
{
	if ((void *)&bure == NULL)
		return (stream);
	stream << "Bureaucrat information: " << std::endl << " -bureaucrat name: " << bure.getname() << std::endl << " -bureaucrat grade: " << bure.getgrade();
	return (stream);
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &source)
{
	if((void *)&source == NULL || (void *)this == NULL)
		return (*this);
	std::cout << "Bureaucrat Copy assignment operator" << std::endl;
	if (this != &source)
	{
		this->grade = source.getgrade();
	}
	return (*this);
}
