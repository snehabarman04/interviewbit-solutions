/*
  Problem Description
 
 

Given an unsorted integer array, find the first missing positive integer.
Your algorithm should run in O(n) time and use constant space.


Problem Constraints
1 <= |A| <= 106
-106 <= Ai <= 106


Input Format
The first argument is an integer array A.


Output Format
Return an integer equal to the first missing positive integer


Example Input
Input 1:
A = [1,2,0]
Input 2:
A = [3,4,-1,1]
Input 3:
A = [-8,-7,-6]


Example Output
Output 1:
3
Output 2:
2
Output 3:
1


Example Explanation
Explanation 1:
3 is the first positive missing integer.
Explanation 2:
2 is the first positive missing integer.
Explanation 3:
1 is the first positive missing integer.

  */



//one solution though it is not of the time complexity O(N) and instead has time complexity O(NlogN)
int Solution::firstMissingPositive(vector<int> &A) {
    //sorting the array first
    sort(A.begin(),A.end());
    //we first let the first missing number to be 1
    int missingNumber = 1;
    for(auto i:A){
        if(i<1) continue; //skip for the negative numbers
        else if(i==missingNumber){
            //if the initially assumed missing number is found then we increment mising number to be the next
            //positive integer ad then again if we keep them then we increment that further
            missingNumber++;
            continue;
        }
        //and if the current value of the element is greater than the missing number we have assumed then that means
        //the missing number was the one we have just incremented to
        else{
            break;
        }
    }
    return missingNumber;
}


//required solution of time complexity O(n)

//Put each positive number x (1 ≤ x ≤ n) at index x - 1
    //Only valid positives (1 to n) are considered.
    //Each number is swapped to its correct position (A[x - 1] = x).
    
    //we know that the maximum number that could be missing would be n only
    int n = A.size();
    for(int i=0; i<n; i++){
        if(A[i]>0 && A[i]<=n){
            int index = A[i]-1;
            if(A[index]!=A[i]){
                swap(A[index],A[i]);
                i--;
                //After each swap, i-- ensures we recheck the swapped-in number.
                //the new element that comes after the swap at the index i needs to be checked again if it's in the correct index
            }
        }
    }
    //now we just have to traverse once more in the array and check if the number present at that position is index+1
    for(int index=0; index<n; index++){
        if(A[index]!=index+1) return index+1;
    }
    return n+1;
