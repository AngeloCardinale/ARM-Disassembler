#pragma once
#include <string>

#include "../condition_codes.cc"
#include "../registers.cc"
#include "../utils.cc"

std::string handle_block_data_transfer(uint32_t instruction) {
    /*
        cond    = 31 - 28       condition code
        100     = 27 - 25       identifier
        P       = 24            Pr/Post Indexing bit
        U       = 23            Up/Down bit
        S       = 22            PSR & Force user bit
        W       = 21            Write-back bit
        L       = 20            Load/Store bit
        Rn      = 19 - 16       Base Register
        Register List = 15 - 0  Register List

        <LDM|STM>{cond}<FD|ED|FA|EA|IA|IB|DA|DB> Rn{!},<Rlist>{^}
    */

    std::string cond = get_condition_code(instruction);
    std::string instruction_text;

    uint32_t P = (instruction >> 24) & 0x1U;
    uint32_t U = (instruction >> 23) & 0x1U;
    uint32_t S = (instruction >> 22) & 0x1U;
    uint32_t W = (instruction >> 21) & 0x1U;
    uint32_t L = (instruction >> 20) & 0x1U;
    uint32_t Rn = (instruction >> 16) & 0xFU;
    uint32_t Register_List = instruction & 0xFFFFU;
    std::string W_flag = (W == 0x1U) ? "!" : "";
    std::string S_flag = (S == 0x1U) ? "^" : "";
    std::string Rlist;

    int count = 0;
    for (int i = 0; i < 16; i++) {
        if((Register_List >> i) & 0x1U == 0x1U) {
            if(count == 0) {
                Rlist = Rlist + get_register(i);
            }
            else {
                Rlist = Rlist + "," + get_register(i);
            }
            count++;
        } 
    }
    
    if(L == 0x1U) {
        if(P == 0x1U) {
            if(U == 0x1U) {
                if(get_register(Rn) == "SP") {
                    instruction_text = "LDM" + cond + "ED " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                }
                else {
                    instruction_text = "LDM" + cond + "IB " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                }
            }
            else {
                if(get_register(Rn) == "SP") {
                    instruction_text = "LDM" + cond + + "EA " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                }
                else {
                    instruction_text = "LDM" + cond + + "DB " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                } 
            } 
        }
        else {
            if(U == 0x1U) {
                if(get_register(Rn) == "SP") {
                    instruction_text = "LDM" + cond + + "FD " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                }
                else {
                    instruction_text = "LDM" + cond + + "IA " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                }
            }
            else {
                if(get_register(Rn) == "SP") {
                    instruction_text = "LDM" + cond + + "FA " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                }
                else {
                    instruction_text = "LDM" + cond + + "DA " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                } 
            } 
        }
    }
    else {
        if(P == 0x1U) {
            if(U == 0x1U) {
                if(get_register(Rn) == "SP") {
                    instruction_text = "STM" + cond + "FA " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                }
                else {
                    instruction_text = "STM" + cond + "IB " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                }
            }
            else {
                if(get_register(Rn) == "SP") {
                    instruction_text = "STM" + cond + "FD " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                }
                else {
                    instruction_text = "STM" + cond + "DB " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                } 
            } 
        }
        else {
            if(U == 0x1U) {
                if(get_register(Rn) == "SP") {
                    instruction_text = "STM" + cond + "EA " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                }
                else {
                    instruction_text = "STM" + cond + "IA " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                }
            }
            else {
                if(get_register(Rn) == "SP") {
                    instruction_text = "STM" + cond + "ED " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                }
                else {
                    instruction_text = "STM" + cond + "DA " + get_register(Rn) + W_flag + ",{" + Rlist + "}" + S_flag;
                } 
            } 
        }
    }

    return instruction_text;
}