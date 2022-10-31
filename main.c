#include "cipher.h"
#include "tests.h"



int main (int argc, char *argv[]) {

    if (test_decode_cyclic_upper_case_positive_k()) {
        return 0;
    }
    return 1 ;
}
