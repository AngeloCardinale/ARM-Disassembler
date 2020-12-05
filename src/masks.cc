#ifndef MASKS
#define MASKS

#if 0
    #include <iostream>
#endif

#include <unordered_map>

#include "bitmap.cc"
#include "masks_data.cc"
#include "instruction_types.cc"

ARMBitmap data_proc(data_processing_mask);
ARMBitmap mul(multiply_mask);
ARMBitmap mul_long(multiply_long_mask);
ARMBitmap s_dat_swap(single_data_swap_mask);

std::unordered_map<arm_instruction_types, ARMBitmap> arm_bitmasks ({  // c++ 17
    { data_processing,         data_proc },
    { multiply,                mul },
    { multiply_long,           mul_long },
    { single_data_swap,        s_dat_swap },
});

struct labeled_bitmask {
    arm_instruction_types label;
    ARMBitmap bitmap;
};

#if 0
    int main() {
        for (const auto& [k, v] : arm_bitmasks) {
            std::cout << k <<  std::endl;
        }
        return 0;
    }
#endif

#endif