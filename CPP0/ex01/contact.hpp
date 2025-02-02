/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacte.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:25:49 by phkevin           #+#    #+#             */
/*   Updated: 2025/01/24 11:59:56 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string FName, LName, NName, Num, Dark;

public:
	void	NewContacte(const std::string& fname, const std::string& lname, const std::string& nname, const std::string& num, const std::string& darksecret);
	std::string	GetFName() const;
	std::string	GetLName() const;
	std::string	GetNName() const;
	std::string	GetNum() const;
	std::string	GetDark() const;
};

#endif // CONTACT_HPP