/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 23:15:23 by Guille            #+#    #+#             */
/*   Updated: 2026/04/28 15:23:53 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::Serializer(const Serializer&){}
Serializer& Serializer::operator=(const Serializer&)
{
	return (*this);
}
Serializer::~Serializer(){}
uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data* 	 Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));	
}