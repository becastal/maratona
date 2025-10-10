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

ll gray(string s) {
	int n = s.size();
	
	ll res = 0;
	int b = s[0] - '0';
	res = b;

	for (int i = 1; i < n; i++) {
		int agr = s[i] - '0';
		b = b ^ agr;
		res = (res << 1LL) | b;
	}

	return res;
}

int main()
{
    _;

	int n; cin >> n;
	string a, b; cin >> a >> b;

	cout << gray(b) - gray(a) - 1 << endl;
    
    return(0);
}
