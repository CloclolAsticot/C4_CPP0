/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:10:33 by csavreux          #+#    #+#             */
/*   Updated: 2025/11/22 13:52:51 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>

static void *fill_field(std::string *field, std::string field_name)
{
	std::cout << field_name;
	if (std::getline(std::cin, *field) == NULL)
		return (NULL);
	while (field->empty())
	{
		std::cout << "Field cannot be empty." << std::endl << std::endl;
		std::cout << field_name;
		if (std::getline(std::cin, *field) == NULL)
			return (NULL);
	}
	std::cout << std::endl;
	return (field);
}


void *add_contact(PhoneBook *phonebook)
{
	std::string fn;
	std::string ln;
	std::string nn;
	std::string pn;
	std::string ds;

	if (fill_field(&fn, "First name: ") == NULL)
		return (NULL);
	
	if (fill_field(&ln, "Last name: ") == NULL)
		return (NULL);

	if (fill_field(&nn, "Nickame: ") == NULL)
		return (NULL);

	if (fill_field(&pn, "Phone number: ") == NULL)
		return (NULL);

	if (fill_field(&ds, "Darkest secret: ") == NULL)
		return (NULL);

	phonebook->addContact(fn, ln, nn, pn, ds);
	return (phonebook);
}

static bool is_index_valid(const std::string &str_index, int *index, int nb_of_contacts)
{
	*index = -1;
	if (str_index.size() != 1)
		return (false);
	if (!std::isdigit(static_cast<unsigned char>(str_index.at(0))))
		return (false);
	*index = str_index.at(0) - '0';
	if (*index < 0 || *index >= nb_of_contacts)
		return (false);
	return (true);
}

void *search(PhoneBook *phonebook)
{
	std::string str_index;
	int index;
	
	if (phonebook->getNbOfContacts() == 0)
	{
		std::cout << "Contact list is empty." << std::endl << std::endl;
		return (phonebook);
	}
	std::cout << std::endl;
	phonebook->displayAllContacts();
	std::cout << "Enter the index of the contact you want to display: ";
	if(std::getline(std::cin, str_index) == NULL)
		return (NULL);
	if (is_index_valid(str_index, &index, phonebook->getNbOfContacts()) == false)
	{
		std::cout << "The index is not valid." << std::endl;
		std::cout << std::endl;
		return (phonebook);		
	}
	std::cout << std::endl;
	phonebook->displayContact(phonebook->getContactList()[index]);
	std::cout << std::endl;
	return (phonebook);
}


int main(void)
{
	PhoneBook phonebook;
	std::string user_cmd;
	
	while (1)
	{
		std::cout << "Enter a command: ";
		
		if (std::getline(std::cin, user_cmd) == NULL || user_cmd.compare("EXIT") == 0)
		{
			std::cout << std::endl;
			break;
		}
		else if (user_cmd.compare("ADD") == 0)
		{
			std::cout << std::endl;
			if(add_contact(&phonebook) == NULL)
			{
				std::cout << std::endl;
				break;
			}
		}
		else if (user_cmd.compare("SEARCH") == 0)
		{
			if (search(&phonebook) == NULL)
			{
				std::cout << std::endl;
				break;
			}				
		}
	}
	return 0;
}
