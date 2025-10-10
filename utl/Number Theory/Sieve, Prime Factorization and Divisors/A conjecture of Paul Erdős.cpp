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

const int MAX = 10000010;
int primo(int x) {
	if (!x or x == 1) return 0;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}

int main()
{
    _;

	vector<int> ruim;
	for (int i = 0; i * i * i * i <= MAX; i++) {
		int i4 = i * i * i *i;
		for (int j = 0; j * j <= MAX and j * j + i4 <= MAX; j++) {
			int j2 = j * j;
			if (primo(i4+j2)) ruim.push_back(i4+j2);
		}
	}
	sort(ruim.begin(), ruim.end());
	ruim.erase(unique(ruim.begin(), ruim.end()), ruim.end());
	//for (int i : ruim) cout << i << endl;

	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		cout << upper_bound(ruim.begin(), ruim.end(), x) - ruim.begin() << endl;
	}
    
    return(0);
}
