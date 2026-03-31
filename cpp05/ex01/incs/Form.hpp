/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:19:44 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/03/26 16:11:45 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form
{
  private:
	const std::string name;
	bool sign;
	const int grade_sign_req;
	const int grade_exec_req;

  public:
	Form();
	Form(const std::string sname, int sgrade_sign_req, int grade_exec_req);
	~Form();
	Form &operator=(Form const &source);
	Form(Form const &source);
	std::string getname() const;
	bool is_signed() const;
	int get_grade_exec_req() const;
	int get_grade_sign_req() const;
	void beSigned(Bureaucrat &boss);

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

std::ostream &operator<<(std::ostream &stream, const Form &bure);
#endif