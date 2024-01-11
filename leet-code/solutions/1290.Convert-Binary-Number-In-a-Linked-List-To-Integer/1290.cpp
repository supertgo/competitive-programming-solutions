/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> binaryArray = getBinaryArray(head);
        int decimal = 0;
        int size = binaryArray.size();

        for (int i = 0; i < size; i++) {
            int expoent = size - 1 - i;
            decimal += binaryArray[i] * pow(2, expoent);
        }
        
        return decimal;
    }
private:
    vector<int> getBinaryArray(ListNode *head) {
        vector<int> binaryArray;

        for ( ;head != NULL; head = head->next) {
            binaryArray.push_back(head->val);
        }

        return binaryArray;
    }
};
