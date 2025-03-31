[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Matthew Tabios`  
### **Student ID:** `828230462`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)
> The GAME is all about playing a game. However, if you make the right decisions, you realize it's bigger than a game
> A binary decision tree is implemented through parsing an external text file. The player chooses between option 1 and 2 to traverse through the tree.
> The game ends when a leaf node is reached.
Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `[This file runs the GameDecisionTree function and Story function, creating the tree and playing the game]`  
- **`GameDecisionTree.h`** → `[Contains the Node class and the Story class. Creates the stories and stores them into nodes and creates the decision tree based off the story]`  
- **`Node.h`** → `[Contains functionality for Node implementation, has 3 parameters, data, left child pointer, and right child pointer, ]`  
- **`Story.h`** → `[Story contains the description for each decision event. Has 4 parameters, description (which is the event itself) the event number, the left event number, and the right event number]`  
- **`story.txt`** → `[Contains all data members for the story. Each story is split using the delimeter '|' for each variable in the Story class]`  

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file? 
  - Story objects are created using a delimiter ("|") to split a text line for each data member
  - Each line in the text file is in the format "eventNumber" | "description" | "leftEventNumber" | "rightEventNumber"
  - For eventNumber, leftEventNumber, rightEventNumber, they are converted from string to integer using the stoi function
- How are nodes linked based on left and right event numbers?
  - 
- What happens if an event has `-1` as left or right children?
  - if an event has a -1 as left or right children, that left or right pointer remains as null and isn't assigned to anything
---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)
- The game moves through the decision tree through the use of a recursive algorithm that first starts at the node
- once user input is used, the playGame function is called on the corresponding node (e.x if user input is 1, playGame is called on the leftNode)

- How does user input determine the path taken? 
  - User input of the number 1 or 2 determines what path is traversed
- What happens when the player reaches a leaf node? 
  - once a player reaches a leaf node, "Game over" is displayed and the program is terminated.
- Explain the special case where multiple events lead to the same outcome.
  - when multiple events lead to the same event, the event is only displayed once due to the use of the pointers referencing the stories

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter? 
  - The file is read through the use fstream library, reading each line as a string
  - Lines in the story file are formatted as eventNumber | description | leftEventNumber | rightEventNumber
  - Once lines are read, they are implemented into a story object with the eventNumber, leftEventNumber, 
  - and rightEventNumber converted into integers
  - Once the story objects are created, node construction begins
    - root node is created along with its left and right child
    - if a node is already constructed, it is skipped
    - if a left node or right node isn't constructed, then they are constructed.
- How do you ensure nodes are properly linked?
  - nodes are properly linked through construction, with both the left and right being created when the root is created
- Any challenges faced while handling file input?  
  - challenges I faced while handling file input was the creation of duplicate nodes. This was fixed through changes in 
  - my conditional statement, checking whether the left or right pointer was pointing to null.

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)
- Initially, I was getting a no conversion error on the stoi function. I realized because it was reading an empty line and trying to convert nothing
  - Fix: adding a condition in the while loop (line != empty string)
- Initially wasn't able to read the story.txt file
  - Fix: had to pass in the absolute file path in my computer

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)
- Welcome to The GAME! Press 1 to start the tutorial!
Press 1 for option 1: Great! Pick your weapon!
Press 2 for option 2: Silly Errors Happen! Try Again
User Input: 1
  Great! Pick your weapon!
Press 1 for option 1: Superior Sword
Press 2 for option 2: Barreling Blaster
User Input: 2
  Barreling Blaster
Press 1 for option 1: Use single-fire
Press 2 for option 2: Use burst-fire
User Input: 2
  Use burst-fire
Press 1 for option 1: Great! You are now ready for the game! Good Luck! Press 2 to play!
  2
Game over
---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(N)`  
- **Searching for an event in the tree** → `O(N)`  
- **Game traversal efficiency** → `O(N)`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)
- I tested an event where two different paths lead to the same event
  - Problem: The same event wasn't leading to the right paths afterwards due to the creation of a duplicate node
  - Solution: added a new condition in the creation statement of the nodes indicating if the next was still pointing to null
Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.


---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)
- added no extra features
Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
