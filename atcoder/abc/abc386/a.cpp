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

	map<int, int> M;

	for (int i = 0, x; i < 4; i++) {
		cin >> x; M[x]++;
	}

	vector<int> cont(4, 0);

	for (auto [a, b] : M) {
		cont[b]++;
	}

	cout << (cont[2] == 2 or cont[3] == 1 ? "Yes" : "No") << endl;
    
    return(0);
}
