/*
Problem Description
 
 

Given an array A of non-negative integers of size N. Find the minimum sub-array Al, Al+1 ,..., Ar such that if we sort(in ascending order) that sub-array, then the whole array should get sorted.
If A is already sorted, output -1.



Problem Constraints
1 <= N <= 1000000

1 <= A[i] <= 1000000



Input Format
First and only argument is an array of non-negative integers of size N.



Output Format
Return an array of length two where the first element denotes the starting index(0-based) and the second element denotes the ending index(0-based) of the sub-array. If the array is already sorted, return an array containing only one element i.e. -1.



Example Input
Input 1:

A = [1, 3, 2, 4, 5]
Input 2:

A = [1, 2, 3, 4, 5]


Example Output
Output 1:

[1, 2]
Output 2:

[-1]


Example Explanation
Explanation 1:

If we sort the sub-array A1, A2, then the whole array A gets sorted.
Explanation 2:

A is already sorted.
  */


vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    int l = -1, r = -1;
    
    // Find the first point where array is unsorted
    for (int i = 0; i < n - 1; i++) {
        if (A[i] > A[i + 1]) {
            l = i;
            break;
        }
    }
    
    if (l == -1) return {-1}; // Already sorted if l hasn't even moved
    
    // Find the last point where array is unsorted
    for (int i = n - 1; i > 0; i--) {
        if (A[i] < A[i - 1]) {
            r = i;
            break;
        }
    }
    
    // Find min and max in subarray A[l..r]
    int subarray_min = INT_MAX, subarray_max = INT_MIN;
    for (int i = l; i <= r; i++) {
        subarray_min = min(subarray_min, A[i]);
        subarray_max = max(subarray_max, A[i]);
    }
    
    //if Al to Ar is sorted then min(Al,...,Ar)>=max(A0,...,Al-1) and max(Al,...,Ar)<=min(Ar+1,...An)
    // so now we expand l to the left untill we get the element that is lesser than the subarray_min
    while (l > 0 && A[l - 1] > subarray_min) l--;
    
    // Expand r to the right
    while (r < n - 1 && A[r + 1] < subarray_max) r++;

    return {l, r};
}
