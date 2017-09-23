#include <iostream>

using namespace std;

pair<int, int> flip(pair<int, int> p) {
    pair<int, int> temp = {p.second, p.first};
    return temp;
}

bool issquare(pair<int, int> s1, pair<int, int> s2, pair<int, int> s3) {
    if(s1.first == s2.first && s2.first == s3.first) {
        if(s1.second + s2.second + s3.second == s1.first) {
            return true;
        }
        else {
            return false;
        }
    }

    // Diff is 3
    if(s1.first == s2.first && s1.second + s2.second == s3.first && s1.first + s3.second == s3.first) {
        return true;
    }
    // Diff is 2
    if(s1.first == s3.first && s1.second + s3.second == s2.first && s1.first + s2.second == s2.first) {
        return true;
    }
    // Diff is 1
    if(s3.first == s2.first && s3.second + s2.second == s1.first && s2.first + s1.second == s1.first) {
        return true;
    }

    return false;
}

int main() {
    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

    auto s1 = pair<int, int>{a1, a2};
    auto s2 = pair<int, int>{b1, b2};
    auto s3 = pair<int, int>{c1, c2};

    bool works = false;
    works |= issquare(s1, s2, s3);
    works |= issquare(s1, s2, flip(s3));
    works |= issquare(s1, flip(s2), s3);
    works |= issquare(s1, flip(s2), flip(s3));
    works |= issquare(flip(s1), s2, s3);
    works |= issquare(flip(s1), s2, flip(s3));
    works |= issquare(flip(s1), flip(s2), s3);
    works |= issquare(flip(s1), flip(s2), flip(s3));

    if(works) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
