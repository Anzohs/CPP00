#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"
# include <iomanip>

class Phonebook{
	private:
		Contact c[8];
		int		index;
		int		get_index();
		bool	e;
		std::string	truncate(const std::string& str) const;
	public:
		Phonebook();
		~Phonebook();
		void	print();
		bool	close();
		void	add(std::string name, int number, std::string last_name, std::string darkest);
		void	search(int index);
		void	exit();
};

#endif
