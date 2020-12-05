#ifndef MASKS_DATA
#define MASKS_DATA

#include <stdint.h>

const int length = 32;
int8_t *data_processing_mask{ new int8_t[length]{-1,-1,-1,-1,  0,0,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1} };
int8_t *multiply_mask{ new int8_t[length]{-1,-1,-1,-1,  0,0,0,0,  0,0,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  1,0,0,1,  -1,-1,-1,-1} };
int8_t *multiply_long_mask{ new int8_t[length]{-1,-1,-1,-1,  0,0,0,0,  1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  1,0,0,1,  -1,-1,-1,-1} };
int8_t *single_data_swap_mask{ new int8_t[length]{-1,-1,-1,-1,  0,0,0,1,  0,-1,0,0  -1,-1,-1,-1,  -1,-1,-1,-1,  0,0,0,0,  1,0,0,1  -1,-1,-1,-1} };

#endif