#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

int partner(int i) {
    if(i % 2 == 0) {
        return i+1;
    }
    return i-1;
}

int nextGuess(vector<int>& v, unordered_set<int>& solved, int i)
{
    while (i < v.size() && solved.count(v[i]) > 0)
    {
        i++;
    }

    return i;
}

int nextGuess2(vector<int>& v, unordered_set<int>& solved, unordered_set<int>& seen, int i)
{
    while (i < v.size() && (solved.count(v[i]) > 0 || seen.count(v[i]) > 0))
    {
        i++;
    }

    return i;
}

int main() {
    int n;
    cin >> n;
    n *= 2;

    vector<int> a;
    vector<int> b;

    int a_score = 0;
    int b_score = 0;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }

    unordered_set<int> seen;
    unordered_set<int> solved;

    int a_loc = 0;
    int b_loc = 0;

    int a_matches = 0;
    int b_matches = 0;

    bool turn = true; // true: a, false: b
    int guesses = 2;

    bool matchinseen = false;
    int  seenmatch = -1;

    while(solved.size() < n) {
        // A's turn
        if(turn) {
            if(seen.size() == 0) {
                int guess1, guess2;
                a_loc = nextGuess(a, solved, a_loc);
                if (a_loc == a.size())
                    continue;
                guess1 = a[a_loc];
                a_loc++;
                a_loc = nextGuess(a, solved, a_loc);
                if (a_loc == a.size())
                    continue;
                guess2 = a[a_loc];
                a_loc++;

                // A made a match
                if(partner(guess1) == guess2) {
                    solved.insert(guess1);
                    solved.insert(guess2);
                    a_matches++;
                }
                // A didn't make a match
                else {
                    seen.insert(guess1);
                    seen.insert(guess2);
                    turn = !turn;
                }
            }
            // seen.size > 0
            else
            {
                int guess1;
                a_loc = nextGuess2(a, solved, seen, a_loc);
                guess1 = a[a_loc];
                a_loc++;

                seen.insert(guess1);
                if (seen.count(partner(guess1)) > 0 )
                {
                    seen.erase(guess1);
                    seen.erase(partner(guess1));
                    solved.insert(guess1);
                    solved.insert(partner(guess1));
                    a_matches++;
                }
                else
                {
                    int guess2;
                    a_loc = nextGuess2(a, solved, seen, a_loc);
                    guess2 = a[a_loc];
                    a_loc++;

                    seen.insert(guess2);
                    if (partner(guess2) == guess1)
                    {
                        solved.insert(guess1);
                        solved.insert(guess2);
                        seen.erase(guess1);
                        seen.erase(guess2);
                        a_matches++;
                    }
                    else
                    {
                        if (seen.count(partner(guess2)) > 0)
                        {
                            solved.insert(guess2);
                            solved.insert(partner(guess2));
                            seen.erase(partner(guess2));
                            seen.erase(guess2);
                            b_matches++;
                        }
                        turn = !turn;
                    }
                }
            }
        }

        // B's turn
        else {
            if(seen.size() == 0)
            {
                int guess1, guess2;
                b_loc = nextGuess(b, solved, b_loc);
                if (b_loc == b.size())
                    continue;
                guess1 = b[b_loc];
                b_loc++;
                b_loc = nextGuess(b, solved, b_loc);
                if (b_loc == b.size())
                    continue;
                guess2 = b[b_loc];
                b_loc++;
                // A made a match
                if(partner(guess1) == guess2) {
                    solved.insert(guess1);
                    solved.insert(guess2);
                    b_matches++;
                }
                // A didn't make a match
                else {
                    seen.insert(guess1);
                    seen.insert(guess2);
                    turn = !turn;
                }
            }
            // seen.size > 0
            else
            {
                int guess1;
                b_loc = nextGuess2(b, solved, seen, b_loc);
                guess1 = b[b_loc];
                b_loc++;

                seen.insert(guess1);
                if (seen.count(partner(guess1)) > 0 )
                {
                    seen.erase(guess1);
                    seen.erase(partner(guess1));
                    solved.insert(guess1);
                    solved.insert(partner(guess1));
                    b_matches++;
                }
                else
                {
                    int guess2;
                    b_loc = nextGuess2(b, solved, seen, b_loc);
                    guess2 = b[b_loc];
                    b_loc++;

                    seen.insert(guess2);
                    if (partner(guess2) == guess1)
                    {
                        solved.insert(guess1);
                        solved.insert(guess2);
                        seen.erase(guess1);
                        seen.erase(guess2);
                        b_matches++;
                    }
                    else
                    {
                        if (seen.count(partner(guess2)) > 0)
                        {
                            solved.insert(guess2);
                            solved.insert(partner(guess2));
                            seen.erase(partner(guess2));
                            seen.erase(guess2);
                            a_matches++;
                        }
                        turn = !turn;
                    }
                }
            }

        }
    }

    if(a_matches == b_matches) {
        cout << "-1" << endl;
    }
    if(a_matches > b_matches) {
        cout << "0" << endl;
    }
    if(a_matches < b_matches) {
        cout << "1" << endl;
    }
}

