For which of the following data structures does the Find function require no worse than
O(log n) running time?
(a) Binary Search Tree (worst case analysis)
(b) Heap (worst case analysis)
(c) Hashing (under simple uniform hashing assumption, and with an ideal hash function)
(d) Two or more of the structures in (a) through (d) require no worse than O(log n) running
time.
(e) Find does not run in time O(log n) for any of these structures.
The correct answer for this problem is (c), since, under the described conditions, hashing
provides O(1)-time find. BUT, we did not emphasize the fact that if a function f(n) is
O(g(n)), and g(n) is O(h(n)), then f(n) is O(h(n)), so we also counted (e) as a correct
response.
