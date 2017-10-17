#include <iostream>
#include <vector>

using namespace std;

struct box {
    double x1, y1, x2, y2;
    string size;
};

bool inbox(box b, double x, double y) {
    return (b.x1 <= x && x <= b.x2 && b.y1 <= y && y <= b.y2);
}

int main() {
    int n;

    bool first = true;
    while(cin >> n && n != 0) {
        if(first) {
            first = false;
        }
        else {
            cout << endl;
        }


        vector<box> boxes;
        for(int i = 0; i < n; i++) {
            box b;
            cin >> b.x1 >> b.y1 >> b.x2 >> b.y2 >> b.size;
            boxes.push_back(b);
        }

        int p;
        cin >> p;

        for(int i = 0; i < p; i++) {
            double x, y;
            string size;
            cin >> x >> y >> size;

            cout << size << " ";

            bool printed = false;
            for(auto b : boxes) {
                if(inbox(b, x, y)) {
                    printed = true;
                    if(b.size == size) {
                        cout << "correct" << endl;
                    }
                    else {
                        cout << b.size << endl;
                    }
                }
            }

            if(!printed) {
                cout << "floor" << endl;
            }
        }
    }
}
