#include <stdio.h>

/*Method 1: Recursive implementation

F_recursive: This function implements the recurrence relation using a simple recursive approach.
The function checks the base cases for n equal to 0, 1, or 2, and returns the corresponding value.
For other values of n, the function calls itself recursively with arguments n-3 and n-2 and returns their
sum.

*/
int F_recursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return F_recursive(n-3) + F_recursive(n-2);
}

/* Method 2: Iterative implementation

F_iterative: This function implements the recurrence relation using an iterative approach.
The function checks the base cases for n equal to 0, 1, or 2, and returns the corresponding value.
For other values of n, the function uses an array f to store the values of the recurrence relation and 
uses a loop to calculate these values iteratively up to n. The function then returns the value of f[n].

*/
int F_iterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    int f[n+1];
    f[0] = 0; f[1] = 1; f[2] = 2;
    
    for (int i=3; i<=n; i++) {
        f[i] = f[i-3] + f[i-2];
    }
    
    return f[n];
}

/*
Method 3: Dynamic Programming implementation

F_dp: This function implements the recurrence relation using a Dynamic Programming approach. 
The function checks the base cases for n equal to 0, 1, or 2, and returns the corresponding value.
For other values of n, the function uses four variables (a, b, c, and d) to store the last three values of 
the recurrence relation and their sum, respectively. The function uses a loop to update these variables
iteratively up to n. The function then returns the value of d.

*/
int F_dp(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    int a = 0, b = 1, c = 2, d;
    
    for (int i=3; i<=n; i++) {
        d = a + b;
        a = b;
        b = c;
        c = d;
    }
    
    return d;
}

int main() {
    int n = 10;
    
    printf("Recursive: %d\n", F_recursive(n));
    printf("Iterative: %d\n", F_iterative(n));
    printf("Dynamic Programming: %d\n", F_dp(n));
    
    return 0;
}

/*
The main differences between these three implementations are their time and space complexity:

-> The recursive implementation has exponential time complexity, as it recalculates the same values multiple
times. This makes it very slow for large values of n. However, it has constant space complexity,
as it does not use any additional memory apart from the stack space used by the recursive calls.

-> The iterative implementation has linear time complexity, as it calculates each value of the recurrence
relation once. This makes it much faster than the recursive implementation for large values of n.
However, it has linear space complexity, as it uses an array of size n+1 to store all values of the
recurrence relation.

-> The Dynamic Programming implementation also has linear time complexity, as it calculates each value
of the recurrence relation once. This makes it as fast as the iterative implementation for large values
of n. However, it has constant space complexity, as it only uses four variables to store the last three
values of the recurrence relation and their sum.

*/