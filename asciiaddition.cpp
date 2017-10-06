#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool isplus(vector<string>& input, ll i) {
    vector<string> plus = {".....",
                           "..x..",
                           "..x..",
                           "xxxxx",
                           "..x..",
                           "..x..",
                           "....."};

    bool same = true;
    for(ll j = 0; j < 5; j++) {
        for(ll k = 0; k < 7; k++) {
            same &= (input[k][i+j] == plus[k][j]);
        }
    }

    return same;
}

vector<string> getnum(vector<string>& input, ll i) {
    vector<string> temp = {".....",
                           ".....",
                           ".....",
                           ".....",
                           ".....",
                           ".....",
                           "....."};

    for(ll j = 0; j < 5; j++) {
        for(ll k = 0; k < 7; k++) {
            temp[k][j] = input[k][i+j];
        }
    }

    return temp;
}

int main() {
    vector<vector<string>> numbers;
    numbers.push_back({"xxxxx",
                       "x...x",
                       "x...x",
                       "x...x",
                       "x...x",
                       "x...x",
                       "xxxxx"});

    numbers.push_back({"....x",
                       "....x",
                       "....x",
                       "....x",
                       "....x",
                       "....x",
                       "....x"});

    numbers.push_back({"xxxxx",
                       "....x",
                       "....x",
                       "xxxxx",
                       "x....",
                       "x....",
                       "xxxxx"});

    numbers.push_back({"xxxxx",
                       "....x",
                       "....x",
                       "xxxxx",
                       "....x",
                       "....x",
                       "xxxxx"});

    numbers.push_back({"x...x",
                       "x...x",
                       "x...x",
                       "xxxxx",
                       "....x",
                       "....x",
                       "....x"});

    numbers.push_back({"xxxxx",
                       "x....",
                       "x....",
                       "xxxxx",
                       "....x",
                       "....x",
                       "xxxxx"});

    numbers.push_back({"xxxxx",
                       "x....",
                       "x....",
                       "xxxxx",
                       "x...x",
                       "x...x",
                       "xxxxx"});

    numbers.push_back({"xxxxx",
                       "....x",
                       "....x",
                       "....x",
                       "....x",
                       "....x",
                       "....x"});

    numbers.push_back({"xxxxx",
                       "x...x",
                       "x...x",
                       "xxxxx",
                       "x...x",
                       "x...x",
                       "xxxxx"});

    numbers.push_back({"xxxxx",
                       "x...x",
                       "x...x",
                       "xxxxx",
                       "....x",
                       "....x",
                       "xxxxx"});

    vector<string> input;
    input.resize(7);
    for(auto& i : input) {
        getline(cin, i);
    }

    string num1, num2;

    for(ll i = 0; i < input[0].size(); i+=6) {
        if(isplus(input, i)) {
            swap(num1, num2);
        }
        else {
            vector<string> temp = getnum(input, i);
            char number = '0';
            for(ll j = 0; j < numbers.size(); j++) {
                if(numbers[j] == temp) {
                    number += j;
                }
            }
            num1.push_back(number);
        }
    }

    ll n = 0;
    n = stoi(num1) + stoi(num2);

    vector<string> output;
    output.resize(7);

    string s = to_string(n);
    for(int i = 0; i < s.size(); i++) {
        vector<string> append = numbers[s[i]-'0'];
        for(int j = 0; j < 7; j++) {
            output[j] += append[j] + '.';
        }
    }

    for(auto i : output) {
        i.pop_back();
        cout << i << endl;
    }
}
