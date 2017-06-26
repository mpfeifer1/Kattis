#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int diff;
    cin >> diff;

    string queue;
    cin >> queue;

    // (-) means more guys, (+) means more girls
    int letin = 0, actualdiff = 0;
    while(queue.size() > 0) {
        // If balance too far off
        if(abs(actualdiff) > diff) {
            break;
        }

        // If want female, found female
        if(actualdiff < 0) {
            int nextfemale = queue.find('W');
            if(nextfemale != -1 && nextfemale < 2) {
                queue.erase(queue.begin() + nextfemale);
                letin++;
                actualdiff++;
                continue;
            }
        }

        // If want male, found male
        if(actualdiff > 0) {
            int nextmale = queue.find('M');
            if(nextmale != -1 && nextmale < 2) {
                queue.erase(queue.begin() + nextmale);
                letin++;
                actualdiff--;
                continue;
            }
        }

        if(queue[0] == 'W') {
            actualdiff++;
        }
        else {
            actualdiff--;
        }
        letin++;
        queue.erase(queue.begin());
    }

    if(abs(actualdiff) > diff) {
        letin--;
    }

    cout << letin << endl;
}
