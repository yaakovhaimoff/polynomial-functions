#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Rational.hpp"

struct Node
{

    Node(const unsigned int, const Rational, Node*, Node*);
    unsigned int m_deg;
    Rational m_rational;
    Node *m_next,
    *m_prev;

};

class List
{
public:
    List();
    List(const std::vector<Rational>&);
    List(const unsigned int, const Rational);
    ~List();
    void insert(const unsigned int, const Rational);
    int getDeg()const;
    int getSize()const;
    Node *getNext();
    void print();
    List &operator=(const List&);
    
    
private:
    Node *m_head;
    
};


