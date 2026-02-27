#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5+100;

ll memo[MAX][3];

int main() { _
    int n;cin>>n;

    vector<array<int, 3>> v(n);
    vector<array<ll, 3>> dp(n);
    for(auto& [x, y, z] : v)cin>>x>>y>>z;
    
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];
    
    for(int i = 1; i < n; i++){
        auto [x, y, z] = v[i];

        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + x;
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + y;
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + z;
    }

    cout<<max({dp[n-1][0], dp[n-1][1], dp[n-1][2]})<<endl;;
    exit(0);
}
