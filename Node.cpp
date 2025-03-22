//
// Created by Matthew Tabios on 3/16/25.
//
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T* eventNum;
    Node* left;
    Node* right;
    string* description;

    Node(T& d, string& ds): eventNum(d), left(nullptr), right(nullptr), description(&ds) {}
    Node(T& d) : eventNum(d), left(nullptr), right(nullptr), description(nullptr) {}
    void print() { cout << description << " ";}
};
