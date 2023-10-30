#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int FixedValue;
        const static int    ConstBitsValue = 8;
    public:
        Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed(void);
        Fixed(const Fixed &Fixed);
        Fixed &operator= (const Fixed &Fixed);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator <<(std::ostream &out, const Fixed &fixed);

#endif