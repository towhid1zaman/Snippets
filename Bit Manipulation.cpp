namespace Bit_Manipulation{
    #define isOn(n, i) (n & (1 << i))
    #define setBit(n, i) (n |= (1 << i))
    #define countSetBits(n) (__builtin_popcount(n))
    #define clearBit(n, i) (n &= ~(1 << i)) // turn off i'th bit
    #define changeithBit(n, i) (n ^= (1 << i)) //toggleBit
    #define rightmost(n) (n & (-n)) //low bit
    #define setAll(n, i) (n = (1 << i) - 1)
    
    #define modulo(n, m) ((n) & (m - 1))   // returns n % m, where m is a power of 2
    #define isPowerOfTwo(n) (!(n & (n - 1)))
    #define nearestPowerOfTwo(n) ((int)pow(2.0, (int)((log((double)n) / log(2.0)) + 0.5)))
    #define turnOffLastBit(n) ((n) & (n - 1))  // turn off the last on bit
    #define turnOnLastZero(n) ((n) | (n + 1))
    #define turnOffLastConsecutiveBits(n) ((n) & (n + 1))
    #define turnOnLastConsecutiveZeroes(n) ((n) | (n - 1))
}using namespace Bit_Manipulation;
