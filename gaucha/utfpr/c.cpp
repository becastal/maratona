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

int main() {
    _;

    int n; 
    cin >> n;
    vector<int> v(n);
    for (int& i : v) cin >> i;

    int maior = 0;
    int li = 0, ri = 0;
    set<int> s;
    for (int r = 0, l = 0; r < n; r++) {
        while (s.count(v[r])) {
            s.erase(v[l++]);
        }
        s.insert(v[r]);
        
        if (r - l + 1 > maior) {
            maior = r - l + 1;
            li = l;
            ri = r;
        }
    }

	//dbg(li), dbg(ri);
	reverse(v.begin() + li, v.begin() + ri + 1);
	for (int i = 0; i < n; i++) {
		cout << v[i] << " \n"[i==n-1];
	}

    return 0;
}

