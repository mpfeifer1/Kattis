#include <unordered_map>
#include <iostream>

using namespace std;

struct node {
    int n;
    node* left = nullptr;
    node* right = nullptr;
};

string traverse(node* root, int level) {
    // Base case
    if(root == nullptr) {
        return "";
    }

    // Build string
    string ans;
    ans += traverse(root->left, level+1);
    ans += char(level);
    ans += traverse(root->right, level+1);
    return ans;
}

void insert(node* root, int n) {
    if(root->n < n) {
        if(root->right == nullptr) {
            node* temp = new node;
            temp->n = n;
            root->right = temp;
        }
        else {
            insert(root->right, n);
        }
    }
    if(root->n > n) {
        if(root->left == nullptr) {
            node* temp = new node;
            temp->n = n;
            root->left = temp;
        }
        else {
            insert(root->left, n);
        }
    }
}

int main() {
    int trees, nodes;
    cin >> trees >> nodes;

    unordered_map<string, int> designs;

    // Create trees
    for(int i = 0; i < trees; i++) {
        node* n = new node;
        n->n = -1;
        for(int j = 0; j < nodes; j++) {
            int temp;
            cin >> temp;
            insert(n, temp);
        }

        string s = traverse(n, 0);
        //cout << s << endl;
        designs[s]++;
    }

    // Count the unique designs
    int total = 0;
    for(auto i : designs) {
        total++;
    }

    // Print the answer
    cout << total << endl;
}
