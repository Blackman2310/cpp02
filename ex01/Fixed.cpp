#include "Fixed.hpp"

Fixed::Fixed(): a(0){
    std::cout << " Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "copy constructor called" << std::endl;
    this->a = other.getRawBits();
}

Fixed::operator=(const *)

Fixed::Fixed(const int value )
{

}

Fixed::Fixed(const float value)
{

}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->a;
}
void Fixed::setRawBits( int const raw )
{
    this->a = raw;
}