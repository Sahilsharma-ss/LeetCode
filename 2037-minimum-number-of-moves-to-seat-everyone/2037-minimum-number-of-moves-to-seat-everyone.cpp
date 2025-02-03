class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int sum=0;
        int j,i;
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        for(i =0,j=0;i<seats.size();i++,j++)
        {
            sum=sum+abs(seats[i]-students[i]);
        }
        return sum;
    }
};