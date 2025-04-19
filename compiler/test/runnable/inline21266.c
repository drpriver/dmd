int count = 0;
inline void a(void){ count++; };
__forceinline void b(void){ count++; };
__attribute__((always_inline)) void c(void){ count++; };
inline __attribute__((noinline)) void d(void){ count++; };
inline void e(void){ count++; };
inline void f(void){ count++; };
void indirect(void){ f(); }

void (*p)(void) = e;
int main(){
    a();
    b();
    c();
    d();
    p();
    indirect();
    __check(count==6);
}
