#ifndef NODE_H
#define NODE_H

using namespace std;
template <typename T>
class Node {
public:
    T& data;
    Node* left;
    Node* right;
    string* description;

    Node(T& d, string* ds) :data(d), left(nullptr), right(nullptr), description(ds) {}
    Node(T* d) : data(d), left(nullptr), right(nullptr), description() {}
    void print() { cout << *description << " ";}// TODO: Implement constructor here
};

#endif // NODE_H