#include "Poly.hpp"

// polynomial constructer made from a vector
//_________________________________________________
Poly::Poly(const std::vector<Rational>& polynomial)
: m_polyHead(polynomial)
{}
// polynomial constructer made by default
//__________
Poly::Poly()
: m_polyHead(0, Rational(0,1))
{}
// polynomial constructer made from a skalar
//____________________
Poly::Poly(const int skalar)
: m_polyHead(0, Rational(skalar,1))
{}
// polynomial constructer made from a degree and rational number
//____________________________________
Poly::Poly(const int deg, const Rational& monomial)
: m_polyHead(deg, monomial)
{}
// the degree of the polynomial
//________________________
int Poly::getDegPol()const
{
    return this->m_polyHead.getHeadList()->m_rational.getNummerator() == 0 ? -1 :
    this->m_polyHead.getHeadList()->m_deg;
}
// getting the haed of the list of the polynomial
//___________________________
Node* Poly::getHeadPol()const
{
    return m_polyHead.getHeadList();
}
//____________________
void Poly::printPoly()const
{
    this->m_polyHead.print();
}
// getting the value of the polynomial in a certain rational point
//________________________________________________
Rational Poly::operator()(Rational& rational)const
{
    auto valueOfpolynomial = Rational();
    auto count = Rational();
    auto temp = m_polyHead.getHeadList();
    for(; temp; temp = temp->m_next)
    {
        //        counting each rational by it's degree
        count = rational;
        for(int i=0; i< temp->m_deg; i++)
        {
            count *= rational;
        }
        valueOfpolynomial += count;
    }
    return valueOfpolynomial;
}
// getting the rational before the degree of the index
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
    
    //    while at least one of the list isn't null will continue adding
    //    to the new polynomial
    while(temp1 || temp2)
    {
        //        add to the new polynomial
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
// multipying two polynomials
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
//            if the cell is empty will assign it's new value
            if(newPol[size -temp1->m_deg-temp2->m_deg-1].getNummerator()==0)
                newPol[size -temp1->m_deg-temp2->m_deg-1] =
                temp1->m_rational * temp2->m_rational;
//            if wasn't empty will add to the value that was there
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
// checking if the degrees of the polynomials are the same
//_____________________________________
bool operator==(Poly& pol1, Poly& pol2)
{
    return pol1.getDegPol() == pol2.getDegPol();
}
// checking if the degrees of the polynomials are the different
//_____________________________________
bool operator!=(Poly& pol1, Poly& pol2)
{
    return !(pol1 == pol2);
}
// multipying a polynomial with a skalar
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
// multipying a polynomial with a skalar from the other side
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
