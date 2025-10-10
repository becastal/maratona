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
	map<string, int> M {
		{"bonecos", 0},
		{"arquitetos", 0},
		{"musicos", 0},
		{"desenhistas", 0}
	};

	while (n--) {
		string a; cin >> a >> a;
		int x; cin >> x;
		M[a] += x;
	}

	cout << M["bonecos"] / 8 + M["arquitetos"] / 4 + M["musicos"] / 6 + M["desenhistas"] / 12 << endl;

    return(0);
}
