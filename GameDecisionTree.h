#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"
#include <typeinfo>

using namespace std;
template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}



    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "failed to open file" << endl;
            return;
        }
        unordered_map<int, Story*> map;
        unordered_map<int, Node<T>*> nodeMap;
        string line;
        while (getline(file, line) && line != "") {
            stringstream ss(line);
            string event, desc, leftEvent, rightEvent;
            int eventID, leftEventID, rightEventID;

            getline(ss, event, delimiter);
            getline(ss, desc, delimiter);
            getline(ss, leftEvent, delimiter);
            getline(ss, rightEvent, delimiter);


            eventID = stoi(event);
            leftEventID = stoi(leftEvent);
            if (rightEvent != "") {
                rightEventID = stoi(rightEvent);
            }

            Story* currentStory = new Story();
            currentStory -> description = desc;
            currentStory -> eventNumber = eventID;
            currentStory -> leftEventNumber = leftEventID;
            currentStory -> rightEventNumber = rightEventID;


            map[eventID] = currentStory;

        }
        file.close();

        for (int i = 1; i < map.size(); i++) {
            Node<Story>* leftNode = nullptr;
            Node<Story>* rightNode = nullptr;
            if (nodeMap.find(i) == nodeMap.end()) {
                nodeMap[i] = new Node<Story>(*map[i]);
                if (!root) {
                    root = nodeMap[i];
                }
            }

            if (nodeMap.find(map[i] -> leftEventNumber) == nodeMap.end() && nodeMap[i] -> left == nullptr) {
                if ((map[i] -> leftEventNumber)!= -1) {
                    leftNode = new Node<Story>(*map[map[i] -> leftEventNumber]);
                    nodeMap[map[i] -> leftEventNumber] = leftNode;
                }
            } else {
                leftNode = nodeMap[map[i] -> leftEventNumber];

            }
            nodeMap[i] -> left = leftNode;

            if (nodeMap.find(map[i] -> rightEventNumber) == nodeMap.end() && nodeMap[i] -> right == nullptr) {
                if (map[i] -> rightEventNumber != -1) {
                    rightNode = new Node<Story>(*map[map[i] -> rightEventNumber]);
                    nodeMap[map[i] -> rightEventNumber] = rightNode;
                }
            }

            nodeMap[i] -> right = rightNode;



        }
    }






    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        playGame(root);
    }

    void playGame(Node<Story>* node) {
        int choice;
        cout << node -> data.description << endl;
        if (node -> left != nullptr) {
            cout << "Press 1 for option 1: " << node->left->data.description << endl;
        }

        if (node -> right != nullptr) {
            cout << "Press 2 for option 2: " << node -> right->data.description << endl;
        }

        if (node -> right == nullptr && node -> left == nullptr) {
            cout << "Game over" << endl;
            return;
        }

        cin >> choice;

        while (choice != 1 && choice != 2) {
            cerr << "Invalid Choice" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }


        if (choice == 1) {
            if (node -> left == nullptr) {
                cout << "Game Over" << endl;
            } else {
                playGame(node -> left);
            }
        }

        if (choice == 2) {
            if (node -> right == nullptr) {
                cout << "Game Over" << endl;
            } else {
                playGame(node -> right);
            }

        }
    }



};

#endif // GAMEDECISIONTREE_H