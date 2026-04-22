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

const ll P = 69420;
const ll M = 1e9+9;
set<char> mirr = {'A','H','I','M','O','T','U','V','W','X','Y'};

struct Str {
	int n;
	vector<ll> base, hashL, hashR, pre;
	Str(string s) : n((int)s.size()), base(n), hashL(n+1), hashR(n+1), pre(n+1,0) {
		base[0] = 1;
		for (int i = 1; i < n; i++) {
			base[i] = (base[i-1]*P)%M;
		}
		for (int i = 0; i < n; i++) {
			pre[i+1] = pre[i] + !mirr.count(s[i]);
		}
		hashL[0] = 0;
		for (int i = 0; i < n; i++) {
			hashL[i+1] = (hashL[i]*P + s[i]) % M;
		}
		hashR[n] = 0;
		for (int i = n-1; i >= 0; i--) {
			hashR[i] = (hashR[i+1]*P + s[i]) % M;
		}
	}
	ll queryL(int l, int r) {
		ll h = (hashL[r+1] - (hashL[l]*base[r-l+1])%M + M)%M;
		return h;
	}
	ll queryR(int l, int r) {
		ll h = (hashR[l] - (hashR[r+1]*base[r-l+1])%M + M)%M;
		return h;
	}
	bool bom(int l, int r) {
		return pre[r+1]-pre[l]==0 and queryL(l,r)==queryR(l,r);
	}
};

void solve(){
	string s; cin >> s;
	Str S(s);

	cout << (S.bom(0, (int)s.size()-1) ? "yes" : "no") << endl;
}

int main(){
	_;
	int t; cin >> t;
	while(t--){
		solve();
	}
	return(0);
}

