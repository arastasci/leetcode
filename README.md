# leetcode
leetcode solutions
## Q1 - Two Sum 
- You can use a hashmap to look up the values you previously traversed. This makes the solution a one pass.
## Q2 - Add Two Numbers
- If you are doing something that produces extra terms to be included into the algorithm, be careful about whether your conditional clauses need to include said term as well. For example, when adding two digits, the resulting carry may be stored as an extra term, in which case, you would need to take into account whether the conditionals should include the carry beside the two digits.
- Then again, you can use ternary operators to decide if it's needed to use the operand in the calculation instead of going for multiple while loops which is confusing. See code for the original solution and compare it to the other for elaboration.
## Q3 - Longest Substring w/o Repeating Characters 
- It is good practice to use vectors as frequency tables or position tables when the problem is about characters.
- We used two pointers. We moved right forward every step and if the last seen place of the new character is greater than left pointer, we moved the left pointer to ```lastSeen[s[right]]```, thus sliding our window.
## Q19 - Remove Nth Node from end of list
- It is desirable to use dummy nodes when dealing with linked lists.
- I used a queue to keep track of the `n`th node from the end of the list, and it is pretty reasonable. 
## Q20 - Valid Parentheses
- A classic stack question.
## Q21 - Merge Two Sorted Lists
- When merging two linked lists, if you consume one list entirely, you can just have the node at that moment point to the list that still has elements left. In other words, there's no need to construct the remaining result list by hand.

## Q27 - Remove Element
- weird question
## Q55 - Jump Game
- implemented a greedy algorithm, working our way from the last index to the first. By using distance and ```nums[i]```, you can greedily walk to the first index.
## Q74 - Search a 2D Matrix
- first find the row, then the column. the conditions may tire you, but you will eventually get it.
## Q110 - Same Tree
- This question is about clever base cases.
## Q104 - Maximum Depth of Binary Tree
- Use recursion and find max for every call.
## Q110 - Balanced Binary Tree
- dfs'ing a binary tree must always have its own method.
- Passing through a pair of values in recursion methods is memory intensive but makes the problem easier.
## Q121 - Best Time to buy n sell stock
- One-pass algorithm by keeping track of minimum value at each iteration.
- Doing comparisons to determine the optimized value itself rather than variables that should result in the most optimal value is useful at times. For example, when looking for max profit, do comparisons on the potential max profit itself rather than trying to find a max value from which to subtract a min value. Doing final comparisons according to what is already known at that moment helps to simplify the flow of the code as well. In other words, work with `maxProfit` and `minValue` instead of maxValue and minValue.
## Q125 - Valid Palindrome
- nothin to add, might do this with recursion too.
## Q138 - Copy List with Random Pointer
- You can use hashmaps when encountered with an obligation of two passing a linked-list.
## Q141 - Linked List Cycle
- Floyd's cycle finding algorithm: Have one slow and one fast pointer, if the fast pointer reaches the end, no cycle. If the fast pointer "catches up" to the slow pointer, there must be a cycle.
## Q142 - Linked List Cycle II
Since. (2S = F) consider the part from 
start - cycle point = A, 
cycle point- intersect = B, 
intersect - cycle point = c

then slow trival A + B
fast travel A + (B+C) * N + B
(B+C) is one cycle and * N number we travel the cycles

from 2S = F we know (B+C)*N = a + b

from (B+C)*N = a + b if we remove B from each side
B*(N-1) + C*N = A.

then A must be equal to C or eqaul to X*C + Y * B where (X - Y = 1)
In other words A mod(b+c) = C,

As a result when we travel from start to point takes A to cycle points
and Intersect to cycle points will be same distance or
travel M cycles then reach to cycle points (from A mod(b+c) = C);
(thats is why we set 1 ptr at start and 1 at intersect and trival at same rate.)
- The do-while loop was handy for this question as when we started, the slow != fast equality didn't hold.

## Q143 - Reorder List
- slow and fast pointers -> find the middle and reverse the other half, creating two separate lists. then connect xth node to n-xth node and the latter to (x+1)th node using temp variables.
- you can also use a vector of nodes and do the second part of it but this uses extra memory.
## Q150 - Evaluate Reverse Polish Notation
- a cool stack question.
## Q155 - Min Stack
- the concept of pairs comes to mind when keeping track of something with a stack. when you pop it, the stack automatically provides the new min at the top() element.
## Q167 - Two Sum2 - Input Array is Sorted
- two pointers where left = 0 and right is at the end of the vector. in order to reach the target you move these two with a condition left < right 
## Q206 - Reverse Linked List
- use a prev pointer and iterate through the list.
- One of the recursive approaches is to keep stacking the function until you've reached the end, then change pointers as you pop. Note that the iterative solution is actually better in terms of space used.
## Q217 - Contains Duplicate
- Use a set to find duplicate.
## Q226 - Invert Binary Tree
- swap, then recursion.
## Q242 - Valid Anagram
- using a frequency table for every unicode character.
- You could also sort and compare since sorted anagrams become identical.
- A hash table is a more generic solution as it can take unicode characters as well.(?)
- It might be a good idea to look for early returns on some validation questions, since once you encounter, say, a negative frequency in this case, you can't recover from it. (?)
## Q424 - Longest Repeating Character Replacement
- two pointer / sliding window question. You can use a frequency table to check for the count, if the current window's character count - the character w/ max count > k, contract the window.
## Q543 - Diameter of Binary Tree
- Apply DFS and change the value of `diameter` as it is `left + right`, the sum of two branches.
## Q572 - Subtree of Another Tree
- same with Q110, except the base conditions are trickier.
## Q704 - Binary Search
- left-right pointer determines middle pointer, check where the target stands respective to middle, move the needed pointer to middle while(left <= right)



