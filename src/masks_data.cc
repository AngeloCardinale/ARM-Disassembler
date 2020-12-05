#ifndef MASKS_DATA
#define MASKS_DATA

#include <stdint.h>

const int length = 32;
signed char *data_processing_mask{ new signed char[length]{-1,-1,-1,-1,  0,0,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1} };
signed char *multiply_mask{ new signed char[length]{-1,-1,-1,-1,  0,0,0,0,  0,0,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  1,0,0,1,  -1,-1,-1,-1} };
signed char *multiply_long_mask{ new signed char[length]{-1,-1,-1,-1,  0,0,0,0,  1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  1,0,0,1,  -1,-1,-1,-1} };
signed char *single_data_swap_mask{ new signed char[length]{-1,-1,-1,-1,  0,0,0,1,  0,-1,0,0,  -1,-1,-1,-1,  -1,-1,-1,-1,  0,0,0,0,  1,0,0,1,  -1,-1,-1,-1} };

#endif