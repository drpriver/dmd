// https://github.com/dlang/dmd/issues/21266
// Tests that C inline functions got inlined into this module.
import imports.imp21266;
void main(){
    int x = 0;
    a(&x);
    assert(x == 1);
    b(&x);
    assert(x == 2);
    c(&x);
    assert(x == 3);
    d(&x);
    assert(x == 4);
}
