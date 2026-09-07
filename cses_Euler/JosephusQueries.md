Problem:
Consider a game where there are n children (numbered 1,2,\dots,n) in a circle. During the game, every second child is removed from the circle, until there are no children left.
Your task is to process q queries of the form: "when there are n children, who is the kth child that will be removed?"

# Josephus Queries
## Problem

There are `n` children in a circle, numbered from `1` to `n`. During the game, every second child is removed until nobody remains.
For each query, we are given `n` and `k`. We must find the child who will be removed in the `k`th position.
The challenge is that `n` can be very large, so simulating the circle one removal at a time is too slow.

---

## Main Observation

The removals happen in rounds.

In the first round, the even-numbered children are removed:

```text
Children:  1   2   3   4   5   6   7   8
Remove:        X       X       X       X

Removed:   2, 4, 6, 8
Remaining: 1, 3, 5, 7
```

After this round, approximately half of the children remain. The same Josephus problem is now repeated on the smaller list of remaining children.

This is why the problem can be solved recursively by reducing `n` by half at every step.

---

## First Round

The first children removed are:

```text
2, 4, 6, 8, ...
```

Therefore, the child at removal position `k` is normally:

```text
2 * k
```

For example, when `n = 8`:

```text
k = 1  -> child 2
k = 2  -> child 4
k = 3  -> child 6
k = 4  -> child 8
```

For odd `n`, the numbering wraps around. Consider `n = 5`:

```text
Children:  1   2   3   4   5
Remove:        X       X   X

First-round removals: 2, 4, 1
Remaining children:   3, 5
```

For `k = 3`:

```text
2 * k = 2 * 3 = 6
```

Since child `6` does not exist, wrap around:

```text
6 - 5 = 1
```

So the third removed child is `1`.

The number of removals in the first round is:

```cpp
firstRound = (n + 1) / 2;
```

If `k <= firstRound`, the answer belongs to the first round:

```cpp
answer = 2 * k;

if (answer > n) {
    answer -= n;
}
```

---

## Reducing the Problem

Suppose `k` is larger than `firstRound`. Then the answer is not removed in the first round.

We remove the first-round positions from `k`:

```cpp
newK = k - firstRound;
```

The remaining children form a smaller Josephus problem with approximately half as many children:

```cpp
newN = n / 2;
```

So we recursively solve:

```cpp
result = counts(n / 2, k - firstRound);
```

### Example: `n = 8`

```text
Original list:  1  2  3  4  5  6  7  8
First round:       2     4     6     8
Remaining list:  1     3     5     7
```

The new problem contains only four positions:

```text
Reduced positions: 1  2  3  4
Original children: 1  3  5  7
```

---

## Mapping the Recursive Answer Back

The recursive call returns a position in the reduced list. We must convert that position back to the original child number.

### When `n` is even

For `n = 8`:

```text
Reduced position:  1   2   3   4
Original child:    1   3   5   7
```

The mapping is:

```cpp
originalChild = 2 * reducedPosition - 1;
```

Example:

```text
reducedPosition = 3
originalChild = 2 * 3 - 1 = 5
```

### When `n` is odd

For `n = 5`, after the first round the remaining list is:

```text
Reduced position:  1   2
Original child:    3   5
```

The mapping is:

```cpp
originalChild = 2 * reducedPosition + 1;
```

Example:

```text
reducedPosition = 2
originalChild = 2 * 2 + 1 = 5
```

---

## Complete Example: `n = 5, k = 5`

The removal order is:

```text
Round 1: 2, 4, 1
Round 2: 5, 3
```

Therefore, the fifth removed child is `3`.

The recursive calculation is:

```text
counts(5, 5)
```

There are three first-round removals:

```text
firstRound = (5 + 1) / 2 = 3
```

Since `k = 5` is later:

```text
newK = 5 - 3 = 2
newN = 5 / 2 = 2
```

Now solve:

```text
counts(2, 2)
```

For `n = 2`, there is one first-round removal. Again, `k` is later:

```text
newK = 2 - 1 = 1
newN = 2 / 2 = 1
```

The base case is:

```text
counts(1, 1) = 1
```

Now map the answer back:

```text
For n = 2 (even):
2 * 1 - 1 = 1

For n = 5 (odd):
2 * 1 + 1 = 3
```

Final answer:

```text
3
```

---

## Recursive Structure

```text
counts(n, k)
|
|-- n == 1
|   `-- return 1
|
|-- k belongs to the first round
|   `-- return 2 * k, with wraparound
|
`-- k belongs to a later round
    |-- solve counts(n / 2, newK)
    `-- map the reduced answer back
```

---

## C++ Implementation

```cpp
#include <iostream>
using namespace std;

long long kthRemoved(long long n, long long k) {
    if (n == 1) {
        return 1;
    }
    long long firstRound = (n + 1) / 2;

    // The answer is removed in the first round.
    if (k <= firstRound) {
        long long answer = 2 * k;

        if (answer > n) {
            answer -= n;
        }
        return answer;
    }

    // Solve the same problem for the remaining children.
    long long reducedPosition =
        kthRemoved(n / 2, k - firstRound);

    // Convert the reduced position to the original numbering.
    if (n % 2 == 0) {
        return 2 * reducedPosition - 1;
    }

    return 2 * reducedPosition + 1;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        long long n, k;
        cin >> n >> k;
        cout << kthRemoved(n, k) << '\n';
    }
}
```
---

## Correctness Intuition

The algorithm is correct because every removal sequence can be divided into two parts:

1. The first round, where the even-numbered children are removed directly.
2. The later rounds, which are exactly the same problem on the remaining children.

If `k` is in the first round, the answer is calculated directly. Otherwise, the algorithm subtracts the number of first-round removals and recursively solves the smaller problem.

The final mapping restores the original child number using the fact that the remaining children are arranged as odd-numbered children.

---

## Complexity

At every recursive call, `n` is divided by two:

```text
n -> n / 2 -> n / 4 -> n / 8 -> ...
```

The recursion depth is therefore `O(log n)`.

For each query:

```text
Time complexity:  O(log n)
Space complexity: O(log n)  // recursion stack
```

This is much faster than simulating all removals, which would take `O(n)` time per query.
