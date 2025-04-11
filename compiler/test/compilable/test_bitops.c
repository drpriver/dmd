// https://github.com/dlang/dmd/issues/18216
//
// Test some of the common bitop intrinsics that other
// C compilers provide.
//
_Static_assert(__builtin_popcount(0xf) == 4, "");
_Static_assert(__builtin_popcount(0x0) == 0, "");
_Static_assert(__builtin_popcountl(0xff0ul) == 8, "");
_Static_assert(__builtin_popcountll(-1ull) == 64, "");
_Static_assert(__popcnt16(0xf) == 4, "");
_Static_assert(__popcnt(0x0) == 0, "");
_Static_assert(__popcnt(0xff0u) == 8, "");
_Static_assert(__popcnt64(-1ull) == 64, "");

_Static_assert(__builtin_clz(1u) == 31, "");
_Static_assert(__builtin_clzl(~0ul) == 0, "");
_Static_assert(__builtin_clzll(1ull<<50) == 13, "");

_Static_assert(__builtin_ctz(1u) == 0, "");
_Static_assert(__builtin_ctz(0xff81u) == 0, "");
_Static_assert(__builtin_ctz(8) == 3, "");
_Static_assert(__builtin_ctzl(1ul<<20) == 20, "");
_Static_assert(__builtin_ctzll(1ull<<50) == 50, "");

// NOTE: gnu statement-expression extension for ctfe check of these.
_Static_assert(({
    unsigned long index = 0;
    __check(_BitScanReverse(&index, 0xful));
    __check(index == 3);
    index;
})==3, "");
_Static_assert(({
    unsigned long index = 0;
    __check(_BitScanReverse64(&index, 0xffffull));
    __check(index == 15);
    index;
})==15, "");

_Static_assert(({
    unsigned long index = 0;
    __check(_BitScanForward(&index, 0x1ul<<28));
    __check(index == 28);
    index;
})==28, "");
_Static_assert(({
    unsigned long index = 0;
    __check(_BitScanForward64(&index, ~0ull));
    __check(index == 0);
    index;
})==0, "");
