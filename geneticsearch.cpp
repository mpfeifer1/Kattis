#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int one(string pat, string all) {
    int index = 0;
    int total = 0;
    index = all.find(pat);
    while(index != -1) {
        total++;
        index = all.find(pat, index+1);
    }
    return total;
}

int two(string pat, string all) {
    vector<string> p;

    for(int i = 0; i < pat.size(); i++) {
        string temp = pat;
        temp.erase(i,1);
        p.push_back(temp);
    }

    sort(p.begin(), p.end());
    p.resize(distance(p.begin(), unique(p.begin(), p.end())));

    int total = 0;
    for(auto s : p) {
        total += one(s, all);
    }

    return total;
}

int three(string pat, string all) {
    string dna = "ATCG";

    vector<string> p;

    for(int i = 0; i < pat.size()+1; i++) {
        for(int j = 0; j < 4; j++) {
            string temp = pat;
            temp.insert(i, 1, dna[j]);
            p.push_back(temp);
        }
    }

    sort(p.begin(), p.end());
    p.resize(distance(p.begin(), unique(p.begin(), p.end())));

    int total = 0;
    for(auto s : p) {
        total += one(s, all);
    }

    return total;
}

int main() {
    string pat, all;
    while(cin >> pat && pat != "0" && cin >> all) {
        cout << one(pat, all) << " ";
        cout << two(pat, all) << " ";
        cout << three(pat, all) << endl;
    }
}
