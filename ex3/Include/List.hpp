#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Rational.hpp"

struct Node
{
    Node(const unsigned int, const Rational, Node*);
    
    // members of node
    unsigned int m_deg;
    Rational m_rational;
    Node *m_next;

};

class List
{
public:
    List();
    List(const std::vector<Rational>&);
    List(const unsigned int, const Rational);
    List(const List&);
    ~List();
    void insert(const unsigned int, const Rational);
    void print()const;
    void copyList(const List& other);
    void deleteList();
    Node *getHeadList()const;
    List &operator=(const List&);
    
    
private:
    Node *m_head;
    
};
