#include <iostream>

#include "Rational.hpp"
#include "Poly.hpp"

void printl();
void printp();

using std::cout;
using std::endl;

int main()
{
    printl();
//    printp();
    auto x = std::vector<Rational>{Rational(5,1), Rational(), Rational(3,-5),
        Rational(-3,-5), Rational(-3,5)};
    auto p = Poly();
    auto p1 = Poly(x);
//    cout << p.printPoly() << endl;
    auto p2 = p+p1;
    p2.printPoly();
    cout << p.getDegPol() << endl;
    

    
    return 0;
}

void printl()
{
    auto r = Rational (3,4);
    auto r3 = Rational (5,6);
    auto r1 = Rational (-1,1);
//    std::cout << r1 << std::endl;
//    std::cout << r << " " << r3 << " r<r3 ";
//    r<r3 ? std::cout << "true\n" : std::cout << "false\n";
//    std::cout << r << " " << r3 << " r>r3 ";
//    r>r3 ? std::cout << "true\n" : std::cout << "false\n";
//    std::cout << r << " " << r3 << " r<=r3 ";
//    r<=r3 ? std::cout << "true\n" : std::cout << "false\n";
//    std::cout << r << " " << r3 << " r>=r3 ";
//    r>=r3 ? std::cout << "true\n" : std::cout << "false\n";
//    std::cout << r << " " << r3 << " r==r3 ";
//    r==r3 ? std::cout << "true\n" : std::cout << "false\n";
//    std::cout << r << " " << r3 << " r!=r3 ";
//    r!=r3 ? std::cout << "true\n" : std::cout << "false\n";
}

void printp()
{
    auto r = Rational (3,4);
    auto r1 = Rational (2,1);
    auto x = std::vector<Rational>{Rational(5,1), Rational(), Rational(3,-5),
        Rational(-3,-5), Rational(-3,5)};
    auto pol = Poly(x);
    pol.printPoly();
    auto pol1 = Poly();
    pol1.printPoly();
    auto pol2 = Poly(5);
    pol2.printPoly();
    auto pol3 = Poly(5,r);
    pol3.printPoly();
}
