#include <cstdlib>
#include <iostream>
#include "Rational.hpp"
#include "Poly.hpp"
#include <string_view>

using std::cout;

const int DEF_NUMERATOR = 0;
const int DEF_DENOMINATOR = 1;
void titlePrint(std::string_view title)
{
    cout << "--------------" << title << "--------------------\n\n";
}

<<<<<<< HEAD
    Rational r1(5, 1);
    Poly polylinum1(vector<Rational> {Rational(14, 1), Rational(), Rational(),
    Rational(5, 1), Rational(), Rational(17, 2)});;  // 5-element Poly
    Poly polylinum2(vector<Rational> {Rational(6, 1), Rational(2, 1), Rational(2, 1)});// 3-element Poly
    Poly polylinum_monomial(5, r1);//Monomial polynomial
    auto p3 = vector<Rational>{Rational(), Rational(3,4)};
    auto x = Poly(p3);
    cout << x << endl;

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

=======
int main()
{
>>>>>>> dev

    bool result;
    titlePrint("EX3");
    titlePrint("Rational");


    auto printTest = [](bool flag)
    {
        static int count = 1;
        std::cout << "TEST " << count;
        flag ? std::cout << " PASSED\n" : std::cout << " FAILED\n";

        ++count;
    };

    auto r1 = Rational(-10, -5);// 2/1
    auto r2 = Rational(2, 1);// 2/1
    auto r3 = Rational(5);// 5/1
    auto r4 = Rational(); // defualt
    auto r5 = Rational(7, 44);
    auto r6 = Rational(81, 44);

    result = r1.getNumerator() == r2.getNumerator() && r1.getDenominator() == r2.getDenominator();
    printTest(result); // TEST 1

    result = r3.getNumerator() == 5 && r3.getDenominator() == DEF_DENOMINATOR;
    printTest(result); //TEST 2
    result = r4.getNumerator() == DEF_NUMERATOR && r4.getDenominator() == DEF_DENOMINATOR;
    printTest(result); //TEST 3

    result = (-r1 == r2 * -1);
    printTest(result); //TEST 4
    result = (r2 == r5 + r6);
    printTest(result); //TEST 5
    r5 += r6; // r5: 2
    printTest(r5 == r2); //TEST 6
    r3 *= (r1 + r2); // r3: 20
    r5 *= 10; // r5 : 20
    printTest(r5 == r3); //TEST 7
    r5 /= r3; // r5 :1
    printTest(r5 == Rational(1)); //TEST 8
    printTest(r5 != r4); //TEST 9
    printTest(r1 <= r2); // TEST 10
    printTest(!(r1 > r2)); // TEST 11

    titlePrint("Poly");

    auto co1 = std::vector<Rational>{ r1, r2,r3, r1 }; // 2, 2 ,20, 2
    auto co2 = std::vector<Rational>{ r1, r2,r1, r1, }; // 2, 2, 2,2
    auto co3 = std::vector<Rational>{ r1, r2 }; // 2,2
    auto co4 = std::vector<Rational>{ r1 * 2 , r2 * 2, r3 * 2, r1 * 2 }; // 2, 2 ,20, 2

    auto p1 = Poly(co1);
    auto p2 = Poly(co2);
    auto p3 = Poly(co3);
    auto p4 = p1 - p2; //copy ctor => 18x^1
    auto p5 = Poly(co4);


    printTest(p3.deg() == p4.deg()); //TEST 12
    printTest((p3 += p4)[0] == 20);  // TEST 13 - 20x +2
    printTest((p2 *= p2).deg() == 6); //TEST 14
    printTest(p4(2 / 1) == 36);  //TEST 15
    p3 = p1; // copy assignment operator:
    printTest(p3 == p1); //TEST 16
    printTest((p1 + p3) != p1 * p1 * p1); //TEST 17
    printTest(p1 * 2 == p5); //TEST 18

    return EXIT_SUCCESS;
}
