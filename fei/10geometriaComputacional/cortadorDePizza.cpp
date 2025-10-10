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

// BIT
//
// BIT de soma 0-based
// 
// upper_bound(x) retorna o menor p tal que pref(p) > x 
//
// Complexidades:
// build - O(n)
// update - O(log(n))
// query - O(log(n))
// upper_bound - O(log(n))

struct Bit {
    int n;
    vector<ll> bit;
    Bit(int _n=0) : n(_n), bit(n + 1) {}
    Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
        for (int i = 1; i <= n; i++) {
            bit[i] += v[i - 1];
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }
    void update(int i, ll x) { // soma x na posicao i
        for (i++; i <= n; i += i & -i) bit[i] += x;
    }
    ll pref(int i) { // soma [0, i]
        ll ret = 0;
        for (i++; i; i -= i & -i) ret += bit[i];
        return ret;
    }
    ll query(int l, int r) {  // soma [l, r]
        return pref(r) - (l ? pref(l - 1) : 0);
    }
    int upper_bound(ll x) {
        int p = 0;
        for (int i = __lg(n); i+1; i--)
            if (p + (1 << i) <= n and bit[p + (1 << i)] <= x)
                x -= bit[p += (1 << i)];
        return p;
    }
};


ll inversoes(vector<int>& v) {
	vector<int> comp = v;	
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	int n = v.size(), m = comp.size();

	Bit bit(m);	

	ll res = 0;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(comp.begin(), comp.end(), v[i]) - comp.begin();
		res += i - bit.pref(idx);
		bit.update(idx, 1);
	}
	return res;
}

int main()
{
    _;
    ll X, Y; cin >> X >> Y;
    ll H, V; cin >> H >> V;
    
	vector<pair<int, int>> hs(H);
	for (auto& [y1, y2] : hs) {
		cin >> y1 >> y2;
	}
	sort(hs.begin(), hs.end());

	vector<int> hsi;
	for (auto [y1, y2] : hs) {
		hsi.push_back(y2);
	}

	vector<pair<int, int>> vs(V);
	for (auto& [x1, x2] : vs) {
		cin >> x1 >> x2;
	}
	sort(vs.begin(), vs.end());

	vector<int> vsi;
	for (auto [x1, x2] : vs) {
		vsi.push_back(x2);
	}

    cout << (H+1) * (V+1) + inversoes(vsi) + inversoes(hsi) << endl;
    
    return(0);
}
