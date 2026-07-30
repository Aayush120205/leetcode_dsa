#!/usr/bin/env python3
"""Summarise gcov output for the solution files.

Usage: python3 scripts/coverage_report.py <build-dir>

Reads the *.gcov files produced by `make coverage` and prints per-solution and
total line coverage, ignoring the test harness itself.
"""
import glob
import os
import sys


def solution_coverage(gcov_path):
    with open(gcov_path, encoding="utf-8", errors="replace") as handle:
        lines = handle.readlines()

    source = None
    for line in lines:
        if line.startswith("        -:    0:Source:"):
            source = line.split("Source:", 1)[1].strip()
            break
    if source is None or not source.endswith(".cpp"):
        return None
    if os.sep + "tests" + os.sep in source or source.startswith("tests" + os.sep):
        return None

    executable = covered = 0
    for line in lines:
        count = line.split(":", 1)[0].strip()
        if count == "-":
            continue
        executable += 1
        if count != "#####":
            covered += 1
    if executable == 0:
        return None
    return os.path.basename(source), covered, executable


def main():
    build_dir = sys.argv[1] if len(sys.argv) > 1 else "build"
    results = {}
    for path in sorted(glob.glob(os.path.join(build_dir, "*.gcov"))):
        entry = solution_coverage(path)
        if entry is None:
            continue
        name, covered, executable = entry
        results[name] = (covered, executable)

    if not results:
        print("No solution coverage data found in %s" % build_dir)
        return 1

    total_covered = total_executable = 0
    print("%-62s %8s %s" % ("solution", "coverage", "lines"))
    for name in sorted(results):
        covered, executable = results[name]
        total_covered += covered
        total_executable += executable
        print("%-62s %7.1f%% %d/%d" %
              (name, 100.0 * covered / executable, covered, executable))
    print("%-62s %7.1f%% %d/%d" %
          ("TOTAL", 100.0 * total_covered / total_executable, total_covered,
           total_executable))
    return 0


if __name__ == "__main__":
    sys.exit(main())
