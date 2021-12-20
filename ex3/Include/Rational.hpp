#pragma once

#include <iostream>
#include <stdio.h>
#include <numeric>


using std::ostream;

class Rational
{

public:
    Rational(const int = 0, const int = 1);
    int getNumerator() const;
    int getDenominator() const;

private:
    int m_numerator;
    int m_denominator;
};

Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator/(const Rational&, const Rational&);
Rational operator*(const Rational&, const Rational&);

Rational operator-(const Rational&);
Rational operator+(const Rational&);

Rational& operator+=(Rational&, const Rational&);
Rational& operator-=(Rational&, const Rational&);
Rational& operator/=(Rational&, const Rational&);
Rational& operator*=(Rational&, const Rational&);

bool operator==(const Rational&, const Rational&);
bool operator!=(const Rational&, const Rational&);
bool operator<=(const Rational&, const Rational&);
bool operator>=(const Rational&, const Rational&);
bool operator<(const Rational&, const Rational&);
bool operator>(const Rational&, const Rational&);

ostream& operator<<(ostream&, const Rational&);
