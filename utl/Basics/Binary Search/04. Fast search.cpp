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
    vector<int> nums(n);

    for (auto& ai : nums)
        cin >> ai;

    sort(nums.begin(), nums.end());
    int k; cin >> k;
    while (k--)
    {
        int l, r; cin >> l >> r;
        cout << upper_bound(nums.begin(), nums.end(), r) - lower_bound(nums.begin(), nums.end(), l) << " ";
    }
    cout << endl;

    return(0);
}
