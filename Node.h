#ifndef NODE_H
#define NODE_H

using namespace std;
template <typename T>
class Node {
public:
    T& data;
    Node<T>* left;
    Node<T>* right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(T& d) : data(d), left(nullptr), right(nullptr) {}
    void print() {
        cout << left << endl;
        cout << right << endl;
    }
};

#endif // NODE_H