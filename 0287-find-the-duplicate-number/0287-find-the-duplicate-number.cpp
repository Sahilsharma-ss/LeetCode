class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int slow = nums[0];
      int fast = nums[0];

      do{
        slow = nums[slow];
        fast = nums[nums[fast]];
      }while(slow != fast);   //  cycle point

      slow = nums[0];
      while(slow!=fast) // get no 
      {
        slow = nums[slow];
        fast = nums[fast];
      }
      return slow;

    }
};