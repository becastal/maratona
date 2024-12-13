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

	int j, r; cin >> j >> r;
	vector<tuple<int, int, int>> p(j);

	int cont = 1;
	for (auto& [pt, ult, idx] : p) idx = cont++;

	for (int i = 0; i < r; i++) {
		for (int l = 0; l < j; l++) {
			int rod; cin >> rod;
			auto& [pt, ult, idx] = p[l];
			pt += rod;
			ult = i * r + l;
		}
	}

	sort(p.begin(), p.end());
	auto& [pt, ult, idx] = p.back();
	cout << idx << endl;
    
    return(0);
}

