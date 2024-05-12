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

bool sinal(int x)
{
    return (x > 0 ? true : false);
}

ll solve()
{
    ll n; cin >> n;
    vector<ll> nums(n);

    for (auto& ni : nums)
        cin >> ni;

    ll soma = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        ll agora = nums[i];
        while (j < n && sinal(nums[i]) == sinal(nums[j]))
            agora = max(agora, nums[j]), j++;

        soma += agora;
        i = j - 1;
    } 

    return soma;
}

int main()
{
    _;
    
    int t; cin >> t;
    
    while (t--)
        cout << solve() << endl;

    return(0);
}
