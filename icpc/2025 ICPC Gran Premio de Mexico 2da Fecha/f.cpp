#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    ll sumA = 0, sumB = 0;
    ll maxD = 0;
    for(int i = 0; i < N; i++){
        ll a, b;
        cin >> a >> b;
        sumA += a;
        sumB += b;
        maxD = max(maxD, a + b);
    }

    ll total = sumA + sumB;
    ll diff = llabs(sumA - sumB);
    ll needPerIndex = 2 * maxD - total;

    ll answer = max(diff, needPerIndex);
    // if needPerIndex < 0 we ignore it because diff>=0.
    cout << answer << "\n";
    return 0;
}
