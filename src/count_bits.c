#include <stdio.h>
#include "count_bits.h"

int generate_lookup_table(void);
int count_bits(unsigned int input);

int main(void) {
	generate_lookup_table();

	printf("0x%04X has %d bits set.\n", INPUT_SAMPLE, bit_lookup[INPUT_SAMPLE]);

	return 0;
}

int generate_lookup_table(void) {
	int i;
	for(i=0; i<TABLE_CAPACITY; i++) {
		bit_lookup[i] = count_bits(i);
	}
	return 0;
}

int count_bits(unsigned int input) {
	int i;
	int num_set = 0;

	for(i=0; i<NUM_BITS; i++) {
		if ((input >> i) & 0x0001) {
			num_set++;
		}
	}
	return num_set;
}
