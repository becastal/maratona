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

const int MAX = 2e5 + 10;
const int mod = 998244353;
ll fat[MAX];

void solve() {
	// o primeiro valor eh: |s| - tamanho a maior subsequencia alternada de s.
	// o segundo: ver as substrings 'erradas' (sequencias iguais) e fazer permutacao em cada tamanho,
	//            que representa os jeitos de escolher a ordem das quais tirar.
	string s; cin >> s;
	int n = (int) s.size(), k = n;
	
	int res = 1;
	for (int l = 0; l < n;) {
		int r = l + 1;
		while (r < n and s[l] == s[r]) {
			r++;
		}
		res = (res * 1LL * (r-l)) % mod;
		k--;
		l = r;
	}

	for (int i = 1; i <= k; i++) {
		res = (res * 1LL * i) % mod;
	}

	cout << k << ' ' << res << endl;
}

int main()
{
    _;

	fat[0] = fat[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fat[i] = (fat[i-1] * i) % mod;
    }

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
