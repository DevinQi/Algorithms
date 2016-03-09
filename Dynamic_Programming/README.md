# Dynamic Programming

Consider the FIbonacci sequence:
  * F(n) = F(n-1) + F(n-2)
  * F(1) = F(2) = 1    

If we solve the recurrence relation, Then the runtime of this algorithm is θ(1.618^n)  

#### Top-Down Memorization
* Like BFS/DFS, we just used an array visited[i] to make sure that we only compute each subproblem at most once
```
    int main(){  
      visited[i] = false for 1 <= i <= n  
      F(n)  
    }  
    F(n){           //recursive function    
      if visited[n] == true, return answer[n];  
      if n == 1 or n == 2, return 1 ;  
      answer[n] = F(n-1) + F(n-2);  
      visited[n] = true;  
      return answer[n];   
    }  
```
* Time Complexity: Each subproblen run once, the total running time is O(n)

#### Weighted Interval Scheduling
 * Input: n intervals [s1,f1],...,[sn,fn] with weights w1,...,wn.  
 * Output: a subset S of disjoint intercals that maximizes ∑ (wi).
 * We can this of the intervals aare requests to book our room from time si to fi, and the i-th request is willing to pay wi dollar if the request is accepted, our objective is to maximize the income, while guaranteeing that there are non time conflicts for the acepted requests
 * **Algorithm (top-down)**
  * Sorting the intervals by increasing starting time, s1 <= s2<= ....<= sn
  * Compute next[i] for 1<= i <= n, where next[i] 's start time is larger than i's finish time
  * Compute opt(1)
 ```
      opt(i){ // recursive function
       if i = n+1, return 0;    no next interval
       opt(i) = max{wi + opt(next(i), opt(i+1)}     //decide choose i or not
      }
```
  * Time Complexxity: Sorting and the next array can be computed in O(nlogn) time, and the top-down can implement as recursion in O(n) time, since there are only n subproblems and each onl needs to look up two values.
 * **Algorithm(bottom-up implementation)**
  * Its essentially an exhaustive search algorithm, but in a much more compact search space!
```
      opt(n+1) = 0
      for i from h downto 1 do{
       opt(i) = max{wi+ opt(next(i),opt(i+1)}
      }
```
