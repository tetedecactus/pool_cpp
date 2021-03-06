/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:48:03 by olabrecq          #+#    #+#             */
/*   Updated: 2022/06/16 18:48:03 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <unistd.h>
#include <string>
#include <cmath>

# define BLUE "\033[0;36m"
# define PINK "\033[0;35m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

class Fixed
{
private:

    int _fixe;
    const static int _nBits;
	std::string name;
    
public:

    Fixed( void );
	Fixed( int const n );
	Fixed( float const n );
	Fixed( Fixed const & src );
    ~Fixed( void );

	Fixed & operator=( Fixed const & rhs );

	Fixed 	operator++(  int );// Notice int inside barcket which indicates postfix increment.
	Fixed 	operator--(  int );//https://www.programiz.com/cpp-programming/increment-decrement-operator-overloading
	Fixed & operator++( void );
	Fixed & operator--( void );
	Fixed 	operator+( Fixed const & rhs);
	Fixed 	operator-( Fixed const & rhs);
	Fixed 	operator*( Fixed const & rhs);
	Fixed 	operator/( Fixed const & rhs);
	
	static Fixed const& max( Fixed const& f1, Fixed const& f2 );
	static Fixed const& min( Fixed const& f1, Fixed const& f2 );
	static Fixed& max( Fixed& f1, Fixed& f2 );
	static Fixed& min( Fixed& f1, Fixed& f2 );

	bool   operator>( Fixed const & rhs ) const;
	bool   operator<( Fixed const & rhs ) const;
	bool   operator>=( Fixed const & rhs ) const; 
	bool   operator<=( Fixed const & rhs ) const;
	bool   operator==( Fixed const & rhs ) const;
	bool   operator!=( Fixed const & rhs ) const;
    
	// static int min( )
	int getRawBits( void ) const;
	void setRaWBits( int const raw );
    
	int toInt( void ) const;
	float toFloat( void ) const;

};

std::ostream & operator<<( std::ostream & o, Fixed const & i ); // lire la dessu


// A FAIRE
// Les 6 op??rateur de comparaison : >, <, >=, <=, == et != --> Bool function
// Les 4 op??rateurs de arithm??tiques : +, -, *, et /. https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
// Les 4 op??rateurs d???incr??mentation et de d??cr??mentation (pr??-incr??mentation et
//post-incr??mentation, pr??-d??cr??mentation et post-d??cr??mentation)

//  Une fonction membre statique min prenant en param??tres deux r??f??rences sur des
	// nombres ?? virgule fixe et qui retourne le plus petit d???entre eux.
//??? Une fonction membre statique min prenant en param??tres deux r??f??rences sur des
// nombres ?? virgule fixe constants et qui retourne le plus petit d???entre eux.
// ??? Une fonction membre statique max prenant en param??tres deux r??f??rences sur des
// nombres ?? virgule fixe et qui retourne le plus grand d???entre eux.
// ??? Une fonction membre statique max prenant en param??tres deux r??f??rences sur des
// nombres ?? virgule fixe constants et qui retourne le plus grand d???entre eux.


#endif
