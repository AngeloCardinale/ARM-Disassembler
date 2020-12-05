#ifndef BITMAP
#define BITMAP

#include <iostream>
#include <memory.h>
#include <stdint.h>
#include <utility>

class Bitmap {
    protected:
        uint32_t num_bits;
        int8_t* mask;
    public: 
        Bitmap(const uint32_t num_bits): 
            num_bits(num_bits), mask(new int8_t[num_bits]) {
                memset(mask, 0, num_bits*sizeof(int8_t));
            }
        Bitmap(const uint32_t num_bits, int8_t* mask): 
            num_bits(num_bits), mask(mask) {

                // this is an error check to make sure that everything is a -1, 0, 1
                for (int i = 0; i < num_bits; i++) {
                    if (mask[i] == 0 || mask[i] == -1 || mask[i] == 1) {
                        continue;
                    } else {
                        std::cout << "Invalid input bitmask\n";
                        throw;
                    }
                }
            }
        ~Bitmap() {
            delete [] mask;
        }
        Bitmap(const Bitmap& orig): num_bits(orig.num_bits), mask(new int8_t[orig.num_bits]) {
            memcpy(mask, orig.mask, orig.num_bits*sizeof(int8_t));
        }
        Bitmap(Bitmap&& orig): num_bits(orig.num_bits), mask(orig.mask) {
            orig.mask = nullptr;
        }

        Bitmap& operator =(Bitmap orig) {
            num_bits = orig.num_bits;
            std::swap(mask, orig.mask);

            return (*this);
        }

        // read only
        int8_t operator [](const int i) const {
            return this->mask[i];
        }
        // int8_t& operator [](const int i) {
        //     return this->mask[i];
        // }

        friend std::ostream& operator <<(std::ostream& s, const Bitmap& map) {
            for (uint32_t i = 0; i < map.num_bits; i++)
                s << (int)map[i];
            return s;   
        }

};

class ARMBitmap : public Bitmap {
    // if it wasn't obvious, you need to use a 32 bit mask
    public: 
        ARMBitmap(): Bitmap(32) {}
        ARMBitmap(int8_t* thirty_two_bit_mask): Bitmap(32, thirty_two_bit_mask) {}
};

#if 0
    int main() {
        ARMBitmap armbitmap;
        std::cout << (int)armbitmap[2] << std::endl;
        std::cout << armbitmap << std::endl;

        int8_t *mask{ new int8_t[32]{-1,-1,-1,-1,  0,0,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1}};
        ARMBitmap armbitmap2(mask);
        std::cout << armbitmap2 << std::endl;
        std::cout << (int)armbitmap2[4] << std::endl;
        // armbitmap2[4] = 40; // will not work, read-only
        return 0;
    }
#endif

#endif