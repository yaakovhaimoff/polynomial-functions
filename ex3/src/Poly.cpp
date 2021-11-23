#include "Poly.hpp"

//_________________________________________________
Poly::Poly(const std::vector<Rational>& polynomial)
: m_polyHead(polynomial), m_size(int(polynomial.size()))
{}
//__________
Poly::Poly()
: m_polyHead(0, Rational(0,1)),
m_size(1)
{}
//____________________
Poly::Poly(int skalar)
: m_polyHead(0, Rational(skalar,1)),
m_size(1)
{}
//____________________________________
Poly::Poly(int deg, Rational monomial)
: m_polyHead(deg, monomial),
m_size(1)
{}
//____________________
void Poly::printPoly()
{
    m_polyHead.print();
}
//________________________
int Poly::getDegPol()const
{
    return this->getSizePol()-1;
}
//___________________________
Node* Poly::getHeadPol()const
{
    return m_polyHead.getHeadList();
}
//________________________________________________
Poly operator+(const Poly& pol1, const Poly& pol2)
{
    auto temp1 = pol1.getHeadPol();
    auto temp2 = pol2.getHeadPol();
    
    int size = std::max(temp1->m_deg, temp2->m_deg)+1;
    std::vector<Rational>newPol(size, 0);
    
    while(temp1 != nullptr || temp2 != nullptr)
    {
        if(temp1!=nullptr)
            newPol[size-temp1->m_deg-1] = temp1->m_rational;
        if(temp2!=nullptr)
            newPol[size-temp2->m_deg-1] += temp2->m_rational;
        
        if(temp1!=nullptr)
            temp1=temp1->m_next;
        if(temp2!=nullptr)
            temp2=temp2->m_next;
    }
    return Poly(newPol);
}
