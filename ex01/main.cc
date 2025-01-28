#include "PhoneBook.h"
#include <iostream>
#include <sstream>

void	add_contact(Phonebook &phonebook)
{
	std::string	name, last_name, darkest_secret, number_str;
	int	number;

	std::cout << "Insert name: ";
	std::getline(std::cin, name);
	std::cout << "Insert last name: ";
	std::getline(std::cin, last_name);
	while (true)
	{
		std::cout << "Insert number: ";
		if (!std::getline(std::cin, number_str))
		{
			std::cout << std::endl;
			std::cout << "EOF detected! Exiting" << std::endl;
			phonebook.exit();
			return;
		}
		std::stringstream string_stream(number_str);
		if (string_stream >> number)
			break;
		std::cout << "Invalid number format. Please enter a valid integer." << std::endl;
	}
	std::cout << "Insert darkest secret: ";
	std::getline(std::cin, darkest_secret);
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
