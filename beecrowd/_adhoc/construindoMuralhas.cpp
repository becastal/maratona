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

	int n, w; cin >> n >> w;
	vector<string> res;

	for (int i = 0; i < n; i++) {
		string titan, nome;
		int x;
		cin >> titan >> nome >> x;
		if (x > w) res.push_back(titan + " " + nome);
	}
	
	for (auto si : res) {
		cout << si << endl;
	}
    
    return(0);
}
