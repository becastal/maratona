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

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		vector<int> a(2), b(2);
		for (int& i : a) cin >> i;
		for (int& i : b) cin >> i;
		
		int res = 0;
		vector<pair<int, int>> perm = {{0, 1}, {1, 0}};
		for (auto i : perm) {
			for (auto j : perm) {
				int ai = 0, bi = 0;
				if (a[i.f] > b[j.f]) ai++;
				if (a[i.f] < b[j.f]) bi++;
				if (a[i.s] > b[j.s]) ai++;
				if (a[i.s] < b[j.s]) bi++;
				if (ai > bi) res++;
			}
		}
		cout << res << endl;
	}
    
    return(0);
}
