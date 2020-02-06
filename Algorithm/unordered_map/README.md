```cpp
unordered_map<pair<string, int>, int> m;
```
`C2338    The C++ Standard doesn't provide a hash for this type.`
```cpp
namespace std
{
    template <typename T, typename U>
    struct hash<pair<T, U>>
    {
        size_t operator()(const pair<T, U>& p) const
        {
            size_t a = std::hash<T>()(p.first);
            size_t b = std::hash<U>()(p.second);
            a ^= b + 0x9E3779B9 + (a << 6) + (a >> 2);
            return a;
        }
    };
}
```
