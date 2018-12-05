// Source : https://oj.leetcode.com/problems/two-sum/
// Author : cjc
// Date   : 2018-12-04

/********************************************************************************** 
* 
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
* 
*               
**********************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    /*
     *   The easy solution is O(n^2) run-time complexity.
     *   ```
     *       foreach(item1 in array) {
     *           foreach(item2 in array){
     *               if (item1 + item2 == target) {
     *                   return result
     *               }
     *           }
     *   ```
     *   
     *   We can see the nested loop just for searching, 
     *   So, we can use a hashmap to reduce the searching time complexity from O(n) to O(1)
     *   (the map's `key` is the number, the `value` is the position)
     *   
     *   But be careful, if there are duplication numbers in array, 
     *   how the map store the positions for all of same numbers?
     *
     */

    //
    // The implementation as below is bit tricky. but not difficult to understand
    //
    //  1) Traverse the array one by one
    //  2) just put the `target - num[i]`(not `num[i]`) into the map
    //     so, when we checking the next num[i], if we found it is exisited in the map.
    //     which means we found the second one.
    //
  public:
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for(unsigned int i = 0; i < numbers.size(); i++) {
            // not found the second one
            if(m.find(numbers[i]) == m.end()) {
                // store the first one position into the second one's key
                m[target - numbers[i]] = i;
            } else {
                // found the second one
                result.push_back(m[numbers[i]] + 1);
                result.push_back(i + 1);
                break;
            }
        }
        return result;
    }
};

int main()
{
    cout << "main:" << endl;
    vector<int> myvector;
    int myint;
    int target = 9;

    cout << "Please enter some integers(enter 0 to end):" << endl;
    do
    {
        cin >> myint;
        myvector.push_back(myint);
    } while (myint);
    //Solution* solution = new Solution;
    // vector<int> result = solution->twoSum(myvector, target);

    Solution solution;
    vector<int> &myreferencevector = myvector;
    vector<int> result = solution.twoSum(myreferencevector, target);

    for (vector<int>::iterator it = result.begin(); it != result.end(); ++it)
        cout << ' ' << *it;

    cout << '\n';

    // delete solution;
    return 0;
}