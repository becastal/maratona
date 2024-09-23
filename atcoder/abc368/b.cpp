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
	priority_queue<int> q;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		q.push(x);
	}

	int cont = 0;
	while (q.size() > 1) {
		int a = q.top(); q.pop();
		int b = q.top(); q.pop();
		a--, b--;
		if (a) q.push(a);
		if (b) q.push(b);
		cont++;
	}
	cout << cont << endl;
    
    return(0);
}
