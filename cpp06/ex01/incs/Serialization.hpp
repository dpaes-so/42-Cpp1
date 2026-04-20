/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:49:22 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/09 14:43:05 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZATION_HPP

# define SERIALIZATION_HPP

#include <stdint.h>
#include <iostream>

struct Data
{
	std::string s;	
};

class Serializer 
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &Serializer);
		Serializer &operator=(const Serializer &Serializer);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
#endif