#pragma once

#include <stdio.h>
#include <vector>
#include "Rational.hpp"
#include "List.hpp"

class Poly
{
public:
    Poly(const std::vector<Rational>&); // regular polynomial
    Poly(Rational);                     // default polynomial
    Poly(int);                          // skalar polynomial
    Poly(int, Rational);                // monomial polynomial
    void printPoly();
    
private:
    List m_polyHead;
    
};
