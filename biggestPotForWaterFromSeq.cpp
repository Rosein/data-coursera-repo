// source of task : https://practice.geeksforgeeks.org/problems/container-with-most-water/0
#include<iostream>
#include<array>
#include<cassert>
#define MIN( a, b ) ( ( a ) < ( b )  ? ( a ) : ( b ) )

void calculateBiggestPotArea()
{
    int maxArea = 0;
    int N;
    std::cin >> N;
    int * seq = new int [ N ];
    if( seq == NULL )
        throw;
    for( int i = 0; i < N; i++ )
        std::cin >> seq [ i ];

    for( int i = 0; i < N - 1; i++ )
        for( int j = i + 1; j < N; j++ )
        {
            int potentialMaxArea = ( j - i ) * MIN( seq [ i ], seq [ j ] );
            if( maxArea < potentialMaxArea )
                maxArea = potentialMaxArea;
        }
    std::cout << maxArea << std::endl;
    delete [] seq;
}
int main ()
{
    int times;
    for( std::cin >> times; times > 0; times-- )
        calculateBiggestPotArea();
    return 0;
}
