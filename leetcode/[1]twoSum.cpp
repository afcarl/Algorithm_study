
// This is the first solution
// Time O(n^2), Space O(1)
// 28ms, don't why so fast

/*|Description:
 *|  First, we copy the given array, and sort it.
 *|  Then find the two numbers (since we have sorted it, we have faster way to find them).
 *|  Then use O(n) time to find the two index
 *|
 *|Attention:
 *|  The final index1 must be less than index2, I think this is unspecified.
 *|  But to AC this question, we must do that.
 */

class Solution1 {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int index1 = -1;
    int index2 = -1;
    int num_1 = 0;
    int num_2 = 0;

    bool flag = false;
    vector<int> copy_numbers = numbers;
    sort(copy_numbers.begin(),copy_numbers.end());

    for (int i=0;i<copy_numbers.size();i++) {
        for (int j=0;j<copy_numbers.size();j++) {
            if (i == j) continue;
            if (copy_numbers[i]+copy_numbers[j] > target) break;
            if (copy_numbers[i]+copy_numbers[j] == target) {
                num_1 = copy_numbers[i];
                num_2 = copy_numbers[j];
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    
    for (int i=0;i<numbers.size();i++) {
        if (numbers[i] == num_1 && index1 == -1) {
            index1 = i+1;
        } else if (numbers[i] == num_2 && index2 == -1) {
            index2 = i+1;
        }
        if (index1 != -1 && index2 != -1) break;
    }

    vector<int> res;
    if (index1 > index2) {
        res.push_back(index2);
        res.push_back(index1);
    } else {
        res.push_back(index1);
        res.push_back(index2);
    }

    return res;
  }
};

// This is the second solution
// Time O(n), Space O(n)
// 22ms

/*|Description:
 *|  We create a unorderd_map to store the relation between value and key.
 *|  And for every element in numbers, call the count function in STL.
 *|
 *|Attention:
 *|  Someone may think this is incorrect since the map key is unique.
 *|  However, when we find the index, one is from vector and the other is from map.
 *|  So there is no collision.
 */

class Solution2 {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int,int> mymap;
    int index1 = -1;
    int index2 = -1;
    for (int i=0;i<numbers.size();i++) {
        mymap.insert(make_pair(numbers[i],i));
    }
    for (int i=0;i<numbers.size();i++) {
        int a = numbers[i];
        if (mymap.count(target-a)) {
            if (i != mymap[target-a]) {
                index1 = i+1;
                index2 = mymap[target-a]+1;
            }
        }
        if (index1 != -1 && index2 != -1) break;
    }
    vector<int> res;
    if (index1 < index2) {
        res.push_back(index1);
        res.push_back(index2);
    } else {
        res.push_back(index2);
        res.push_back(index1);
    }
    return res;
  }
};
