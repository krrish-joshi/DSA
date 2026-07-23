class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if (st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(i);   // <-- added: was missing, so stack was never filling up
        }

        while(!st.empty()){
            st.pop();     // <-- fixed: clear the stack before reusing it for the right pass
        }

        for(int i=n-1;i>=0;i--){    // <-- fixed: was "i<n;i--" (never runs) — should be i>=0
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if (st.empty()) right[i] = n;
            else right[i] = st.top();

            st.push(i);
        }

        int area, maxArea = 0;

        for(int i=0; i<n; i++){
            area = heights[i] * (right[i] - left[i] - 1);   // <-- fixed: "height" -> "heights", added width calc
            maxArea = max(maxArea, area);                    // <-- added: was missing, so max was never tracked
        }

        return maxArea;   // <-- added: function had no return statement
    }
};