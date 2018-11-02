/*

*/

//version 1(8 ms)
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), startComparator);
        int room = 0;
        // store the not finished room, sorted in endTime
        priority_queue<int, vector<int>, greater<int>> endQueue;
        for (auto itr : intervals) {
            while (!endQueue.empty()) {
                if (itr.start < endQueue.top()) {
                    break;
                }
                endQueue.pop();
            }
            endQueue.push(itr.end);
            room = max(room, (int)endQueue.size());
        }
        return room;
    }
    
    static bool startComparator(Interval& a, Interval& b) {
        return a.start < b.start;
    }
};

