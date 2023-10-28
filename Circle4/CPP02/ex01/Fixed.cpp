#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->FixedValue = 0;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->FixedValue = value << this->ConstBitsValue;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->FixedValue = roundf(value * (1 << this->ConstBitsValue));
}

Fixed::Fixed(const Fixed &Fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    this->FixedValue = Fixed.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &Fixed)
{
    std::cout << "Assignation operator called " << std::endl;
    if (this != &Fixed)
    {
        this->FixedValue = Fixed.getRawBits();
    }
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->FixedValue);
}

void    Fixed::setRawBits(int const raw)
{
    this->FixedValue = raw;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->FixedValue / (1 << this->ConstBitsValue));
}

int Fixed::toInt( void ) const
{
    return (this->FixedValue >> this->ConstBitsValue);
}

std::ostream& operator <<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}