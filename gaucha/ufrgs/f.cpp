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

	int n; cin >> n;
	string s; cin >> s;
	stack<int> a, b, c;

	for (char ci : s) {
		if (ci == '(') {
			a.push(1);
			continue;
		}
		if (ci == ')') {
			if (a.empty()) {
				return cout << "NO" << endl, 0;
			}
			a.pop();
			continue;
		}

		if (ci == '[') {
			b.push(1);
			continue;
		}
		if (ci == ']') {
			if (b.empty()) {
				return cout << "NO" << endl, 0;
			}
			b.pop();
			continue;
		}

		if (ci == '{') {
			c.push(1);
			continue;
		}
		if (ci == '}') {
			if (c.empty()) {
				return cout << "NO" << endl, 0;
			}
			c.pop();
			continue;
		}
	}

	if (!a.empty() or !b.empty() or !c.empty())
		return cout << "NO" << endl, 0;
	cout << "YES" << endl;
    
    return(0);
}
