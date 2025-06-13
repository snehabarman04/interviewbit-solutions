/*
Problem Description
 
 

Given a matrix of M * N elements (M rows, N columns), return all elements of the matrix in spiral order.


Problem Constraints
1 <= M, N <= 1000


Input Format
The first argument is a matrix A.


Output Format
Return an array of integers representing all elements of the matrix in spiral order.


Example Input
A = 
    [
        [ 1, 2, 3 ],
        [ 4, 5, 6 ],
        [ 7, 8, 9 ]
    ]


Example Output
[1, 2, 3, 6, 9, 8, 7, 4, 5]
*/


vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> answer;
    int m = A.size();
    int n = A[0].size();
    int top=0; 
    int bottom=m-1;
    int left = 0;
    int right = n-1;
    //we woould need to print the entire row on top first because othersie in case fo a single row
    //the last element would not get printed at all
    while(left<=right && top<=bottom){
        //top iteration
        for(int j=left; j<=right; j++){
            answer.push_back(A[top][j]);
        }
        top++;
        //right iteration
        for(int i=top; i<=bottom; i++){
            answer.push_back(A[i][right]);
        }
        right--;
        //bottom iteration
        //but if we have a say single row then?
        //then we have to recheck the condition that top<=bottom or not
        if(top<=bottom){
            for(int j=right; j>=left; j--){
                answer.push_back(A[bottom][j]);
            }
            bottom--;
        }
        if(left<=right){
            //left iteration
            for(int i=bottom; i>=top; i--){
                answer.push_back(A[i][left]);
            }
            left++;
        }
    }
    //always check for all the edge cases 
    return answer;
}
