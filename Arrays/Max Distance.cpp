/*
  Problem Description
 
 

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].



Problem Constraints
1 <= |A| <= 106
-109 <= Ai <= 109


Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the maximum value of j - i;



Example Input
Input 1:

 A = [3, 5, 4, 2]


Example Output
Output 1:

 2


Example Explanation
Explanation 1:

 Maximum value occurs for pair (3, 4).
*/







int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    //building the prefix leftMin array
    //this will store the minimum till that index
    vector<int> leftMin(n);
    leftMin[0] = A[0];
    for(int i=1; i<n; i++){
        leftMin[i] = min(A[i],leftMin[i-1]);
    }
    
    //building the suffix rightMax array
    //this will store the maximum from the right to this index
    vector<int> rightMax(n);
    rightMax[n-1] = A[n-1];
    for(int i=n-2; i>=0; i--){
        rightMax[i] = max(rightMax[i+1],A[i]);
    }
    
    //the idea is to do the same nested for loop that we could have done in brute force
    //but by optimising it a little such that we readily get to compare the maximum and the minimum
    //by using two pointer on the leftMin and the rightMax arrays
    int i = 0, j = 0, maxDiff = 0;
    while (i < n && j < n) {
        if (leftMin[i] <= rightMax[j]) {
            maxDiff = max(maxDiff, j - i);
            j++;
        } else {
            i++;
        }
    }
    return maxDiff;
}
