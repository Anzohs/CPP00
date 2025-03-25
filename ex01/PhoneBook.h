/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:25:21 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/24 22:25:22 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
