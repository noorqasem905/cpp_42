/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:22:07 by nqasem            #+#    #+#             */
/*   Updated: 2025/07/31 20:45:00 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

std::string ft_replace(const std::string &line, const std::string &s1, const std::string &s2)
{
	std::string result = line;
	size_t pos = 0;
	while ((pos = result.find(s1, pos)) != std::string::npos)
	{
		result.erase(pos, s1.length());
		result.insert(pos, s2);
		pos += s2.length();
	}
	return result;
}

int openFile(char **av, std::ifstream &file_inb, std::fstream &file_outb)
{
	if (av[1] == NULL)
	{
		std::cerr << RED << "Error: No file name provided." << RESET << std::endl;
		return (1);
	}
	file_inb.open(av[1], std::ios::in);
	if (!file_inb.is_open())
	{
		std::cerr << RED << "Error: Could not open file " << av[1] << RESET << std::endl;
		return (1);
	}
	const std::string rep_filename = av[1] + std::string(".replace");
	file_outb.open(rep_filename.c_str(), std::ios::out | std::ios::trunc);
	if (!file_outb.is_open())
	{
		std::cerr << RED << "Error: Could not create output file " << rep_filename << RESET << std::endl;
		return (1);
	}
	return (0);
}

int main(int ac, char **av) 
{
	if (ac != 4) 
	{
		std::cerr << YELLOW << "Usage: " << av[0] << " <filename> <string_to_replace> <replacement_string>" << RESET << std::endl;
		std::cerr << RED << "Error: Please provide exactly three arguments." << RESET << std::endl;
		return (1);
	}
	std::ifstream 	file_in;
	std::fstream 	file_out;
	std::string 	s1 = av[2];
	std::string 	s3 = av[3];
	std::string		filename = av[1];
	std::string 	line;
	
	if (openFile(av, file_in, file_out) != 0)
		return (1);
	
	while (getline(file_in, line))
	{
		line = ft_replace(line, s1, s3);
		file_out << line << std::endl;
	}
	file_in.close();
	file_out.close();
	std::cout << GREEN << "✓ Replacement completed successfully" << RESET << std::endl;
	std::cout << CYAN << "Output saved to: " << YELLOW << filename << ".replace" << RESET << std::endl;

	return 0;
}