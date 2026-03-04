/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:42:23 by Guille            #+#    #+#             */
/*   Updated: 2026/03/04 01:17:56 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void)
{
	int nb = std::rand() % 3;
	if (nb == 0)
		return (new A);
	else if (nb == 1)
		return (new B);
	else if (nb == 2)
		return (new C);
	return (NULL);
}
void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "type A\n";
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "type B\n";
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "type C\n";
}
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "type A\n";
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "type B\n";

		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "type C\n";
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}

		}
	}
	
}
