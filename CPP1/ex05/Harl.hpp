/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:29:49 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/03 10:29:56 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Harl
{
private:
	void	debug();
	void	info();
	void	warning();
	void	error();

public:
	void	complain(std::string level);
};
#endif // HARL_HPP