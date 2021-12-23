#include "Poly.hpp"

// polynomial constructer made from a vector
//_________________________________________________
Poly::Poly(const std::vector<Rational>& polynomial)
    : m_polyHead(polynomial)
{}
// polynomial constructer made by default
//__________
Poly::Poly()
    : m_polyHead(0, Rational(0, 1))
{}
// polynomial constructer made from a skalar
//_______________________________
Poly::Poly(const Rational skalar)
    : m_polyHead(0, skalar)
{}
// polynomial constructer made from a degree and rational number
//____________________________________
Poly::Poly(const int deg, const Rational& monomial)
    : m_polyHead(deg, monomial)
{}
// the degree of the polynomial
//________________________
int Poly::deg()const
{
    return this->m_polyHead.getHeadList()->m_rational.getNumerator() == 0 ? -1 :
        this->m_polyHead.getHeadList()->m_deg;
}
// getting the haed of the list of the polynomial
//___________________________
const Node* Poly::getHeadPol()const
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
Rational Poly::operator()(const Rational& rational)const
{
    auto valueOfpolynomial = Rational();
    auto count = Rational();
    auto temp = m_polyHead.getHeadList();
    for (; temp; temp = temp->m_next)
    {
        //        counting each rational by it's degree
        count = rational;
        for (int i = 1; i < temp->m_deg; i++)
        {
            count *= rational;
        }
        //  if the degree is 0 then the rational in power of 0 is 1
        if (temp->m_deg == 0)
            count = Rational(1, 1);
        valueOfpolynomial = valueOfpolynomial + ((temp->m_rational * count));
    }
    return valueOfpolynomial;
}
// getting the rational before the degree of the index
//______________________________________________
Rational Poly::operator[](const int index)const
{
    Rational defualtPoint;
    auto temp = m_polyHead.getHeadList();

    for (; temp; temp = temp->m_next)
        if (index == temp->m_deg)
             return temp->m_rational;

    return Rational();
}


//________________________________________________
Poly operator+(const Poly& pol1, const Poly& pol2)
{
    auto temp1 = pol1.getHeadPol();
    auto temp2 = pol2.getHeadPol();

    auto size = std::max(temp1->m_deg, temp2->m_deg) + 1;
    std::vector<Rational>newPol(size, 0);

    //    while at least one of the list isn't null will continue adding
    //    to the new polynomial
    while (temp1 || temp2)
    {
        //          adding to the new polynomial
        //         and moving forward in the list
        if (temp1)
        {
            newPol[size - temp1->m_deg - 1] += temp1->m_rational;
            temp1 = temp1->m_next;
        }
        if (temp2)
        {
            newPol[size - temp2->m_deg - 1] += temp2->m_rational;
            temp2 = temp2->m_next;
        }
    }
    return Poly(newPol);
}
//________________________________________________
Poly operator-(const Poly& pol1, const Poly& pol2)
{
    return pol1 + (-pol2);
}
//  making all polynomial minus for futher calculations
//_____________________________
Poly operator-(const Poly& pol)
{
    auto temp = pol.getHeadPol();
    auto size = temp->m_deg + 1;
    std::vector<Rational>newPol(size, 0);
    while (temp)
    {
        newPol[size - temp->m_deg - 1] =
            Rational(-temp->m_rational.getNumerator(),
                temp->m_rational.getDenominator());
        temp = temp->m_next;
    }
    return Poly(newPol);
}
// multipying two polynomials
//________________________________________________
Poly operator*(const Poly& pol1, const Poly& pol2)
{
    auto temp1 = pol1.getHeadPol();
    auto temp2 = pol2.getHeadPol();

    auto size = temp1->m_deg + temp2->m_deg + 1;
    std::vector<Rational>newPol(size, 0);

    for (; temp1 != nullptr; temp1 = temp1->m_next)
    {
        for (temp2 = pol2.getHeadPol(); temp2 != nullptr; temp2 = temp2->m_next)
        {
            //            if the cell is empty will assign it's new value
            if (newPol[size - temp1->m_deg - temp2->m_deg - 1].getNumerator() == 0)
                newPol[size - temp1->m_deg - temp2->m_deg - 1] =
                temp1->m_rational * temp2->m_rational;
            //            if wasn't empty will add to the value that was there
            else
                newPol[size - temp1->m_deg - temp2->m_deg - 1] =
                newPol[size - temp1->m_deg - temp2->m_deg - 1] +
                temp1->m_rational * temp2->m_rational;

        }
    }
    return Poly(newPol);
}
// multipying a polynomial with a skalar
//_______________________________________________________
Poly operator*(const Rational& rational, const Poly& pol)
{
    auto temp = pol.getHeadPol();
    auto size = temp->m_deg + 1;
    std::vector<Rational>newPol(size, 0);

    for (; temp; temp = temp->m_next)
    {
        newPol[size - temp->m_deg - 1] = temp->m_rational * rational;
    }
    return Poly(newPol);
}
// multipying a polynomial with a skalar from the other side
//_______________________________________________________
Poly operator*(const Poly& pol, const Rational& rational)
{
    return rational * pol;
}
//____________________________________________
Poly& operator+=(Poly& pol1, const Poly& pol2)
{
    pol1 = pol1 + pol2;
    return pol1;
}
//___________________________________________
Poly& operator-=(Poly& pol1, const Poly& pol2)
{
    pol1 = pol1 - pol2;
    return  pol1;
}
//___________________________________________
Poly& operator*=(Poly& pol1, const Poly& pol2)
{
    pol1 = pol1 * pol2;
    return pol1;
}
// checking if the degrees of the polynomials are the same
//_____________________________________
bool operator==(const Poly& pol1, const Poly& pol2)
{
    return pol1.deg() == pol2.deg();
}
// checking if the degrees of the polynomials are the different
//_____________________________________
bool operator!=(const Poly& pol1, const Poly& pol2)
{
    return !(pol1 == pol2);
}
//___________________________________________________
ostream& operator<<(std::ostream& output, const Poly& pol)
{
    pol.printPoly();
    return output;
}
