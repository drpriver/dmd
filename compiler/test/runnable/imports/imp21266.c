// https://github.com/dlang/dmd/issues/21266

// These are called.
inline                           void a(int *x){ ++*x; };
__forceinline                    void b(int *x){ ++*x; };
__attribute__((always_inline))   void c(int *x){ ++*x; };
inline __attribute__((noinline)) void d(int *x){ ++*x; };

// These are not.
void not_exist(void);
inline void not_called(void){ not_exist(); }
__forceinline void not_called2(void){ not_exist(); }
__attribute__((noinline)) inline void not_called3(void){ not_exist(); }
