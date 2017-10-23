#include <iostream>

using namespace std;

int main() {
    long double d;
    cin >> d;

    string a, garbo, b;
    cin >> a >> garbo >> b;

    if(a == "th" || a == "thou")
        goto end1;
    d *= 1000;
    if(a == "in" || a == "inch")
        goto end1;
    d *= 12;
    if(a == "ft" || a == "foot")
        goto end1;
    d *= 3;
    if(a == "yd" || a == "yard")
        goto end1;
    d *= 22;
    if(a == "ch" || a == "chain")
        goto end1;
    d *= 10;
    if(a == "fur" || a == "furlong")
        goto end1;
    d *= 8;
    if(a == "mi" || a == "mile")
        goto end1;
    d *= 3;
    if(a == "lea" || a == "league")
        goto end1;

    end1:

    if(b == "th" || b == "thou")
        goto end2;
    d /= 1000;
    if(b == "in" || b == "inch")
        goto end2;
    d /= 12;
    if(b == "ft" || b == "foot")
        goto end2;
    d /= 3;
    if(b == "yd" || b == "yard")
        goto end2;
    d /= 22;
    if(b == "ch" || b == "chain")
        goto end2;
    d /= 10;
    if(b == "fur" || b == "furlong")
        goto end2;
    d /= 8;
    if(b == "mi" || b == "mile")
        goto end2;
    d /= 3;
    if(b == "lea" || b == "league")
        goto end2;

    end2:

    cout << fixed;
    cout.precision(13);
    cout << d << endl;
}
