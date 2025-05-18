#UKG FIND NUMBER SEQUENCE

In a game, there is a string, `direction`, of length `n` that consists of characters `L` and `R`. `L` denotes left, `R` denotes right, and there is a line segment of length `2^n` that extends from [0, 2^n], a player takes n turns.

In the `i` th turn,
- The player places the number `i` at the center of the current line segment.
- If `direction[i] = 'L'`, the player proceeds in the left direction, eliminating the right half of the current line segment, and vice versa for `direction[i] = 'R'`. 

Following this rule, find the final order of numbers on the line segment, starting from the left.

**Example**:

`direction = "LRRLLL"`

There are `n` = 6 characters in the initial length of the line segment. The segment length is `2^n` = 2^6 = 64 in the range [0, 64]. The game proceeds as follows:

| Center | Number | Direction | Remaining Segment |
|--------|--------|-----------|-------------------|
|        |        |           | [ 0, 64]          |
| 32     | 1      | L         | [ 0, 32]          |
| 16     | 2      | R         | [16, 32]          |
| 24     | 3      | R         | [24, 32]          |
| 28     | 4      | L         | [24, 28]          |
| 26     | 5      | L         | [24, 26]          |
| 25     | 6      | L         | [24, 25]          |


The smallest center point is 16 and the value placed is 2. The next smaller center is 24 with a value of 3. When the centers are ordered ascending, their values are `[2, 3, 6, 5, 4, 1]`.

**Function Description**:   
Complete the function `findNumberSequence` in the editor below. `findNumberSequence` has the following parameter: `string direction`: a string of length n where each character denotes the direction of a turn

**Returns**:   
`int[n]` : an integer array that denotes the indices of characters in the string ordered by placement point.

**Constraints**   
- 1 <= n <= 10^5
- The string `direction` consists of 'L' or 'R' only

**Sample Case 0**  
*Input*  `direction = "LRLRRL"`  
*Output* `[2 4 5 6 3 1]`  
*Explanation* `n` is 6, thus 2^6 is 64

| Center | Number | Direction | Remaining Segment |
| ------ | ------ | --------- | ----------------- |
|        |        |           | [0, 64]           |
| 32     | 1      | L         | [0, 32]           |
| 16     | 2      | R         | [16, 32]          |
| 24     | 3      | L         | [16, 24]          |
| 20     | 4      | R         | [20, 24]          |
| 22     | 5      | R         | [22, 24]          |
| 23     | 6      | L         | [22, 23]          |

Thus, the order of numbers starting from the left is `[2 4 5 6 3 1]`

**Sample Case 1**   
*Input* `direction = "LLLRRLLR"`   
*Output* `[4 5 8 7 6 3 2 1]`   
*Explanation* `n` is 8, thus 2^8 is 256

| Center | Number | Direction | Remaining Segment |
| ------ | ------ | --------- | ----------------- |
|        |        |           | [0, 256]          |
| 128    | 1      | L         | [0, 128]          |
| 64     | 2      | L         | [0, 64]           |
| 32     | 3      | L         | [0, 32]           |
| 16     | 4      | R         | [16, 32]          |
| 24     | 5      | R         | [24, 32]          |
| 28     | 6      | L         | [24, 28]          |
| 26     | 7      | L         | [24, 26]          |
| 25     | 8      | R         | [25, 26]          |

Thus, the order of numbers starting from the left is `[4 5 8 7 6 3 2 1]`