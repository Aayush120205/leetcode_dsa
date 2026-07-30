# Unit tests

Each solution folder holds a bare LeetCode submission (no `main`, no includes),
so every test file supplies the implicit LeetCode environment via
`leetcode_prelude.hpp` and then `#include`s the solution into an anonymous
namespace. That keeps the duplicate `Solution` class names from colliding while
testing the committed code as-is — the solutions themselves are unmodified.

```bash
make test      # build and run every test
make coverage  # rerun under gcov and print per-solution line coverage
```

Tests are written with the tiny framework in `test_framework.hpp`:

```cpp
TEST(BinarySearch, target_present) {
    Solution s;
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    CHECK_EQ(s.search(nums, 9), 4);
}
```

Available assertions: `CHECK_EQ`, `CHECK_NEAR`, `CHECK_TRUE`. The runner exits
non-zero if any assertion fails.
