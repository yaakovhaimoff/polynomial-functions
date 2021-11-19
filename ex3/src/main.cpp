#include <iostream>

#include "Rational.hpp"
#include "Poly.hpp"

int main()
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
    auto x = std::vector<Rational>{Rational(5,1), Rational(3,1), Rational(3,5)};
    auto pol = Poly(x);
    pol.printPoly();
    
    return 0;
}
