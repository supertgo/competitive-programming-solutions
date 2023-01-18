class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        int start = 0;
        int end = length;
        int mid;

        while (start <= end && start < length) {
            mid = (start + end) / 2;
            if (nums[mid] == target) return mid;
            if(nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    }
};
