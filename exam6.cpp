#include <iostream>
#include <string>

using namespace std;

// Node structure for BST nodes
struct Node {
    int key;
    string value;
    Node* left;
    Node* right;

    Node(int k, string v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BST {
private:
    Node* root;

    // Helper function to insert a new node into the BST
    Node* insertNode(Node* root, int key, string value) {
        if (root == nullptr) {
            return new Node(key, value);
        }
        if (key < root->key) {
            root->left = insertNode(root->left, key, value);
        } else if (key > root->key) {
            root->right = insertNode(root->right, key, value);
        }
        return root;
    }

    // Helper function to search for a key in the BST
    Node* searchNode(Node* root, int key) {
        if (root == nullptr || root->key == key) {
            return root;
        }
        if (key < root->key) {
            return searchNode(root->left, key);
        }
        return searchNode(root->right, key);
    }

    // Helper function to print the BST in inorder traversal
    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << "(" << root->key << ", " << root->value << ") ";
            inorderTraversal(root->right);
        }
    }

public:
    BST() : root(nullptr) {}

    // Function to insert a key-value pair into the BST
    void insert(int key, string value) {
        root = insertNode(root, key, value);
    }

    // Function to search for a key in the BST
    Node* search(int key) {
        return searchNode(root, key);
    }

    // Function to display the BST
    void display() {
        inorderTraversal(root);
    }
};

// Hashing Table class with chaining using BST
class HashTable {
private:
    static const int TABLE_SIZE = 10;
    BST* table[TABLE_SIZE];

    // Hash function to map keys to table indices
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    // Function to insert a key-value pair into the hashing table
    void insert(int key, string value) {
        int index = hashFunction(key);
        if (table[index] == nullptr) {
            table[index] = new BST();
        }
        table[index]->insert(key, value);
    }

    // Function to search for a key in the hashing table
    Node* search(int key) {
        int index = hashFunction(key);
        if (table[index] != nullptr) {
            return table[index]->search(key);
        }
        return nullptr;
    }

    // Function to display the hashing table
    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "Index " << i << ": ";
            if (table[i] != nullptr) {
                table[i]->display();
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;

    // Insert some key-value pairs into the hash table
    hashTable.insert(5, "Alice");
    hashTable.insert(10, "Bob");
    hashTable.insert(15, "Charlie");
    hashTable.insert(20, "David");
    hashTable.insert(25, "Eve");

    // Display the hash table
    cout << "Hash Table:" << endl;
    hashTable.display();

    // Search for a key in the hash table
    int searchKey = 10;
    Node* result = hashTable.search(searchKey);
    if (result != nullptr) {
        cout << "Key " << searchKey << " found in the hash table. Value: " << result->value << endl;
    } else {
        cout << "Key " << searchKey << " not found in the hash table." << endl;
    }

    return 0;
}a