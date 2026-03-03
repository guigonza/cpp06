/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guille <Guille@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:34:40 by Guille            #+#    #+#             */
/*   Updated: 2026/03/03 22:16:07 by Guille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter&){}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
	return (*this);
}
ScalarConverter::~ScalarConverter(){}

ScalarConverter::LiteralType ScalarConverter::detectType(const std::string& literal)
{
	char *endptr;
	errno = 0;
	if (literal.empty())
		return (TYPE_INVALID);
	if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "nanf" || literal == "+inff" || literal == "-inff")
		return (TYPE_PSEUDO);
	else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return (TYPE_CHAR);
	errno = 0;
	std::strtol(literal.c_str(), &endptr, 10);
	if (*endptr == '\0' && errno != ERANGE)
		return (TYPE_INT);
	errno = 0;
	std::strtof(literal.c_str(), &endptr);
	if (*endptr == 'f' && *(endptr + 1) == '\0')
		return (TYPE_FLOAT);
	std::strtod(literal.c_str(), &endptr);
	if (*endptr == '\0')
		return (TYPE_DOUBLE);
	return (TYPE_INVALID);
}

double ScalarConverter::toDouble(const std::string& literal, LiteralType type)
{
    switch (type)
    {
        case TYPE_CHAR:
			return (static_cast<double>(literal[1]));
		case TYPE_INT:	
			return (static_cast<double>(std::strtol(literal.c_str(), NULL, 10))); 
        case TYPE_FLOAT:
			return (static_cast<double>(std::strtof(literal.c_str(), NULL))); 
        case TYPE_DOUBLE:
			return (std::strtod(literal.c_str(), NULL));
        case TYPE_PSEUDO:
			if (literal == "nanf" || literal == "+inff" || literal == "-inff")
				return (static_cast<double>(std::strtof(literal.c_str(), NULL)));
			else
				return (std::strtod(literal.c_str(), NULL));
        default:           
			return 0.0;
    }
}
void	ScalarConverter::printChar(double value, bool isPseudo)
{
	if (isPseudo)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (value < 0 || value > 127 || std::isnan(value))
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (!std::isprint((int)value))
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}
void	ScalarConverter::printInt(double value, bool isPseudo)
{
	if (isPseudo || std::isnan(value) || std::isinf(value))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (value < INT_MIN || value > INT_MAX)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}
void	ScalarConverter::printFloat(double value)
{
	if (std::isnan(value))
	{
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		if (value < 0)
		{
			std::cout << "float: -inff" << std::endl;
			return ;
		}
		std::cout << "float: +inff" << std::endl;
		return ;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}
void	ScalarConverter::printDouble(double value)
{
	if (std::isnan(value))
	{
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		if (value < 0)
		{
			std::cout << "double: -inf" << std::endl;
			return ;
		}
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}
void	ScalarConverter::convert(const std::string& literal)
{
	LiteralType type = detectType(literal);
	if (type == TYPE_INVALID)
        throw std::invalid_argument("Invalid literal: " + literal);
	double		value = toDouble(literal, type);
	bool		isPseudo = (type == TYPE_PSEUDO);

	printChar(value, isPseudo);
	printInt(value, isPseudo);
	printFloat(value);
	printDouble(value);
}