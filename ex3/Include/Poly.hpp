#pragma once

#include <vector>
#include <algorithm>    // max, min
#include "List.hpp"

class Poly
{
public:
    Poly(const std::vector<Rational>&); // regular polynomial
    Poly();                             // default polynomial
    Poly(const int);                    // skalar polynomial
    Poly(const int, const Rational&);   // monomial polynomial
    int deg()const;
    void printPoly()const;
    const Node* getHeadPol()const;
    Rational operator()(const Rational&)const;
    Rational operator[](const int)const;


private:
    List m_polyHead;
};

Poly operator+(const Poly&, const Poly&);
Poly operator-(const Poly&, const Poly&);

Poly operator-(const Poly&);

Poly operator*(const Poly&, const Poly&);
Poly operator*(const Poly&, const Rational&);
Poly operator*(const Rational&, const Poly&);

Poly& operator+=(Poly&, const Poly&);
Poly& operator-=(Poly&, const Poly&);
Poly& operator*=(Poly&, const Poly&);

bool operator==(const Poly&, const Poly&);
bool operator!=(const Poly&, const Poly&);

ostream& operator<<(std::ostream&, const Poly&);

