/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:30:00 by nqasem            #+#    #+#             */
/*   Updated: 2025/12/25 18:53:19 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

int main()
{
	Bureaucrat Ahmed("Ahmed", 75);
	Bureaucrat Talal("Talal", 150);
	Bureaucrat Abd("Abd", 2);
	Bureaucrat Final("Final", 149);

	Form formA("FormA", 50, 100);
	Form formB("FormB", 100, 150);

	Ahmed.signForm(formA);
	Talal.signForm(formB);
	Abd.signForm(formA);
	Final.signForm(formB);

    return 0;
}
