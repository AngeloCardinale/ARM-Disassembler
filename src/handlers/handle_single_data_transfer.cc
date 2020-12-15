#pragma once
#include <string>

#include "../condition_codes.cc"
#include "../registers.cc"
#include "../shift.cc"
#include "../utils.cc"

std::string get_shift(uint32_t I, uint32_t offset, uint32_t Rm, std::string pos_neg) {
    std::string output;
    if (I) { // shift and Rm
        output = pos_neg + get_register(Rm) + "," + shift(offset);
    } else { // Immediate offset
        output = "#" + std::to_string(offset);
    }
    
    return output;
}

std::string handle_single_data_transfer(uint32_t instruction) {
   
    /*
        cond        = 31 - 28   condition code
        01          = 27 - 26   identifier
        I           = 25        Immediate Offset
        P           = 24        Pre/Post indexing bit
        U           = 23        Up/Down bit
        B           = 22        Byte/Word bit
        W           = 21        Write Back bit
        L           = 20        Load/Store bit
        Rn          = 19 - 16   Base register
        Rd          = 15 - 12   Source/Destination register
        Offset      = 11 - 0    Offset

        <LDR|STR>{cond}{B}{T} Rd,<Address>
        where:
            B           = if B is present, byte transfer, else word transfer
            T           = if T is present the W bit will be set in a post-indexed instruction, forcing
                            non-privleged mode for the transfer cycle. T is not allowed when a pre-indexed
                            addressing mode is specified or implied
            Rd          = expression evaluating to a valid register number
            Rn, Rm      = expressions evaluating to valid register numbers
            <Address>   = A pre-indexed addressing specification
                            [Rn]                        offset of 0
                            [Rn, <#expression>]{!}      offset of <expression> bytes
                            [Rn,{+/-}Rm{,<shift>}]{!}   offset of +/- contents of index register shifted by <shift>
                          A post indexed addressing specification
                            [Rn],<#expression>          offset of <expression> bytes
                            [Rn],{+/-}Rm{,<shift>}      offset of +/- contents of index register, shifted by <shift>
            <shift>     = A general shift operation
            {!}         = writed back the base register (set the W bit) if ! is present

            STR R1,[R2,R4]!
            LDR R1,[R2,R3,LSL#2]
    */
    
    std::string cond = get_condition_code(instruction);
    uint32_t I = (instruction >> 25) & 0x1U;
    uint32_t P = (instruction >> 24) & 0x1U;
    uint32_t U = (instruction >> 23) & 0x1U;
    uint32_t B = (instruction >> 22) & 0x1U;
    uint32_t W = (instruction >> 21) & 0x1U;
    uint32_t L = (instruction >> 20) & 0x1U;
    uint32_t Rn = (instruction >> 16) & 0xFU;
    uint32_t Rd = (instruction >> 12) & 0xFU;
    uint32_t shift = (instruction >> 4) & 0xFFU;
    uint32_t Rm = (instruction) & 0xFU;
    uint32_t offset = (instruction) & 0xFFFU;

    std::string instruction_text;
    std::string exclamation = (W == 0x1U) ? "!" : "";
    std::string pos_neg = (U == 0x1U) ? "" : "-";
    std::string B_flag = (B == 0x1U) ? "B" : "";
    std::string shift_text = get_shift(I, offset, Rm, pos_neg);
    std::string address;
    if (P) { // pre indexed
        if (offset == 0x0U) {
            address = "[" + get_register(Rn) + "]"; // TODO
        } else {
            address = "[" + get_register(Rn) + "," + shift_text; // TODO
        }
    }
    else {  // post indexed
        if (offset == 0x0U) {
            address = "[" + get_register(Rn) + "]";
        } else {
            address = "[" + get_register(Rn) + "]," + shift_text;
        }
    }


    if (L) { // load
        instruction_text = "LDR" + cond + B_flag + get_register(Rd) + address;
    } 
    else {  // store
        instruction_text = "STR" + cond + B_flag + get_register(Rd) + address;
    }

    return instruction_text;
}