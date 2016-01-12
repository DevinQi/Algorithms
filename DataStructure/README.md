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













