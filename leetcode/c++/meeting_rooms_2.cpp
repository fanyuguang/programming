#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	int minMeetingRooms(vector<vector<int>>& intervals) 
	{
		map<int, int> room_store;
		for (auto iter : intervals) 
		{
			++room_store[iter[0]];
			--room_store[iter[1]];
		}
		int cur_rooms = 0;
		int min_rooms = 0;
		for (auto iter : room_store) 
		{
            cur_rooms += iter.second;
			min_rooms = max(min_rooms, cur_rooms);
		}
		return min_rooms;
	}
};

int main()
{
    vector<vector<int>> itervals = {{0, 30}, {5, 10}, {15, 20}};
    Solution s;
    int result = s.minMeetingRooms(itervals);
    cout << result << endl;
    return 0;
}
