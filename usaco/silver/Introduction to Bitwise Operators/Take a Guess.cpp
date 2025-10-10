#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	auto query = [&](string s, int a, int b) {
		cout << s << ' ' << a << ' ' << b << endl;
		int res; cin >> res; return res;
	};

	auto soma = [&](int a, int b) {
		int and_ = query("and", ++a, ++b);
		int or_ = query("or", a, b);

		int xor_ = ~and_ & or_;    // a ^ b = ~(a & b) & (a | b);
		return (and_ << 1) + xor_; // a + b = 2 * (a & b) + (a ^ b);
	};

	int n, k; cin >> n >> k;

	int ab = soma(0, 1);
	int ac = soma(0, 2);
	int bc = soma(1, 2);

	vector<int> v = {(ab + ac - bc) / 2};
	v.push_back(ab - v[0]);
	v.push_back(ac - v[0]);

	for (int i = 3; i < n; i++) {
		v.push_back(soma(i-1, i) - v.back());
	}

	sort(v.begin(), v.end());
	cout << "finish " << v[k-1] << endl;

    return(0);
}
