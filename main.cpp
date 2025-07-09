#include <iostream>
#include "Vector.h"
#include "Set.h"

int main() {
    // Testing Vector
    std::cout << "Testing Vector:" << std::endl;
    Vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(15);
    std::cout << "Vector: " << vec << std::endl;

    // Testing Set
    std::cout << "\nTesting Set:" << std::endl;
    Set<int> set1, set2;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set2.insert(2);
    set2.insert(3);
    set2.insert(4);
    std::cout << "Set 1: " << set1 << std::endl;
    std::cout << "Set 2: " << set2 << std::endl;

    Set<int> unionSet = set1 + set2;
    std::cout << "Union: " << unionSet << std::endl;

    Set<int> differenceSet = set1 - set2;
    std::cout << "Difference: " << differenceSet << std::endl;

    Set<int> intersectionSet = set1 * set2;
    std::cout << "Intersection: " << intersectionSet << std::endl;

    Set<int> symmetricDiffSet = set1 ^ set2;
    std::cout << "Symmetric Difference: " << symmetricDiffSet << std::endl;

    return 0;
}
