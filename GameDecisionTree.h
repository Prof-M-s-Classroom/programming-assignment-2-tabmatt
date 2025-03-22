#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

using namespace std;
template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    Node<string>* findOrMakeNode(unordered_map<string, Node<T>*>& nodeMap, string* data) {
        if (nodeMap.contains(data)) {
            return nodeMap[data];
        } else {
            Node<string>* newNode = new Node<string>(data);
            return newNode;
        }
    }

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        ifstream file(filename);

         if (!file) {
           cerr <<  "Failed to open the file.\n";
             return;
        }


        unordered_map<string, Node<string>*> nodeMap;
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string eventNumber, desc, leftEvent, rightEvent;
            getline(ss, eventNumber, delimiter);
            getline(ss, desc, delimiter);
            getline(ss, leftEvent, delimiter);
            getline(ss, rightEvent, delimiter);

            Node<string>* nodeOne = new Node<string> (eventNumber, &desc);





        }






    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        string input;


    }
};

#endif // GAMEDECISIONTREE_H