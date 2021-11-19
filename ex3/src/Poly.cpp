#include "Poly.hpp"

//_________________________________________________
Poly::Poly(const std::vector<Rational>& polynomial)
: m_polyHead(polynomial)
{}
//___________________________
Poly::Poly(Rational rational)
: m_polyHead(rational)
{}
//____________________
Poly::Poly(int skalar)
: m_polyHead(skalar)
{}
//________________________________
Poly::Poly(int deg, Rational monomial)
: m_polyHead(deg, monomial)
{}
//____________________
void Poly::printPoly()
{
    m_polyHead.print();
}
