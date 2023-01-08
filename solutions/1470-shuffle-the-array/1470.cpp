class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> answer;
        answer.reserve(n * 2);
        for (int i = 0, j = n; i < n && j < n * 2; i++, j++) {
            answer.push_back(nums[i]);
            answer.push_back(nums[j]);
        }

        return answer;
    }
};
