#pragma once
#include<iostream>
using std::cout;

using T = double;
template<typename T>
class BinTree {
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T _data) {
            data = _data;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

public:
    BinTree() {
        root = nullptr;
    }

    BinTree(const BinTree& other) {
        root = copy_of(other.root);
    }

    BinTree& operator=(const BinTree& other) {
        if (this != &other) {
            erase(root);
            root = copy_of(other.root);
        }
        return *this;
    }

    ~BinTree() {
        erase(root);
    }

    int get_size() {
        return get_size(root);
    }

    int height() {
        return height(root);
    }

    void print() {
        print(root, 0);
    }

    void add_element(T element, const char* path) {
        add_element(element, path, root);
    }

    void remove_at(const char* path) {
        remove_at(path, root);
    }

private:
    Node* copy_of(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        Node* result = new Node(node->data);
        result->left = copy_of(node->left);
        result->right = copy_of(node->right);
        return  result;
    }

    void erase(Node*& sub_root) {
        if (sub_root != nullptr) {
            erase(sub_root->left);
            erase(sub_root->right);
            delete sub_root;
        }
    }

    int get_size(Node* sub_root) {
        if (sub_root == nullptr) {
            return 0;
        }
        return 1 + get_size(sub_root->left)
                 + get_size(sub_root->right);
    }
    
    int height(Node* sub_root) {
        if (sub_root == nullptr) {
            return 0;
        }
        int left_height = height(sub_root->left);
        int right_height = height(sub_root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }

    void print(Node* sub_root, int spaces) {
        if (sub_root != nullptr) {
            for (int i = 0; i < spaces; i++) {
                cout << ' ';
            }
            cout << sub_root->data << '\n';
            print(sub_root->left, spaces + 3);
            print(sub_root->right, spaces + 3);
        }
    }

    void add_element(T element, const char* path, Node*& sub_root) {
        if (path[0] == '\0') {
            sub_root = new Node(element);
        }
        else if (path[0] == 'L') {
            add_element(element, path + 1, sub_root->left);
        }
        else if (path[0] == 'R') {
            add_element(element, path + 1, sub_root->right);
        }
        else {
            cout << "Error!\n";
        }
    }

    void remove_at(const char* path, Node*& sub_root) {
        if (path[0] == '\0') {
            replace_sub_root(sub_root);
        }
        else if (path[0] == 'L') {
            remove_at(path + 1, sub_root->left);
        }
        else if (path[0] == 'R') {
            remove_at(path + 1, sub_root->right);
        }
        else {
            cout << "Error!\n";
        }
    }

    void replace_sub_root(Node*& sub_root) {
        if (sub_root == nullptr) {
            return;
        }

        if (sub_root->left == nullptr && sub_root->right == nullptr) {
            delete sub_root;
            sub_root = nullptr;
            return;
        }

        int left_height = height(sub_root->left);
        int right_height = height(sub_root->right);
        
        if (left_height > right_height) {
            sub_root->data = sub_root->left->data;
            replace_sub_root(sub_root->left);
        }
        else {
            sub_root->data = sub_root->right->data;
            replace_sub_root(sub_root->right);
        }
    }
};