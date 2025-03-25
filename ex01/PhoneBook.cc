/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cc                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:25:37 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/24 22:25:39 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"


Phonebook::Phonebook()
{
	this->index = 0;
	this->e = false;
}


Phonebook::~Phonebook(){}

int	Phonebook::get_index()
{
	if (this->index == 8)
		this->index = 0;
	return (this->index);
}

void	Phonebook::add(std::string name, int number, std::string last_name, std::string darkest)
{
	Contact c = Contact();
	c.set_name(name);
	c.set_number(number);
	c.set_lastname(last_name);
	c.set_darkest(darkest);
	this->c[this->get_index()] = c;
	this->index++;
}

bool	Phonebook::close(void)
{
	return (this->e);
}

std::string Phonebook::truncate(const std::string& str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void	Phonebook::print()
{
	std::cout << std::setw(10) << "Index" << "|"
	<< std::setw(10) << "First Name" << "|"
	<< std::setw(10) << "Last Name" << "|"
	<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->c[i].get_name().empty())
			continue;
		std::cout << std::setw(10) << i << "|"
		<< std::setw(10) << truncate(this->c[i].get_name()) << "|"
		<< std::setw(10) << truncate(this->c[i].get_lastname()) << "|"
		<< std::setw(10) << truncate(this->c[i].get_darkestsecret()) << std::endl;
	}
}

void	Phonebook::search(int index)
{
	if (index < 0 || index >= 8 || this->c[index].get_name().empty())
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	std::cout << "Name : " << this->c[index].get_name() << std::endl;
	std::cout << "Last Name : " << this->c[index].get_lastname() << std::endl;
	std::cout << "Number : " << this->c[index].get_number() << std::endl;
	std::cout << "Darkest Secret : " << this->c[index].get_darkestsecret() << std::endl;
}

void	Phonebook::exit()
{
	this->e = true;
}
