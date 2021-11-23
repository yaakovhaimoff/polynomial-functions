#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Rational.hpp"

struct Node
{
    Node(const unsigned int, const Rational, Node*, Node*);
    
    // members of node
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
    List(const List&);
    ~List();
    void insert(const unsigned int, const Rational);
    int getDeg()const;
    Node *getHeadList()const;
    Rational getRationalList()const;
    void print();
    List &operator=(const List&);
    void copyList(const List& other);
    void deleteList();
    
    
private:
    Node *m_head;
    
};
