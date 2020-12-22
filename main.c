#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stock.h"
#include "stock.c"

void test_initialise(){
    TradingQ q = initialise_q();
    assert(q!=NULL);
    Transaction trans = initialise_transaction();
    assert(trans!=NULL);
}

int main()
{
    test_initialise();
    return 0;
}
