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

void solve() {
	int n; cin >> n;
	
	// impar de par e impar de impar tiro um de cada.
	// par de ambos eu tiro 2 de qualquer

	vector<int> a(2*n);
	stack<int> imp, par;
	for (int i = 0; i < 2*n; i++) {
		cin >> a[i];
		if (a[i] & 1) {
			imp.emplace(i+1);
		} else {
			par.emplace(i+1);
		}
	}
	
	if ((int)imp.size() & 1 and (int)par.size() & 1) imp.pop(), par.pop();
	else {
		if (par.size() >= 2) par.pop(), par.pop();
		else imp.pop(), imp.pop();
	}

	while (par.size()) {
		int a = par.top(); par.pop();
		int b = par.top(); par.pop();
		cout << a << ' ' << b << endl;
	}

	while (imp.size()) {
		int a = imp.top(); imp.pop();
		int b = imp.top(); imp.pop();
		cout << a << ' ' << b << endl;
	}
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
