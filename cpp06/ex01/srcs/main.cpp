/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:45:31 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/23 14:33:59 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Serialization.hpp"

int main()
{
	Data * d = new Data;
	d->s = "something";	

	uintptr_t ser = Serializer::serialize(d);
	Data *der = Serializer::deserialize(ser);

	std::cout << "Original address: " << d << std::endl;
	std::cout << "Serialized: 	  0x" << ser << std::endl;
	std::cout << "Deserialized:	  " << der << std::endl;

	if (der == d)
		std::cout << "Pointers match" << std::endl;
	else
		std::cout << "Pointers don't match" << std::endl;
	delete (d);
	return 0;
}