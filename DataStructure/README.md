Abstract Data Type
------------------
A description of **information** and a collection of **operations** on that information.
### Dynamic Array
* Allocate a small array in the heap initially and double its size as needed.
* Allocate a Huge array which we can never get out of range.
* [Example code]().

### Stack ADT
* Items removed in LIFO (last in first out) order
* Realization of Stack ADT:
  * Array
  * Link-list
* [code]()

### Queue ADT
* Items are removed in FIFO (first in first out) order
* Realization of Queue ADT:
  * Cycle array
  * Link-list
* [code]()

### Dictionay ADT
* A dictionary is an ordered or unordered list of key-element **pairs**, where keys are used to locate elements in the list. 
* Realization of Dictionary ADT:
  * Unsorted array or link-list:
    * Search Θ(n)
    * Insert Θ(1)
    * Delete Θ(n) (search first)
  * Sorted array or link-list:
    * Search Θ(logn)
    * Insert Θ(n)
    * Delete Θ(n)

### Heap ADT
* A max-heap is a binary tree with following properties:
  * **Structural property**: All level are completely filled, expect(possiblly) last level, the filled elements in last level is **left-justified**
  * **Heap-Order properties**: For any node i, key (priority) of parents of i is large or equal to key of i
* min-heap is the same with max-heap but the order is opposite
* Height of a heap with n nodes Θ(log(n))
* Insertion of heap : O(Height of heap) = o(log(n)):
  * with a operation of bubble up
  * [code]()
* Deletemax (Deletemin) : O(log(n))
  * with a operation of bubble down
  * [code]()
* Building a heap:
  * Use bubble down operatrion
  * A careful analysis yields a worst-case complexity of Θ(n)
  * A heap can be build in linear time
* Heap sort:
  * [code]()

Tree
----
### Binary Search Tree
* Defination:
  * A Binary tree is either:
    1. empty or
    2. consistes of three parts: a node and two binary tree(left sub-tree and right-tree)
  * Terminology:
    * root, leaf, parent, child, level, sibling, ancestor, descendant, etc..
* Ordering:
  * Every key in the left is less than the root key
  * Every key in the right is larger than the root key
* Operations:
  * Search(k): 
    * Compare k to current node, stop if found, else recurse on subtree unless it’s empty
    * Running time: Θ(Height)
  * Insert(k):
    * Search for k first, then insert (k,val).
    * Running time: Θ(Height)
  * Delete(k):
    * Search for k, if node is a leaf, just delete it; if node has one child, move child up; Else swap with successor or predecessor node and than delete.
    * Running time: Θ(Height)
* Height of Binary Search tree:
  * Worst-case: n - 1 = Θ(n)
  * Best-case: floor(lg(n)) = Θ(log(n))
  * Average-case: Θ(log(n))

### AVL Tree
* **Defination** An AVl Tree is a binary search tree with additional structual property:
 * The height of the left and right subtree differ at most 1
 * The height of empty tree is defined as -1
 * **Balance Factor** At each non-empty node, we store height(R) -height(L)(-1,0,1):
  * -1 : left is heavy
  * 0 : balanced
  * 1 : right is heavy
* **Fix** (rebalancing):
 * T.balance = -2:
  * if t.left.balance = 1, double right rotation
  * else, right rotation
 * T.balance = 2:
  * if t.right.balance = 1, double left rotation
  * else, left rotation
* **Opeartion**:
 * Search: like BST, Θ(height) = Θ(log(n))
 * Insert: Θ(height) and fix will be called at most onece
 * Delete: Θ(height)
* **Height** : Θ(height)
* [code]()

### 2-3 Tree
* **Defination**: A 2-3 Tree is like a BST with additional structual properties:
 * Every node either contains one KVP and two children or two KVPs and three children.
 * All the leaves are at the **same level**.
* **Operation**:
 * **Search**:
  * If root has 1 node: Same like BST , Θ(log(n))
  * If root has 2 nodes: we must examine both keys and follow the appropriate path.
 * **Insert** Θ(log(n)):
  * If the leaf has only 1 KVP, just add the new one to make a 2-node.
  * Otherwise, order the three keys as a < b < c. Split the leaf into two 1-nodes, containing a and c, and (recursively) insert b into the parent along with the new link
 * **Delete** Θ(log(n)) (delete KVP x form a node V) :
  * if V is a 2-node, just delete x;
  * if V has a immediate sibling U, perfrom a transfer
  * Otherwise, merge V and a 1-node sibling U.
* [code]()

### B-Tree
* **Defination**:
 * A B-tree of minsize d is a search tree satisfying:
  * Each node contains at most 2d KVPs. Each non-root node contains at least d KVPs.
  * All the leaves are at the same level
* **Height** of a B-tree is Θ (log n)/(log d).
* Cost of search, insert, delete is = O(log n);
 
Multi-Dimensional Data
----------------------
### Quad-Tree
Suppose we have n points P = {(x0, y0), (x1, y1), · · · , (xn−1, yn−1)} in the plane
* **Build** a quad-tree:
 1. Find square R that contains all points of P.
 2. Root of quadtree corresponds to R
 3. **Split**: Partition R into four equal subsquares, each is a child of R.
 4. Recursively repeat this process for any node that containts more than one point
 5. Each leaf stores one point
* **Spread factor** of points P:β(P) = dmax/dmin:
 * dmax(dmin): maximum (minimum) distance between two points in P
* **Height** of quadtree: h ∈ Θ(log dmax/dmin)
* Worst-case complexity to build initial tree = Θ(#nodes) = Θ(nh)
* Worst-case complexity of range search = O(#nodes) = O(nh)
* [code]()
* 

### kd-tree
Suppose we have n points P = {(x0, y0), (x1, y1), · · · , (xn−1, yn−1)} in the plane
* **Build** a kd-tree on P:
 1. Split P into two equal subsets using vertical line
 2. Split each of the two subsets into two equal pieces using horizontal lines
 3. Continue until every point is in a separate region
* **Complexity** of build a ke-tree: Θ(n log n)
* **Height** of kd-tree : Θ(log n)
* **Complexity of Range Search**:
 * O(k + U) where k is number of keys reported and U is number of regions we go to but unsuccessfully, It solves to O（k + √n)
* Storge: O(n)
* Construction Time: O(nlog(n))
* Range Query Time: O( n^(1- 1/d) + k)
* 

### Range Tree
**Range Tree** for two dimention
* **Search**: O(k + log^2 n)
* Construction Time: O(n log n)
* pace Usage: O(n log n)
**Range Tree** for n dimention
* **Storge**: O(n (log n)^(d−1))
* Construction time: O(n (log n)^(d−1))
* Range query time: O((log n)^d + k)
*

### Trie
* A dictonary for binary string
* Structure of tire:
 * Item(keys) are stored only in the leaf nodes
 * A left child corresponds to a 0 bits
 * A right child corresponds to a 1 bit
* **prefix-free**: no key is a prefix of a another key
* Time Complexity of all operations (Search, Insert, Delete) is Θ(|x|), where x is length of binary string.
* [code]()
* 











