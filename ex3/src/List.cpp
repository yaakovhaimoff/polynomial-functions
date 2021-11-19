#include "List.hpp"

//_____________________________________________________________________
Node::Node(const unsigned int deg, const Rational rational, Node* next)
: m_deg(deg), m_rational(rational), m_next(nullptr)
{}


//_____________________________
List::List(): m_head(nullptr){}
//__________________________________________________________________
void List::insertPolynomial(const std::vector<Rational>& polynomial)
{
    for(int i=0; i < polynomial.size(); i++)
    {
        this->insert(((unsigned int)polynomial.size()-1), polynomial[i]);
    }
}
//________________________________________________
void List::insertRational(const Rational rational)
{
    this->insert(1, rational);
}
//_______________________________________
void List::insertSkalar(const int skalar)
{
    Rational rational;
    this->insert(1, rational);
}
//________________________________________________________________________
void List::insertMonomial(const unsigned int deg, const Rational rational)
{
    this->insert(deg, rational);
}
//________________________________________________________________
void List::insert(const unsigned int deg, const Rational rational)
{
    // Create the new Node.
    m_head = new Node(deg, rational, m_head);
}
//________________
void List::print()
{
    Node *p=m_head;
    while(p)
    {
        std::cout<< p->m_rational<< "x^" << p->m_deg << "\n";
        p=p->m_next;
    }
    std::cout<< "end of polynomial\n";
}
