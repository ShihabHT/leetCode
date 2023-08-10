/*
Qs: is it possible to create an array of methods to perform and another array for their arguments,
LIke the following methods = {"NumArray", "sumRange", "update", "sumRange"}; 
queries = {{1,3,5},{0,2},{1,2},{0,2}}; then call all the methods with a loop

ChatGPT:
Yes, it is possible to create an array of methods and another array for their arguments, and then use
a loop to call the methods with their respective arguments. Here's how you can achieve that in C++:
*/

#include <iostream>
#include <vector>
#include <functional>

class NumArray {
public:
    std::vector<int> nums;

    NumArray(std::vector<int>& nums) : nums(nums) {
    }

    void update(int index, int val) {
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; ++i) {
            sum += nums[i];
        }
        return sum;
    }
};

int main() {
    using Method = std::function<void(NumArray&, int, int)>;

    Method methods[] = {
        [](NumArray& obj, int index, int val) { obj.update(index, val); },
        [](NumArray& obj, int left, int right) {
            int result = obj.sumRange(left, right);
            std::cout << "Sum: " << result << std::endl;
        }
    };

    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<std::vector<int>> queries = {{1, 3, 5}, {0, 2}, {1, 2}, {0, 2}};

    NumArray numArray(nums);

    for (int i = 0; i < sizeof(methods) / sizeof(methods[0]); ++i) {
        methods[i](numArray, queries[i][0], queries[i][1]);
    }

    return 0;
}
/*
In this example, the methods array holds lambda functions that call the update and sumRange methods
of the NumArray class. The queries array contains the corresponding arguments for each method call.
The loop iterates through the methods, and for each method, it calls the appropriate lambda function
with the associated arguments. The update method updates the array value, and the sumRange method
calculates and prints the sum.

Keep in mind that this approach may not be the most efficient way to perform these operations,
especially if the number of operations is large, due to the linear time complexity of the sumRange
method. This example is just for demonstration purposes.
*/