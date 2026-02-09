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
    int N;
    cin >> N;
    string S;
    cin >> S;
    array<int, 3> dp{};
    auto&& [rock, scissors, paper]{dp};
    for(const auto c : S){
        dp = {max(scissors, paper), max(rock, paper), max(rock, scissors)};
        if (c == 'R') {
            scissors = 0;
            ++paper;
        } else if (c == 'S') {
            paper = 0;
            ++rock;
        } else if (c == 'P') {
            rock = 0;
            ++scissors;
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
