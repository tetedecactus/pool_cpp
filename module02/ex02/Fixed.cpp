/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:48:08 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/16 18:48:08 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//====== STATIC INITILIZATION ==========
const int Fixed::_nBits( 8 );

//======== CONSTRUCTOR & DESTRUCTOR =============================
Fixed::Fixed( void )  : _fixe( 0 ) { std::cout << GREEN << ": Default Constructor Called" << RESET << std::endl; }

Fixed::Fixed( int const n ) : _fixe( n << _nBits ) { std::cout << YELLOW << ": Int constructor Called" << RESET << std::endl; }

Fixed::Fixed( float const n ) : _fixe(roundf(n * (float)(1 << _nBits))) { std::cout << YELLOW << ": Float constructor Called" << RESET << std::endl; }

Fixed::Fixed( Fixed const & src ) {
	std::cout << BLUE << ": Copy Constructor Called with _fixe value of : "<< src._fixe << RESET << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed( void ) { std::cout << RED << ": Destructor Called" << RESET << std::endl; }

//====== OPERATOR ======================================

Fixed & Fixed::operator=( Fixed const & rhs ) {

	std::cout << YELLOW << ": Copy assignement operator Called" << RESET << std::endl;
	if (this != &rhs)
		this->_fixe = rhs.getRawBits();

	return *this;
}

// ========== OPERATOR +,-,*,/ ==========================
Fixed Fixed::operator+( Fixed const & rhs ) {
	Fixed fixi;
	// fixi._fixe = getRawBits() + rhs.getRawBits();
	fixi.setRaWBits(getRawBits() + rhs.getRawBits());
	return fixi;
}

Fixed Fixed::operator-( Fixed const & rhs ) {
	Fixed fixi;
	fixi._fixe = getRawBits() - rhs.getRawBits();
	return fixi;
}

Fixed Fixed::operator*( Fixed const & rhs ) {
	Fixed fixi;
	long nb = getRawBits() * rhs.getRawBits();
	fixi.setRaWBits(nb >> _nBits);
	return fixi;
}

Fixed Fixed::operator/( Fixed const & rhs ) {
	Fixed fixi;
	long nb = (getRawBits() << _nBits) / rhs.getRawBits();
	fixi.setRaWBits(nb);
	return fixi;
}

// ============== OPERATOR ++,-- ===============
Fixed & Fixed::operator++( void ) {
	++_fixe;
	return *this;
}

Fixed & Fixed::operator--( void ) {
	--_fixe;
	return *this;
}
Fixed  Fixed::operator++( int ) {
	Fixed fixi(*this);
	_fixe++;
	return fixi;
}

Fixed  Fixed::operator--( int ) {
	Fixed fixi(*this);
	_fixe--;
	return fixi;
}

// =============== OPERATOR >,<,>=,<=,!=, ==, ==========================================
bool   Fixed::operator>( Fixed const & rhs ) const	{ return this->getRawBits() > rhs.getRawBits() ? true : false; }
bool   Fixed::operator<( Fixed const & rhs ) const	{ return this->getRawBits() < rhs.getRawBits() ? true : false; }
bool   Fixed::operator>=( Fixed const & rhs ) const	{ return this->getRawBits() >= rhs.getRawBits() ? true : false; } 
bool   Fixed::operator<=( Fixed const & rhs ) const	{ return this->getRawBits() <= rhs.getRawBits() ? true : false; }
bool   Fixed::operator==( Fixed const & rhs ) const	{ return this->getRawBits() == rhs.getRawBits() ? true : false; }
bool   Fixed::operator!=( Fixed const & rhs ) const	{ return this->getRawBits() != rhs.getRawBits() ? true : false; }

// ================= OPERATOR min,max, ================================================
Fixed const& Fixed::max( Fixed const& f1, Fixed const& f2 ) { return f1 >= f2 ? f1 : f2; }
Fixed const& Fixed::min( Fixed const& f1, Fixed const& f2 ) { return f1 <= f2 ? f1 : f2; }

Fixed& Fixed::max( Fixed& f1, Fixed& f2 ) { return f1 >= f2 ? f1 : f2; }
Fixed& Fixed::min( Fixed& f1, Fixed& f2 ) { return f1 <= f2 ? f1 : f2; }

// ================= set & get rawbits ===============
int Fixed::getRawBits( void ) const { return _fixe; }
void Fixed::setRaWBits( int const raw )	{ this->_fixe = raw; }

// ================= to Int & to Float =================
int Fixed::toInt( void ) const { return _fixe >> _nBits; }
float Fixed::toFloat( void ) const { return (float)_fixe / (1 << _nBits); }


// ================== OPERATOR << =====================
std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
	o << PINK <<": The value of _fixe is : " << RESET << i.toFloat();

	return o;
}