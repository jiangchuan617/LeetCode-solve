#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {

    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    Solution mysolution;
    vector<int> res = mysolution.intersect(nums1, nums2);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}