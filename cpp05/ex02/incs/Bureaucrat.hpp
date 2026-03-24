/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:19:44 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/24 18:21:46 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class AForm;

class Bureaucrat
{
  private:
	const std::string name;
	int grade;

  public:
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &source);
	Bureaucrat(Bureaucrat const &source);
	void gradeincrement();
	void gradedecrement();
	std::string getname() const;
	int getgrade() const;
	void signForm(AForm &F);
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bure);
#endif