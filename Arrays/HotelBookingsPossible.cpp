/*

Problem Description
 
 

A hotel manager has to process N advance bookings of rooms for the next season. His hotel has C rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .

Note- If we have arrival and departure on the same date then arrival must be served before the departure.


Problem Constraints
1 <= |A| <= 106
|A|== |B|
1 <= Ai <= Bi <= 108
1 <= C <= 106



Input Format
First argument is an integer array A containing arrival time of booking.

Second argument is an integer array B containing departure time of booking.

Third argument is an integer C denoting the count of rooms.



Output Format
Return True if there are enough rooms for N bookings else return False.

Return 0/1 for C programs.



Example Input
Input 1:

 A = [1, 3, 5]
 B = [2, 6, 8]
 C = 1
Input 2:

 A = [1, 2, 3]
 B = [2, 3, 4]
 C = 2


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 At day = 5, there are 2 guests in the hotel. But I have only one room.
Explanation 2:

 At day = 1, there is 1 guest in the hotel.
 At day = 2, there are 2 guests in the hotel. 
 At day = 3, there are 2 guests in the hotel.
 At day = 4, there is 1 guest in the hotel.

 We have two rooms available, which satisfy the demand.

  */




bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    if(K == 0) return false;
    vector<pair<int,int>> temp;
    for(int i=0; i<arrive.size(); i++){
        temp.push_back(make_pair(arrive[i],0));
        temp.push_back(make_pair(depart[i],1));
    }
    //Since 0 < 1, when sorting pairs:
    //If two events have same date, arrival (date,0) comes after departure (date,1)
    //So we get correct behavior: departures processed after arrivals if on same day
    //so guest can leave and another arrive on the same day.


    sort(temp.begin(),temp.end());
    int rooms = 0;
    for(int i=0; i<temp.size(); i++){
        if(temp[i].second==0){
            rooms++;
        }
        else rooms--;
        if(rooms>K) return false;
    }
    return true;
}
