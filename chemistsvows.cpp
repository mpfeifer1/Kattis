#include <bits/stdc++.h>

using namespace std;

vector<string> table = {
"H","He",
"Li","Be","B","C","N","O","F","Ne",
"Na","Mg","Al","Si","P","S","Cl","Ar",
"K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
"Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe",
"Cs","Ba","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn",
"Fr","Ra","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Fl","Lv",
"La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu",
"Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"
};

void solve() {
    string s;
    cin >> s;
    s = '*' + s;
    vector<bool> works(s.size(),false);
    works[0] = true;

    for(int i = 1; i <= s.size(); i++) {
        for(auto j : table) {
            if(j.size() > i) continue;

            int ptr1 = i;
            int ptr2 = j.size()-1;

            bool good = true;
            while(ptr2 >= 0) {
                if(j[ptr2] != s[ptr1]) {
                    good = false;
                }
                ptr1--;
                ptr2--;
            }

            if(good && works[i-j.size()]) {
                works[i] = true;
            }
        }
    }

    /*
    for(auto i : s) {
        cout << i << " ";
    }
    cout << endl;
    for(auto i : works) {
        cout << i << " ";
    }
    cout << endl;
    */

    if(works[s.size()-1]) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    for(auto& i : table) {
        for(auto& j : i) {
            j = tolower(j);
        }
    }

    int cases;
    cin >> cases;

    while(cases--) {
        solve();
    }
}
