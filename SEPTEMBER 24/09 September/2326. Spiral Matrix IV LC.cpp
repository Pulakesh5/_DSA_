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
auto speedUP = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int startRow = 0, lastRow = m-1;
        int startCol = 0, lastCol = n-1;

        vector<vector<int>> matrixTraversal(m, vector<int>(n, -1));
        
        while(startRow<=lastRow && startCol<=lastCol)
        {
            for(int j=startCol; j<=lastCol && head; j++)
            {
                matrixTraversal[startRow][j] = head->val;
                head = head->next;
            }
            startRow++;
            for(int i=startRow; i<=lastRow && head; i++)
            {
                matrixTraversal[i][lastCol] = head->val;
                head = head->next;
            }
            lastCol--;
            for(int j=lastCol; j>=startCol && head; j--)
            {
                matrixTraversal[lastRow][j] = head->val;
                head = head->next;
            }
            lastRow--;
            for(int i=lastRow; i>=startRow && head; i--)
            {
                matrixTraversal[i][startCol] = head->val;
                head = head->next;
            }
            startCol++;
        }
        return matrixTraversal;
    }
};
