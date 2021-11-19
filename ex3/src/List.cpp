#include "List.hpp"

//_____________________________________________________________________
Node::Node(const unsigned int deg, const Rational rational, Node* next)
: m_deg(deg), m_rational(rational), m_next(next)
{}

//__________________________________________________________________
List::List(const std::vector<Rational>& polynomial)
: m_head(nullptr), m_mid(nullptr),
m_temp(nullptr), m_size(0)
{
    for(int i=0; i < polynomial.size(); i++)
    {
        this->insert(((unsigned int)polynomial.size()-i-1), polynomial[i]);
    }
}
//________________________________________________
List::List(const Rational rational)
: m_head(nullptr),m_size(0)
{
    m_head = new Node(0, Rational(0,1), m_head);
    m_size++;
}
//_______________________________________
List::List(const int skalar)
: m_head(nullptr),m_size(0)
{
    m_head = new Node(0, Rational(skalar,1), m_head);
    m_size++;
}
//________________________________________________________________________
List::List(const unsigned int deg, const Rational rational)
: m_head(nullptr),m_size(0)
{
    m_head = new Node(deg, rational, m_head);
    m_size++;
}
//________________________________________________________________
void List::insert(const unsigned int deg, const Rational rational)
{
    // creating the fisrt node
    if (m_size == 0 && rational.getNummerator()!=0)
    {
        m_head = new Node(deg, rational, m_head);
        m_head->m_next = m_head;
        m_head->m_prev = m_head;
    }
    // creating the second node
    else if (m_size == 1 && rational.getNummerator()!=0)
    {
        m_mid = new Node(deg, rational, m_mid);
        m_head->m_next = m_mid;
        m_head->m_prev = m_mid;
        m_mid->m_next = m_head;
        m_mid->m_prev = m_head;
    }
    // creating the third node and so on
    else if (m_size > 1 && rational.getNummerator()!=0)
    {
        m_temp = new Node(deg, rational, m_temp);
        m_head->m_prev = m_temp;
        m_temp->m_next = NULL;
        m_mid->m_next = m_temp;
        m_temp->m_prev = m_mid;
        m_mid = m_temp;
    }
    //  counting the nodes
    if(rational.getNummerator()!=0)
        m_size++;
}
//________________
void List::print()
{
    Node *p=m_head;
    for(int i=0; i<m_size; i++, p=p->m_next)
    {
        std::cout<< p->m_rational<< "x^" << p->m_deg << " ";
    }
    std::cout<< "\nend of polynomial\n";
}

