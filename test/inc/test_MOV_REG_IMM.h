#define CODE                                                                                                           \
    "MOV RAX, 0x2;\n"                                                                                                  \
    "MOV RAX, 0x7F;\n"                                                                                                 \
    "MOV RAX, 0x80;\n"                                                                                                 \
    "MOV RAX, 0x80;\n"                                                                                                 \
    "MOV RAX, 0xFF;\n"                                                                                                 \
    "MOV RAX, 0x7FF;\n"                                                                                                \
    "MOV EAX, 0x2;\n"                                                                                                  \
    "MOV EAX, 0x7F;\n"                                                                                                 \
    "MOV EAX, 0x80;\n"                                                                                                 \
    "MOV EAX, 0x80;\n"                                                                                                 \
    "MOV EAX, 0xFF;\n"                                                                                                 \
    "MOV EAX, 0x7FF;\n"                                                                                                \
    "MOV RAX, 0x7FFFFFFF;\n"                                                                                           \
    "MOV RAX, 0x8FFFFFFF;\n"                                                                                           \
    "MOV RAX, 0xFFFFFFFF;\n"                                                                                           \
    "MOV RAX, 0x7FFFFFFFFF;\n"                                                                                         \
    "MOV RAX, 0xAFFFFFFFFF;\n"                                                                                         \
    "MOV RAX, 0xFFFFFFFF0000000E;\n"                                                                                   \
    "MOV RAX, 0xFF0FFFFF0000000E;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFF000000EE;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFF00000EEE;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFF000EEEEE;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFF00EEEEEE;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFF0EEEEEEE;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFFE0000000;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFFF0000001;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFF80000001;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFFE0000001;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFF72000001;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFF60100001;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFF500D0001;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFF4000D001;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFF30000D01;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFF200000D1;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFF10000001;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFF01111111;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFEF0000000;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFFEEEEEEEE;\n"                                                                                   \
    "MOV RAX, 0xFFFFFEEEEEEEEEEE;\n"                                                                                   \
    "MOV RAX, 0xFFFFF77777777777;\n"                                                                                   \
    "MOV RAX, 0xFFFFF22222222222;\n"                                                                                   \
    "MOV RAX, 0xF000000000000001;\n"                                                                                   \
    "MOV RAX, 0xFFFFFFFFFFFFFFFF;\n"                                                                                   \
    "MOV RAX, -0x1;\n"                                                                                                 \
    "MOV RAX, -0x2;\n"                                                                                                 \
    "MOV RSI, 0x2;\n"                                                                                                  \
    "MOV RSI, 0x7F;\n"                                                                                                 \
    "MOV RSI, 0x80;\n"                                                                                                 \
    "MOV RSI, 0x80;\n"                                                                                                 \
    "MOV RSI, 0xFF;\n"                                                                                                 \
    "MOV RSI, 0x7FF;\n"                                                                                                \
    "MOV ESI, 0x2;\n"                                                                                                  \
    "MOV ESI, 0x7F;\n"                                                                                                 \
    "MOV ESI, 0x80;\n"                                                                                                 \
    "MOV ESI, 0x80;\n"                                                                                                 \
    "MOV ESI, 0xFF;\n"                                                                                                 \
    "MOV ESI, 0x7FF;\n"                                                                                                \
    "MOV RSI, 0x7FFFFFFF;\n"                                                                                           \
    "MOV RSI, 0x8FFFFFFF;\n"                                                                                           \
    "MOV RSI, 0xFFFFFFFF;\n"                                                                                           \
    "MOV RSI, 0x7FFFFFFFFF;\n"                                                                                         \
    "MOV RSI, 0xAFFFFFFFFF;\n"                                                                                         \
    "MOV RSI, 0xFFFFFEEEEEEEEEEE;\n"                                                                                   \
    "MOV RSI, 0xFFFFFFFFEEEEEEEE;\n"                                                                                   \
    "MOV RSI, -0x2;\n"                                                                                                 \
    "MOV RSI, 0x2;\n"                                                                                                  \
    "MOV RSI, 0x7F;\n"                                                                                                 \
    "MOV RSI, 0x80;\n"                                                                                                 \
    "MOV RSI, 0x80;\n"                                                                                                 \
    "MOV RSI, 0xFF;\n"                                                                                                 \
    "MOV RSI, 0x7FF;\n"                                                                                                \
    "MOV ESI, 0x2;\n"                                                                                                  \
    "MOV ESI, 0x7F;\n"                                                                                                 \
    "MOV ESI, 0x80;\n"                                                                                                 \
    "MOV ESI, 0x80;\n"                                                                                                 \
    "MOV ESI, 0xFF;\n"                                                                                                 \
    "MOV ESI, 0x7FF;\n"                                                                                                \
    "MOV RSI, 0x7FFFFFFF;\n"                                                                                           \
    "MOV RSI, 0x8FFFFFFF;\n"                                                                                           \
    "MOV RSI, 0xFFFFFFFF;\n"                                                                                           \
    "MOV RSI, 0x7FFFFFFFFF;\n"                                                                                         \
    "MOV RSI, 0xAFFFFFFFFF;\n"                                                                                         \
    "MOV RSI, 0xFFFFFEEEEEEEEEEE;\n"                                                                                   \
    "MOV RSI, 0xFFFFFFFFEEEEEEEE;\n"                                                                                   \
    "MOV RSI, -0x2;\n"                                                                                                 \
    "MOV R13, 0x2;\n"                                                                                                  \
    "MOV R13, 0x7F;\n"                                                                                                 \
    "MOV R13, 0x80;\n"                                                                                                 \
    "MOV R13, 0x80;\n"                                                                                                 \
    "MOV R13, 0xFF;\n"                                                                                                 \
    "MOV R13, 0x7FF;\n"                                                                                                \
    "MOV R13D, 0x2;\n"                                                                                                 \
    "MOV R13D, 0x7F;\n"                                                                                                \
    "MOV R13D, 0x80;\n"                                                                                                \
    "MOV R13D, 0x80;\n"                                                                                                \
    "MOV R13D, 0xFF;\n"                                                                                                \
    "MOV R13D, 0x7FF;\n"                                                                                               \
    "MOV R13, 0x7FFFFFFF;\n"                                                                                           \
    "MOV R13, 0x8FFFFFFF;\n"                                                                                           \
    "MOV R13, 0xFFFFFFFF;\n"                                                                                           \
    "MOV R13, 0x7FFFFFFFFF;\n"                                                                                         \
    "MOV R13, 0xAFFFFFFFFF;\n"                                                                                         \
    "MOV R13, 0xFFFFFEEEEEEEEEEE;\n"                                                                                   \
    "MOV R13, 0xFFFFFFFFEEEEEEEE;\n"                                                                                   \
    "MOV R13, -0x2;\n"                                                                                                 \
    "MOV R15, 0x2;\n"                                                                                                  \
    "MOV R15, 0x7F;\n"                                                                                                 \
    "MOV R15, 0x80;\n"                                                                                                 \
    "MOV R15, 0x80;\n"                                                                                                 \
    "MOV R15, 0xFF;\n"                                                                                                 \
    "MOV R15, 0x7FF;\n"                                                                                                \
    "MOV R15W, 0x2;\n"                                                                                                 \
    "MOV R15W, 0x7F;\n"                                                                                                \
    "MOV R15W, 0x80;\n"                                                                                                \
    "MOV R15W, 0x80;\n"                                                                                                \
    "MOV R15W, 0xFF;\n"                                                                                                \
    "MOV R15W, 0x7FF;\n"                                                                                               \
    "MOV R15, 0x7FFFFFFF;\n"                                                                                           \
    "MOV R15, 0x8FFFFFFF;\n"                                                                                           \
    "MOV R15, 0xFFFFFFFF;\n"                                                                                           \
    "MOV R15, 0x7FFFFFFFFF;\n"                                                                                         \
    "MOV R15, 0xAFFFFFFFFF;\n"                                                                                         \
    "MOV R15, 0xFFFFFEEEEEEEEEEE;\n"                                                                                   \
    "MOV R15, 0xFFFFFFFFEEEEEEEE;\n"                                                                                   \
    "MOV R15, -0x2;\n"                                                                                                 \
    "MOV R15B, -0x2;\n"                                                                                                \
    "MOV R15B, 0x2;\n"                                                                                                 \
    "MOV R15B, 0x7F;\n"                                                                                                \
    "MOV R15B, 0x80;\n"                                                                                                \
    "MOV R15B, 0x80;\n"                                                                                                \
    "MOV R15B, 0xFF;\n"                                                                                                \
    "MOV RSI, -0x1;\n"                                                                                                 \
    "MOV RBP, -0x2EFD9F53;\n"                                                                                          \
    "MOV RBP, -0x2EFA9F53;\n"                                                                                          \
    "MOV RBP, 0x2EFA;\n"                                                                                               \
    "MOV R8, -0x2;\n"                                                                                                  \
    "MOV R9, -0x2;\n"                                                                                                  \
    "MOV R10, -0x2;\n"                                                                                                 \
    "MOV R10B, -0x2;\n"                                                                                                \
    "MOV R11B, -0x2;\n"                                                                                                \
    "MOV R12B, -0x2;\n"                                                                                                \
    "MOV AL, -0x2;\n"                                                                                                  \
    "MOV AL, -0x1;\n"                                                                                                  \
    "MOV AL, 0x1;\n"                                                                                                   \
    "MOV CL, -0x2;\n"                                                                                                  \
    "MOV CL, -0x1;\n"                                                                                                  \
    "MOV CL, 0x1;\n"                                                                                                   \
    "MOV AX, -0x2;\n"                                                                                                  \
    "MOV AX, -0x1;\n"                                                                                                  \
    "MOV AX, 0x1;\n"                                                                                                   \
    "MOV CX, -0x2EFD;\n"                                                                                               \
    "MOV CX, -0x2EFA;\n"                                                                                               \
    "MOV CX, 0x2EFA;\n"                                                                                                \
    "MOV SI, -0x2EFD;\n"                                                                                               \
    "MOV SI, -0x2EFA;\n"                                                                                               \
    "MOV SI, 0x2EFA;\n"                                                                                                \
    "MOV RCX, -0x2EFD;\n"                                                                                              \
    "MOV RCX, -0x2EFA;\n"                                                                                              \
    "MOV RCX, 0x2EFA;\n"                                                                                               \
    "MOV RSI, -0x2EFD;\n"                                                                                              \
    "MOV RSI, -0x2EFA;\n"                                                                                              \
    "MOV RSI, 0x2EFA;\n"                                                                                               \
    "MOV RCX, -0x2EFDEEEEEE;\n"                                                                                        \
    "MOV RCX, -0x2EFAEEEEEE;\n"                                                                                        \
    "MOV RCX, 0x2EFAEEEEE;\n"                                                                                          \
    "MOV RSI, -0x2EFDEEEE;\n"                                                                                          \
    "MOV RSI, -0x2EFAEEE;\n"                                                                                           \
    "MOV RSI, 0x2EFAEEEEE;\n"