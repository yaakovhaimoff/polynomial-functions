#include "Rational.hpp"
#include <iostream>

// rational constructor
//_____________________________________
Rational::Rational(const int numerator,
    const int denominator) :
    m_numerator(numerator / std::gcd(numerator, denominator)),
    m_denominator(denominator / std::gcd(numerator, denominator))
{
    if ((this->m_numerator < 0 && this->m_denominator < 0) ||
        (this->m_numerator > 0 && this->m_denominator < 0))
    {
        this->m_numerator *= -1;
        this->m_denominator *= -1;
    }
}
//__________________________________
int Rational::getNumerator() const
{
    return this->m_numerator;
}
//__________________________________
int Rational::getDenominator() const
{
    return this->m_denominator;
}

// rational operators:

// adding rationals
//___________________________________________
Rational operator+(const Rational& rational1,
    const Rational& rational2)
{
    return Rational(rational1.getNumerator() * rational2.getDenominator() +
        rational1.getDenominator() * rational2.getNumerator(),
        rational1.getDenominator() * rational2.getDenominator());
}
// subtracting rationals
//__________________________________________
Rational operator-(const Rational& rational)
{
    return Rational(-rational.getNumerator(),
        rational.getDenominator());
}
//_________________________________________
Rational operator-(const Rational& rational1,
    const Rational& rational2)
{
    return rational1 + (-rational2);
}
//__________________________________________
Rational operator+(const Rational& rational1)
{
    return rational1;
}
// dividing rationals
//______________________________________
Rational operator/(const Rational& rational1,
                   const Rational& rational2)
{
    return Rational(rational1.getNumerator() * rational2.getDenominator(),
        rational1.getDenominator() * rational2.getNumerator());
}
// multipying rationals
//______________________________________
Rational operator*(const Rational& rational1,
                   const  Rational& rational2)
{
    return Rational(rational1.getNumerator() * rational2.getNumerator(),
                    rational1.getDenominator() * rational2.getDenominator());
}
//___________________________________________
Rational& operator+=(Rational& rational1,
                     const Rational& rational2)
{
    rational1 = rational1 + rational2;
    return rational1;
}
//______________________________________
Rational& operator-=(Rational& rational1,
                     const Rational& rational2)
{
    rational1 = rational1 - rational2;
    return rational1;
}
//______________________________________
Rational& operator/=(Rational& rational1,
                     const Rational& rational2)
{
    rational1 = rational1 / rational2;
    return rational1;
}
//______________________________________
Rational& operator*=(Rational& rational1,
                    const Rational& rational2)
{
    rational1 = rational1 * rational2;
    return rational1;
}
// checking the rationals are equal
//__________________________________
bool operator==(const Rational& rational1,
                const Rational& rational2)
{
    return rational1.getNumerator() == rational2.getNumerator()
        && rational1.getDenominator() == rational2.getDenominator();
}
// checking the rationals are deifferent
//__________________________________
bool operator!=(const Rational& rational1,
                const Rational& rational2)
{
    return !(rational1 == rational2);
}
// checking which rational is bigger
//__________________________________
bool operator<(const Rational& rational1,
               const Rational& rational2)
{
    return rational1.getNumerator() *
        rational2.getDenominator() <
        rational1.getDenominator() *
        rational2.getNumerator();
}
//__________________________________
bool operator>(const Rational& rational1,
               const Rational& rational2)
{
    if (rational1 == rational2)
        return false;
    return !(rational1 < rational2);
}
//__________________________________
bool operator<=(const Rational& rational1,
                const Rational& rational2)
{
    if (rational1 == rational2)
        return true;
    return !(rational1 > rational2);
}
//__________________________________
bool operator>=(const Rational& rational1,
                const Rational& rational2)
{
    return !(rational1 < rational2);
}
// printing the rational
//___________________________________________________________
ostream& operator<<(ostream& ouput, const Rational& rational)
{
    ouput << rational.getNumerator() << "/" << rational.getDenominator();
    return ouput;
}
