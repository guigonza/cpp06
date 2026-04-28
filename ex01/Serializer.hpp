/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:44:27 by Guille            #+#    #+#             */
/*   Updated: 2026/04/28 15:25:06 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP	
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>
#include <iostream>

#ifndef DATA
# define DATA
struct Data
{
	int			number;
	std::string string;
	float		numberf;
	double		numberd;
};
#endif


class Serializer {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* 	 deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);
		~Serializer();

};

#endif