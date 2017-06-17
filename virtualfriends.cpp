#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node {
    string name;
    int rank;
    Node* parent;
    Node(string s) : name(s), rank(1), parent(this){}
};

map<string, Node*> people;
void makeSet(string a);
void union2(string a, string b);
Node* findSet(string a);

void makeSet(string a) {
    Node* n = new Node(a);
    people.insert(pair<string, Node*>(a,n));
}

void union2(string a, string b) {
    Node* temp1 = people.find(a)->second;
    Node* temp2 = people.find(b)->second;

    temp1 = findSet(a);
    temp2 = findSet(b);

    if(temp1 == temp2) {
        return;
    }

    if(temp1->rank > temp2->rank) {
        temp2->parent = temp1;
        temp1->rank += temp2->rank;
        return;
    }
    if(temp1->rank < temp2->rank) {
        temp1->parent = temp2;
        temp2->rank += temp1->rank;
        return;
    }
    if(temp1->rank == temp2->rank) {
        temp2->parent = temp1;
        temp1->rank += temp2->rank;
        return;
    }

    return;
}

Node* findSet(string a) {
    Node* temp = people.find(a)->second;
    Node* leaf = temp;
    while(temp->parent != temp) {
        temp = temp->parent;
    }
    leaf->parent = temp;
    return temp;
}


int main()
{
    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++) {
        int inputs;
        cin >> inputs;
        people.clear();

        for(int j = 0; j < inputs; j++) {
            string name1, name2;
            cin >> name1 >> name2;

            if(people.count(name1) == 0) {
                makeSet(name1);
            }
            if(people.count(name2) == 0) {
                makeSet(name2);
            }

            union2(name1, name2);
            cout << findSet(name1)->rank << endl;

        }
    }
    return 0;
}

