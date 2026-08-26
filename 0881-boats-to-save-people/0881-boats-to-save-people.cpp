class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int l=0;
        int r=n-1;
        int boats=0;
        while(l<=r)
        {
            int sum = people[l]+people[r];
            if(sum<=limit)
            {
                l++;
                r--;
                boats++;
            }
            else
            {
                r--;
                boats++;
            }
        }
        return boats;
    }
};