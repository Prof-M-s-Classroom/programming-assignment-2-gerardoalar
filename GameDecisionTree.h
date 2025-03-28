#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        string line;
        string userline;
        int count = 1;
        int linenum = 0;
        int num;
        int numr;
        int numl;
        string desc;
        string nodenumLeft;
        int numLeft;
        string descLeft;
        string rightLeft;
        int numrLeft;
        string leftLeft;
        int numlLeft;
        string nodenumRight;
        int numRight;
        string descRight;
        string rightRight;
        int numrRight;
        string leftRight;
        int numlRight;

        ifstream file;
        string filename1 = "/Users/nesting/CLionProjects/programming-assignment-2-gerardoalar/story.txt";
        file.open(filename1);
        cout<<"Loading story from file "<<filename<<endl;
        if (!file.is_open()) {
            std::cerr << "Could not open file " << filename<< std::endl;
        }

        while (getline(file, line)) {
            linenum++;
        }
        file.close();
        file.open(filename1);
        while (getline(file, line)) {
            if (root == nullptr) {
                string nodenum = line.substr(0, line.find(delimiter));
                num = stoi(nodenum,0,10);

                line = line.substr(line.find(delimiter) + 1);
                desc = line.substr(0, line.find(delimiter));

                line = line.substr(line.find(delimiter) + 1);
                string left = line.substr(0, line.find(delimiter));
                numl = stoi(left,0,10);

                line = line.substr(line.find(delimiter) + 1);
                string right = line.substr(0, line.find(delimiter));
                numr = stoi(right,0,10);
                Node<T>* newNode = new Node<T>(Story(desc,num,numl,numr));

                root = newNode;
                ifstream file2;
                file2.open(filename1);
                while (getline(file2, line)) {
                    if (count == numl) {
                        nodenumLeft = line.substr(0, line.find(delimiter));
                        numLeft = stoi(nodenumLeft,0,10);

                        line = line.substr(line.find(delimiter) + 1);
                        descLeft = line.substr(0, line.find(delimiter));

                        line = line.substr(line.find(delimiter) + 1);
                        leftLeft = line.substr(0, line.find(delimiter));
                        numlLeft = stoi(leftLeft,0,10);

                        line = line.substr(line.find(delimiter) + 1);
                        rightLeft = line.substr(0, line.find(delimiter));
                        numrLeft = stoi(rightLeft,0,10);

                        Node<T>* newNodeLeft = new Node<T>(Story(descLeft,numLeft,numlLeft,numrLeft));
                        root->left = newNodeLeft;
                        file2.close();
                        count = 1;
                    }
                    count++;
                }
                count = 1;
                file2.open(filename1);
                while (getline(file2, line)) {
                    if (count == numr) {
                        nodenumRight = line.substr(0, line.find(delimiter));
                        numRight = stoi(nodenumRight,0,10);

                        line = line.substr(line.find(delimiter) + 1);
                        descRight = line.substr(0, line.find(delimiter));

                        line = line.substr(line.find(delimiter) + 1);
                        leftRight = line.substr(0, line.find(delimiter));
                        numlRight = stoi(leftRight,0,10);

                        line = line.substr(line.find(delimiter) + 1);
                        rightRight = line.substr(0, line.find(delimiter));
                        numrRight = stoi(rightRight,0,10);

                        Node<T>* newNodeRight = new Node<T>(Story(descRight,numRight,numlRight,numrRight));
                        root->right = newNodeRight;

                        file2.close();
                        count = 1;
                    }
                    count++;
                }
            }
        }
    }
    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        int user;
        Story temp;
        Node<T>* curr = root;
        while (curr->left !=nullptr && curr->right !=nullptr) {
            temp = curr->getData();
            cout<<temp.description<<endl;
            cout<<"what would you like to do? ";
            cout<<temp.leftEventNumber<<" or ";
            cout<<temp.rightEventNumber<<endl;
            cin>>user;
            if (user == temp.leftEventNumber) {
                curr= curr->left;
            }
            else if (user == temp.rightEventNumber) {
                curr = curr->right;
            }
            else {
                cout<<"Wrong input!"<<endl;
            }
            temp = curr->getData();
            cout<<temp.description<<endl;
        }
    }
};

#endif // GAMEDECISIONTREE_H