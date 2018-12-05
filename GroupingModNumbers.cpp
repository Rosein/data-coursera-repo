// https://practice.geeksforgeeks.org/problems/grouping-of-numbers/0
#include<iostream>
#define MAX( a, b ) ( ( a ) > ( b )  ? ( a ) : ( b ) )
void countPowerBiggestModGroup()
{
    int N, K,*seq, *countResidue, broker, power;
    std::cin >> N >> K;
    countResidue = new int [ K ];
    for( int i = 0; i < K; i++ )
        countResidue [ i ] = 0;
    for( int i = 0; i < N; i++ )
    {
        std::cin >> broker;
        ++( countResidue [ broker % K ] );
    }
    power = 0;
    if( countResidue[ 0 ] > 0 ) power++; // We add just one, cause on the other hand we could have a sum of pair of divisible numbers by K
    if( K % 2 == 0 && countResidue[ K / 2 ] > 0 ) power++;

    // The only way to have a pair which sum is divisible by K is to add two numbers which sum of residues is divisible by K
    // Upper observation let us to count power of subset which sum of any two elements aren't divisible by K.
    for( int i = 1, j = K - 1; i < j; i++, j-- )
            power += ( MAX( countResidue[ i ], countResidue[ j ] ) );
    std::cout << power << std::endl;
    delete [] countResidue;

}
int main()
{
    int times;
    for( std::cin >> times; times > 0; times-- )
        countPowerBiggestModGroup();
    return 0;
}
