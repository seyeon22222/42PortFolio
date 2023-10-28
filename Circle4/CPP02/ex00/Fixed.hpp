#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


class Fixed
{
    private:
        int FixedValue;
        const static int    ConstBitsValue = 8;
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed &Fixed);
        Fixed &operator= (const Fixed &Fixed);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif