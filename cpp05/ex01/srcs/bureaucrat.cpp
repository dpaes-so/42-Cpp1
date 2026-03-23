/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:38:50 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/23 18:09:09 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

Bureaucrat::Bureaucrat(const std::string sname, int sgrade) : name(sname)
{
	std::cout << "Default construcopr" << std::endl;
	if (sgrade > 150)
		throw GradeTooLowException();
	if (sgrade < 1)
		throw GradeTooHighException();
	this->grade = sgrade;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Default destrcutor" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Too Low!");
}

void Bureaucrat::gradeincrement()
{
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
	try
	{
		if (grade > 149)
		{
			throw GradeTooHighException();
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
	return(this->name);
}

int Bureaucrat::getgrade() const
{
	return(this->grade);
}

void Bureaucrat::signForm(Form &F)
{
	if(!F.is_signed())
	{
		F.beSigned(*this);
		if(F.is_signed())
			std::cout << this->getname() << " signed " << F.getname() << std::endl;
		else
			std::cout << this->getname() << " couldn’t sign " << F.getname() << " because " << "grade is too low!" << std::endl;
	}
	else
	{
		std::cout << this->getname() << " couldn’t sign " << F.getname() << " because " << "its alredy signed!"<< std::endl;
	}
}
std::ostream &operator<<(std::ostream &stream,  Bureaucrat const &bure)
{
	stream << bure.getname() <<  " bureaucrat grade " << bure.getgrade();
	return(stream);
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &source)
{
	std::cout << "Copy assignment operator" <<std::endl;
	if(this != &source)
		this->grade = source.getgrade();
	return(*this);
}
