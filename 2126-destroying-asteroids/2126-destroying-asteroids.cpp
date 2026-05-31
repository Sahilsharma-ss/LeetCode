class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n = asteroids.size();
        vector<int>bigger;
        int cnt = 0;
        long long massofasteroid = mass;
        for(int i=0;i<n;i++)
        {
            if(asteroids[i]<=massofasteroid)
            {
                massofasteroid+=asteroids[i];
                cnt++;
            }
            else
            {
                bigger.push_back(asteroids[i]);
            }
        }
        for(int i : bigger)
        {
            if(massofasteroid>=i)
            {
                cnt++;
                massofasteroid+=i;
            }
            else
            {
                break;
            }
        }
        return cnt==n;
    }
};