
#include <iostream>
#include <vector>
using namespace std;


void partir(vector<double> &v, vector<double> &v1, vector<double> &v2){
//
	int i = 0,j = 0, m = v2.size();
	while (i < v1.size()){
		v1[i] = v[j];
		
		j++;
		i++;
	}
	i = 0;
	while (i < v2.size()){
		v2[i] = v[j];
		
		j++;
		i++;
	}
	
}

vector<double> fusionar(vector<double> v1, vector<double> v2){
//cost lineal
	int c1 = 0, c2 = 0;
	vector<double> v(v1.size()+v2.size());
	
	for(int i = 0; i < v.size(); i++){
		if(c1 < v1.size() and c2 < v2.size()){
			if(v1[c1] < v2[c2]){
				v[i] = v1[c1];
				c1++;
			}
			else if(v1[c1] > v2[c2]){
				v[i] = v2[c2];
				c2++;
			}
			else{	//v1[c1] == v2[c2]
				v[i] = v1[c1];
				c1++; c2++;
			}
		}
		else if(c1 < v1.size()){
			v[i] = v1[c1];
			c1++;
		}
		else if(c2 < v2.size()){
			v[i] = v2[c2];
			c2++;
		}
	}
	return v;
}

void mergesort(vector<double> &v){
	vector<double> v1(v.size()/2);
	int n = v.size();
	
	if (n > 1) {
		int m = n / 2;
		if(v.size()%2 != 0) m++;	//si el size del vector es impar
		vector<double> v2(m);
		
		// parteix el vector en curs en dues: l'actual i v2
		partir(v,v1, v2);
		
		
		//merge v1 y v2 
		mergesort(v1);
		
		mergesort(v2);
		
		// fusiona vector v1 y v2
		v = fusionar(v1, v2);
	}
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
