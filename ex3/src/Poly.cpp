#include "Poly.hpp"

//_________________________________________________
Poly::Poly(const std::vector<Rational>& polynomial)
{
    m_polyHead->insertPolynomial(polynomial);
}
//___________________________
Poly::Poly(Rational rational)
{
    m_polyHead->insertRational(rational);
}
//____________________
Poly::Poly(int skalar)
{
    m_polyHead->insertSkalar(skalar);
}
//________________________________
Poly::Poly(int deg, Rational monomial)
{
    m_polyHead->insertMonomial(deg, monomial);
}
//____________________
void Poly::printPoly()
{
    m_polyHead->print();
}
