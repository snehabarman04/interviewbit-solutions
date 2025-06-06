/*
Problem Description

Given an array A of size N. You need to find the sum of Maximum and Minimum element in the given array.

NOTE: You should make minimum number of comparisons.



Problem Constraints
1 <= N <= 105

-109 <= A[i] <= 109



Input Format
First and only argument is an integer array A of size N.



Output Format
Return an integer denoting the sum Maximum and Minimum element in the given array.



Example Input
Input 1:

 A = [-2, 1, -4, 5, 3]
Input 2:

 A = [1, 3, 4, 1]


Example Output
Output 1:

 1
Output 2:

 5


Example Explanation
Explanation 1:

 Maximum Element is 5 and Minimum element is -4. (5 + (-4)) = 1. 
Explanation 2:

 Maximum Element is 4 and Minimum element is 1. (4 + 1) = 5.
*/


/*
Solution: We can break the array into two sections and search for the smallest and largest numbers within each part. 
By performing this process for both halves of the array, we can identify the smallest number in the entire array by 
comparing the smallest numbers from each half. Similarly, we determine the largest number by comparing the largest numbers 
from both halves. After finding these smallest and largest values, we add them together and return their sum.
  */







pair<int,int> minMax(int l, int r, vector<int> &A){
    int n = r-l+1;
    if(n==1) return {A[l],A[l]};
    
    int mini = INT_MAX;
    int maxi = INT_MIN;
    
    int mid = (r+l)/2;
    
    pair<int,int> left = minMax(l,mid,A);
    pair<int,int> right = minMax(mid+1,r,A);
    
    mini = min(left.first,right.first);
    maxi = max(left.second,right.second);
    return make_pair(mini,maxi);
}

int Solution::solve(vector<int> &A) {
    pair<int,int> result = minMax(0,A.size()-1,A);
    return result.first+result.second;
}
