class Solution {
public:
    int xc;
    int yc;
    int distance(int x ,int y){
        int dis_sq = (xc-x)*(xc-x) + (yc-y)*(yc-y);
        return dis_sq;
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        xc = xCenter;
        yc = yCenter;
        int rad_sq = radius*radius;
        bool flag = false;
        for(int i=y1;i<=y2;i++){
            if(distance(x1,i) <= rad_sq) return true;
            if(distance(x2,i) <= rad_sq) return true;
        }
        for(int i = x1;i<=x2;i++){
            if(distance(i,y1) <= rad_sq) return true;
            if(distance(i,y2) <= rad_sq) return true;
        }
        if(xc>=x1 && xc<=x2 && yc>=y1 && yc<= y2) return true;
        return false;
    }
};