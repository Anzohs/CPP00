/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:25:49 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/24 22:39:03 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <cctype>
#include <iostream>
#include <sstream>

static std::string 	get_var(Phonebook &phonebook, std::string message)
{
	std::string str;

	while (str.length() < 1)
	{
		std::cout << message;
		if (!std::getline(std::cin, str))
		{
			std::cout << std::endl;
			std::cout << "EOF detected! Exiting" << std::endl;
			phonebook.exit();
			return ("");
		}
		if (str.length() == 0)
			std::cout << "Can't pass empty string" << std::endl;
	}
	return (str);
}

static bool is_number(const std::string &s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}

static int	get_number(Phonebook &phonebook)
{
	std::string number_str;
	int	number;

	while (number_str.length() < 1)
	{
		std::cout << "Insert number: ";
		if (!std::getline(std::cin, number_str))
		{
			std::cout << std::endl;
			std::cout << "EOF detected! Exiting" << std::endl;
			phonebook.exit();
			return (-1);
		}
		std::stringstream string_stream(number_str);
		if (is_number(number_str) && string_stream >> number)
			break;
		std::cout << "Invalid number format. Please enter a valid integer.";
		number_str = "";
		std::cout << std::endl;
	}
	return  number;
}

void	add_contact(Phonebook &phonebook)
{
	std::string	name, last_name, darkest_secret, number_str;
	int	number;

	name = get_var(phonebook, "Insert First name: ");
	if (!name[0])
		return;
	last_name = get_var(phonebook, "Insert Last name: ");
	if (!last_name[0])
		return;
	number = get_number(phonebook);
	if (number < 0)
		return;
	darkest_secret = get_var(phonebook, "Insert Darkest secret: ");
	if (!darkest_secret[0])
		return;
	phonebook.add(name, number, last_name, darkest_secret);
}

void	search_contact(Phonebook &phonebook)
{
	int	index;
	std::string	index_str;

	phonebook.print();
	std::cout << "Enter the index of the contact to display: ";
	std::getline(std::cin, index_str);
	std::stringstream ss(index_str);
	if (!(ss >> index))
	{
		std::cout << "Invalid index format." << std::endl;
		return;
	}
	phonebook.search(index);
}

int	main()
{
	Phonebook phonebook;
	std::string command;

	phonebook = Phonebook();
	while (!phonebook.close())
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl;
			std::cout << "Input error or EOF detected. Exiting." << std::endl;
			break;
		}
		if (command == "ADD")
			add_contact(phonebook);
		else if (command == "SEARCH")
			search_contact(phonebook);
		else if (command == "EXIT")
			phonebook.exit();
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
	}
	return 0;
}
