// Leetcode 42. Trapping rainwater
// This is the monotonic stack solution, do DP solution later when learning DP

class Solution {
public:
    int trap(vector<int>& height) {
        // between any 2 -> left at i, right a j -> min(left, right) - i
        if (height.empty()) return 0;

        stack<int> s;
        int ans = 0;
        int curr = 0;

        while (curr < height.size()) {
            while (!s.empty() && height[curr] > height[s.top()]) {
                int top = s.top();
                s.pop();
                if (s.empty()) break;

                int dist = curr - s.top() -1;
                int boundedHeight = min(height[curr], height[s.top()]) - height[top];
                ans += dist*boundedHeight;
            }

            s.push(curr);
            curr++;
        }

        return ans;

    }
};