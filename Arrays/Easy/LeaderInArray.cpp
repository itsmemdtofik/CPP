/**
 * <pre>
 * !Leaders in an Array;
 *
 * Given an array arr[] of size n, the task is to find all the Leaders in the array.
 * An element is a Leader if it is greater than or equal to all the elements to its right side.
 * Note: The rightmost element is always a leader.
 *
 * Examples
 * Input: arr[] = [16, 17, 4, 3, 5, 2]
 * Output: [17 5 2]
 * Explanation: 17 is greater than all the elements to its right i.e., [4, 3, 5, 2
 * therefore 17 is a leader. 5 is greater than all the elements to its right i.e
 * [2], therefore 5 is a leader. 2 has no element to its right, therefore 2 is
 * leader.
 *
 * Input: arr[] = [1, 2, 3, 4, 5, 2]
 * Output: [5,2]
 * Explanation: 5 is greater than all the elements to its right i.e., [2], therefore
 * 5 is a leader. 2 has no element to its right, therefore 2 is a leader.
 *
 * !Approach: Time Complexity O(n), Space complexity: O(n)
 * Step1: Start from the end(rightmost element), which is always a leader.
 * Step2: Traverse the array from right to left, compare each element with the leader.
 * Step3: If an element is greater thant or equal to leader, it is leader and we update the leader.
 * Step4: Stores the leader in list(Since we are processing from right to left, we will reverse result list at the end).
 * The final list of leaders will be in reverse order, so reverse it before returning.
 * </pre>
 */

#include <iostream>
#include <vector>
#include <algorithm>

class LeaderInArray {
public:
    static std::vector<int> leaderInArr(const std::vector<int> &number) {
        std::vector<int> leaders;
        if (number.empty())
            return leaders;

        int leader = number.back(); /* last element is always a leader */
        leaders.push_back(leader);

        /* Traverse from right to left */
        for (int i = number.size() - 2; i >= 0; i--) {
            if (number[i] >= leader) {
                leaders.push_back(number[i]);
                leader = number[i];
            }
        }

        /* Reverse to maintain left-to-right order */
        std::reverse(leaders.begin(), leaders.end());
        return leaders;
    }
};

int main() {
    const std::vector<int> arr1 = {1, 2, 3, 4, 5, 2};
    const std::vector<int> arr2 = {16, 17, 4, 3, 5, 2};

    const auto leaders1 = LeaderInArray::leaderInArr(arr1);
    const auto leaders2 = LeaderInArray::leaderInArr(arr2);

    std::cout << "Leaders in array 1: ";
    for (const int x: leaders1)
        std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "Leaders in array 2: ";
    for (const int x: leaders2)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
