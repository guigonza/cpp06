/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 01:13:37 by Guille            #+#    #+#             */
/*   Updated: 2026/03/04 01:16:50 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Base.hpp"
#include"A.hpp"
#include"B.hpp"
#include"C.hpp"

int main(void)
{
	std::srand(std::time(0));
	Base* base = generate();

    std::cout << "Identify using pointer: ";
    identify(base);

    std::cout << "Identify using reference: ";
    identify(*base);

    delete base;
    return (0);
}