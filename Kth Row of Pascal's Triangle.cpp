/*
Problem Description

Given an index k, return the kth row of the Pascal's triangle.
Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:

Input : k = 3


Return : [1,3,3,1]

Note: k is 0 based. k = 0, corresponds to the row [1]. 

Note: Could you optimize your algorithm to use only O(k) extra space?


*/


long long nCr(int n, int r){
    int res = 1;
    for(int i=0; i<r; i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}

vector<int> Solution::getRow(int k) {
    vector<int> row(k+1);
    if(k==0){
        row[0]=1;
        return row;
    }
    //every element in the rth row and cth column is (r-1) C (c-1)
    for(int i=0; i<k+1; i++){
        row[i] = (int)nCr(k,i);
    }
    return row;
}
