#!/usr/bin/env bash
# Syntax-checks every solution file by compiling it against tests/prelude.hpp,
# which supplies the declarations the LeetCode judge would provide.
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cxx="${CXX:-g++}"
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT

status=0
while IFS= read -r solution; do
    unit="$tmp/unit.cpp"
    {
        echo "#include \"$root/tests/prelude.hpp\""
        echo "#include \"$solution\""
    } > "$unit"

    if ! "$cxx" -std=c++17 -fsyntax-only "$unit"; then
        echo "FAIL ${solution#"$root"/}"
        status=1
    fi
done < <(find "$root" -mindepth 2 -name '*.cpp' -not -path "$root/tests/*" | sort)

if [ "$status" -eq 0 ]; then
    echo "All solutions compile."
fi
exit "$status"
