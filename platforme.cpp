#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct platform {
    int height;
    int left;
    int right;
};

bool cmp(platform lhs, platform rhs) {
    return lhs.height < rhs.height;
}

int main() {
    int platforms;
    cin >> platforms;

    vector<int> ground;
    ground.resize(10001, 0);

    vector<platform> v;
    for(int i = 0; i < platforms; i++) {
        platform p;
        cin >> p.height >> p.left >> p.right;
        p.right--;
        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp);

    int total = 0;
    for(auto i : v) {
        total += i.height - ground[i.left];
        total += i.height - ground[i.right];

        for(int j = i.left; j <= i.right; j++) {
            ground[j] = i.height;
        }
    }

    cout << total << endl;
}
