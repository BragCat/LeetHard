class Node {
public:
	int father, size; 
	Node(): father(-1), size(1) {}
};

class DisjointSet {
public:
	DisjointSet(int n) {
		nodes = vector<Node>(n, Node{});
	}
	int getFather(int x) {
		if (nodes[x].father == -1) {
			return x;
		}	
		nodes[x].father = getFather(nodes[x].father);
		return nodes[x].father;
	}

	int getSize(int x) {
		return nodes[getFather(x)].size;
	}

	void join(int x, int y) {
		int fx = getFather(x);
		int fy = getFather(y);
		if (fx == fy) {
			return;
		}
		if (nodes[fx].size >= nodes[fy].size) {
			nodes[fy].father = fx;
			nodes[fx].size += nodes[fy].size;
			nodes[fy].size = 0;
		} else {
			nodes[fx].father = fy;
			nodes[fy].size += nodes[fx].size;
			nodes[fx].size = 0;
		}
	}	
private:
	vector<Node> nodes;
};


class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    	vector<int> ans;
    	int m = grid.size();
    	if (m == 0) {
    		return ans;
    	}
    	int n = grid[0].size();
    	if (n == 0) {
    		return ans;
    	}
 		vector<vector<int>> finalGrid = grid;
 		for (auto &p : hits) {
 			finalGrid[p[0]][p[1]] = 0;
 		}      

 		DisjointSet ds(m * n + 1);
 		int rootNumber = m * n;
 		for (int i = 0; i < m; ++i) {
 			for (int j = 0; j < n; ++j) {
 				if (finalGrid[i][j] == 1) {
 					int nodeNumber = i * n + j;
 					if (i == 0) {
 						ds.join(nodeNumber, rootNumber);
 					} else if (finalGrid[i - 1][j] == 1) {
 						ds.join(nodeNumber, nodeNumber - n);
 					} 
 					if (j > 0 && finalGrid[i][j - 1] == 1) {
 						ds.join(nodeNumber, nodeNumber - 1);
 					}
 				}
 			}
 		}

 		int cnt = ds.getSize(rootNumber);
 		for (int i = hits.size() - 1; i >= 0; --i) {
 			int x = hits[i][0], y = hits[i][1];

 			if (grid[x][y] == 1 && finalGrid[x][y] == 0) {
 				finalGrid[x][y] = 1;
 				int nodeNumber = x * n + y;
 				if (x == 0) {
 					ds.join(nodeNumber, rootNumber);
 				}
 				if (x > 0 && finalGrid[x - 1][y] == 1) {
 					ds.join(nodeNumber, nodeNumber - n);
 				}
 				if (x < m - 1 && finalGrid[x + 1][y] == 1) {
 					ds.join(nodeNumber, nodeNumber + n);
 				}
 				if (y > 0 && finalGrid[x][y - 1]) {
 					ds.join(nodeNumber, nodeNumber - 1);
 				}
 				if (y < n - 1 && finalGrid[x][y + 1]) {
 					ds.join(nodeNumber, nodeNumber + 1);
 				}

 				int newCnt = ds.getSize(rootNumber);
 				if (newCnt == cnt) {
 					ans.push_back(0);
 				} else {
 					ans.push_back(newCnt - cnt - 1);
 				}
 				cnt = newCnt;
 			} else {
 				ans.push_back(0);
 			}
 		}
 		reverse(ans.begin(), ans.end());
 		return ans;
    }
};
