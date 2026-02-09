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
	vector<int> v(n), res(n);
	for (int& i : v) cin >> i;
	stack<int> s;

	for (int i = n-1; i; i--) {
		while (!s.empty() and v[s.top()] < v[i]) 
			s.pop();
		s.push(i);
		res[i-1] = (int)s.size();
	}

	for (int i : res) cout << i << ' '; cout << endl;
    
    return(0);
}
