/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:12:31 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/04 21:18:24 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Contact add_contact()
{
	Contact new_contact;
	
	std::cout <<  "ENTER THE FIRST NAME: ";
	std::getline(std::cin ,new_contact.first_name);
	std::cout << "\n";
	std::cout <<  "ENTER THE LAST NAME: ";
	std::getline(std::cin ,new_contact.last_name);
	std::cout << "\n";
	std::cout <<  "ENTER THE NICKNAME: ";
	std::getline(std::cin ,new_contact.nickname);
	std::cout << "\n";
	std::cout <<  "ENTER THE PHONE NUMBER: ";
	std::getline(std::cin ,new_contact.phone_nuber);
	std::cout << "\n";
	std::cout <<  "ENTER THE DARKEST_SECRET: ";
	std::getline(std::cin ,new_contact.darkest_secret);
	std::cout << "\n";

	return (new_contact);
}

Contact search_contact();

int main ()
{
	// si le phonebook ce ferme quand il reouver cb de contact ya??
	Phonebook phonebook;
	int i = 0;
	std::cout << "\t\t📞--->PHONEBOOK<---📞\n" << std::endl;
	std::cout << "*******************************************************\n" << std::endl;
	std::cout << "PLEASE ENTER COMMAND\n" << std::endl;
	std::cout << "ADD || SEARCH || EXIT" << std::endl;
	
	std::getline(std::cin, phonebook.cmd);
    if (phonebook.cmd == "ADD")
		phonebook.contact[i++] =  contact[i].add_contact();
	else if (phonebook.cmd == "SEARCH")
		std::cout << "COMMAND IS: "<< phonebook.cmd <<"" << "\n";
	else if (phonebook.cmd == "EXIT")
		std::cout << "COMMAND IS: "<< phonebook.cmd <<"" << "\n";
	else
		std::cout << "Wrong command you dump ass" << std::endl;
  return 0;
}
// Note
// when endl or \nz