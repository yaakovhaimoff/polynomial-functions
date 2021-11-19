#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Rational.hpp"

struct Node
{
    Node(const unsigned int, const Rational, Node*);
    unsigned int m_deg;
    Rational m_rational;
    Node *m_next,
    *m_prev;

};

class List
{
public:
    List();
    ~List();
    void insertPolynomial(const std::vector<Rational>&);
    void insertRational(const Rational);
    void insertSkalar(const int);
    void insertMonomial(const unsigned int, const Rational);
    void insert(const unsigned int, const Rational);
    void print();
    
    
    
private:
    Node *m_head;
    
};
