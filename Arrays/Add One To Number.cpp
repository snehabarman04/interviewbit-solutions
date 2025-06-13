/*
Problem Description
 
 

Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer. For example: 
for this problem, following are some good questions to ask :

Q : Can the input have 0's before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0's before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.


Problem Constraints
1 <= |A| <= 106
0 <= Ai <= 9


Input Format
First argument is an array of digits.



Output Format
Return the array of digits after adding one.



Example Input
Input 1:

[1, 2, 3]


Example Output
Output 1:

[1, 2, 4]


Example Explanation
Explanation 1:

Given vector is [1, 2, 3].
The returned vector should be [1, 2, 4] as 123 + 1 = 124.
  */

vector<int> Solution::plusOne(vector<int> &A) {
    //initial size of the integer array
    int n = A.size();
    int n_copy = n;
    //removing the heading zeroes
    int i=0;
    while(A[i]==0){
        n--;
        i++;
    }
    //but for only 0 it should handle the exception
    if(n==0) n++;
    //now the n is the actual size of the integer
    vector<int> answer;
    int carry = 1;
    for(int j=n_copy-1; j>=n_copy-n; j--){
        int sum = A[j]+ carry;
        answer.push_back(sum % 10);
        carry = sum/10;
    }
    if(carry!=0) answer.push_back(carry);
    reverse(answer.begin(), answer.end());
    return answer;
}
