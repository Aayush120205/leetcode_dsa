#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0118-pascals-triangle/0118-pascals-triangle.cpp"
}  // namespace
TEST(PascalsTriangle, five_rows) {
    Solution s;
    vector<vector<int>> expected{
        {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
    CHECK_EQ(s.generate(5), expected);
}

TEST(PascalsTriangle, single_row) {
    Solution s;
    vector<vector<int>> expected{{1}};
    CHECK_EQ(s.generate(1), expected);
}

TEST(PascalsTriangle, generate_row_directly) {
    Solution s;
    vector<int> expected{1, 5, 10, 10, 5, 1};
    CHECK_EQ(s.generateRow(6), expected);
}

TEST(PascalsTriangle, row_count_matches_request) {
    Solution s;
    vector<vector<int>> triangle = s.generate(30);
    CHECK_EQ(triangle.size(), static_cast<size_t>(30));
    CHECK_EQ(triangle.back().size(), static_cast<size_t>(30));
    CHECK_EQ(triangle.back()[1], 29);
}
