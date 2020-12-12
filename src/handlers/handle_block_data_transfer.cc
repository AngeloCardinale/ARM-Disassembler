#include <string>

#include "../condition_codes.cc"
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

    uint32_t P = (instruction >> 24) & 0x1U;
    uint32_t U = (instruction >> 23) & 0x1U;
    uint32_t S = (instruction >> 22) & 0x1U;
    uint32_t W = (instruction >> 21) & 0x1U;
    uint32_t L = (instruction >> 20) & 0x1U;
    uint32_t Rn = (instruction >> 16) & 0xFU;
    uint32_t Register_List = instruction & 0xFFFFU;

    std::string instruction_text;

    if(L) {
        instruction_text = "LDM" + cond;
    }
    else {
        instruction_text = "STM" + cond;
    }

    return instruction_text;
}