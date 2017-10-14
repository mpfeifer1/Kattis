#include <iostream>
#include <vector>

using namespace std;

string digit(int i) {
    switch(i) {
        case 0:
            return "";
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
    }
}

string tens(int i) {
    switch(i) {
        case 0:
            return "";
        case 1:
            return "ten";
        case 2:
            return "twenty";
        case 3:
            return "thirty";
        case 4:
            return "forty";
        case 5:
            return "fifty";
        case 6:
            return "sixty";
        case 7:
            return "seventy";
        case 8:
            return "eighty";
        case 9:
            return "ninety";
    }
}

string str(int i) {
    if(i >= 100) {
        return digit(i/100) + "hundred" + str(i%100);
    }

    if(i == 10) {
        return "ten";
    }
    if(i == 11) {
        return "eleven";
    }
    if(i == 12) {
        return "twelve";
    }
    if(i == 13) {
        return "thirteen";
    }
    if(i == 14) {
        return "fourteen";
    }
    if(i == 15) {
        return "fifteen";
    }
    if(i == 16) {
        return "sixteen";
    }
    if(i == 17) {
        return "seventeen";
    }
    if(i == 18) {
        return "eighteen";
    }
    if(i == 19) {
        return "nineteen";
    }

    string answer = "";
    if(i >= 10) {
        answer += tens(i / 10);
        i %= 10;
    }
    if(i >= 0) {
        answer += digit(i);
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<string> sentence;
    int index = 0;
    int characters = 0;
    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        if(word == "$") {
            index = i;
        }
        else {
            characters += word.length();
        }
        sentence.push_back(word);
    }

    for(int i = 1; i <= 1000; i++) {
        if(str(i).length() + characters == i) {
            sentence[index] = str(i);
            break;
        }
    }

    for(auto i : sentence) {
        cout << i << " ";
    }
    cout << endl;
}
