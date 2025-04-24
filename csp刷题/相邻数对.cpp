#include<bits/stdc++.h>
using namespace std;
unordered_map<int, int>cnt;
int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> nums(n, 0);
    for (auto& num : nums) {
        cin >> num;
        cnt[num]++;
        ans += cnt[num - 1] + cnt[num + 1];
    }
    cout << ans;
    return 0;
}