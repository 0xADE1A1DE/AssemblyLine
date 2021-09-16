# How to add new instructions

1. Get the instruction opcode layout and operand encoding format (please refer to the [intel manual](https://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-instruction-set-reference-manual-325383.pdf)).
1. Add the new instruction to the asm\_instr enumerator set found in the [/src/enums.h](https://github.com/0xADE1A1DE/AssemblyLine/tree/main/src/enums.h).
1. Add a new entry to INSTR\_TABLE[] [/src/instructions.h](https://github.com/0xADE1A1DE/AssemblyLine/tree/main/src/enums.h) while maintaining alphabetical order  

#### Instruction table format: 
```c
struct INSTR_TABLE[] {
  
  /* null-terminated string representation of an instruction ex: "mov"
   * subsequent instructions of the same name with a different operand
   * encoding will be placed contiguously with the first instance of the
   * instuction and will have the '\0' string
   */
  char instr_name[MAX_INSTR_LEN];

  // asm_instr enumerator for uniquely identifying a instruction
  int name;

  /* contains the valid operand formats for an instruction that maps
   * to the same operand enccoding (at most 2 for a single operand encoding)
   * ex: rr (instr reg,reg) && rm (instr reg, [mem]) -> RM
   */
  int opd_format[VALID_OPERAND_FORMATS];

  /* operand encoding format as an enumerator (determines how instruction
   * operands will be encoded) in assemblyline the 'I' character op/en will be
   * ignored unless it is standalone ex: MI -> M , RMI -> RM , I -> I
   */
  operand_encoding encode_operand;

  /* enumerator for defining the semantic type of an instruction
   * where special encoding is required ( currently, only applicable for 
   * SHIFT, DATA_TRANSFER, and CONTROLFLOW type instructions) 
   * else set this to 'OTHER'
   */
  instr_type type;

  /* 'i' index of opcode[i] when a byte changes in the opcode depending
   * on the register size for the instruction
   * (set this value to NA if not applicable to the instruction)
   */
  int op_offset_i;

  /* 'i' index of opcode[i] when an offset is present for a REG value denoted as
   * '+ rd' in the intel manual section 3.1.1.1 
   * (set this value to NA if not applicable to the instruction)
   */
  int rd_offset_i;

  /* used for instructions with a single register operand denoted as '/digit'
   * in the intel manual section 3.1.1.1
   * (set this value to NA if not applicable to the instruction)
   */
  int single_reg_r;

  // number of bytes in the opcode[MAX_OPCODE_LEN] field
  int instr_size;

  /* displacement for the W0 prefix (following byte after the vector extension prefix VEX)
   * check intel manual section 3.1.1.2
   * (set this value to NA if not applicable to the instruction)
   */
  int w0_disp;

  /* opcode layout for an instruction ex: {REX,0x0f,0xa9,REG}
   * REX and REG are placeholders for the prefix and register values
   * more can be found in enums.h op_encoding
   */
  unsigned int opcode[MAX_OPCODE_LEN];                 
}
```