/*
Problem Description
 
 

Given a collection of intervals, merge all overlapping intervals.



Problem Constraints
1 <= Total number of intervals <= 100000.



Input Format
First argument is a list of intervals.



Output Format
Return the sorted list of intervals after merging all the overlapping intervals.



Example Input
Input 1:

[1,3],[2,6],[8,10],[15,18]


Example Output
Output 1:

[1,6],[8,10],[15,18]


Example Explanation
Explanation 1:

Merge intervals [1,3] and [2,6] -> [1,6].
so, the required answer after merging is [1,6],[8,10],[15,18].
No more overlapping intervals present.


Solution:
Sort the intervals based on their start point. This brings potentially overlapping intervals closer.
Initialize currentInterval with the first interval.
Iterate through each subsequent interval:
If it overlaps with the current one (a[i][0] <= currentInterval[1]), merge them by updating the start and end using min and max.
If there's no overlap, push currentInterval into the result and start a new currentInterval.
After the loop, push the last currentInterval into the result.
Return the merged list.
*/

bool compare(const Interval &a, const Interval &b) {
    return a.start < b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), compare);
    Interval temp = A[0];
    vector<Interval> result;
    
    for(int i=1; i<A.size(); i++){
        //if overlap happens this condition will be satified
        if(temp.end>=A[i].start){
            temp.end =  max(temp.end, A[i].end);
            
        }
        //if no overlap
        else{
            result.push_back(temp);
            temp = A[i];
        }
    }
    result.push_back(temp);
    return result;
}
