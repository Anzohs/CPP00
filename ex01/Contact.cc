#include "Contact.h"

Contact::Contact()
{
	this->name = "";
	this->last_name = "";
	this->darkest_secret = "";
	this->number = 0;
}

Contact::~Contact(){}

std::string	Contact::get_name(void) {return this->name;}
std::string	Contact::get_lastname(void) {return this->last_name;}
std::string	Contact::get_darkestsecret(void) {return this->darkest_secret;}
int	Contact::get_number(){return this->number;}

void	Contact::set_name(std::string name)
{
	this->name = name;
}

void	Contact::set_number(int number)
{
	this->number = number;
}

void	Contact::set_lastname(std::string last_name)
{
	this->last_name = last_name;
}

void	Contact::set_darkest(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}
