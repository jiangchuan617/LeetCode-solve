#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
//        首先排序
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
//        双指针法
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> intersection;
        int idx1 = 0;
        int idx2 = 0;
        while (idx1 < len1 && idx2 < len2) {
            if (nums1[idx1] < nums2[idx2]) {
                idx1++;
            } else if (nums1[idx1] > nums2[idx2]) {
                idx2++;
            } else {
                intersection.push_back(nums1[idx1]);
                idx1++;
                idx2++;
            }
        }
        return intersection;

    }

    vector<int> intersect_disorder(vector<int> &nums1, vector<int> &nums2) {
        map<int, int> map1;
//        遍历向量映射
        for (const auto &num : nums1) {
            ++map1[num];
        }
        vector<int> intersection;
        for (const auto &num : nums2) {
            if (map1.count(num)) {
                intersection.push_back(num);
                --map1[num];
                if (map1[num] == 0) {
                    map1.erase(num);
                }
            }

        }
        return intersection;
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
};