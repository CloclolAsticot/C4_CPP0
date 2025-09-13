/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:17:09 by csavreux          #+#    #+#             */
/*   Updated: 2025/09/13 11:12:39 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
class	PhoneBook
{
	private:
		Contact _contacts[8];
		static 	int _new_contact_index;
		bool _is_contact_list_full;

	public:
		PhoneBook(void);
		~PhoneBook(void);
	
		void add(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		void search(void);
		
		const Contact *get_ContactList(void) const;	// read contact_list
};

#endif