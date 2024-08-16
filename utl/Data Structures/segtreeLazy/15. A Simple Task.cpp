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

const int MAX = 1e5 + 10;

int cont[26];

int main()
{
    _;

	int n, q; cin >> n >> q;
	string s; cin >> s;

	seg::build();
	while (q--) {
		int l, r, k; cin >> l << r << k; l--, r--;
		for (int i = 0; i < n; i++) {
			cont[i] seg::query	
		}
	}
    
    return(0);
}
