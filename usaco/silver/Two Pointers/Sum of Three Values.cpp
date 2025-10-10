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
 
	int n, x; cin >> n >> x;
	vector<int> v(n);
	for (int& vi : v)
		cin >> vi;
 
	map<int, int> m;	
	for (int i = 0; i < n; i++)
		m.insert({x - v[i], i});
 
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (m.count(v[i] + v[j]) and m[v[i] + v[j]] != i and m[v[i] + v[j]] != j)
				return cout << i + 1 << ' ' << j + 1 << ' ' << m[v[i] + v[j]] + 1 << endl, 0;
	
	cout << "IMPOSSIBLE" << endl;
    
    return(0);
}
