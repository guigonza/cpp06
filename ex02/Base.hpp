/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:34:26 by Guille            #+#    #+#             */
/*   Updated: 2026/03/04 00:46:30 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP
# include <iostream>
# include <ctime>
# include <cstdlib>

class Base
{
	public:
		virtual ~Base();
};

Base*	generate(void);
void identify(Base* p);
void identify(Base& p);

#endif