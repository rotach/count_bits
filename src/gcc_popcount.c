#include <stdio.h>
#include "count_bits.h"


int main(void) {
	printf("%04X has %d bits set.\n", INPUT_SAMPLE, __builtin_popcount(INPUT_SAMPLE));
	return 0;
}
