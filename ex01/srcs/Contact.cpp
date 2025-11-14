/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:30:40 by csavreux          #+#    #+#             */
/*   Updated: 2025/11/14 14:59:44 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
	// std::cout << "Contact Constructer called" << std::endl;
	return;
}

Contact::~Contact(void)
{
	// std::cout << "Contact Destructor called" << std::endl;
	return;
}

std::string Contact::getFirstname(void) const
{
	return (this->_first_name);
}

void	Contact::setFirstname(std::string str)
{
	this->_first_name = str;
	return;
}

std::string Contact::getLastname(void) const
{
	return (this->_last_name);
}

void	Contact::setLastname(std::string str)
{
	this->_last_name = str;
	return;
}

std::string Contact::getNickname(void) const
{
	return (this->_nickname);
}

void	Contact::setNickname(std::string str)
{
	this->_nickname = str;
	return;
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->_phone_number);
}

void	Contact::setPhoneNumber(std::string str)
{
	this->_phone_number = str;
	return;
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->_darkest_secret);
}

void	Contact::setDarkestSecret(std::string str)
{
	this->_darkest_secret = str;
	return;
}
