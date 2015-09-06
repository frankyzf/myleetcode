#include "common.h"

class Solution {
public:
    int maxSubArray(int A[], int n) {
        return rangeMaxSub(A, 0, n-1);
    }

    int rangeMaxSub(int A[], int start, int end)
    {
        if (start == end)
            return A[start];
        else
        {
            int mid = (start+end)/2;
            int leftmax = INT_MIN;
            int rightmax= INT_MIN;
            int pointmax = INT_MIN;
            if(mid > start)
                leftmax = rangeMaxSub(A, start, mid-1);
            if(mid < end)
                rightmax = rangeMaxSub(A, mid+1, end);
            pointmax = pointMaxSub(A, mid, start, end);
            int max = leftmax>rightmax?leftmax:rightmax;
            max = max>pointmax?max:pointmax;


            return max;
        }
    }
    int pointMaxSub(int A[], int index, int start, int end)
    {
        int leftmax = 0;
        int rightmax = 0;
        int val = leftmax;
        for(int i = index -1; i >= start; i--)
        {
            val += A[i];
            if(val > leftmax)
                leftmax = val;
        }

        val = rightmax;
        for(int i = index+1; i<=end; i++)
        {
            val += A[i];
            if(val > rightmax)
                rightmax = val;
        }
        return A[index] + leftmax + rightmax;
    }
};


int main() {

    return 1;
}