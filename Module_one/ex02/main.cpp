/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:31:45 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/28 19:09:14 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(){
	std::string st= "HI THIS IS BRAIN";
	std::string *stringPTR = &st; 
	std::string &stringREF = st;

	std::cout << &st << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << st << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

}