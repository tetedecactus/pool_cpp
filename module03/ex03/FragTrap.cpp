/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:58:50 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/28 16:58:50 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//=================== CONSTRUCTOR & DESTRUCTOR =========================
FragTrap::FragTrap( void ) : ClapTrap() {
    hitPoint = 100;
    energyPoint = 100;
    attDamage = 30;
    std::cout << YELLOW << "FragTrap " + this->getName() << RESET << ": Constructor FragTrap called and have :" << energyPoint << " of ernergy point" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
    hitPoint = 100;
    energyPoint = 100;
    attDamage = 30;
    std::cout << YELLOW << "FragTrap " + this->getName() << RESET << ": Constructor FragTrap called and have :" << energyPoint << " of ernergy point" << std::endl;
}

FragTrap::FragTrap( FragTrap const & src ) 
{
    *this = src;
    std::cout << YELLOW << "FragTrap " + this->getName() << RESET << ": Copy constructor FragTrap called" << std::endl;
    return ;
}

FragTrap::~FragTrap() { std::cout << YELLOW << "FragTrap " + this->name << RESET << ": Destructor FragTrap called " << std::endl; }

//==================== ASSIGNEMENT OPERATOR ================================

FragTrap& FragTrap::operator=( FragTrap const & rhs ) {

    this->name = rhs.name;
    this->hitPoint = rhs.hitPoint;
    this->energyPoint = rhs.energyPoint;
    this->attDamage = rhs.attDamage;    

    return *this;
}

//==================== SPECIFIC FUNCTION ======================

void FragTrap::highFivesGuys( void ) const {
    std::string input;
    do
    {
        std::cout << "Voulez-vous faire un high Five? [y/n]" << std::endl;
        std::getline(std::cin, input);
        if (input == "n")
            return ;
    } while (input != "y");
    if (input == "y")
        std::cout << YELLOW << this->getName() << ":  Do a HighFivesGuys" << RESET << std::endl;
    return;
}

// =============== Setter Getter
void FragTrap::setAttDamage( void ) { this->attDamage = 30; }
int FragTrap::getAttDamage( void ) const { return this->attDamage; }

void printStats( FragTrap const & frag ) {
    std::cout << YELLOW << "======== STATS ============" << RESET << std::endl;
    std::cout << PINK << "Nom : " << frag.getName() << std::endl;
    std::cout << "Hit Point : " << frag.getHitPoint() << std::endl;
    std::cout << "Energy Point : " << frag.getEnergyPoint() << std::endl;
    std::cout << "Attack Damage : " << frag.getAttDamage() << RESET << std::endl;
}

