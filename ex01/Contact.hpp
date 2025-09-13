/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:16:42 by csavreux          #+#    #+#             */
/*   Updated: 2025/08/30 17:20:25 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class	Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

	public:

		Contact(void);
		~Contact(void);
	
		std::string getFirstname(void) const;
		void		setFirstname(std::string str);
		
		std::string getLastname(void) const;
		void		setLastname(std::string str);

		std::string getNickname(void) const;
		void		setNickname(std::string str);

		std::string getPhoneNumber(void) const;
		void		setPhoneNumber(std::string str);

		std::string getDarkestSecret(void) const;
		void		setDarkestSecret(std::string str);
};

#endif