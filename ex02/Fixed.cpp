#include "Fixed.hpp"


Fixed::Fixed():a(0){
	std::cout << " Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
	std::cout << "copy constructor called" << std::endl;
	this->a = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
	{
		this->a = other.getRawBits();
	}
	return *this;
}
Fixed::~Fixed(){
	    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value )
{
    std::cout << "Int constructor called" << std::endl;
    this->a =  value <<  b;
}

Fixed::Fixed(const float value)
{
    std::cout << "Flaot constructor called" << std::endl;
    this->a = roundf(value * (1 << b));
}

int Fixed::getRawBits( void ) const
{
    return this->a;
}

void Fixed::setRawBits( int const raw )
{
    this->a = raw;
}

bool Fixed::operator>(const Fixed &other) const{
	return this->a > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const{
	return this->a < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const{
	return this->a >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const{
	return this->a <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const{
	return this->a == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const{
	return this->a != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const{
	Fixed r;
	r.setRawBits(this->getRawBits() + other.getRawBits());
	return r;
}

Fixed Fixed::operator-(const Fixed &other) const{
	Fixed r;
	r.setRawBits(this->getRawBits() - other.getRawBits());
	return r;
}

Fixed Fixed::operator*(const Fixed &other) const{
	Fixed r;
	long long tmp;
	tmp = (long long)this->getRawBits() * (long long)other.getRawBits();
	r.setRawBits(tmp >> b);
	return r;
}

Fixed Fixed::operator/(const Fixed &other) const{
	Fixed r;
	long long tmp;
	tmp = (long long)this->getRawBits() << b;
	if(other.getRawBits() != 0)
		r.setRawBits(tmp / other.getRawBits());
	return r;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed &Fixed::operator++(void){
	this->a++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed tmp;
	tmp = *this;
	this->a++;
	return tmp;
}

Fixed &Fixed::operator--(void){
	this->a--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed tmp;
	tmp = *this;
	this->a--;
	return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b){
	if(a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b){
	if(a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b){
	if(a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b){
	if(a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

float Fixed::toFloat( void ) const{
    return (float)(this->a / (float)(1 << b));
}

int Fixed::toInt( void ) const{
    return this->a >> b;
}

