/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 23:21:42 by Guille            #+#    #+#             */
/*   Updated: 2026/03/04 00:24:50 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.number = 42;
	data.numberd = 42.6;
	data.numberf = 42.6f;
	data.string = "Cuarentaidos";
	Data *ptr;
	uintptr_t raw;
	
	std::cout << "\nOriginal Data address: " << &data << std::endl;
	raw = Serializer::serialize(&data);
	std::cout << "uintptr_t raw serialized: " << raw << std::endl;

	ptr = Serializer::deserialize(raw);
	std::cout << "uintptr_t raw deserialized: " << ptr << std::endl;
	if (ptr == &data)
		std::cout << "Success! Pointers are equal" << std::endl;
	else
		std::cout << "Failure! Pointers are diferent" << std::endl;
	
	std::cout << "\nData deserilized content: " << std::endl;
	std::cout << "Int: " << ptr->number << std::endl;
	std::cout << "Double: " << ptr->numberd << std::endl;
	std::cout << "Float: " << ptr->numberf << std::endl;
	std::cout << "String: " << ptr->string << std::endl;

	return (0);
}