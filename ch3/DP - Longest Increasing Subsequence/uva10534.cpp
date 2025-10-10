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

template<typename T> vector<T> lis(vector<T>& v) {
	int n = v.size(), m = -1;
	vector<T> d(n+1, INF);
	vector<int> l(n);
	d[0] = -INF;

	for (int i = 0; i < n; i++) {
		// Para non-decreasing use upper_bound()
		int t = lower_bound(d.begin(), d.end(), v[i]) - d.begin();
		d[t] = v[i], l[i] = t, m = max(m, t);
	}

	return l;
}

void solve(int n) {
	vector<int> v(n);
	// para cada i ver lis que acaba em i e lds que comeca em i.
	// res eh min(inc[i], dec[i])*2-1

	for (int& i : v) cin >> i;
	auto inc = lis(v);

	reverse(v.begin(), v.end());
	auto dec = lis(v);
	reverse(dec.begin(), dec.end());

	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, min(inc[i], dec[i])*2-1); 
	}

	cout << res << endl;
}

int main()
{
    _;

	int n;
	while (cin >> n) {
		solve(n);
	}
    
    return(0);
}
