/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:17:09 by csavreux          #+#    #+#             */
/*   Updated: 2025/11/16 17:34:05 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact			_contacts[8];
		static 	int 	_new_contact_index;
		static 	int 	_nb_of_contacts;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		const Contact 	*getContactList(void) const; // 1st const makes the returned pointer read-only. 2nd makes the function read-only.
		int 			getNbOfContacts(void) const;
	
		void 			addContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		void 			displayContact(Contact contact);
		void 			displayAllContacts(void);
};

#endif