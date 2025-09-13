/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:30:35 by csavreux          #+#    #+#             */
/*   Updated: 2025/09/13 13:01:09 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook Constructor called" << std::endl;
	for (int i = 0; i < 8; i++) {
		this->_contacts[i] = Contact();
	}
	this->_is_contact_list_full = false;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook Destructor called" << std::endl;
	return;
}

const Contact	*PhoneBook::get_ContactList(void) const
{
	return (this->_contacts);
}

void PhoneBook::add(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	this->_contacts[this->_new_contact_index].setFirstname(fn);
	this->_contacts[this->_new_contact_index].setLastname(ln);
	this->_contacts[this->_new_contact_index].setNickname(nn);
	this->_contacts[this->_new_contact_index].setPhoneNumber(pn);
	this->_contacts[this->_new_contact_index].setDarkestSecret(ds);
	this->_new_contact_index++;
	if(this->_new_contact_index == 7)
	{
		this->_new_contact_index = 0;
		if (this->_is_contact_list_full == false)
			this->_is_contact_list_full = true;
	}
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
		int i_field = 0;
		for (int i = nb_of_spaces; i < 10; i++) 
			std::cout << field[i_field];
		i_field++;
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
	std::cout << std::endl;
}

static void display_whole_contact(Contact contact)
{
	std::cout << contact.getFirstname() << std::endl;
	std::cout << contact.getLastname() << std::endl;
	std::cout << contact.getNickname() << std::endl;
	std::cout << contact.getPhoneNumber() << std::endl;
	std::cout << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::search(void)
{
	// display all contacts
	int nb_of_contacts;
	if (this->_is_contact_list_full == true)
		nb_of_contacts = 8;
	else
	 	nb_of_contacts = this->_new_contact_index;
	for (int i = 0; i < nb_of_contacts; i++)
	{
		std::cout << "         " << i << "|";
		display_brief_contact(this->_contacts[i]);
	}
	
	// search for a contact and displays it
	int index;
	std::cout << "Enter the index of the contact you want to display : ";
	std::cin >> index;
	std::cout << std::endl;
	if (index < 0 || (this->_is_contact_list_full == false && index >= this->_new_contact_index) || index > 7)
	{
		std::cout << "The entered index is out of range" << std::endl;
		return;
	}
	display_whole_contact(_contacts[index]);
	return;
}

int PhoneBook::_new_contact_index = 0;