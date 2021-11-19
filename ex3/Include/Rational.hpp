#pragma once

#include <iostream>
#include <stdio.h>
#include <numeric>


using std::ostream;

class Rational
{
    
public:
    Rational(const int = 0, const int = 1);
    int getNummerator() const;
    int getDenominator() const;
    
private:
    int m_nummerator;
    int m_denominator;
};

Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator-(const Rational&);
Rational operator+(const Rational&);
Rational &operator+=(Rational&, Rational&);
Rational operator-=(Rational&, Rational&);
Rational operator/(Rational&, Rational&);
Rational operator/=(Rational&, Rational&);
Rational operator*(Rational&, Rational&);
Rational operator*=(Rational&, Rational&);
bool operator==(Rational&, Rational&);
bool operator!=(Rational&, Rational&);
bool operator<=(Rational&, Rational&);
bool operator>=(Rational&, Rational&);
bool operator<(Rational&, Rational&);
bool operator>(Rational&, Rational&);

ostream &operator<<(ostream&, const Rational&);
