#include <iostream>
#include "Set.h"

void main() {
    std::cout << "\n--Adding elements to Set test--\n";
    std::cout << "-- SetA.push(1), SetA.push(2), ... --\n";

    Set <int> setA;
    setA.push(1);
    setA.push(2);
    setA.push(2);
    setA.push(3);
    setA.push(2);
    setA.push(4);
    setA.push(5);
    setA.push(6);

    std::cout << "--Po: SetA--\n";
    std::cout << setA;

    Set <int> setB;
    setB.push(1);
    setB.push(2);
    setB.push(3);
    setB.push(6);
    setB.push(7);

    std::cout << "\n--Removing elements from Set test--\n";
    std::cout << "--Before: SetA--\n";
    std::cout << setA;

    std::cout << "--SetA.pop(6) --\n";
    setA.pop(6);

    std::cout << "--After: SetA--\n";
    std::cout << setA;
    std::cout << "\n---\n";

    std::cout << "\n--Emptying Set test--\n";
    std::cout << "--Before: SetA--\n";
    std::cout << setA << "Set size: " << setA.getSize() << "\n\n";

    std::cout << "--SetA.empty() --\n";
    setA.empty();

    std::cout << "--After: SetA--\n";
    std::cout << setA << "Set size: " << setA.getSize() << "\n\n";

    std::cout << "\n-----------Overloaded operators test-----------";

    setA.push(1);
    setA.push(2);
    setA.push(3);
    setA.push(4);
    setA.push(5);

    std::cout << "\n--SetA:--\n";
    std::cout << setA;
    std::cout << "\n--SetB:--\n";
    std::cout << setB;

    std::cout << "\n--Overloaded addition operator test--\n";
    std::cout << "--Before: SetA--\n";
    std::cout << setA;

    std::cout << "--SetA += SetB --\n";
    setA += setB;

    std::cout << "--After: SetA--\n";
    std::cout << setA;
    std::cout << "\n---\n";

    std::cout << "\n--Overloaded subtraction operator test--\n";
    std::cout << "--SetA(1,2,3,4,5,6,7) SetB(1,2,3,6,7)--\n";
    std::cout << "--SetA -= SetB --\n";
    setA -= setB;
    std::cout << "--After: SetA--\n";
    std::cout << setA;
    std::cout << "\n----\n";

    Set <int> setInt3;
    setInt3.push(5);
    setInt3.push(6);

    std::cout << "\n--Overloaded multiplication operator test--\n";
    std::cout << "--SetA(4,5) SetB(5,6)--\n";
    std::cout << "--SetA *= SetB --\n";
    setA *= setInt3;

    std::cout << "--After: SetA--\n";
    std::cout << setA;
    std::cout << "\n---\n";

    std::cout << "\n--Overloaded assignment operator test--\n";
    std::cout << "--SetA(5) SetB(1,2,3,6,7)--\n";
    std::cout << "--SetA = SetB --\n";
    setA = setB;
    std::cout << "--After: SetA--\n";
    std::cout << setA;
}