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

int solve()
{
    int n; cin >> n;
    vector<int> nums(n);

    for (auto& ni : nums)
        cin >> ni;

    sort(nums.begin(), nums.end());
    bool sinal = true;

    int i = 0, j = n - 1, soma = 0;
    vector<int> alternado;
    
}

int main()
{
    _;
    
    int t; cin >> t;
    
    while (t--)
        cout << solve() << endl;

    return(0);
}