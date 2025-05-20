class Solution {
    public int subtractProductAndSum(int n) {
        int temp=n;
        int sum=0;
        int prod=1;
        while(n>0){sum+=n%10;n=n/10;}
        while(temp>0){prod*=temp%10;temp=temp/10;}
        return prod-sum;
    }
}