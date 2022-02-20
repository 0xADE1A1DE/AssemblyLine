# How to add new instructions

1. Get the instruction opcode layout and operand encoding format (please refer to the [intel manual](https://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-instruction-set-reference-manual-325383.pdf)).
1. Add the new instruction to the asm\_instr enumerator set found in the [enums.h](/src/enums.h).
1. Add a new entry to INSTR\_TABLE[] [instructions.c](/src/instructions.c) while maintaining alphabetical order  

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

  /* contains the valid operand formats for an instruction that maps to the same operand
   * enccoding (at most 2 for a single operand encoding)
   * ex: rr (instruction reg,reg) && rm (instruction reg, [mem]) both maps to RM
   *     when both operand formats are set to NA. 
   * ex: {NA,NA}, this denotes that the instruction cannot be accessed during the
   *     parsing phase rather it could only be accessed during encoding by incrementing 
   *     the INSTR_TABLE[key] index using key++, therefore ordering is important for 
   *     this type of entry.
   */
  int opd_format[VALID_OPERAND_FORMATS];

  /* operand encoding format as an enumerator (determines how instruction
   * operands will be encoded) in assemblyline the 'I' character op/en will be
   * ignored unless it is standalone ex: MI -> M , RMI -> RM , I -> I
   */
  operand_encoding encode_operand;

  /* enumerator for defining the semantic type of an instruction
   * where special encoding is required ( currently, only applicable for 
   * SHIFT, DATA_TRANSFER, and CONTROL_FLOW type instructions) else set this to 'OTHER'
   */
  instr_type type;

  /* 'i' index of opcode[i] when a byte changes in the opcode depending
   * on the register size for the instruction
   * (set this value to NA if not applicable to the instruction)
   */
  int op_offset_i;

  /* used for instructions with a single register operand denoted as '/digit'
   * in the intel manual section 3.1.1.1
   * (set this value to NA if not applicable to the instruction)
   */
  int single_reg_r;

  // number of bytes in the opcode[MAX_OPCODE_LEN] field
  int instr_size;
  
  /* opcode layout for an instruction ex: {REX,0x0f+rd,0xa9,REG}
   * REX VEX, and REG are placeholders for prefix and register values for encoding of
   * VEX prefix please refer to the intel manual section 2.3.5 as well as common.h
   * '#define VEX(vvvv,L,pp,mmmmm,WIG)' and enums.h 'opcode_encoding'.
   * '+rd' refers to '+rb, +rw, +rd, +ro' in intel manual section 3.1.1.1
   */
  unsigned int opcode[MAX_OPCODE_LEN];                 
}
```
