#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> c;
int maxN(vector <int> &c, int k){
	int count = 0;
	sort(c.begin(), c.end());
	for (auto i : c){
		if (k - i >= 0){
			k= k-i;
			count++;
		} else {
			break;
		}
	}
	return count;
}
int maxP(vector <int> &c, int k){
	int count = 0;
	sort(c.begin(), c.end(), greater <int>());
	for (auto i : c){
		if (k - i >= 0){
			k= k-i;
			count += i;
		} else {
			continue;
		}
	}
	return count;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, p; cin >> k;
    while (cin >> p) {
        c.push_back(p);
    }
    cout << "Numero mxximo de contenedores cargados: " << maxN(c, k) << '\n';
    cout << "Numero mxximo de peso cargado: " << maxP(c, k) << '\n';
    return 0;
}
