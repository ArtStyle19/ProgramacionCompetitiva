#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> P;
int maxProgramas(vector <int> P, int D){
    int count = 0;
    sort(P.begin(), P.end()); //Creciente
    for (auto i : P){
        if (D - i >= 0){
            D = D - i;
            count++;
        } else {
            break;
        }
    }
    return count;
}
int maxMegabytes(vector <int> &P, int D){
    int count = 0;
    sort(P.begin(), P.end(), greater <int> ()); //DeCreciente
    for (auto i : P){
        if (D - i >= 0){
            D = D - i;
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
    int N, D, S; cin >> N; cin >> D;
    while (--N){
        cin >> S;
        P.push_back(S);
    }
    cout << "Numero maximo de programas: " << maxProgramas(P, D) << '\n';
    cout << "Numero maximo de megabytes consumidos: " << maxMegabytes(P, D) << '\n';
    return 0;
}
