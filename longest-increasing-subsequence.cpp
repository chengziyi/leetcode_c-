#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(vector<int>& v) {
    for (vector<int>::iterator j = v.begin(); j != v.end(); ++j) {
        cout << *j << " ";
    }
    cout << endl;
}

template <class T>
void print_vector(const vector <T> & v)
{
    typename vector <T>::const_iterator i;
    for (i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        if (0 == n) {
            return 0;
        }
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    int result = 0;
    int a[8] = { 10, 9, 2, 5, 3, 7, 101, 18 };
    vector<int> v_input(a, a+8);

    Solution sol;
    //print_vector(v_input);
    result = sol.lengthOfLIS(v_input);
    cout << result << endl;
    return 0;
}
