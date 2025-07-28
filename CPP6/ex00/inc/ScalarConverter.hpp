/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 07:58:09 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/31 07:58:09 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "Param.hpp"

//==============================
// LOGO IN LOG
//==============================
#define LOGO "Scalar Converter: "

class ScalarConverter
{
	private:
		//==============================
		// CONSTRUCTEUR
		//==============================
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

		static void ConvChar(double value);
		static void ConvInt(double value);
		static void ConvDouble(double value);
		static void ConvFloat(double value);


	public:
		//==============================
		// FONCTION
		//==============================
		static void convert(std::string str);
};

#endif //SCALARCONVERTER_HPP