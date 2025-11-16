/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:30:35 by csavreux          #+#    #+#             */
/*   Updated: 2025/11/16 17:34:56 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

const Contact	*PhoneBook::getContactList(void) const
{
	return (this->_contacts);
}

int		PhoneBook::getNbOfContacts(void) const
{
	return (this->_nb_of_contacts);
}

void PhoneBook::addContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	this->_contacts[this->_new_contact_index].setFirstname(fn);
	this->_contacts[this->_new_contact_index].setLastname(ln);
	this->_contacts[this->_new_contact_index].setNickname(nn);
	this->_contacts[this->_new_contact_index].setPhoneNumber(pn);
	this->_contacts[this->_new_contact_index].setDarkestSecret(ds);
	this->_new_contact_index++;
	if (this->_new_contact_index == 8)
		this->_new_contact_index = 0;
	if (this->_nb_of_contacts < 8)
		this->_nb_of_contacts++;
}

void PhoneBook::displayContact(Contact contact)
{
	std::cout << "First name: " << contact.getFirstname() << std::endl;
	std::cout << "Last name: " << contact.getLastname() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

static void display_field(std::string field)
{
	int nb_of_spaces;
	
	nb_of_spaces = 10 - field.size();
	// display method for ok-sized fields
	if (nb_of_spaces >= 0)
	{
		for (int i = 0; i < nb_of_spaces; i++)
			std::cout << " ";
		for (int i = 0; i < 10 - nb_of_spaces; i++)
			std::cout << field[i];
		return;
	}
	// display method for too long fields
	for (int i = 0; i < 9; ++i)
		std::cout << field[i];
	std::cout << ".";
	return;
}

static void display_brief_contact(Contact contact)
{
	display_field(contact.getFirstname());
	std::cout << "|";
	display_field(contact.getLastname());
	std::cout << "|";
	display_field(contact.getNickname());
	std::cout << "|";
	std::cout << std::endl;
}

void PhoneBook::displayAllContacts(void)
{
	for (int i = 0; i < this->_nb_of_contacts; i++)
	{
		std::cout << "         " << i << "|";
		display_brief_contact(this->_contacts[i]);
	}
	std::cout << std::endl;
	return;
}

int PhoneBook::_new_contact_index = 0;
int PhoneBook::_nb_of_contacts = 0;