#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void solve(int T) {
    int n; cin >> n; n--;
    vector<int> v(n);
    for (int& i : v) cin >> i;

    ll res = 0, agr = 0;
    int l = 0, temp_l = 0, r = 0;

    for (int i = 0; i < n; ++i) {
        agr += v[i];
        if (agr >= res) {
            res = agr;
            l = temp_l;
            r = i;
        }
        if (agr < 0) {
            agr = 0;
            temp_l = i + 1;
        }
    }

    if (res <= 0) {
        cout << "Route " << T << " has no nice parts" << endl;
    } else {
        cout << "The nicest part of route " << T << " is between stops " << l + 1 << " and " << r + 2 << endl;
    }
}

int main()
{
    _;

	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
    
    return(0);
}
