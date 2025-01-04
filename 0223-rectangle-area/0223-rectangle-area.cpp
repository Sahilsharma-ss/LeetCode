class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int rec1 = (ay2 - ay1) * (ax2 - ax1), rec2 = (by2 - by1) * (bx2 - bx1);
        int cx1, cy1, cx2, cy2;

        cx1 = max(ax1, bx1);
        cy1 = max(ay1, by1);
        cx2 = min(ax2, bx2);
        cy2 = min(ay2, by2);

        if ((cy2 - cy1 < 0) || (cx2 - cx1) < 0) return rec1 + rec2;

        int overlap = (cy2 - cy1) * (cx2 - cx1);
        return rec1 + rec2 - overlap;
    }
};