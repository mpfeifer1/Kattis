#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct ingredient {
    string name;
    double weight;
    double percent;
};

int main() {
    int recipes;
    cin >> recipes;
    for(int i = 0; i < recipes; i++) {
        int ingredients, portion, portionDesired;
        cin >> ingredients >> portion >> portionDesired;

        double scale;
        vector<ingredient> ings;
        double relevantWeight;
        scale = double(portionDesired) / double(portion);
        for(int j = 0; j < ingredients; j++) {
            string n;
            double w, p;
            cin >> n >> w >> p;
            if(p == 100.0) {
                relevantWeight = w;
            }
            ingredient ing = {n, w, p};
            ings.push_back(ing);
        }
        cout << "Recipe # " << i + 1 << endl;
        for(int j = 0; j < ingredients; j++) {
            double print = relevantWeight * (ings[j].percent / 100) * scale;
            cout << ings[j].name << " ";
            cout << fixed << setprecision(1) << print << endl;
        }
        cout << "----------------------------------------" << endl;
    }
}

