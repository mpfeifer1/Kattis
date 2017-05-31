#include <iostream>

using namespace std;

int main() {
    int n;
    while(cin >> n && n != 0) {
        int x, y;

        int savH = 0, savW = 0;
        int curH = 0, curW = 0;

        while(cin >> x && cin >> y && x != -1 && y != -1) {
            if(curW + x > n) {
                // Start new row
                savH += curH;
                savW = max(savW, curW);
                curH = 0;
                curW = 0;
            }

            curH = max(curH, y);
            curW += x;
        }

        savH += curH;
        savW = max(savW, curW);
        curH = 0;
        curW = 0;

        cout << savW << " x " << savH << endl;
    }
}
