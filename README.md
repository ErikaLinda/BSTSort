# Binary Search Tree and Binary Search Tree Sort

This is an original BSTSort and BST implementation for Data Structures course in Spring 2016 taught by Prof. Christina Pöpper. Developed together with Quan Wong. It was a two part assignmnet, first to implement BST as a data structure and then BSTSort algorithm.

## Original assignment brief

You have already implemented a Binary Search Tree class in the previous assignment. Use
that to implement the BST Sort algorithm in C++.
The program should first input *n*, the number of numbers to sort, and then input *n* integers
from the user. It should then produce a random permutation of the *n* numbers and insert
them in a Binary Search Tree in the order given by the permutation. Finally it should output
the numbers in sorted order using an printInorder function that you should add to the BST
class that you had implemented.

To produce a random permutation use the rand function in the library *cstdlib* (see http://www.cplusplus.com/reference/cstdlib/rand/). We suggest that you write a function
like:
```
void randomPermutation(int *a, int n){
...
}
```

which takes the pointer to the first element in the array where the *n* numbers are stored
and the value of *n*, and randomly permutes the n numbers in the array. Each of the *n!*
permutations should be equally likely. Your functions should make only *O(n)* calls to the
rand function and should take only *O(n)* time ignoring the calls to the rand function.

## Implementation

The algorithm is implemented according to instructions and it was tested for arrays of different
sizes including 0, 1, 5 and 15. It does not crash, and always returns permutation of the user’s
input, and then the sorted output via *printInorder()*. Function randomPermutation is of time
*O(n)* since swap is of order *O(1)* and is called n times. Also rand is called only *O(n)* times as
required.
Example:

```bash
Enter the number of integer s to be sor ted :
7
Enter an i n t e g e r :
89
Enter an i n t e g e r :
5
Enter an i n t e g e r :
􀀀8
Enter an i n t e g e r :
0
Enter an i n t e g e r :
11
Enter an i n t e g e r :
11
Enter an i n t e g e r :
6
Permutation of the i npu t : 5 0 􀀀8 89 11 11 6
11 i s al ready i n the t ree .
Sorted output : 􀀀8 0 5 6 11 89
```

In addition, the BST implementation was fixed since last submission, which stopped working
if user requested to remove the root-value of the tree. Now it has been fixed and tested for
different cases: root with no children, root with only right sub-tree, root with only left sub-tree,
and root with both sub-trees. In all cases the program performed as desired.
