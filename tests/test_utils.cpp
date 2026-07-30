#include "prelude.hpp"

// Included before the solutions so that the (re-)includes inside them are
// no-ops and the solution classes end up in their own namespaces.
#include "../utils/array_utils.hpp"
#include "../utils/binary_search.hpp"
#include "../utils/two_pointers.hpp"

namespace p0015 {
#include "../0015-3sum/0015-3sum.cpp"
}
namespace p0018 {
#include "../0018-4sum/0018-4sum.cpp"
}
namespace p0034 {
#include "../0034-find-first-and-last-position-of-element-in-sorted-array/0034-find-first-and-last-position-of-element-in-sorted-array.cpp"
}
namespace p0035 {
#include "../0035-search-insert-position/0035-search-insert-position.cpp"
}
namespace p0069 {
#include "../0069-sqrtx/0069-sqrtx.cpp"
}
namespace p0410 {
#include "../0410-split-array-largest-sum/0410-split-array-largest-sum.cpp"
}
namespace p0704 {
#include "../0704-binary-search/0704-binary-search.cpp"
}
namespace p0875 {
#include "../0875-koko-eating-bananas/0875-koko-eating-bananas.cpp"
}
namespace p1011 {
#include "../1011-capacity-to-ship-packages-within-d-days/1011-capacity-to-ship-packages-within-d-days.cpp"
}
namespace p1283 {
#include "../1283-find-the-smallest-divisor-given-a-threshold/1283-find-the-smallest-divisor-given-a-threshold.cpp"
}
namespace p1482 {
#include "../1482-minimum-number-of-days-to-make-m-bouquets/1482-minimum-number-of-days-to-make-m-bouquets.cpp"
}

namespace {

void testFirstAndLastTrue() {
    auto atLeastFive = [](long long x) { return x >= 5; };
    assert(dsa::firstTrue(0, 10, atLeastFive) == 5);
    assert(dsa::firstTrue(6, 10, atLeastFive) == 6);
    assert(dsa::firstTrue(0, 4, atLeastFive) == 5);  // never true -> high + 1

    auto atMostFive = [](long long x) { return x <= 5; };
    assert(dsa::lastTrue(0, 10, atMostFive) == 5);
    assert(dsa::lastTrue(0, 3, atMostFive) == 3);
    assert(dsa::lastTrue(6, 10, atMostFive) == 5);  // never true -> low - 1
}

void testBounds() {
    vector<int> nums = {1, 2, 2, 2, 5};
    assert(dsa::lowerBound(nums, 2) == 1);
    assert(dsa::upperBound(nums, 2) == 4);
    assert(dsa::lowerBound(nums, 0) == 0);
    assert(dsa::lowerBound(nums, 6) == 5);
    assert(dsa::upperBound(nums, 5) == 5);
    assert(dsa::binarySearch(nums, 5) == 4);
    assert(dsa::binarySearch(nums, 3) == -1);

    vector<int> empty;
    assert(dsa::lowerBound(empty, 1) == 0);
    assert(dsa::binarySearch(empty, 1) == -1);
}

void testArrayUtils() {
    vector<int> nums = {1, 2, 3, 4, 5};
    assert(dsa::countGroupsWithCapacity(nums, 5) == 4);
    assert(dsa::countGroupsWithCapacity(nums, 15) == 1);
    assert(dsa::sumOfCeilDiv(nums, 1) == 15);
    assert(dsa::sumOfCeilDiv(nums, 2) == 1 + 1 + 2 + 2 + 3);
}

void testTwoSumPairs() {
    vector<int> nums = {-2, -1, -1, 1, 1, 2, 3};
    auto pairs = dsa::twoSumPairs(nums, 0, (int)nums.size() - 1, 0);
    vector<pair<int, int>> expected = {{-2, 2}, {-1, 1}};
    assert(pairs == expected);
    assert(dsa::twoSumPairs(nums, 0, (int)nums.size() - 1, 100).empty());
}

void testSolutions() {
    vector<int> threeSumInput = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> threeSumExpected = {{-1, -1, 2}, {-1, 0, 1}};
    assert(p0015::Solution().threeSum(threeSumInput) == threeSumExpected);

    vector<int> fourSumInput = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> fourSumExpected = {
        {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
    assert(p0018::Solution().fourSum(fourSumInput, 0) == fourSumExpected);

    vector<int> range = {5, 7, 7, 8, 8, 10};
    assert((p0034::Solution().searchRange(range, 8) == vector<int>{3, 4}));
    assert((p0034::Solution().searchRange(range, 6) == vector<int>{-1, -1}));

    vector<int> insert = {1, 3, 5, 6};
    assert(p0035::Solution().searchInsert(insert, 5) == 2);
    assert(p0035::Solution().searchInsert(insert, 7) == 4);
    assert(p0035::Solution().searchInsert(insert, 0) == 0);

    assert(p0069::Solution().mySqrt(0) == 0);
    assert(p0069::Solution().mySqrt(8) == 2);
    assert(p0069::Solution().mySqrt(2147395600) == 46340);
    assert(p0069::Solution().mySqrt(INT_MAX) == 46340);

    vector<int> split = {7, 2, 5, 10, 8};
    assert(p0410::Solution().splitArray(split, 2) == 18);
    vector<int> splitSingle = {1, 2, 3, 4, 5};
    assert(p0410::Solution().splitArray(splitSingle, 1) == 15);

    vector<int> search = {-1, 0, 3, 5, 9, 12};
    assert(p0704::Solution().search(search, 9) == 4);
    assert(p0704::Solution().search(search, 2) == -1);

    vector<int> piles = {3, 6, 7, 11};
    assert(p0875::Solution().minEatingSpeed(piles, 8) == 4);
    vector<int> bigPiles = {1000000000};
    assert(p0875::Solution().minEatingSpeed(bigPiles, 1) == 1000000000);

    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(p1011::Solution().shipWithinDays(weights, 5) == 15);
    assert(p1011::Solution().shipWithinDays(weights, 1) == 55);

    vector<int> divisor = {1, 2, 5, 9};
    assert(p1283::Solution().smallestDivisor(divisor, 6) == 5);
    assert(p1283::Solution().smallestDivisor(divisor, 17) == 1);

    vector<int> bloom = {1, 10, 3, 10, 2};
    assert(p1482::Solution().minDays(bloom, 3, 1) == 3);
    assert(p1482::Solution().minDays(bloom, 3, 2) == -1);
    vector<int> bloom2 = {7, 7, 7, 7, 12, 7, 7};
    assert(p1482::Solution().minDays(bloom2, 2, 3) == 12);
}

}  // namespace

int main() {
    testFirstAndLastTrue();
    testBounds();
    testArrayUtils();
    testTwoSumPairs();
    testSolutions();
    printf("all tests passed\n");
    return 0;
}
