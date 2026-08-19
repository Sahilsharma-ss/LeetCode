class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end());
        int ind =0;
        int n1= reservedSeats.size();
        int tot = n*2;
        while(ind<n1)
        {
            int row = reservedSeats[ind][0]; // get the row 
            vector<int>vec(11,1);
            while(ind<n1 && reservedSeats[ind][0]==row)
            {
                vec[reservedSeats[ind][1]] = 0;
                ind++;
            }
            int cnt =0;
            int curr = 0;
            if((vec[2]==1 && vec[3]==1 && vec[4]==1 && vec[5]==1) &&  (vec[6]==1 && vec[7]==1 && vec[8]==1 && vec[9]==1) )
            {
                cnt=2;
            }
            else if( (vec[2]==1 && vec[3]==1 && vec[4]==1 && vec[5]==1) ||  (vec[6]==1 && vec[7]==1 && vec[8]==1 && vec[9]==1) || (vec[4]==1 && vec[5]==1 && vec[6]==1 && vec[7]==1) )
            {
                cnt=1;
            }
            else
            {
                cnt=0;
            }
            // for(int i =2;i<=9;i++)
            // {
            //     if(vec[i]==0){
            //         curr++;
            //     }
            //     else
            //     {
            //         curr=0;
            //     }
            //     if(curr==4)
            //     {
            //         cnt++;
            //         curr=0;
            //     }
            // }
            int res = 2-cnt;
            cout<<res<<" ";
            tot -= res;
            
        }
        return tot;
    }
};