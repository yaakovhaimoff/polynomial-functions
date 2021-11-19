#include "Rational.hpp"
#include <iostream>
//_____________________________________
Rational::Rational(const int numerator,
                   const int denominator):
m_nummerator(numerator/std::gcd(numerator,denominator)),
m_denominator(denominator/std::gcd(numerator,denominator))
{
    if((this->m_nummerator < 0 && this->m_denominator < 0) ||
       (this->m_nummerator > 0 && this->m_denominator < 0))
    {
        this->m_nummerator*=-1;
        this->m_denominator*=-1;
    }
}
//__________________________________
int Rational::getNummerator() const
{
    return this->m_nummerator;
}
//__________________________________
int Rational::getDenominator() const
{
    return this->m_denominator;
}
//___________________________________________
Rational operator+(const Rational& rational1,
                   const Rational& rational2)
{
    return Rational(rational1.getNummerator()* rational2.getDenominator() +
                    rational1.getDenominator()* rational2.getNummerator(),
                    rational1.getDenominator()*rational2.getDenominator());
}
//__________________________________________
Rational operator-(const Rational& rational)
{
    return Rational(-rational.getNummerator(),
                    rational.getDenominator());
}
//_________________________________________
Rational operator-(const Rational&rational1,
                   const Rational&rational2)
{
    return rational1 + (-rational2);
}
//__________________________________________
Rational operator+(const Rational&rational1)
{
    return rational1;
}
//___________________________________________
Rational &operator+=(Rational& rational1,
                     Rational& rational2)
{
    rational1 = rational1 + rational2;
    return rational1;
}
//______________________________________
Rational operator-=(Rational& rational1,
                    Rational& rational2)
{
    rational1 = rational1 - rational2;
    return rational1;
}
//______________________________________
Rational operator/(Rational& rational1,
                   Rational& rational2)
{
    return Rational(rational1.getNummerator()*rational2.getDenominator(),
                    rational1.getDenominator()*rational2.getNummerator());
}
//______________________________________
Rational operator/=(Rational& rational1,
                    Rational& rational2)
{
    rational1 = rational1/rational2;
    return rational1;
}
//______________________________________
Rational operator*(Rational& rational1,
                   Rational& rational2)
{
    return Rational(rational1.getNummerator()*rational2.getNummerator(),
                    rational1.getDenominator()*rational2.getDenominator());}
//______________________________________
Rational operator*=(Rational& rational1,
                    Rational& rational2)
{
    rational1 = rational1*rational2;
    return rational1;
}
//__________________________________
bool operator==(Rational& rational1,
                Rational& rational2)
{
    return rational1.getNummerator()==rational2.getNummerator()
    && rational1.getDenominator()==rational2.getDenominator();
}
//__________________________________
bool operator!=(Rational& rational1,
                Rational& rational2)
{
    return !(rational1==rational2);
}
//__________________________________
bool operator<(Rational& rational1,
               Rational& rational2)
{
    return rational1.getNummerator() *
    rational2.getDenominator() <
    rational1.getDenominator() *
    rational2.getNummerator();
}
//__________________________________
bool operator>(Rational& rational1,
               Rational& rational2)
{
    if(rational1 == rational2)
        return false;
    return !(rational1 < rational2);
}
//__________________________________
bool operator<=(Rational& rational1,
                Rational& rational2)
{
    if(rational1 == rational2)
        return true;
    return !(rational1 > rational2);
}
//__________________________________
bool operator>=(Rational& rational1,
                Rational& rational2)
{
    return !(rational1 < rational2);
}
////___________________________________________________________
ostream &operator<<(ostream& ouput, const Rational& rational)
{
    ouput << rational.getNummerator()<< "/" << rational.getDenominator();
    return ouput;
}
