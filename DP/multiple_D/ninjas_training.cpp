// Naukri.com / Coding Ninjas Ninjas Training
// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one 
// of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity 
// has some merit points on each day. As Ninja has to improve all his skills, he can’t do the 
// same activity in two consecutive days. Can you help Ninja find out the maximum merit points 
// Ninja can earn?
// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.
// If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.


int f(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
    // base condition -> when 0th day, return max which was not 
    // done on the last day

    if (day == 0) {
        int maxi = 0;
        for (int task=0; task<3; task++) {
            if (task!=last) maxi = max(maxi, points[day][task]);
        }
        return maxi;    
    }

    if (dp[day][last] != -1) return dp[day][last];

    int maxi = 0; 
    for (int task=0; task<3; task++) {
        for (int task=0; task<3; task++){
            int pts = 0;
            if (task!=last) pts = points[day][task] + f(day-1, task, points, dp);
            maxi = max(maxi, pts);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    // 3 used to denote no task done last
    // 0 - 0th task, 1 - 1st task, 2 - 2nd task
    return f(n-1, 3, points, dp);
}
