/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:45:31 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/09 15:18:15 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Serialization.hpp"

int main()
{
	Data * d = new Data;

	d->s = "something";
		
	std::cout << "pre stuff something: " << &d->s << std::endl;
	std::cout << "og: " << d << std::endl;
	uintptr_t ser = Serializer::serialize(d);
	std::cout << "ser: " << ser << std::endl;
	Data *der  = Serializer::deserialize(ser);
	std::cout << "der: " << der << std::endl;
	std::cout << "post stuff something: " << &d->s << std::endl;

}