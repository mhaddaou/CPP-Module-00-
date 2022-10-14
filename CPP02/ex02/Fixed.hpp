/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:21:39 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/10/13 19:58:35 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed{
    private:
        int  _fixedPoint;
        static const int _bits = 8;
    public:
        Fixed(); // default constructor
        ~Fixed(); // destructor
        Fixed (const Fixed& obj); //copy constructor
        Fixed (const int number); // constructor int parameter
        Fixed (const float number);    
        Fixed& operator=(const Fixed& obj);
        Fixed& operator+(const Fixed& obj); 
        Fixed& operator-(const Fixed& obj); 
        Fixed& operator*(const Fixed& obj); 
        Fixed& operator/(const Fixed& obj); 
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        
        bool operator>(const Fixed& obj ) const;
        bool operator<( const Fixed& obj ) const;
        bool operator>=( const Fixed& obj ) const;
        bool operator<=( const Fixed& obj ) const;
        bool operator==( const Fixed& obj ) const;
        bool operator!=(const Fixed& obj ) const;


        Fixed operator ++ (void);
        Fixed operator ++ (int);
        Fixed operator -- (void);
        Fixed operator -- (int);
        
};

std::ostream &operator<<(std::ostream &op, const Fixed &obj); 

#endif 