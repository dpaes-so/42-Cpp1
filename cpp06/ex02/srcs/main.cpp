/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:45:31 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/04/20 18:44:16 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Base.hpp"

int main()
{
	srand(time(0));
	Base *thing = generate();
	Base &reskin = *thing;
	identify(thing);
	identify(reskin);

	delete thing;
	return (0);
}