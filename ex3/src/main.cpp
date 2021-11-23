#include <iostream>

#include "Rational.hpp"
#include "Poly.hpp"

void printl();
void printp();

using std::cout;
using std::endl;

int main()
{
//    printl();
    printp();
//    auto x = std::vector<Rational>{Rational(5,1), Rational(), Rational(3,-5),
//        Rational(-3,-5), Rational(-3,5)};
//    Rational r(3,4);
//    List x3(4, r);
//    List x1(x);
//    x1.print();
//    List x2 = x1;
//    x1 = x3;
//    x2.print();
//    x1.print();

    return 0;
}

void printl()
{
    auto r = Rational (3,4);
    auto r3 = Rational (5,6);
    auto r1 = Rational (-1,1);
    std::cout << r1 << std::endl;
    std::cout << r << " " << r3 << " r<r3 ";
    r<r3 ? std::cout << "true\n" : std::cout << "false\n";
    std::cout << r << " " << r3 << " r>r3 ";
    r>r3 ? std::cout << "true\n" : std::cout << "false\n";
    std::cout << r << " " << r3 << " r<=r3 ";
    r<=r3 ? std::cout << "true\n" : std::cout << "false\n";
    std::cout << r << " " << r3 << " r>=r3 ";
    r>=r3 ? std::cout << "true\n" : std::cout << "false\n";
    std::cout << r << " " << r3 << " r==r3 ";
    r==r3 ? std::cout << "true\n" : std::cout << "false\n";
    std::cout << r << " " << r3 << " r!=r3 ";
    r!=r3 ? std::cout << "true\n" : std::cout << "false\n";
}

void printp()
{
    auto r1 = Rational (2,1);
    auto r = Rational (3,4);
    auto x = std::vector<Rational>{Rational(5,1), Rational(), Rational(3,-5),
        Rational(-3,-5), Rational(-3,5)};
    auto x2 = std::vector<Rational>{Rational(5,1), Rational(), Rational(3,-5),
        Rational(-3,-5), Rational(-3,5)};
    auto pol = Poly(x);
    pol.printPoly();
    auto pol1 = Poly(x2);
//    pol1.printPoly();
    auto pol2 = Poly(5);
//    pol2.printPoly();
    auto pol3 = Poly(5,r);
//    pol3.printPoly();
    auto x1 = Poly();
    x1 = pol2 + pol3;
    x1.printPoly();
}
