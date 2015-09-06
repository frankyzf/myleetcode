#inlcude "common.h"

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        int k = (m+n)/2;
        if((m+n)%2)
        {
            return findK(A, m, B, n, k + 1);
        }
        else
        {
            return (findK(A,m, B, n, k) + findK(A,m,B,n,k+1))/2;
        }
    }
    double findK(int A[], int m, int B[], int n, int k)
    {
        //cout << A[0] << ", " << m << ", " << B[0] << ", " << n << ", " << k <<endl;
        if (m > n )
            return findK(B, n, A, m, k);
        else if (m == 0)
            return B[k-1];
        else if (k == 1)
            return A[0] <= B[0]? A[0] : B[0];
        else
        {
            int m2 = std::min(m, k/2);
            int n2 = k - m2;
            if(A[m2-1] < B[n2-1])
                return findK(A+m2, m-m2, B, n, k-m2);
            else if( A[m2 -1 ] > B[n2 -1])
                return findK(A, m, B+n2, n-n2, k-n2);
            else
                return A[m2-1];
        }
    }
};

int main() {


    return 1;
}