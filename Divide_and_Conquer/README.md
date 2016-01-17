# Divide and Conquer

#### Counting Inversion
  * **Input**: n distinct number a1,a2,....,an
  * **Outout**: number of pairs that with i < j but ai > aj.
  * Example:

    | 3 | 9 | 2 | 4 | 6 | 1 | 7 | 8 |
    |---|---|---|---|---|---|---|---|

  There are 11 inversion pairs in this example : (3,2),(3,1),(9,2),(9,4),(9,6),(9,1),(9,7),(9,8),(2,1),(4,1),(6,1)
  * Using divide-and-conquer Algorithm:
    Try to break the problem into two halves:
    * We can count the number of inversion in the first  half as well as the second half
    * It remain to count the number of inversions with one number in the first half and the other number in the second half,these **cross** inversion pairs are easier to count,because we know their relative positions and we just need to count how many are they
    * Observe that we can determine this infomation when we merge the two sorted list as in merge sort.When we insert a number in the second half to the merged list, we know how many numbers in the first half is grater than it, as in merge sort,this can be done in O(n) time
      
    First merge

    | 3 | 9 | 2 | 4 |
    |---|---|---|---|

    | 6 | 1 | 7 | 8 |
    |---|---|---|---|

    Second merge

    | 3 | 9 |
    |---|---|

    | 2 | 4 |
    |---|---|

    | 6 | 1 |
    |---|---|

    | 7 | 8 |
    |---|---|

  * Pesudo Code:
   ```
   count(A[1,n])                                                T(n)
    if n =1,return
    count(A[1,n/2]                                              T(n/2)
    count (A[n/2+1,n])                                          T(n/2)
    sort(A[1,n/2])                                              O(nlog(n))
    sort(A[n/2+1,n])                                            O(nlog(n))
    merg-and-count-cross-inversions(A[1,n/2],A[n/2+1,n])        O(n)
  ```
  Totoal running time is T(n) = 2T(n/2) + O(nlog(n))  ===> T(n) = Θ(nlog(n))
  
  * [Code](https://github.com/DevinQi/Algorithms/blob/master/Divide_and_Conquer/Counting_inversion_pair)

### Maximum Subarray
* **input**: n number a1,......,an
* **output**: i,j such that maximizes sum(ai,aj)
* For Example:
 * Data: 1, -3 ,4 ,5 ,6 ,-20, 5, 7 ,7 ,-3, 9 ,10 ,11, -10, 3, 3
 * Optional solution: 5 ,7 ,7, -3, 9, 10 ,11.
* Algothrim:
 * Break the array into two haves, and find the maxmum subarray within each half.
 * The optional solution is either contained in the first(second) half or crross the mid point.
 * Assume [i,j] is an optional solution with i<= n/2 < j
 * Observe that [i,n/2] must be the maximum subarray ending at n/2, suppose not, the sume from [i,n/2] is even bigger than [i,j]. Contradictiong to the optimality of [i,j]. This observation leads to the following claim that leads to a simple algorithm:
  * [i,j] is an maximum subarray crossing n/2 if and only if
  * [i,n/2] is a maximum subarray ending at n/2 and
  * [n/2+1,j] is a maximum subarray starting from n/2 +1.
 * The total time complexity :
  T(n) = 2T(n/2) + O(n)   <- for maximum "crossing" subarray, and this implies that T(n) = O(nlog(n))
* [code]()















