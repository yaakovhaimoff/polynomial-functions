#include "List.hpp"

//_____________________________________________________________________
Node::Node(const unsigned int deg, const Rational rational,
           Node* next, Node* prev)
: m_deg(deg), m_rational(rational), m_next(next), m_prev(prev)
{}

//_________________________________________________
List::List(const std::vector<Rational>& polynomial)
: m_head(nullptr)
{
    for(int i=0; i < polynomial.size(); i++)
    {
        this->insert(((unsigned int)polynomial.size()-i-1), polynomial[i]);
    }
}
//_________________________________________________________
List::List(const unsigned int deg, const Rational rational)
: m_head(nullptr)
{
    m_head = new Node(deg, rational, nullptr, nullptr);
}
//________________________________________________________________
void List::insert(const unsigned int deg, const Rational rational)
{
    Node *newNode = new Node(deg, rational, nullptr, nullptr);
    
    if(m_head==nullptr)
        m_head = newNode;
    else
    {
        Node* temp = m_head;
        while(temp->m_next!=nullptr)
            temp = temp->m_next;
        
        temp->m_next = newNode;
        newNode->m_prev = temp;
    }
}
//_____________________
int List::getDeg()const
{
    return this->m_head->m_deg;
}
//______________________
int List::getSize()const
{
    int count = 0;
    for(Node* temp = this->m_head; temp!=nullptr; temp=temp->m_next)
    {
        count++;
    }
    return count;
}
//___________________
Node* List::getNext()
{
    return this->m_head->m_next;
}
//________________
void List::print()
{
    for(Node* temp = this->m_head; temp!=nullptr; temp=temp->m_next)
    {
        std::cout<< temp->m_rational<< "x^" << temp->m_deg << " ";
    }
    std::cout<< "\nend of polynomial\n";
}
//___________
List::~List()
{
    Node* p1 = m_head, *p2;
    while(p1->m_next!=nullptr)
    {
        p2 = p1;
        p1 = p1->m_next;
        delete (p2);
    }
}
////______________________________________
//List &List::operator=(const List& list1)
//{
//    std::cout << "operator= called\n";
//
//    if ( &list1 != this ) // avoid self assignment
//    {
//        delete [] m_head;              // prevents memory leak
//        m_head = list1.m_head;
//        m_size = list1.m_size;
//    }
//    return *this;
//}
