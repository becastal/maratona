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

const int mod = 1e9 + 7;
const int N = 1e5 + 7;

int main()
{
    _;

	vector<int> pot(N, 1);
	for (int i = 1; i < N; i++) {
		pot[i] = (pot[i-1] << 1) % mod;
	}

	int t; cin >> t;
	vector<int> a(t), b(t);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;

	for (int i = 0; i < t; i++) {
		if (a[i] == b[i] or !b[i]) cout << 1 << endl;
		else cout << pot[b[i]] << endl;
	}
    
    return(0);
}
