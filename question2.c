#include <stdio.h>
#include <limits.h>

// 1. Recursive Method:
// Advantages: Simple and closely follows the mathematical formulation of the problem.
// Disadvantages: Performs the same calculations multiple times, leading to inefficiency for larger inputs.
// It could also lead to stack overflow for very large inputs due to the depth of the recursion.
int F_recursive(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    
    return F_recursive(n-3) + F_recursive(n-2);
}
int memo[INT_MAX] = {-1};

// 2. Recursive Method with Memoization:
// Advantages: More efficient than simple recursion, as it avoids redundant calculations by storing previously calculated results.
// Disadvantages: Still possible to cause stack overflow for very large inputs due to the depth of recursion. 
// It uses more memory than the simple recursive method due to the additional storage for memoization.
int F_recursive_memo(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    
    if(memo[n] != -1) return memo[n];  // Return stored result
    
    return memo[n] = F_recursive_memo(n-3) + F_recursive_memo(n-2);  // Store and return result
}

// 3. Iterative Method:
// Advantages: Most efficient method, no recursion so no risk of stack overflow. Avoids redundant calculations without needing as much extra memory as the memoization method.
// Disadvantages: Slightly more complex than the recursive methods, may be less intuitive for some people, especially those more comfortable with recursion.
int F_iterative(int n) {
    int F[n+1];

    F[0] = 0;
    F[1] = 1;
    F[2] = 2;

    for(int i = 3; i <= n; i++) {
        F[i] = F[i-3] + F[i-2];
    }

    return F[n];
}

int main() {
    int n = 10;  // Test value
    
    printf("Recursive: %d\n", F_recursive(n));
    printf("Recursive with Memoization: %d\n", F_recursive_memo(n));
    printf("Iterative: %d\n", F_iterative(n));
    
    return 0;
}
