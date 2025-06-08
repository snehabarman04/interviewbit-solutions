/*
Problem Description
 
 

Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.



Problem Constraints
1 <= N, M <= 1000
0 <= A[i][j] <= 1


Input Format
The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.


Output Format
Return a 2-d matrix that satisfies the given conditions.


Example Input
Input 1:
[   [1, 0, 1],
    [1, 1, 1], 
    [1, 1, 1]   ]
Input 2:
[   [1, 0, 1],
    [1, 1, 1],
    [1, 0, 1]   ]


Example Output
Output 1:
[   [0, 0, 0],
    [1, 0, 1],
    [1, 0, 1]   ]
Output 2:
[   [0, 0, 0],
    [1, 0, 1],
    [0, 0, 0]   ]
*/






//first solution
void markColumn(vector<vector<int> > &A, int column){
    for(int i=0; i<A.size(); i++){
        if(A[i][column]!=0) A[i][column]=-1;
    }
}
void markRow(vector<vector<int> > &A, int row){
    for(int i=0; i<A[0].size(); i++){
        if(A[row][i]!=0) A[row][i]=-1;
    }
}
void Solution::setZeroes(vector<vector<int> > &A) {
    //first approach - brute force
    //iterate through the entire array and mark all the 1's we need to change to 0 as -1
    //then iterate through the array again and then change those -1's as 0
    //time complexity ~ O(n^3)
    int rows = A.size();
    int cols = A[0].size();
    
    //marking the -1's
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(A[i][j]==0){
                markColumn(A,j);
                markRow(A,i);
            }
        }
    }
    //reiterating through the grid to replace the -1's with the 0's
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(A[i][j]==-1){
                A[i][j]=0;
            }
        }
    }    
}


//second approach
void Solution::setZeroes(vector<vector<int> > &A) {
    //we keep a track of the columns and the rows which need to be changed
    //if they need to be changed either due to the 0 in the row or the column then mark the respective cell as 0
    //It first scans the matrix to identify which rows and columns contain a zero
    //storing this information in two helper vectors: rowToBeMarked and columnToBeMarked 
    //In the second pass, it iterates through the matrix again 
    //and sets A[i][j] to zero if either the i-th row or j-th column was marked
    //This ensures that all elements in rows or columns with at least one zero are converted to zero
    //without modifying the matrix during the initial scan, preventing unintended side effects.
    
    //time complexity ~ O(2*n*m)
    //space complexity = O(n)+O(m)
    
    //creating two vectors
    vector<int> columnToBeMarked (A[0].size(),0);
    vector<int> rowToBeMarked (A.size(),0);
    
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[0].size(); j++){
            if(A[i][j]==0){
                columnToBeMarked[j] = 1;
                rowToBeMarked[i] = 1;
            }
        }
    }
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[0].size(); j++){
            if(columnToBeMarked[j]==1 || rowToBeMarked[i]==1){
                A[i][j]=0;
            }
        }
    }
}


//best approach with O(1) space complexity
void Solution::setZeroes(vector<vector<int> > &A) {
    /*
    This code sets matrix rows and columns to zero in-place with O(1) space
    by using the first row and first column as markers. In the first pass, 
    it marks rows and columns that need zeroing. 
    A separate variable col0 tracks if the first column should be zeroed. 
    In the second pass (bottom-up), it zeroes cells based on these markers. 
    Unlike the previous solution, which uses extra space (O(m + n)), this approach avoids additional memory, 
    making it more space-efficient while ensuring correctness by scanning in reverse to preserve markers.
    */
    
    //time complexity ~ O(2nm)
    //space complexity = O(1)
    
    int col0 = 1; //initially marking it as 1 then if zero comes in the first column then we will mark it as 0
    int rows = A.size();
    int cols = A[0].size();
    
    //in the first iteration we are marking the required columns and the rows
    for(int i=0; i<rows; i++){
        //marking the first column col0 as 0
        if(A[i][0]==0) col0=0;
        //traversing from the second column only because the first column will be the marker
        for(int j=1; j<cols; j++){
            if(A[i][j]==0){
                A[0][j]=0; //marking the marker row's this column as 1
                A[i][0]=0; //marking the marker column's this row as 1
            }
        }
    }
    
    //now doing the second traversal bottom up so that we don't mess up with the marker 0's and 1's
    for(int i=rows-1; i>=0; i--){
        for(int j=cols-1; j>=1; j--){
            if(A[i][0]==0 || A[0][j]==0){
                A[i][j]=0;
            }
        }
        
        //after the inner loop has done traversing the grid then we would mark all the first column's required 1's as 0
        if (col0==0) A[i][0] = 0;
    }
}


