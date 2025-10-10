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

	vector<ll> fat(21, 1);
	for (int i = 2; i < 21; i++) {
		fat[i] = fat[i-1] * i;
	}

	int n, m;
	while (cin >> n >> m) {
		cout << fat[n] + fat[m] << endl;
	}
    
    return(0);
}
