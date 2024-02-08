//
// Created by Stepan on 26.01.2024.
//

#ifndef CPP_LAB12_ZIPITERATOR_H
#define CPP_LAB12_ZIPITERATOR_H

#include <iterator>

// T1, T2 are iterators
template<typename T1, typename T2>
class zip_iterator {
public:
    typedef std::pair<typename T1::value_type, typename T2::value_type> value_type;
    typedef value_type *pointer;
    typedef value_type &reference;

    typedef std::input_iterator_tag iterator_category;

    zip_iterator() : iter1(), iter2() {}

    zip_iterator(T1 iter1, T2 iter2) : iter1(iter1), iter2(iter2) {}

    zip_iterator(const zip_iterator &other) : iter1(other.iter1), iter2(other.iter2) {}

    zip_iterator &operator=(const zip_iterator &other) {
        if (this != &other) {
            iter1 = other.iter1;
            iter2 = other.iter2;
        }
        return *this;
    }

    template<typename V, typename W>
    zip_iterator(V &container1, W &container2) : iter1(container1.begin()), iter2(container2.begin()) {}

    reference operator*() const {
        return std::make_pair(*iter1, *iter2);
    }

    pointer operator->() const {
        return new std::pair<typename T1::value_type, typename T2::value_type>(*iter1, *iter2);
    }


    zip_iterator operator++() {
        iter1++;
        iter2++;
        return *this;
    }

    zip_iterator operator++(int) {
        zip_iterator old(*this);
        iter1++;
        iter2++;
        return old;
    }

    bool operator==(const zip_iterator &other) const {
        return iter1 == other.iter1 && iter2 == other.iter2;
    }

    bool operator!=(const zip_iterator &other) const {
        return iter1 != other.iter1 || iter2 != other.iter2;
    }

    bool operator==(const std::pair<T1, T2> &other) const {
        return iter1 == other.first && iter2 == other.second;
    }

    bool operator!=(const std::pair<T1, T2> &other) const {
        return iter1 != other.first || iter2 != other.second;
    }

    bool any(const std::pair<T1, T2> &other) const {
        return iter1 == other.first || iter2 == other.second;
    }

    T1 iter1;
    T2 iter2;
private:

    template<class Iter>
    friend
    struct std::iterator_traits;
};


#endif //CPP_LAB12_ZIPITERATOR_H
