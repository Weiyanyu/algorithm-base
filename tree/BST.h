//
// Created by 72419 on 2018/3/20 0020.
//

#ifndef CPP_BST_H
#define CPP_BST_H

#include <iostream>

template <typename Key, typename Value>
class BST {
private:
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    int count;
    Node* root;

    //递归的insert
    Node* insert(Node* node, Key key, Value value) {
        if (node == nullptr) {
            count++;
            return new Node(key, value);
        }

        if (key == node->key) {
            node->value = value;
        }
        else if (key < node->key) {
            node->left = insert(node->left, key, value);
        }
        else {
            node->right = insert(node->right, key, value);
        }
        return node;
    }

    Node* loopInsert(Node *node, Key key, Value value) {
        if (node == nullptr) {
            count++;
            return new Node(key, value);
        }
        Node* p = node;
        while (true) {
            if (key < p->key) {
                if (p->left != nullptr)
                    p = p->left;
                else {
                    count++;
                    p->left = new Node(key, value);
                    return node;
                }

            } else if (key > p->key) {
                if (p->right != nullptr)
                    p = p->right;
                else {
                    count++;
                    p->right = new Node(key, value);
                    return node;
                }
            } else {
                p->value = value;
                return node;
            }
        }
    }



    void inorder(Node *node) {
        if (node == nullptr) return;
        inorder(node->left);
        std::cout << node->key << " ";
        inorder(node->right);
    }

    bool contain(Node* node, Key key) {
        if (node == nullptr) {
            return false;
        }
        if (node->key == key) {
            return true;
        } else if (node->key > key) {
            return contain(node->left, key);
        } else {
            return contain(node->right, key);
        }
    }

    Value* search(Node* node, Key key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->key == key) {
            return &(node->value);
        } else if (node->key > key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

public:
    BST() {
        root = nullptr;
        count = 0;
    }
    ~BST() {
        //TODO ~BST()
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }

    void loopInsert(Key key, Value value) {
        root = loopInsert(root, key, value);
    }

    bool contain(Key key) {
        return contain(root, key);
    }

    Value* search(Key key) {
        return search(root, key);
    }

    void inorder() {
        inorder(root);
    }

};

#endif //CPP_BST_H
