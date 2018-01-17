#include <iostream>
#include <vector>

using namespace std;

int setfind(int a, int* v) {
    if(v[a] < 0) {
        return a;
    }

    v[a] = setfind(v[a], v);
    return v[a];
}

void setunion(int a, int b, int* v) {
    a = setfind(a, v);
    b = setfind(b, v);

    // Same number
    if(a == b) {
        return;
    }

    if(v[a] == v[b]) {
        v[a] += v[b];
        v[b] = a;
        return;
    }

    if(v[a] > v[b]) {
        v[b] += v[a];
        v[a] = b;
        return;
    }

    if(v[a] < v[b]) {
        v[a] += v[b];
        v[b] = a;
        return;
    }
}

void readint(int& ret){
    ret = 0;
    char r;
    bool start=false,neg=false;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(neg) ret *= -1;
}

//void readint(long long& ret){
//    char r;
//    bool start=false,neg=false;
//    while(true){
//        r=getchar();
//        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
//            continue;
//        }
//        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
//            break;
//        }
//        if(start)ret*=10;
//        start=true;
//        if(r=='-')neg=true;
//        else ret+=r-'0';
//    }
//    if(neg) ret *= -1;
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m, n;
    readint(m);
    readint(n);

    int v[m+1];
    for(int i= 0; i <= m; i++) {
        v[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        char c;
        c = getchar();
        int q1, q2;
        readint(q1);
        readint(q2);

        if(c == '?') {
            if(setfind(q1, v) == setfind(q2, v)) {
                cout << "yes" << endl;
            }
            else {
                cout << "no" << endl;
            }
        }
        else {
            setunion(q1, q2, v);
        }
    }
}
