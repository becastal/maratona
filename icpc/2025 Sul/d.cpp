#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

map<ll, ll> memo;
int kesimo(ll k) {
	if (!k) return 0;

	ll d = 1, cont = 9, i = 1;
	while (k > d * cont) {
		k -= d * cont;
		d++;
		cont *= 10, i *= 10;
	}

	ll num = i + (k - 1) / d;
	return int(to_string(num)[(k - 1) % d] - '0');
}

const int mod = 1e9+7;
ll pow(ll x, ll y, ll m) { // iterativo
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return ret;
}

vector<vector<int>> F = {{}, {}, {2}, {3}, {2, 2}, {5}, {2, 3}, {7}, {2, 2, 2}, {3, 3}};

struct val {
	ll p[10];	

	val(int x) {
		memset(p, 0, sizeof(p));
		for (ll i : F[x]) p[i]++;
	};

	friend val operator* (val a, val b) {
		for (ll i : {2, 3, 5, 7}) {
			a.p[i] += b.p[i];
		}
		return a;
	};
	friend bool operator< (val a, val b) {
		long double lna = 0.0, lnb = 0.0;
		for (int i : {2, 3, 5, 7}) {
			lna += a.p[i] * logl(i);
			lnb += b.p[i] * logl(i);
		}
		return lna < lnb;
	};


	int valor() {
		ll res = 1;
		if (!p[2] and !p[3] and !p[5] and !p[7]) return 0;
		for (int i : {2, 3, 5, 7}) {
			if (p[i]) res = (res * pow(i, p[i], mod)) % mod;			
		}
		return res;	
	};
};

int solve() {
	ll L, R; cin >> L >> R;

	int n = R - L + 1;
	vector<int> A(n);
	for (ll i = L; i <= R; i++) {
		A[i-L] = kesimo(i);
	}

	val res(0);
	for (int l = 0, r; l < n; l = r) {
		r = l + 1;
		if (!A[l]) continue;
		val a(A[l]);

		r = l + 1;
		while (r < n and A[r]) {
			a = a * val(A[r++]);
		}

		if (res < a) res = a;
	};

	cout << res.valor() << endl;
	//for (int i : {2, 3, 5, 7}) {
	//	cout << i << ": " << res.p[i] << endl;
	//}

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
