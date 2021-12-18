#include <iostream>
#include <vector>
using namespace std;

int particio(vector<double> &A, int u, int v) {
	int pu = u + (v-u) /2;	//crear un pivot inicial
	double p = A[pu];
	int i = u, j = v;
	while (i <= j) {
		while (A[i] < p) {
			++i;
		}
		while (A[j] > p) {
			--j;
		}
		if (i <= j){
			double aux = A[i]; // intercanvi
			A[i] = A[j];
			A[j] = aux;
			i++;
			j--;
		}
	}
	
	return i;
}

void quicksort(vector<double> &A, int u, int v) {
	if(u < v) {
		int k = particio(A, u, v);
		quicksort(A, u, k-1);
		quicksort(A, k, v);
	}
}

void mergesort(vector<double> &A) {
	int u = 0, v = A.size()-1;
	quicksort(A, u, v);
}

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
