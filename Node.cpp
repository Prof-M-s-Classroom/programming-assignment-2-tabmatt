//
// Created by Matthew Tabios on 3/16/25.
//
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T& data;
    Node<T>* left;
    Node<T>* right;

    Node(T& d) : data(d), left(nullptr), right(nullptr) {}
};
