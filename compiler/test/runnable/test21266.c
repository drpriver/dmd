// https://github.com/dlang/dmd/issues/21266
void i_do_not_exist(void);
inline void i_am_not_called(void){
    i_do_not_exist();
}

#ifndef __forceinline
#define __forceinline __attribute__((always_inline)) inline
#endif
__forceinline void i_am_also_not_called(void){
    i_do_not_exist();
}

// Weird, but allowed
__attribute__((noinline)) inline void i_am_not_called_dont_inline_me(void){
    i_do_not_exist();
}


int main(){
    return 0;
}
