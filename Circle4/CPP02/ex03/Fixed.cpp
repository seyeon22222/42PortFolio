#include "Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    this->FixedValue = 0;
}

Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    this->FixedValue = value << this->ConstBitsValue;
}

Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
    this->FixedValue = roundf(value * (1 << this->ConstBitsValue));
}

Fixed::Fixed(const Fixed &Fixed)
{
    // std::cout << "Copy constructor called" << std::endl;
    this->FixedValue = Fixed.getRawBits();
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &Fixed)
{
    // std::cout << "Assignation operator called " << std::endl;
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

bool Fixed::operator> (const Fixed &Fixed) const
{
    return (this->getRawBits() > Fixed.getRawBits());
}

bool Fixed::operator< (const Fixed &Fixed) const
{
    return (this->getRawBits() < Fixed.getRawBits());
}

bool Fixed::operator>= (const Fixed &Fixed) const
{
    return (this->getRawBits() >= Fixed.getRawBits());
}

bool Fixed::operator<= (const Fixed &Fixed) const
{
    return (this->getRawBits() <= Fixed.getRawBits());
}

bool Fixed::operator== (const Fixed &Fixed) const
{
    return (this->getRawBits() == Fixed.getRawBits());
}

bool Fixed::operator!= (const Fixed &Fixed) const
{
    return (this->getRawBits() != Fixed.getRawBits());
}

Fixed Fixed::operator+ (const Fixed &Fixed) const
{
    return (this->toFloat() + Fixed.toFloat());
}

Fixed Fixed::operator- (const Fixed &Fixed)const
{
    return (this->toFloat() - Fixed.toFloat());
}

Fixed Fixed::operator* (const Fixed &Fixed)const
{
    return (this->toFloat() * Fixed.toFloat());
}

Fixed Fixed::operator/ (const Fixed &Fixed)const
{
    if (Fixed.toFloat() == 0)
        std::cerr << "0으로 나눌 수 없습니다" << std::endl;
    return (this->toFloat() / Fixed.toFloat());
}

Fixed &Fixed::operator++ (void) // 전위
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this); 
}

const Fixed Fixed::operator++ (int)
{
    const Fixed   TempValue(*this);

    this->setRawBits(this->getRawBits() + 1);
    return (TempValue);
}

Fixed &Fixed::operator-- (void)
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this); 
}

const Fixed Fixed::operator-- (int)
{
    const Fixed   TempValue(*this);

    this->setRawBits(this->getRawBits() - 1);
    return (TempValue);
}

Fixed &Fixed::max(Fixed &FirstNum, Fixed &SecNum)
{
    if (FirstNum.getRawBits() > SecNum.getRawBits())
        return (FirstNum);
    else
        return (SecNum);
}

Fixed &Fixed::min(Fixed &FirstNum, Fixed &SecNum)
{
    if (FirstNum.getRawBits() > SecNum.getRawBits())
        return (SecNum);
    else
        return (FirstNum);
}

const Fixed &Fixed::max(const Fixed &FirstNum, const Fixed &SecNum)
{
    if (FirstNum.getRawBits() > SecNum.getRawBits())
        return (FirstNum);
    else
        return (SecNum);
}

const Fixed &Fixed::min(const Fixed &FirstNum, const Fixed &SecNum)
{
    if (FirstNum.getRawBits() > SecNum.getRawBits())
        return (SecNum);
    else
        return (FirstNum);
}