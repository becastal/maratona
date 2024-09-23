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

	int m; cin >> m;
	int maior = 1, id = 0;
	while (maior * 3 < m) {
		maior *= 3;
		id++;
	}

	vector<int> res;
	while (m) {
		if (maior <= m) {
			m -= maior;	
			res.push_back(id);
		}
		else {
			maior /= 3;
			id--;
		}
	}

	assert((int) res.size() <= 20);
	cout << (int) res.size() << endl;
	for (int i : res) cout << i << ' ';
	cout << endl;
    
    return(0);
}
