#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>

class Contact{
	private:
		std::string name;
		std::string	last_name;
		int			number;
		std::string	darkest_secret;
	public:
		Contact();
		~Contact(void);
		int get_number(void);
		std::string get_name(void);
		std::string get_lastname(void);
		std::string get_darkestsecret(void);
		void	set_name(std::string name);
		void	set_number(int number);
		void	set_lastname(std::string last_name);
		void	set_darkest(std::string darkest_secret);

};

#endif
