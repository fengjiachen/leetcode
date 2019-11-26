// Find the total area covered by two rectilinear rectangles in a 2D plane.

// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
#include <iostream>
using namespace std;
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int repeatX = 0;
    if (A <= E && E <= C)
    {
        repeatX = min(C, G) - E;
    }
    else if (E <= A && A <= G)
    {
        repeatX = min(C, G) - A;
    }
    else
    {
        repeatX = 0;
    }
    int repeatY = 0;
    if (B <= F && F <= D)
    {
        repeatY = min(D, H) - F;
    }
    else if (F <= B && B <= H)
    {
        repeatY = min(D, H) - B;
    }
    else
    {
        repeatY = 0;
    }
    int aera1 = (C - A) * (D - B);
    int aera2 = (G - E) * (H - F);
    int aera3 = repeatX * repeatY;
    return aera1 - aera3 + aera2;
}
int main()
{
    int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
    cout << computeArea(A, B, C, D, E, F, G, H) << endl;
    return 0;
}