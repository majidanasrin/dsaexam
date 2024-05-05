#include <iostream>
#include <string>

using namespace std;

// Node structure representing a file or directory
struct TreeNode {
    string name;
    TreeNode* children[10]; // Assuming a maximum of 10 children

    TreeNode(string name) : name(name) {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }

    ~TreeNode() {
        // Recursively delete child nodes
        for (int i = 0; i < 10; ++i) {
            if (children[i] != nullptr) {
                delete children[i];
            }
        }
    }
};

// Function to traverse the file system tree and print paths for all files
void traverseFileSystem(TreeNode* node, string currentPath) {
    // Base case: If node is NULL, return
    if (node == nullptr) {
        return;
    }

    // Append current node's name to the current path
    currentPath += "/" + node->name;

    // If node is a file, print its path
    if (node->children[0] == nullptr) {
        cout << "File Path: " << currentPath << endl;
    }

    // Recursively traverse child nodes
    for (int i = 0; i < 10; ++i) {
        traverseFileSystem(node->children[i], currentPath);
    }
}

int main() {
    // Create the file system tree
    TreeNode* root = new TreeNode("File System");
    TreeNode* documents = new TreeNode("Documents");
    TreeNode* photos = new TreeNode("Photos");
    TreeNode* programs = new TreeNode("Programs");
    TreeNode* python = new TreeNode("Python");
    TreeNode* music = new TreeNode("Music");
    TreeNode* playlist = new TreeNode("Playlist");

    root->children[0] = documents;
    root->children[1] = programs;
    root->children[2] = music;

    documents->children[0] = new TreeNode("Report.docx");
    documents->children[1] = photos;
    photos->children[0] = new TreeNode("SummerVacation.jpg");

    programs->children[0] = python;
    python->children[0] = new TreeNode("script.py");

    music->children[0] = playlist;
    playlist->children[0] = new TreeNode("Track1.mp3");

    // Traverse the file system tree and print paths for all files
    cout << "Paths for all files in the File System Tree:" << endl;
    traverseFileSystem(root, "");

    // Deallocate memory
    delete root;

    return 0;
}