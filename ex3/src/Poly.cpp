#include "Poly.hpp"

//_________________________________________________
Poly::Poly(const std::vector<Rational>& polynomial)
: m_polyHead(polynomial)
{}
//___________________________
Poly::Poly()
: m_polyHead(0, Rational(0,1))
{}
//____________________
Poly::Poly(int skalar)
: m_polyHead(0, Rational(skalar,1))
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
//________________________
int Poly::getDegPol()const
{
    return this->m_polyHead.getDeg() > 0 ? this->m_polyHead.getDeg() :
    -1;
}
//_________________________
int Poly::getSizePol()const
{
    return this->m_polyHead.getSize();
}
//_______________________________________________
Poly operator+(const Poly& pol1, const Poly& pol2)
{
    Poly newPol;
        int size = std::min(pol1.getSizePol(), pol2.getSizePol());
    while(size>0)
    {
        if(pol1.getDegPol() == pol2.getDegPol())
        {
            newPol = Poly(pol1.getDegPol());
        }
        else
        {
            newPol = Poly(pol2.getDegPol());
        }
    }
    
    return newPol;
}
