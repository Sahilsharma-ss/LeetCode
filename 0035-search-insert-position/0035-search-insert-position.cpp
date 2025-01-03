


class Solution {
    public int searchInsert(int[] nums, int target) {
       
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                return i;
            }
        }

     
        int[] newNums = new int[nums.length + 1];

       
        for (int i = 0; i < nums.length; i++) {
            newNums[i] = nums[i];
        }

        newNums[nums.length] = target;

        
        insertionSort(newNums);

        
        for (int i = 0; i < newNums.length; i++) {
            if (newNums[i] == target) {
                return i;
            }
        }

      
        return -1;
    }

    public void insertionSort(int[] nums) {
        int n = nums.length;
        for (int i = 1; i < n; i++) {
            int key = nums[i];
            int j = i - 1;

           
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j = j - 1;
            }
            nums[j + 1] = key;
        }
    }
}