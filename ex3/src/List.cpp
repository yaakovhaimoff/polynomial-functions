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
    this->insert(deg, rational);
}
//___________________________
List::List(const List &other)
: m_head(nullptr)
{
    std::cout << "copy ctor\n";
    this->copyList(other);
}
//________________________________________________________________
void List::insert(const unsigned int deg, const Rational rational)
{
    Node *newNode = new Node(deg, rational, nullptr, nullptr);
    
    if(m_head==nullptr && rational.getNummerator()!=0)
        m_head = newNode;
    else if(rational.getNummerator()!=0)
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
//____________________________
Node* List::getHeadList()const
{
    return this->m_head;
}
//___________________________________
Rational List::getRationalList()const
{
    return this->m_head->m_rational;
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
    deleteList();
}
//____________________________________
void List::copyList(const List& other)
{
    Node* temp = other.m_head;
    this->deleteList();
    m_head = nullptr;
    while(temp!=nullptr)
    {
        this->insert(temp->m_deg, temp->m_rational);
        temp=temp->m_next;
    }
}
//_____________________
void List::deleteList()
{
    std::cout << "deleteList called\n";
    Node* p1 = m_head, *p2;
    while(p1!=nullptr)
    {
        p2 = p1;
        p1 = p1->m_next;
        delete (p2);
    }
}
//______________________________________
List &List::operator=(const List& list1)
{
    std::cout << "operator= called\n";
                                                        
    if ( &list1 != this )       // avoid self assignment
    {
        // prevents memory leak
        this->copyList(list1);
    }
    return *this;
}


