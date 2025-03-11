/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:07:29 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/11 08:58:25 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Constructeur par défaut de la classe Point.
 * 
 * Initialise un point avec des coordonnées (0,0) en utilisant
 * des objets Fixed pour garantir la précision des calculs.
 */
Point::Point() : FixedX(0), FixedY(0)
{
	
}

/**
 * @brief Constructeur paramétré de la classe Point.
 * 
 * Initialise un point avec les coordonnées spécifiées.
 * 
 * @param x Coordonnée X sous forme d'un objet Fixed.
 * @param y Coordonnée Y sous forme d'un objet Fixed.
 */
Point::Point(const Fixed x, const Fixed y)
{
	FixedX = x;
	FixedY = y;
}

/**
 * @brief Constructeur de copie de la classe Point.
 * 
 * Crée un nouveau point en copiant les coordonnées d'un autre point.
 * 
 * @param pt Point à copier.
 */
Point::Point(const Point &pt)
{
	FixedX = pt.getx();
	FixedY = pt.gety();
}

/**
 * @brief Surcharge de l'opérateur d'assignation pour la classe Point.
 * 
 * Assigne les coordonnées d'un autre point à l'objet actuel. 
 * Si l'objet actuel n'est pas le même que celui à assigner, 
 * les coordonnées sont copiées.
 * 
 * @param other Point à assigner.
 * @return Point& Référence vers l'objet actuel.
 */
Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->FixedX = other.getx();
		this->FixedY = other.gety();
	}
		
	return *this;
}

/**
 * @brief Retourne la coordonnée x du point.
 * 
 * Cette fonction retourne la valeur de la coordonnée x du point 
 * sous forme de nombre à virgule flottante.
 * 
 * @return float Coordonnée x du point sous forme flottante.
 */
float Point::getx() const
{
	return FixedX.toFloat();
}

/**
 * @brief Retourne la coordonnée y du point.
 * 
 * Cette fonction retourne la valeur de la coordonnée y du point 
 * sous forme de nombre à virgule flottante.
 * 
 * @return float Coordonnée y du point sous forme flottante.
 */
float Point::gety() const
{
	return FixedY.toFloat();
}

/**
 * @brief Destructeur de la classe Point.
 * 
 * Ce destructeur est appelé lorsqu'un objet de la classe Point est détruit. 
 * Il ne réalise aucune opération particulière ici car la classe ne possède 
 * pas de ressources dynamiques à libérer.
 */
Point::~Point()
{
	
}

