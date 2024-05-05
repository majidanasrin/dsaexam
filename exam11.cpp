#include <iostream>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform depth-first search to find the path from root to a target node
bool findPath(TreeNode* root, int target, int path[], int& pathLen) {
    if (root == nullptr) return false;

    path[pathLen++] = root->val;

    if (root->val == target || findPath(root->left, target, path, pathLen) || findPath(root->right, target, path, pathLen)) {
        return true;
    }

    pathLen--;
    return false;
}

// Function to find the path between two nodes in a binary tree
int* findPathBetweenNodes(TreeNode* root, int node1, int node2) {
    int path1[100], path2[100];
    int pathLen1 = 0, pathLen2 = 0;

    // Find paths from root to each node
    findPath(root, node1, path1, pathLen1);
    findPath(root, node2, path2, pathLen2);

    // Find the common prefix in the two paths
    int i;
    for (i = 0; i < min(pathLen1, pathLen2); ++i) {
        if (path1[i] != path2[i]) {
            break;
        }
    }

    // Construct the path from node1 to LCA
    int* path = new int[pathLen1 + pathLen2 - 2 * i];
    int k = 0;
    for (int j = pathLen1 - 1; j >= i; --j) {
        path[k++] = path1[j];
    }

    // Add the path from LCA to node2
    for (int j = i; j < pathLen2; ++j) {
        path[k++] = path2[j];
    }

    return path;
}

// Function to create a new binary tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode(value);
    return newNode;
}

int main() {
    // Constructing the binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int node1 = 4, node2 = 7;
    cout << "Path between nodes " << node1 << " and " << node2 << ": ";
    int* path = findPathBetweenNodes(root, node1, node2);
    int pathLength = (sizeof(path)/sizeof(*path));
    for (int i = 0; i < pathLength; ++i) {
        cout << path[i] << " ";
    }
    cout << endl;

    delete[] path;

    return 0;
}