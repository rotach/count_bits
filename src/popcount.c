#include <stdio.h>
#include "count_bits.h"
#include <math.h>

int main(void) {
  int i = 0;

  unsigned int masks[4];
  masks[0] = 0x5555;
  masks[1] = 0x3333;
  masks[2] = 0x0F0F;
  masks[3] = 0x00FF;

  unsigned int running_sum = INPUT_SAMPLE;
  unsigned int x1 = 0;
  unsigned int x2 = 0;

  for(i=0; i<4; i++) {
    x1 = running_sum & masks[i];
    x2 = (running_sum >> (unsigned int)pow(2, i)) & masks[i];
    running_sum = x1 + x2;
    //printf("%d %04X %04X %04X\n", (unsigned int)pow(2, i), x1, x2, running_sum);
  }

  printf("%04X has %d bits set.\n", INPUT_SAMPLE, running_sum);

	return 0;
}
