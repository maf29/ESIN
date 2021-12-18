#include <iostream>
#include <vector>
using namespace std;


void mergesort(vector<double>& v);


int main() {
    int n;
    while (cin >> n) {
        vector<double> v(n);
        for (int i=0; i<n; ++i) {
            cin >> v[i];
        }
        mergesort(v);
        for (int i=0; i<n; ++i) {
            cout << " " << v[i];
        }
        cout << endl;
    }
}
