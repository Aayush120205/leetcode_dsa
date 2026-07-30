# Shared utilities

Header-only helpers extracted from the solutions in this repository, so that a
pattern is implemented (and verified) once instead of being re-typed per
problem.

| Header | Helper | Replaces |
| --- | --- | --- |
| `binary_search.hpp` | `firstTrue(low, high, pred)` | "binary search on the answer" loops in 0410, 0875, 1011, 1283, 1482 |
| `binary_search.hpp` | `lastTrue(low, high, pred)` | 0069 |
| `binary_search.hpp` | `lowerBound` / `upperBound` / `binarySearch` | 0034, 0035, 0704 |
| `array_utils.hpp` | `countGroupsWithCapacity(nums, capacity)` | identical greedy grouping in 0410 (`countPartitions`) and 1011 (`findDays`) |
| `array_utils.hpp` | `sumOfCeilDiv(nums, divisor)` | 0875 (`findTotalHours`) and 1283 (`sumbyD`) |
| `two_pointers.hpp` | `twoSumPairs(nums, lo, hi, target)`, `isDuplicateAt` | duplicate-skipping two-pointer inner loop of 0015 and 0018 |

`leetcode.hpp` is a small prelude with the standard includes and
`using namespace std;`, matching the environment the LeetCode judge provides.

## Submitting to LeetCode

Solutions that use these helpers start with a relative `#include`, which the
LeetCode editor cannot resolve. To submit such a solution, paste the bodies of
the helpers it includes above `class Solution` (or inline the two-line loop
again) and drop the `#include` line.

## Local verification

```sh
make test   # unit + example-based tests for the utilities and the solutions using them
make check  # syntax-checks every solution file against tests/prelude.hpp
```
