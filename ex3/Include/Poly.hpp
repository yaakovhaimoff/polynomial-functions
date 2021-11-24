#pragma once

#include <stdio.h>
#include <vector>
#include <algorithm>    // max, min
#include "Rational.hpp"
#include "List.hpp"

class Poly
{
public:
    Poly(const std::vector<Rational>&); // regular polynomial
    Poly();                             // default polynomial
    Poly(const int);                    // skalar polynomial
    Poly(const int, const Rational&);   // monomial polynomial
    void printPoly()const;
    int getDegPol()const;
    Node *getHeadPol()const;
    Rational operator()(Rational&)const;
    Rational operator[](int&)const;
    
    
private:
    List m_polyHead;
};

Poly operator+(const Poly&, const Poly&);
Poly operator-(const Poly&, const Poly&);
Poly operator-(const Poly&);
Poly &operator+=(Poly&, Poly&);
Poly operator-=(Poly&, Poly&);
Poly operator*(const Poly&, const Poly&);
Poly operator*(Poly&, Rational&);
Poly operator*(Rational&, Poly&);
Poly operator*=(Poly&, Poly&);
bool operator==(Poly&, Poly&);
bool operator!=(Poly&, Poly&);

ostream &operator<<(ostream&, const Poly&);
