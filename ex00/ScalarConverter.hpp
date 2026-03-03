/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:31:34 by Guille            #+#    #+#             */
/*   Updated: 2026/03/03 21:52:58 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP	
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cerrno>
#include <iomanip>
#include <stdexcept>

class ScalarConverter {
	public:
		static void convert(const std::string& literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

		enum LiteralType {
			TYPE_CHAR,
			TYPE_INT,
			TYPE_FLOAT,
			TYPE_DOUBLE,
			TYPE_PSEUDO,
			TYPE_INVALID
		};

	    // Detección y conversión
		static LiteralType  detectType(const std::string& literal);
		static double       toDouble(const std::string& literal, LiteralType type);

		// Impresión
		static void         printChar(double value, bool isPseudo);
		static void         printInt(double value, bool isPseudo);
		static void         printFloat(double value);
		static void         printDouble(double value);
};

#endif