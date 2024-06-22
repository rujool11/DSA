// InterviewBit next smaller element 
// look for elemnts in the left side according to question
// so we traverse left to right,
// pop elements if they are greater than current instead of lesser like nge

vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    vector<int> ans(A.size());

    for (int i=0; i<A.size(); i++) {
        while (!s.empty() && s.top()>=A[i]) s.pop();
        ans[i] = (s.empty()) ? -1 : s.top();
        s.push(A[i]); 
    }
    
    return ans;
}
