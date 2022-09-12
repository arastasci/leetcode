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
## Q39 - Combination Sum
- DFS through the vector and make a decision tree by backtracking.
- After you've chosen a path, you either choose to add another one of the most recent added element or to add no more of it. This makes the tree have distinct leaves.          
## Q40 - Combination Sum II
- You should sort the array to use this to your advantage for finding duplicate values. After the candidates array, you call the dfs method which using a for loop and recursion, backtracks and finds you all the combination sums.
- The important part here is you do the backtracking by first dfs'ing, then popping the element from the combination and iterating this over a loop, if `prev = candidates[i]`, you continue. If you draw this, a neat decision tree shows up where there is no duplicate values.
- Thinking the process of backtracking like this as a call stack helps simplify the concept.
- Another implementation of this problem can be inspired from Q90 - Subsets II.
## Q46 - Permutations
- Swap the places of a passed parameter `start` and the iterative parameter `i` and swap them back after you dfs'ed. This is a backtracking problem.
## Q49 - Group Anagrams
- serializing(?) the `vector<int> count` of every string as a string key and adding them to a hashmap as key solves the problem.
## Q55 - Jump Game
- implemented a greedy algorithm, working our way from the last index to the first. By using distance and ```nums[i]```, you can greedily walk to the first index.
## Q74 - Search a 2D Matrix
- first find the row, then the column. the conditions may tire you, but you will eventually get it.
## Q78 - Subsets
- This is a backtracking problem. You create a subset by choosing to add or not add an element. Recursively doing this creates a decision tree.  
## Q79 - Word Search
- You can either keep track of previously traversed coordinates or invalidate them with an invalid character. 
- My original solution (which used more memory but was slightly faster) used a `m x n` bool grid for the above.
- A popular backtracking problem.

## Q90 - Subsets II
- You sort the array to make it easier to detect duplicates and move on.
- backtracking and using a for loop makes it possible to eliminate duplicate combinations. Another implementation of this problem can be inspired from Q40 - Combination Sum II.

## Q98 - Validate Binary Search Tree
- By In-Order Traversal(left node -> current root -> right node) you can determine if a tree is a valid BST. You use a stack and push and pop to traverse from left to right.
## Q100 - Same Tree
- This question is about clever base cases.
## Q102 - Binary Tree Level Order Traversal
- By passing the level through function parameters, you can BFS through the tree with recursion.
- You can do this easily iteratively.
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
```
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
```
- The do-while loop was handy for this question as when we started, the slow != fast equality didn't hold.

## Q143 - Reorder List
- slow and fast pointers -> find the middle and reverse the other half, creating two separate lists. then connect xth node to n-xth node and the latter to (x+1)th node using temp variables.
- you can also use a vector of nodes and do the second part of it but this uses extra memory.
## Q150 - Evaluate Reverse Polish Notation
- a cool stack question.
## Q155 - Min Stack
- the concept of pairs comes to mind when keeping track of something with a stack. when you pop it, the stack automatically provides the new min at the top() element.
## Q167 - Two Sum2 - Input Array is Sorted
- two pointers where left = 0 and right is at the end of the vector. in order to reach the target you move these two with a condition left < right.
## Q199 - Binary Tree Right Side View
- Always initialise your pointers.
- DFS and BFS solutions are both possible: With DFS, you pass function parameter `level` and using that, fill `vector<int> levels`. With BFS, you can do a classic queue + iterative solution.
## Q206 - Reverse Linked List
- use a prev pointer and iterate through the list.
- One of the recursive approaches is to keep stacking the function until you've reached the end, then change pointers as you pop. Note that the iterative solution is actually better in terms of space used.
## Q215 - Kth Largest Element in an Array
- Using a min heap of size `k` solves the problem.
-**Another solution is "QuickSelect" which you must implement later.**

## Q217 - Contains Duplicate
- Use a set to find duplicate.
 ## Q226 - Invert Binary Tree
- swap, then recursion.
## Q230 - Kth Smallest Element in a BST
- You can do this with in order traversal (refer to Q98)(DFS) or with BFS and max-heap. I originally implemented this with a cursed recursive dfs solution.
## Q235 - Lowest Common Ancestor of a Binary Search Tree
- You can (again) do this recursively or iteratively, both have the same approaches: the first one that splits the two nodes `p` and `q` is the LCA.
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
## Q703 - Kth Largest Element in a Stream
- You keep the Kth largest element as the root of the min-heap, so keep `k` elements in the heap and if size goes over capacity pop.
## Q704 - Binary Search
- left-right pointer determines middle pointer, check where the target stands respective to middle, move the needed pointer to middle `while(left <= right)`
## Q973 - K Closest Points to Origin
- Can be implemented both with max heap and min heap. With min-heap you have to add all the values to the heap and then retrieve the first `k` ones. with max heap you maintain the size of the heap = `k`, if size exceeds it, you pop it; this way the ones besides k smallest values are popped.
- https://leetcode.com/problems/k-closest-points-to-origin/discuss/221532/C%2B%2B-STL-quickselect-priority_queue-and-multiset
## Q1046 - Last Stone Weight
- Classic max-heap question.
## Q1448 - Count Good Nodes in Binary Tree
- Traversing the tree with DFS is the way I went with this one. If ```node->val >= maxVal``` then increment `res` value.


