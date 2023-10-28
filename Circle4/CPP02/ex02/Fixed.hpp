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
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed(void);
        Fixed(const Fixed &Fixed);
        Fixed &operator= (const Fixed &Fixed);
        bool operator> (const Fixed &Fixed) const;
        bool operator< (const Fixed &Fixed) const;
        bool operator>= (const Fixed &Fixed) const;
        bool operator<= (const Fixed &Fixed) const;
        bool operator== (const Fixed &Fixed) const;
        bool operator!= (const Fixed &Fixed) const;
        Fixed operator+ (const Fixed &Fixed) const;
        Fixed operator- (const Fixed &Fixed) const;
        Fixed operator* (const Fixed &Fixed) const;
        Fixed operator/ (const Fixed &Fixed) const;
        Fixed &operator++ (void); // 전위
        const Fixed operator++ (int); // 후위
        Fixed &operator-- (void); // 전위
        const Fixed operator-- (int); // 후위
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        static Fixed &min(Fixed &FirstNum, Fixed &SecNum);
        static Fixed &max(Fixed &FirstNum, Fixed &SecNum);
        static const Fixed &min(const Fixed &FirstNum, const Fixed &SecNum);
        static const Fixed &max(const Fixed &FirstNum, const Fixed &SecNum);
};

std::ostream& operator <<(std::ostream &out, const Fixed &fixed);

#endif