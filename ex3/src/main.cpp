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
//    auto r1 = Rational (2,1);
    auto r = Rational (2,1);
//    auto x = std::vector<Rational>{Rational(5,1), Rational(), Rational(3,-5),
//        Rational(-3,-5), Rational(-3,5)};
//    auto x2 = std::vector<Rational>{Rational(7,2), Rational(), Rational(7,2), Rational(), Rational(3,-5), Rational(3,-5), Rational(10,5)};
//    auto pol = Poly(x);
////    pol.printPoly();
//    auto pol1 = Poly(x2);
////    pol1.printPoly();
//    auto pol2 = Poly(5);
////    pol2.printPoly();
//    auto pol3 = Poly(5,r);
////    pol3.printPoly();
//    auto x1 = Poly();
//    x1.printPoly();
//    pol1.printPoly();
//    x1 -= pol1;
//    x1.printPoly();
    auto x = std::vector<Rational>{Rational(2,1), Rational(8,4), Rational(),
        Rational(), Rational(1,1)};
//    auto x1 = std::vector<Rational>{Rational(3,1), Rational(4,1), Rational(5,1),
//        Rational(3,1), Rational(4,1)
//    };
//    auto x2 = std::vector<Rational>{Rational(-3,1), Rational(4,1), Rational(-4,1), Rational(4,1)};
    auto p = Poly(x);
//    auto p1 = Poly(x1);
//    auto p2 = Poly(8);
//    auto p3 = Poly(x2);
    cout << p;
//    cout << p1;
//    cout << p3;
    cout << r << endl;
//    p2 = r*p3;
//    cout << p2;
//    p3*=p3;
//    p3 = p3 + p3;;
//    cout << p3;
//    cout << p2 ;
//    cout << p2.getDegPol() << endl;
//    p == p1 ? cout << "true\n" : cout << "false\n";
    cout <<  p(r) << endl;
   
}
