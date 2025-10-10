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
typedef pair<int, int> ii;

const int MAX = 1e5 + 10;

namespace seg {
	ii seg[4*MAX]; // {#s que dividem todos, num que divide todos};
	vector<int> v;
	int n;

	ii combina(ii a, ii b) {
		if (a.s == -1) a.s = b.s;
		if (b.s == -1) b.s = a.s;
		int tmp = __gcd(a.s, b.s);
		int fi = (tmp == a.s ? a.f : 0) + (tmp == b.s ? b.f : 0);
		//cout<<"a: "<<a.f<<' '<<a.s<<" $ "<<"b: "<<b.f<<' '<<b.s<<" = "<<fi<<' '<<tmp<<endl;
		return {fi, tmp};
	}
	ii build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = {1, v[l]};
		int m = (l+r)/2;
		return seg[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	ii query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return {0, -1};
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return combina(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
};

int main()
{
    _;

	int n; cin >> n; seg::n = n;
	seg::v.resize(n);
	for (int& i : seg::v)
		cin >> i;

	seg::build();

	int t; cin >> t;
	while (t--) {
		int l, r; cin >> l >> r; l--, r--;
		ii qry = seg::query(l, r);
		cout << r - l + 1 - qry.f << endl;
	}
	cout << endl;
    
    return(0);
}
