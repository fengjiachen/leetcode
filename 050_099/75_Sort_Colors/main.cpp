#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums)
{
    int count[3] = {};
    for (int i = 0; i < (int)nums.size();i++)
    {
        switch (nums[i])
        {
        case 0:
            count[0]++;
            break;
        case 1:
            count[1]++;
            break;
        case 2:
            count[2]++;
            break;
        default:
            break;
        }
    }
    int j = 0;
    for (int i = 0; i < 3;i++){
        while (count[i]>0)
        {
            nums[j++] = i;
            count[i]--;
        }
    }
}
int main()
{
    cout << "hello " << endl;
    int a[] = {2,0,2,1,1,0};
    vector<int> matrix(a,a+6);
    sortColors(matrix);
    for(int i=0;i<(int)matrix.size();i++)
    {
        cout<<matrix[i]<<" ";
    }
    cout<<endl;
}