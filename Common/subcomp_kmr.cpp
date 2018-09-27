#include <bits/stdc++.h>

using namespace std;

constexpr uint32_t log2floor(uint32_t n) { return 31 - __builtin_clz(n); }

template<size_t N>
struct subcomp
{
    uint32_t A[log2floor(N) + 1][N];
    template<typename Iterator>
    subcomp(Iterator begin, Iterator end)
    {
        uint32_t n;
        for(n = 0; begin != end; n++, ++begin)
            A[0][n] = *begin;
        for(uint32_t p = 1; (1u << p) <= n; p++)
        {
            map<pair<uint32_t, uint32_t>, uint32_t> dict;
            uint32_t curr = 0;
            for(uint32_t i = 0; i <= n - (1u << p); i++)
            {
                pair<uint32_t, uint32_t>
                    key = {A[p-1][i], A[p-1][i + (1u << (p-1))]};
                auto it = dict.find(key);
                if(it == dict.end())
                    dict[key] = A[p][i] = curr++;
                else
                    A[p][i] = it->second;
            }
        }
    }
    // check if [a, a+n) is equal to [b, b+n)
    bool operator() (uint32_t a, uint32_t b, uint32_t n) const
    {
        uint32_t k = log2floor(n);
        return A[k][a] == A[k][b] and
                A[k][a + (n - (1u << k))] == A[k][b + (n - (1u << k))];
    }
};

int main()
{
    string in;
    cin >> in;
    static subcomp<1u << 10> comp(in.begin(), in.end());
    uint32_t a, b, n;
    while(cin >> a >> b >> n)
    {
        cout << comp(a, b, n) << endl;
    }
}