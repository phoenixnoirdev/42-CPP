/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:08:12 by phkevin           #+#    #+#             */
/*   Updated: 2025/03/10 12:48:04 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* strPTR = &str;
    std::string& strREF = str;

    std::cout << "Adress str: " << &str << std::endl;
    std::cout << "Adress str via PTR: " << strPTR << std::endl;
    std::cout << "Adress str via REF: " << &strREF << std::endl;

    std::cout << "\nstr value: " << str << std::endl;
    std::cout << "str value via PTR: " << *strPTR << std::endl;
    std::cout << "str value via REF: " << strREF << std::endl;
    
    return 0;
}