#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->FixedValue = 0;
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
    std::cout << "getRawBits member function called" << std::endl;
    return (this->FixedValue);
}

void    Fixed::setRawBits(int const raw)
{
    this->FixedValue = raw;
}