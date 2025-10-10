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

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int& i : v) cin >> i;

    ll res = 0;
    for(int j = 0; j < n; j++){
        ll b = 0, a = 0;
        vector<pair<int,int>> vi;
        for(int i = 0; i < n; i++){
            if(i == j) continue;
            vi.emplace_back(v[i], i);
        }
		sort(vi.rbegin(), vi.rend());

        ll soma = 0, mn = LINF, ruim = 0;
        for(int i = 0; i < k; i++){
            soma += vi[i].f;
            mn = min(mn, (ll)vi[i].f);
            if(vi[i].s == j-1 or vi[i].s == j+1) ruim = 1;
        }

        if(ruim) b = v[j] + soma;
        else{
            int agr = 0;
            if(j-1 >= 0) agr = max(agr, v[j-1]);
            if(j+1 < n) agr = max(agr, v[j+1]);
            b = v[j] + (soma - mn + agr);
        }

        vector<pair<int,int>> sobra;
        for(int i = 0; i < n; i++){
            if(i == j or i == j-1 or i == j+1) continue;
            sobra.emplace_back(v[i], i);
        }

        if(k < (int)sobra.size()){
			sort(sobra.rbegin(), sobra.rend());
            a = v[j];
            for(int i = 0; i < k; i++){
                a += sobra[i].f;
            }
        }

        res = max(res, max(a, b));
    }
    cout << res << endl;
}

int main() {
    _;

    int t; cin >> t;
    while(t--) {
		solve();
	}

    return(0);
}
