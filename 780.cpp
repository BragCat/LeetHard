class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
 		while (tx >= sx && ty >= sy) {
 			if (tx == sx && ty == sy) {
 				return true;
 			}

 			if (tx > ty) {
 				if (tx == sx) {
 					return false;
 				}
 				if (sx >= ty) {
 					int r = (tx - sx) % ty;
 					if (r != 0) {
 						return false;
 					}
 					tx = sx;
 				} else {
 					tx %= ty;
 				}
 			} else if (tx < ty){
 				if (ty == sy) {
 					return false;
 				}
 				if (sy >= tx) {
 					int r = (ty - sy) % tx;
 					if (r != 0) {
 						return false;
 					}
 					ty = sy;
 				} else {
 					ty %= tx;
 				}
 			} else {
 				if (sx == 0) {
 					tx = 0;
 				} else if (sy == 0) {
 					ty = 0;
 				} else {
 					return false;
 				}
 			}
 		}      
 		return false;
    }
};