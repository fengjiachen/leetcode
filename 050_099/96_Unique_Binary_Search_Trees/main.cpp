// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

// Example:

// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include <iostream>
#include <vector>
using namespace std;
int numTrees(int n)
{
    int a[n + 1];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int j = i - 1;
        a[i] = 0;
        for (int k = 0; k <= j - k; k++)
        {
            if (k != (j - k))
            {
                a[i] += 2 * a[k] * a[j - k];
            }
            else
            {
                a[i] += a[k] * a[j - k];
            }
        }
    }
    return a[n];
}
int main()
{
    cout << numTrees(1) << endl;
    cout << numTrees(2) << endl;
    cout << numTrees(3) << endl;
    cout << numTrees(4) << endl;
    cout << numTrees(5) << endl;
    cout << numTrees(6) << endl;
}