#include <string>

#include "../condition_codes.cc"
#include "../utils.cc"
#include "../registers.cc"

std::string handle_single_data_swap(uint32_t instruction) {
    
    /*
        condition   = 31 - 28  condition field
        00010       = 27 - 23  Identifier
        B           = 22       Byte/Word bit
        00          = 21 - 20  Identifier
        Rn          = 19 - 16  Base register
        Rd          = 15 - 12  Destination Register
        0000        = 11 - 8   Identifier
        1001        =  7 - 4   Identifier
        Rm          = 3 - 0    Source Register

        {B}         = if B is present then Byte transfer, otherwise word transfer
        Rd,Rm,Rn    = are expressions evaluating to valid register numbers
        

        <SWP>{cond}{B} Rd,Rm,[Rn]

    */
    
    std::string cond = get_condition_code(instruction);
    
    uint32_t B = (instruction >> 22) & 0x1U;     // Byte / Word bit 0 = Swap word quantity, 1 = Swap byte quantity
    uint32_t Rn = (instruction >> 16) & 0xFU;    // Base register
    uint32_t Rd = (instruction >> 12) & 0xFU;    // Destination Register
    uint32_t Rm = instruction & 0xFU;            // Source Register

    std::string instruction_text;
    if (B == 1)
    {
         std:: string instruction_text = "SWP" + cond + "B " +  get_register(Rd) + "," + get_register(Rm) + ",[" + get_register(Rn)+ "]";
    }
    else
    {
         std:: string instruction_text = "SWP" + cond + ' ' +  get_register(Rd) + "," + get_register(Rm) + ",[" + get_register(Rn)+ "]";
    }
   
  return instruction_text;
    
    
}