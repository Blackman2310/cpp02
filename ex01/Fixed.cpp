#include "Fixed.hpp"

Fixed::Fixed(): fixed_point(0){
    std::cout << " Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "copy constructor called" << std::endl;
    this->fixed_point = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        this->fixed_point = other.getRawBits();
    }
    return *this;
}

Fixed::Fixed(const int value )
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point =  value <<  b;
}

Fixed::Fixed(const float value)
{
    std::cout << "Flaot constructor called" << std::endl;
    this->fixed_point = roundf(value * (1 << b));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
    return (float)(this->fixed_point / (float)(1 << b));
}

int Fixed::toInt( void ) const
{
    return this->fixed_point >> b;
}

int Fixed::getRawBits( void ) const
{
    return this->fixed_point;
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_point = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
