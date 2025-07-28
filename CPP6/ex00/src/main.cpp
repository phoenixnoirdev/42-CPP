/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 07:58:13 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/31 07:58:13 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Param.hpp"
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << GREEN << LOGO << CYAN << "Usage: ./ScalarConverter <value>" << RESET << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);

	return 0;
}

