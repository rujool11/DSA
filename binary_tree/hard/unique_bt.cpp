// GFG is unique BT possible?

// Pre -> 1, In->2 , Post-> 3 (these are a & b values)

class Solution
{
public:
    bool isPossible(int a,int b)
    {
        // unique BT can be constructed using the following ->
        
        // In and Pre 
        // In and Post
        // NOT using Pre and Post
        
        return (a+b == 3 || a+b == 5); 
    }
};