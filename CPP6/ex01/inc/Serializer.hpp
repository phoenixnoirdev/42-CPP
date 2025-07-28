/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:34:04 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/31 08:34:04 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Param.hpp"

//==============================
// LOGO IN LOG
//==============================
#define LOGO "Scalar Converter: "

class Serializer
{
private:
	//==============================
	// CONSTRUCTEUR
	//==============================

	Serializer();
	Serializer(const Serializer &obj);
	Serializer& operator=(const Serializer &obj);
	~Serializer();



public:

	//==============================
	// FONCTION
	//==============================

	static uintptr_t Serialize(Data *ptr);
	static  Data* Deserialize(uintptr_t raw);

};

#endif //SERIALIZER_HPP