/*
Problem description
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
  */

//brute force solution but doesn't work with large numbers
//time complexity  ~ O(N)
//space complexity ~ O(N)
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int a = -1;
    int B = -1;
    map<int,int> count;
    for(int i:A){
        count[i]++;
    }
    for(int i=1; i<=A.size(); i++){
        if(count[i]==2) a=i;
        if(count[i]==0) B=i;
    }
    return {a,B};
}

//more optimal solution
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    //using basic math operations and equations
    //we know the sum of n natural numbers = n(n+1)/2 and the sum of these numbers given also we can find
    //so the difference between the two will be x-y where x is the repeating number and y is the missing one
    //also the sum of squares is n(n+1)(2n+1)/6 and taking the difference from the sum of the available numbers is 
    //x^2 - y^2 = (x+y)(x-y)
    //solving them we can find the values of x and y
    
    long long n = A.size();
    long long Sn = n*(n+1)/2;
    long long S = 0;
    for(long long i=0 ; i<n; i++){
        S+=(long long)A[i];
    } 
    long long diff = S-Sn;
    long long S2N = n*(n+1)*(2*n+1)/6;
    long long S2 = 0;
    for(long long i=0; i<n; i++){
        S2+=(long long)A[i]*(long long)A[i];
    }
    long long sum = (S2-S2N)/diff;
    long long x = (sum+diff)/2;
    long long y = (sum-diff)/2;
    return {(int)x,(int)y};
    
}
