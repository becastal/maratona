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

int main()
{
    _;

	ll n, S; cin >> n;
	S = (1 + n) * n / 2;
	if (S & 1) return cout << "NO" << endl, 0;

	ll s = 0, ok = 0;
	vector<int> cor(n + 1, 0);
	for (int i = 1; i <= n and !ok; i++) {
		s += i;
		cor[i] = 1;

		ll falta = S/2 - s;
		if (falta > i and falta <= n) {
			cor[falta] = 1;	
			ok = 1;
		} else if (falta < 0 and abs(falta) <= i)  {
			cor[abs(falta)] = 0;	
			ok = 1;
		}
	}

	if (!ok) return cout << "NO" << endl, 0;

	cout << "YES" << endl;

	int A = accumulate(cor.begin(), cor.end(), 0);
	cout << A << endl;
	for (int i = 1; i <= n; i++) {
		if (cor[i]) cout << i << ' ';
	}
	cout << endl;

	int B = n - A;
	cout << B << endl;
	for (int i = 1; i <= n; i++) {
		if (!cor[i]) cout << i << ' ';
	}
	cout << endl;
    
    return(0);
}
