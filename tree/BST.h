//
// Created by 72419 on 2018/3/20 0020.
//

#ifndef CPP_BST_H
#define CPP_BST_H

#include <iostream>
#include <queue>

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

        Node(Node *node) {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
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


    void preOrder(Node* node) {
        if (node == nullptr) return;
        std::cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        std::cout << node->key << " ";
        inOrder(node->right);
    }

    void postOrder(Node* node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->key << " ";
    }

    void levelOrder(Node* root) {
        std::queue<Node* > q;
        if (root == nullptr) return;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            std::cout << node->key << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
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

    Node* minimum(Node* node) {
        if (node->left == nullptr)
            return node;
        return minimum(node->left);
    }

    Node* maxmum(Node* node) {
        if (node->right == nullptr)
            return node;
        return maxmum(node->right);
    }

    Node* removeMin(Node* node) {
        if (node->left == nullptr) {
            Node* rightNode = node->right;
            delete node;
            count--;
            return rightNode;
        }

        node->left = removeMin(node->left);
        return node;
    }

    Node* removeMax(Node* node) {
        if (node->right == nullptr) {
            Node* leftNode = node->left;
            delete node;
            count--;
            return leftNode;
        }

        node->right = removeMax(node->right);
        return node;
    }

    Node* remove(Node* node, Key key) {
        if (node == nullptr)
            return nullptr;
        if (key < node->key) {
            node->left = remove(node->left, key);
            return node;
        }
        else if (key > node->key) {
            node->right = remove(node->right, key);
            return node;
        }
        else {
            if (node->left == nullptr) {
                Node* rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            if (node->right == nullptr) {
                Node* leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }
            //leftNode 和 rightNode 都不为空，需要找到右子树的最小值作为替代
            Node* successor = new Node(minimum(node->right));
            count++;
            successor->right = removeMin(node->right);
            successor->left = node->left;
            delete node;
            count--;
            return successor;
        }
    }

public:
    BST() {
        root = nullptr;
        count = 0;
    }
    ~BST() {
        destory(root);
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

    //前序遍历
    void preOrder() {
        preOrder(root);
    }
    //中序遍历
    void inOrder() {
        inOrder(root);
    }
    //后序遍历
    void postOrder() {
        postOrder(root);
    }

    void levelOrder() {
        levelOrder(root);
    }

    void destory(Node* node) {
        if (node == nullptr) return;
        destory(node->left);
        destory(node->right);
        count--;
        delete node;
    }

    Key minimum() {
        Node* min = minimum(root);
        return min->key;
    }

    Key maxmum() {
        Node* max = maxmum(root);
        return max->key;
    }

    void removeMin() {
        if (root) {
            root = removeMin(root);
        }
    }

    void removeMax() {
        if (root) {
            root = removeMax(root);
        }
    }

    void remove(Key key) {
        root = remove(root, key);
    }

};

#endif //CPP_BST_H
