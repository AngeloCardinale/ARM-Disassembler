#include <memory.h>
#include <utility>
#include <stdio.h>
#include <stdlib.h>

class bitmask {
    private:
        int length;
        int* mask;
    public:
        bitmask(): length(32), mask(new int[length]) {
            memset(mask, 0, length*sizeof(int));
        }
        bitmask(int* mask_values, int length): length(length), mask(new int[length]) {
            memcpy(mask, mask_values, length*sizeof(int));
        } 
        ~bitmask() {
            delete[] mask;
        }
        bitmask(const bitmask& orig): length(orig.length) {
            mask = new int[length];
            memcpy(mask, orig.mask, sizeof(int));
        }
        bitmask(bitmask&& orig): length(orig.length) {
            std::swap(mask, orig.mask);
        }
        bitmask& operator =(bitmask orig) {
            length = orig.length;
            std::swap(mask, orig.mask);
            return (*this);
        }

        int operator [](const int i) const {
            if (i < 0 || i >= length) 
                fputs("trying to access an invalid element", stderr);

            return mask[i];
        }
        int& operator [](const int i) {
            if (i < 0 || i >= length) 
                fputs("trying to access an invalid element", stderr);

            return mask[i];
        }

        int length() const {
            return length;
        }
};