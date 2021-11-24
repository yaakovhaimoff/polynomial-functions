#include "Poly.hpp"

//_________________________________________________
Poly::Poly(const std::vector<Rational>& polynomial)
: m_polyHead(polynomial)
{}
//__________
Poly::Poly()
: m_polyHead(0, Rational(0,1))
{}
//____________________
Poly::Poly(const int skalar)
: m_polyHead(0, Rational(skalar,1))
{}
//____________________________________
Poly::Poly(const int deg, const Rational& monomial)
: m_polyHead(deg, monomial)
{}
//_________________________
void Poly::printPoly()const
{
    m_polyHead.print();
}
//________________________
int Poly::getDegPol()const
{
    return this->m_polyHead.getHeadList()->m_rational.getNummerator() == 0 ? -1 :
    this->m_polyHead.getHeadList()->m_deg;
}
//___________________________
Node* Poly::getHeadPol()const
{
    return m_polyHead.getHeadList();
}
//________________________________________________
Rational Poly::operator()(Rational& rational)const
{
    auto point = Rational();
    auto count = Rational();
    auto temp = m_polyHead.getHeadList();
    for(; temp; temp = temp->m_next)
    {
        count = rational;
        for(int i=0; i< temp->m_deg; i++)
        {
            count *= rational;
        }
        point += count;
    }
    return point;
}
//______________________________________________
Rational& Poly::operator[](const int index)const
{
    auto point = Rational();
    auto temp = m_polyHead.getHeadList();
    
    for(; temp; temp = temp->m_next)
        if(index == temp->m_deg)
            break;
    
    return temp->m_rational;
}


//________________________________________________
Poly operator+(const Poly& pol1, const Poly& pol2)
{
    auto temp1 = pol1.getHeadPol();
    auto temp2 = pol2.getHeadPol();
    
    auto size = std::max(temp1->m_deg, temp2->m_deg)+1;
    std::vector<Rational>newPol(size, 0);
    
    //    while at leat one of the list isn't null
    while(temp1 || temp2)
    {
        //        add the new polynomials
        if(temp1)
            newPol[size-temp1->m_deg-1] = temp1->m_rational;
        if(temp2)
            newPol[size-temp2->m_deg-1] += temp2->m_rational;
        //        move forward in list
        if(temp1)
            temp1=temp1->m_next;
        if(temp2)
            temp2=temp2->m_next;
    }
    return Poly(newPol);
}
//______________________________________
Poly &operator+=(Poly& pol1, Poly& pol2)
{
    pol1 = pol1 + pol2;
    return pol1;
}
//________________________________________________
Poly operator-(const Poly& pol1, const Poly& pol2)
{
    return pol1 + (-pol2);
}
//_____________________________
Poly operator-(const Poly& pol)
{
    auto temp = pol.getHeadPol();
    auto size = temp->m_deg+1;
    std::vector<Rational>newPol(size, 0);
    while(temp)
    {
        newPol[size-temp->m_deg-1] =
        Rational(-temp->m_rational.getNummerator(),
                 temp->m_rational.getDenominator());
        temp=temp->m_next;
    }
    return Poly(newPol);
}
//_____________________________________
Poly operator-=(Poly& pol1, Poly& pol2)
{
    pol1 = pol1 - pol2;
    return  pol1;
}
//________________________________________________
Poly operator*(const Poly& pol1, const Poly& pol2)
{
    auto temp1 = pol1.getHeadPol();
    auto temp2 = pol2.getHeadPol();
    
    auto size = temp1->m_deg + temp2->m_deg +1;
    std::vector<Rational>newPol(size, 0);
    
    for(; temp1!=nullptr; temp1 = temp1->m_next)
    {
        for(temp2 = pol2.getHeadPol(); temp2!=nullptr; temp2 = temp2->m_next)
        {
            if(newPol[size -temp1->m_deg-temp2->m_deg-1].getNummerator()==0)
                newPol[size -temp1->m_deg-temp2->m_deg-1] =
                temp1->m_rational * temp2->m_rational;
            else
                newPol[size -temp1->m_deg-temp2->m_deg-1] =
                newPol[size -temp1->m_deg-temp2->m_deg-1] +
                temp1->m_rational * temp2->m_rational;
            
        }
    }
    return Poly(newPol);
}
//_____________________________________
Poly operator*=(Poly& pol1, Poly& pol2)
{
    pol1 = pol1 * pol2;
    return pol1;
}
//_____________________________________
bool operator==(Poly& pol1, Poly& pol2)
{
    return pol1.getDegPol() == pol2.getDegPol();
}
//_____________________________________
bool operator!=(Poly& pol1, Poly& pol2)
{
    return !(pol1 == pol2);
}
//___________________________________________
Poly operator*(Rational& rational, Poly& pol)
{
    auto temp = pol.getHeadPol();
    auto size = temp->m_deg +1;
    std::vector<Rational>newPol(size, 0);
    
    for(; temp; temp = temp->m_next)
    {
        newPol[size-temp->m_deg-1] = temp->m_rational * rational;
    }
    return Poly(newPol);
}
//___________________________________________
Poly operator*(Poly& pol, Rational& rational)
{
    return rational * pol;
}
//___________________________________________________
ostream &operator<<(ostream& output, const Poly& pol)
{
    pol.printPoly();
    return output;
}
