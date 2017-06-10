#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int comp, econ;
        cin >> comp >> econ;

        vector<int> comp_iq, econ_iq;

        long double comp_total = 0, econ_total = 0;

        for(int j = 0; j < comp; j++) {
            int temp;
            cin >> temp;
            comp_iq.push_back(temp);

            comp_total += temp;
        }

        for(int j = 0; j < econ; j++) {
            int temp;
            cin >> temp;
            econ_iq.push_back(temp);

            econ_total += temp;
        }

        long double comp_avg_old = comp_total / comp;
        long double econ_avg_old = econ_total / econ;

        int funny = 0;
        for(int j = 0; j < comp; j++) {
            long double comp_avg_new = (comp_total - comp_iq[j]) / (comp - 1);
            long double econ_avg_new = (econ_total + comp_iq[j]) / (econ + 1);

            if(comp_avg_new > comp_avg_old && econ_avg_new > econ_avg_old) {
                funny++;
            }
        }

        cout << funny << endl;
    }
}
