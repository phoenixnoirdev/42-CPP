/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:01:50 by phkevin           #+#    #+#             */
/*   Updated: 2025/02/24 15:15:25 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include "contact.hpp"

const int MaxSize = 8;
const int MaxCharSize = 10;

class PhoneBook
{
private:
	Contact book[MaxSize];

public:
	void	AddPhoneBook(const std::string& fname, const std::string& lname, const std::string& nname, const std::string& num, const std::string& darksecret);
	void	GetAll() const;
	void	GetIndex(int i) const;
};

#endif // PHONEBOOK_HPP