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
 
const int MAX = 1e6+10;
int divi[MAX];
 
void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;
 
	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}
 
void fact(vector<int>& v, int n) {
	if (n != divi[n]) fact(v, n/divi[n]);
	v.push_back(divi[n]);
}
 
vector<int> fact_(int n) {
	vector<int> res;
	fact(res, n);
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	return res;
}
 
int main()
{
    _;
 
	crivo(MAX-1);
	int n; cin >> n;
	vector<int> cont(MAX+1, 0);
 
	ll res = 0;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
 
		if (x == 1) {
			res += i;
			continue;
		}
 
		auto f = fact_(x);
		int m = f.size(), ncop = 0;
		for (int mask = 1; mask < (1 << m); mask++) {
			int agr = 1;
			for (int j = 0; j < m; j++) {
				if (mask & (1 << j)) agr *= f[j];
			}
			ncop += (__builtin_popcount(mask) & 1 ? +1 : -1) * cont[agr];
			cont[agr]++;
		}
 
		res += i - ncop;
	}
	cout << res << endl;
    
    return(0);
}
