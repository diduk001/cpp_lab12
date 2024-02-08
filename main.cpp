#include <iostream>
#include "ZipIterator.hpp"
#include <vector>
#include <set>

void equal_vectors_test() {
    std::cout << "Equal vector test:" << std::endl;

    std::vector<int> v1(5);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    v1[3] = 4;
    v1[4] = 5;

    std::vector<int> v2(5);
    v2[0] = 6;
    v2[1] = 7;
    v2[2] = 8;
    v2[3] = 9;
    v2[4] = 10;

    zip_iterator<std::vector<int>::iterator, std::vector<int>::iterator> zip(v1, v2);
    while (!zip.any(std::make_pair(v1.end(), v2.end()))) {
        std::cout << zip->first << ' ' << zip->second << std::endl;
        zip++;
    }
}

void different_vectors_test() {
    std::cout << "Different vectors test:" << std::endl;

    std::vector<int> v1(5);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    v1[3] = 4;
    v1[4] = 5;

    std::vector<int> v2(3);
    v2[0] = 6;
    v2[1] = 7;
    v2[2] = 8;

    zip_iterator<std::vector<int>::iterator, std::vector<int>::iterator> zip(v1, v2);
    while (!zip.any(std::make_pair(v1.end(), v2.end()))) {
        std::cout << zip->first << ' ' << zip->second << std::endl;
        zip++;
    }
}

void set_and_vector_test() {
    std::cout << "Set and vector test:" << std::endl;

    std::vector<int> v1(5);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    v1[3] = 4;
    v1[4] = 5;

    std::set<std::string> s1;
    s1.insert("c");
    s1.insert("b");
    s1.insert("a");
    s1.insert("e");

    zip_iterator<std::vector<int>::iterator, std::set<std::string>::iterator> zip(v1, s1);
    while (!zip.any(std::make_pair(v1.end(), s1.end()))) {
        std::cout << zip->first << ' ' << zip->second << std::endl;
        zip++;
    }
}

void changing_elements_test() {
    std::cout << "Changing elements test:" << std::endl;

    std::vector<int> v1(5);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    v1[3] = 4;
    v1[4] = 5;

    std::vector<int> v2(5);
    v2[0] = 6;
    v2[1] = 7;
    v2[2] = 8;
    v2[3] = 9;
    v2[4] = 10;

    zip_iterator<std::vector<int>::iterator, std::vector<int>::iterator> zip1(v1, v2);
    while (!zip1.any(std::make_pair(v1.end(), v2.end()))) {
        *zip1.iter1 *= 2;
        *zip1.iter2 *= 3;
        zip1++;
    }

    zip_iterator<std::vector<int>::iterator, std::vector<int>::iterator> zip2(v1, v2);
    while (!zip2.any(std::make_pair(v1.end(), v2.end()))) {
        std::cout << zip2->first << ' ' << zip2->second << std::endl;
        zip2++;
    }

}

int main() {
    equal_vectors_test();
    different_vectors_test();
    set_and_vector_test();
    changing_elements_test();

    return 0;
}
