#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

	class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			int x, y, flag = true;
			map <int, int> m;
			map <int, int>::iterator it;
			for (int i = 0; i < nums.size(); i++){
				// cout << nums[i] << ' ';
				// cout << m[nums[i]] << ' ' << i << ' '; 
				it = m.find(target - nums[i]);
				if(it == m.end()){
					cout << "in1 ";
					m[nums[i]] = i;
					continue;
				}
				else{
					if(flag){
						cout << "in3 ";
						x = i;
						y = it->second;
						flag = false;
						it--;
						cout << "testing " << it->first << ' ' << it->second << "laolao"; 
 					}
					m[nums[i]] = i;
				}
				cout << x << ' ' << y << '\n';
			}
			cout << x << ' ' << y;
			return vector<int> {min(x, y), max(x, y)};
		}
	};
int main() {
	Solution sol;
	vector<int> nums = {1, 2, 3, 1, 0, 6};
	int target = 6; 
	sol.twoSum(nums, target);	
	return 0;
}