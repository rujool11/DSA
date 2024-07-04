// Leetcode 135. Candy

//Brute Force solution ->  T(n) = O(3n), S(n) = O(2n)
// (check from left, check from right, then take max of the two)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int num = ratings.size();
        vector<int> left(num);
        vector<int> right(num);

        left[0] = 1;
        right[num-1] = 1;

        for (int i=1; i<num; i++) {
            if (ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
            else left[i] = 1;
        }

        for (int i=num-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) right[i] = right[i+1] + 1;
            else right[i] = 1;
        }
        
        int res = 0;
        for (int i=0 ; i<num; i++) {
            res += max(left[i], right[i]);
        }

        return res;
    }
};

//Better solution -> T(n) = O(2n), S(n) = O(n) 
class Solution {
public:
    int candy(vector<int>& ratings) {
        int num = ratings.size();
        vector<int> left(num);
        left[0] = 1;

        for (int i=1; i<num; i++) {
            if (ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
            else left[i] = 1;
        }

        int res = left[num-1];
        int curr = 1, right = left[num-1];
        for (int i=num-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) curr = right + 1;
            else curr = 1;
            right = curr;
            res += max(curr, left[i]);
        }
        

        return res;
    }
};

// Optimal solution (slope) -> 

class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1, i = 1;
        
        while (i < ratings.size()) {
            if (ratings[i] == ratings[i-1]) { // flat surface
                sum++;
                i++;
                continue;
            }

            int peak = 1;
            while (i < ratings.size() && ratings[i] > ratings[i-1]) { // inc slope
                peak++;
                sum += peak;
                i++;
            }

            int down = 1;
            while (i < ratings.size() && ratings[i] < ratings[i-1]) { // dec slope
                sum += down;
                i++;
                down++;
            }

            if (down > peak) sum += (down - peak); 
        }

        return sum;
    }
};