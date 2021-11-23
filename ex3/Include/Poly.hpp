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
    Poly(int);                          // skalar polynomial
    Poly(int, Rational);                // monomial polynomial
    void printPoly();
    int getDegPol()const;
    int getSizePol()const;
    Node *getHeadPol()const;
//    Poly &operator=(const Poly&);
    
    
private:
    List m_polyHead;
    int m_size;
    
};

Poly operator+(const Poly&, const Poly&);
