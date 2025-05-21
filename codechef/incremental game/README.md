Incremental Game
Alice and Bob play a game with two piles of stones, where they take turns removing stones under specific rules. The goal is to determine the winner when both players play optimally.

Problem Statement
Alice and Bob start with two piles of stones, one with X stones and the other with Y stones. They take turns, with Alice going first. The rules are:

Alice's First Move: She must choose one of the piles and remove at least 1 and at most K stones from it.

Subsequent Moves: Each player must choose one of the two piles and remove strictly more stones than the opponent's previous move. If they cannot do this, they lose.

The player who cannot make a move loses. Both players play optimally to win.

Input Format
The first line contains an integer T, the number of test cases.

Each test case consists of three integers X, Y, and K, representing the number of stones in the two piles and the maximum stones Alice can remove on her first move.

Output Format
For each test case, output "Alice" or "Bob" (case-insensitive), indicating the winner.

Constraints
1 ≤ T ≤ 8000

1 ≤ X, Y, K ≤ 20

Sample Input and Output
Input:

3
4 4 10
4 4 1
5 9 7
Output:

Alice
Bob
Alice
Explanation
Test Case 1:

Alice removes all 4 stones from one pile (since 4 ≤ K = 10).

Bob cannot remove more than 4 stones from the remaining pile, so he loses.

Test Case 2:

Alice can only remove 1 stone (since K = 1).

Bob then removes all stones from the other pile (4 stones), leaving Alice with no valid move.

Test Case 3:

Alice removes 5 stones from the second pile (since 5 ≤ K = 7).

Bob cannot remove more than 5 stones from either pile, so he loses.