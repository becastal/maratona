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
	vector<int> v(n);
	for (int& vi : v)
		cin >> vi;

	int menor = INF;
	stack<pair<int, int>> s;
	s.push({0, 0});
	for (int i = 0; i < n; i++)
	{
		while (!s.empty() and s.top().f >= v[i])
			s.pop();
		cout << s.top().s << ' ';
		s.push({v[i], i + 1});
	}
	cout << endl;

    return(0);
}

