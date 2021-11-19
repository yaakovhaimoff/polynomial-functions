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
//    ~List();
    List(const std::vector<Rational>&);
    List(const Rational);
    List(const int);
    List(const unsigned int, const Rational);
    void insert(const unsigned int, const Rational);
    void print();
    
    
    
private:
    Node *m_head,
    *m_mid,
    *m_temp;
    int m_size;
    
    
};
