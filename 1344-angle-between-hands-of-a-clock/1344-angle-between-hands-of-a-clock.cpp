class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle1 = abs(((5.5)*minutes) - (30*hour));
        double angle2 = abs(360-angle1);
        return angle1>angle2?angle2:angle1;
    }
};