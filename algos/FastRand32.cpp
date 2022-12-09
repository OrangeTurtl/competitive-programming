#include <bits/stdc++.h>
struct FastRand32
{
    // инициализация начальным значением. На codeforces лучше инициализировать
    // std::chrono::high_resolution_clock::now().time_since_epoch().count()
    FastRand32(uint32_t seed = 666)
        : x(seed)
    { }

    // псевдо-случайное число из отрезка [a, b]
    template<typename IntegerType = int32_t>
    IntegerType operator()(IntegerType a, IntegerType b) {
        return get<IntegerType>(a, b);
    }
    
    // то же самое, но для полуинтервала [0, n)
    template<typename IntegerType = int32_t>
    IntegerType operator()(IntegerType n) {
        return get<IntegerType>(0, n-1);
    }
    
    // аналог в виде функции:
    template<typename IntegerType = int32_t>
    IntegerType get(IntegerType a, IntegerType b) {
        uint32_t number = x;
        xorshift32();
        return number % uint32_t(b - a + 1) + a;
    }
    
protected:
    void xorshift32()
    {
        /* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
    }
    
private:
    uint32_t x;
};

int32_t main() {
    FastRand32 random;
    const int n = 10, q = 10;
    for (int i = 0; i < q; i++) {
        int L = random(n);
        int R = random(n);
        if (L > R) std::swap(L, R);
        std::cout << L << " " << R << std::endl;
    }
}