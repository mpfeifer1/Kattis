#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int touched = 0;
    vector<node*> next;
};

int insert(node* root, string s) {
    int c = s.back() - 'a';
    s.pop_back();

    if(root->next[c] == nullptr) {
        root->next[c] = new node;
        root->next[c]->next.resize(26, nullptr);
    }

    int ans = root->next[c]->touched;
    root->next[c]->touched++;

    if(s.size() == 0) {
        return ans;
    }

    return insert(root->next[c], s);
}

int main() {
    int n;
    cin >> n;

    node* tree = new node;
    tree->next.resize(26, nullptr);

    while(n--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());

        cout << insert(tree, s) << endl;
    }
}
