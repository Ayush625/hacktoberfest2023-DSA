// Linear Search Algorithm in C++ using vectors

#include <iostream>
#include <vector>

class LinearSearch
{
    std::vector<int> arr;
    int target, location;

public:
    /// @brief constructor
    /// @param mArr
    /// @param mTarget
    LinearSearch(std::vector<int> mArr, int mTarget)
    {
        arr = mArr;
        target = mTarget;
        location = -1;
    }

    /// @brief Linear search algorihtm
    /// @return
    int search()
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == target)
            {
                location = i;
            }
            else
            {
                continue;
            }
        }

        return location;
    }
};

int main()
{
    std::vector<int> tArr = {1, 2, 3, 4};
    int tTarget = 6;

    LinearSearch l(tArr, tTarget);

    int result = l.search();

    if (result < 0)
    {
        std::cout << tTarget << " was not found in the array" << std::endl;
    }
    else
    {
        std::cout << tTarget << " was found at index " << result << std::endl;
    }
    return 0;
}