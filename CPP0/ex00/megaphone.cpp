/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:22:01 by phkevin           #+#    #+#             */
/*   Updated: 2025/01/24 11:26:23 by phkevin          ###   Luxembour.lu      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        for (int i = 0; argv[i] != NULL; i++)
        {
            if (i > 0)
            {
                for (int ii = 0; ii < (int)strlen(argv[i]); ii++)
                    std::cout << (char)toupper(argv[i][ii]);
                
                if(i < (argc - 1))
                    std::cout << " ";
            }
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" << std::endl;
    return 0;
}