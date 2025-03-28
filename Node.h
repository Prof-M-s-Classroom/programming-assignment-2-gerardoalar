#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {
    } // TODO: Implement constructor here
    void setData(T value) { data = value; }
    void setLeft(Node* Node) { left = Node; }
    void setRight(Node* Node) { right = Node; }

    Node* getLeft() { return left; }
    Node* getRight() { return right; }
    T getData() { return data; }
};

#endif // NODE_H