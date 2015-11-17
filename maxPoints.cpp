#include "common.h"
//not checked yet

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        const int size = points.size();
        if(size <= 1)
            return size;
        auto calcx = [](const Point& p1, const Point& p2){
            if(p1.x == p2.x)
                return numeric_limits<double>::quiet_NaN();
            auto x = p2.x - p1.x;
            auto y = p2.y - p1.y;
            auto tag = (double) y/x;
            return tag;
        };
        int maxnum = 0;

        for (int i = 0; i < points.size(); ++i) {
            unordered_map<double, int> tagnode;
            int dup = 1;
            int vert = 0;
            for (int j = 0; j < points.size(); ++j) {
                if(i == j)
                    continue;
                if(points[i].x == points[j].x && points[i].y == points[j].y ){
                    dup ++;
                    continue;
                }
                auto p = calcx(points[i], points[j]);

                if(std::isnan(p)){
                    vert ++;
                }
                else{
                    tagnode[p]++;
                }
            }
            maxnum = max(maxnum, vert+dup);
            if(tagnode.size() >0) {
                auto it = max_element(tagnode.begin(), tagnode.end(),
                                      [](const pair<const double, int> &p1, const pair<const double, int> &p2) {
                                          return p1.second < p2.second;
                                      });
                maxnum = max(maxnum, it->second+dup);
            }
        }
        return maxnum;
    }
};

int main() {
    vector<Point> data {{0,0}, {1,1}, {1,-1}};
    cout << Solution().maxPoints(data);
    return 1;
}