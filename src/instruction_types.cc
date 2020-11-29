#include <unordered_map>
#include "bitmask"

enum instruction_types
{
    data_processing,
    multiply,
    multiply_long,
    single_data_swap,
    branch_and_exchange,
    hwdt_reg_offset, // halfword data transfer: register offset
    hwdt_imm_offset, // halfword data transfer: immediate offset
    single_data_transfer,
    block_data_transfer,
    branch,
    co_data_transfer,  // coprocessor data transfer
    co_data_operation, // coprocessor data operation
    co_reg_transfer,   // coprocessor register transfer
    software_interrupt,
};

    const int length = 32;
    data_processing = new bitmask(length, [-1,-1,-1,-1,  0,0,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,]);
    multiply = new bitmask(length, [-1,-1,-1,-1,  0,0,0,0  0,0,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  1,0,0,1,  -1,-1,-1,-1,]);
    multiply_long = new bitmask(length, [-1,-1,-1,-1,  0,0,0,0,  1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  -1,-1,-1,-1,  1,0,0,1,  -1,-1,-1,-1,]);
    single_data_swap = new bitmask(length, [-1,-1,-1,-1,  0,0,0,1,  0,-1,0,0  -1,-1,-1,-1,  -1,-1,-1,-1,  0,0,0,0,  1,0,0,1  -1,-1,-1,-1,]);
    branch_and_exchange = new bitmask(length, [-1,-1,-1,-1, ]);
    hwdt_reg_offset = new bitmask(length, [-1,-1,-1,-1, ]);
    hwdt_imm_offset = new bitmask(length, [-1,-1,-1,-1, ]);
    single_data_transfer = new bitmask(length, [-1,-1,-1,-1, ]);
    block_data_transfer = new bitmask(length, [-1,-1,-1,-1, ]);
    branch = new bitmask(length, [-1,-1,-1,-1, ]);
    co_data_transfer = new bitmask(length, [-1,-1,-1,-1, ]);
    co_data_operation = new bitmask(length, [-1,-1,-1,-1, ]);
    co_reg_transfer = new bitmask(length, [-1,-1,-1,-1, ]);
    software_interrupt = new bitmask(length, [-1,-1,-1,-1, ]);

std::unordered_map<instruction_types, bitmask> masks = {
    {instruction_types.data_processing, data_processing},
    {instruction_types.multiply, multiply},
    {instruction_types.multiply_long, multiply_long},
    {instruction_types.single_data_swap, single_data_swap},
    {instruction_types.branch_and_exchange, branch_and_exchange},
    {instruction_types.hwdt_reg_offset, hwdt_reg_offset},
    {instruction_types.hwdt_imm_offset, hwdt_imm_offset},
    {instruction_types.single_data_transfer, single_data_transfer},
    {instruction_types.block_data_transfer, block_data_transfer},
    {instruction_types.branch, branch},
    {instruction_types.co_data_transfer, co_data_transfer},
    {instruction_types.co_data_operation, co_data_operation},
    {instruction_types.co_reg_transfer, co_reg_transfer},
    {instruction_types.software_interrupt, software_interrupt},
};


struct labeled_bitmask {
   instruction_type label;
   bitmask mask;
};

std::list<labeled_bitmask> valid_masks;
for (auto const& [k, v] : masks) {
  valid_masks.push_back({k, v});
}

std::vector<std::string> output_text;
output_text.reserve(instructions.length());

for (int i = 0; i < instructions.length(); i++) {
  uint32_t instruction = instructions[i];
  for (int j = 31, x = 0; j >= 0; j--, x++) {
    int bit = (instruction >> j) % 2;
    std::list<labaled_bitmask>::iterator it = valid_masks.begin();
    while (it!= valid_masks.end()) {
      if ((*it).mask[x] == -1) {
        it++;
      }
      else if ((*it).mask[x] == bit) {
        it++;
      }
      else if ((*it).mask[x] != bit) {
        valid_masks.erase(it++);
      }
      else {
        fputs("something went wrong", stderr);
      }
    } 
  }

  if (valid_masks.lenth() != 1)
    fputs("something went wrong", stderr);
  std::string instruction_text = InstructionText(valid_masks[0].label, instruction).getText(); // these two lines can be one line
  output_text.push_back(instruction_text);
}

//write output text to file