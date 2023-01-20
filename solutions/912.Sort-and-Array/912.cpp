class Solution {
public:
    void merge(vector<int>&v, int start, int mid, int end) {
        auto const left_size = mid - start + 1;
        auto const right_size = end - mid;

        auto *left = new int[left_size];
        auto *right = new int[right_size];

        for (int i = 0; i < left_size; i++) {
            left[i] = v[start + i];
        }
        for (int j = 0; j < right_size; j++) {
            right[j] = v[mid + 1 + j];
        }

        auto i = 0;
        auto j = 0;
        auto k = start;

        while (i < left_size && j < right_size) {
            if (left[i] <= right[j]) {
                v[k] = left[i];
                i++;
                k++;
            } else {
                v[k] = right[j];
                j++;
                k++;
            }
        }

        while (i < left_size) {
            v[k] = left[i];
            i++;
            k++;
        }

        while (j < right_size) {
            v[k] = right[j];
            j++;
            k++;
        }

        delete[] left;
        delete[] right;
    }

    void merge_sort(vector<int>&v, int const left, int const right) {
        if (left >= right) return;

        auto mid = left + (right -left) / 2;

        merge_sort(v, left, mid);
        merge_sort(v, mid + 1, right);
        merge(v, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);

        return nums;
    }
};
