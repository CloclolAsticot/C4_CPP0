/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:10:33 by csavreux          #+#    #+#             */
/*   Updated: 2025/11/14 18:46:29 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstring>
#include <iostream>
#include <string>

void add_contact(PhoneBook *phonebook)
{
	std::string fn;
	std::string ln;
	std::string nn;
	std::string pn;
	std::string ds;

	std::cout << "First Name : ";
	std::getline(std::cin, fn);
	
	std::cout << "Last Name : ";
	std::getline(std::cin, ln);
	
	std::cout << "Nickname : ";
	std::getline(std::cin, nn);

	std::cout << "Phone Number : ";
	std::getline(std::cin, pn);

	std::cout << "Darkest Secret : ";
	std::getline(std::cin, ds);

	phonebook->addContact(fn, ln, nn, pn, ds);
}

void search(PhoneBook *phonebook)
{
	phonebook->displayAllContacts();
	int index;
	std::cout << "Enter the index of the contact you want to display : ";
	std::cin >> index;
	if (index >= phonebook->getNbOfContacts())
	{
		std::cout << "The index is out of range" << std::endl;
		return;
	}
	phonebook->displayContact(phonebook->getContactList()[index]);
}


int main(void)
{
	PhoneBook phonebook;
	
	while (1)
	{
		std::cout << "Enter a command: ";
		
		// Get user command
		std::string user_cmd;
		std::getline(std::cin, user_cmd);
		
		// Treat user command
		if (user_cmd.compare("ADD") == 0)
			add_contact(&phonebook);
		else if (user_cmd.compare("SEARCH") == 0)
			search(&phonebook);
		else if (user_cmd.compare("EXIT") == 0)
			break;
	}
	return 0;
}
