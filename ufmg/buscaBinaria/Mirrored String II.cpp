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
	int n = s.size();
	Str S(s);
	auto da = [&](int x){
		bool ok = 0;
		for (int i = 0; i <= n - x and !ok; i++){
			ok |= S.bom(i, i+x-1);
		}
		return ok;
	};

	vector<int> par, impar;
	for (int i = 2; i <= n; i += 2) {
		par.push_back(i);
	}
	for (int i = 1; i <= n; i += 2) {
		impar.push_back(i);
	}

	int li = 0, ri = impar.size();
	while(li < ri){
		int mi = (li+ri)/2;
		if(da(impar[mi])) {
			li = mi+1;
		} else {
			ri = mi;
		}
	}

	int lp = 0, rp = par.size();

	while(lp < rp){
		int mp = (lp+rp)/2;
		if(da(par[mp])) {
			lp = mp+1;
		} else {
			rp = mp;
		}
	}

	int a = (!li ? 0 : impar[li-1]), b = (!lp ? 0 : par[lp-1]);
	cout << max(a, b) << endl;
}

int main(){
	_;
	int t; cin >> t;
	while(t--){
		solve();
	}
	return(0);
}

