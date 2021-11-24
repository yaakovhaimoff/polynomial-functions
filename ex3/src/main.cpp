#include <iostream>

#include "Rational.hpp"
#include "Poly.hpp"

using std::cout;
using std::endl;
using std::vector;

int main()
{

    Rational r1(5, 1);
    Poly polylinum1(vector<Rational> {Rational(14, 1), Rational(), Rational(),
    Rational(5, 1), Rational(), Rational(17, 2)});;  // 5-element Poly
    Poly polylinum2(vector<Rational> {Rational(6, 1), Rational(2, 1), Rational(2, 1)});// 3-element Poly
    Poly polylinum_monomial(5, r1);//Monomial polynomial

    // print polylinum1 size and contents
    cout << "The high degree of polylinum1 is: "
        << polylinum1.getDegPol() << '\n';

    // print polylinum2 size and contents
    cout << "The high degree of polylinum2 is: "
        << polylinum2.getDegPol() << '\n';

    // print polylinum2 size and contents
    cout << "The high degree of polylinum_monomial is: "
        << polylinum_monomial.getDegPol() << '\n';

    // print polylinum1 contents
    cout << "polylinum1 after initialization:\n" << polylinum1;

    // print polylinum2 contents
    cout << "\npolylinum2 after initialization:\n" << polylinum2;

    // print polylinum2 contents
    cout << "\npolylinum_monomial after initialization:\n" << polylinum_monomial;

    Poly polynom_copy(polylinum2);  // calls copy constructor
    cout << "\npolylinum use copy constructor from polylinum2:\n" << polynom_copy;


    Poly polylinum3 = polylinum2;
    //print polylinum1 = polylinum2
    cout << "\npolylinum3 = polylinum2 = " << polylinum3;
    
    polylinum3 = polylinum1 * polylinum2;
    //print polylinum1 * polylinum2
    cout << "\npolylinum1 * polylinum2 = " << polylinum3;

    polylinum3 = polylinum1 + polylinum2;
    // print polylinum1 + polylinum2
    cout << "\npolylinum1 + polylinum2 = " << polylinum3;

    polylinum3 = polylinum1 - polylinum2;
    // print polylinum1 - polylinum2
    cout << "\npolylinum1 - polylinum2 = " << polylinum3;

    // print polylinum1 += polylinum2
    cout << "\npolylinum1 += polylinum1 = " << (polylinum1 += polylinum1);

    // print polylinum1 + polylinum2
    cout << "\npolylinum2 *= polylinum2 = " << (polylinum2 *= polylinum2);

    // use overloaded inequality (!=) operator
    if (polylinum1 != polylinum2)
        cout << "\npolylinum1 and polylinum2 are not equal";
    else
        cout << "\npolylinum1 and polylinum2 are equal";

    if (polylinum1 == polylinum1)
        cout << "\npolylinum1 and polylinum1 are equal";

    cout << "\nSolution of polynom_copy for X = 5/1 : " << polynom_copy(r1);


    return EXIT_SUCCESS; // end main
}
