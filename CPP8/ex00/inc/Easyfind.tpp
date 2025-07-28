/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:53:36 by phkevin           #+#    #+#             */
/*   Updated: 2025/04/12 00:53:36 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

/**
 * @brief Recherche une valeur dans un conteneur et l'affiche si trouvee.
 *
 * Utilise std::find pour rechercher une valeur donnee dans un conteneur.
 * Si la valeur est trouvee, elle est affichee avec sa position.
 * Sinon, une exception ExcepValue est lancee.
 *
 * @tparam T Le type du conteneur (doit avoir begin(), end() et iterator).
 * @param cont Le conteneur dans lequel chercher la valeur.
 * @param val La valeur a rechercher dans le conteneur.
 *
 * @throws ExcepValue Si la valeur n'est pas trouvee dans le conteneur.
 */
template <typename T>
void easyfind(T& cont, int val)
{
    typename T::iterator it;
    
    it = std::find(cont.begin(), cont.end(), val);

    if (it == cont.end())
        throw ExcepValue();

    if (std::string(LANG) == "FR")
      std::cout << GREEN << LOGO  << CYAN << *it << RESET << " Trouver a la position " << CYAN << std::distance(cont.begin(), it) << RESET << std::endl;
    else
      std::cout << GREEN << LOGO  << CYAN << *it << RESET << " Find at position " << CYAN << std::distance(cont.begin(), it) << RESET << std::endl;
}

/**
 * @brief Retourne le message d'erreur pour l'exception ExcepValue.
 *
 * Cette methode est surchargee depuis std::exception et indique que la 
 * valeur recherchee n'a pas ete trouvee dans le conteneur.
 *
 * @return Un pointeur vers une chaine de caractere contenant le message 
 *         d'erreur.
 */
const char *ExcepValue::what() const throw()
{

  if (std::string(LANG) == "FR")
    return (YELLOW LOGOEXCE RED "La valeur n'a pas ete trouver dans le conteneur." RESET);
  else
    return (YELLOW LOGOEXCE RED "The value was not found in the container." RESET);
}