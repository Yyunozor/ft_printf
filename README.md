# `ft_printf` **Roadmap**

This roadmap for the `ft_printf` project integrates advanced structuring, modularity, and an extensive focus on testing and error handling. This approach guarantees smooth mandatory and bonus implementation while complying strictly with the 42 Norm.

---

## **Directory Structure**

```
plaintext
Copy code
ft_printf_project/
├── Makefile                  ──> Builds project, manages dependencies, bonus rules
├── ft_printf.h               ──> Header with prototypes, includes, macros, and typedefs
├── libft/                    ──> Libft functions (if allowed, copied here)
│   ├── Makefile              ──> Makefile specific for libft
│   ├── ft_*.c                ──> Libft functions
│   └── libft.h               ──> Header for libft
├── src/                      ──> Main source folder for ft_printf
│   ├── ft_printf.c           ──> Core formatting and dispatching logic
│   ├── conversions/          ──> Files handling individual conversions
│   │   ├── x_char.c          ──> %c, %%
│   │   ├── x_str.c           ──> %s, NULL handling
│   │   ├── x_ptr.c           ──> %p
│   │   ├── x_int.c           ──> %d, %i
│   │   ├── x_uint.c          ──> %u
│   │   ├── x_hex.c           ──> %x, %X
│   │   └── x_mod.c           ──> %%
│   └── bonus/                ──> Folder for bonus functionality: flags, width, precision
├── obj/                      ──> Directory for compiled .o files
└── tests/                    ──> Testing folder
    ├── test_ft_printf.c      ──> Main test file for ft_printf
    └── test_cases/           ──> Structured test cases
        ├── test_mandatory.c  ──> Mandatory conversion tests
        └── test_bonus.c      ──> Bonus feature tests

```

---

## **Phase-by-Phase Guide**

### **Phase 1: Setup and Planning**

1. **Read & Analyze Requirements**:
    - Break down **mandatory** conversions: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`.
    - Understand **bonus objectives**: flags (`0`, `+`, `#`), width, and precision.
2. **Repository & Directory Structure**:
    - Create a **Git repository** following 42 standards.
    - **Structure directories** based on modularity to facilitate bonus extensions later.
3. **Makefile Creation**:
    - Implement **rules**: `all`, `clean`, `fclean`, `re`, and `bonus`.
    - Add flags: `Wall -Wextra -Werror`.
    - **Test Makefile** thoroughly to confirm each rule works as expected.

---

### **Phase 2: Core Parsing Logic**

1. **Implement ft_printf Parsing**:
    - In `ft_printf.c`, define **variadic handling** with `va_list`, `va_start`, `va_end`.
    - Build a **dispatcher** to route each format specifier to corresponding conversion handlers.
    - Use a **loop** to scan the format string, detect `%` symbols, and call the right handler.
2. **Basic Tests for Parsing**:
    - Write tests to ensure correct identification and routing of specifiers **without** conversion handling.
    - Verify that `%` triggers handler functions correctly.

---

### **Phase 3: Mandatory Conversions**

### 3.1 **Conversion Implementations**

- Each conversion should be handled in dedicated files within `src/conversions/` for modularity:
1. **Character (%c) and Percent (%%)**:
    - Implement in `x_char.c`.
    - Handle `%c` for single characters and `%%` for literal `%`.
2. **String (%s)**:
    - Implement in `x_str.c`.
    - Ensure **graceful handling** of `NULL` strings as `(null)`.
3. **Integers (%d and %i)**:
    - Implement in `x_int.c`.
    - **Test edge cases**: `INT_MIN`, `INT_MAX`.
4. **Unsigned Integer (%u)**:
    - Implement in `x_uint.c`.
    - Cover values such as `0` and `UINT_MAX`.
5. **Hexadecimal (%x and %X)**:
    - Implement in `x_hex.c`.
    - Include checks for **lowercase and uppercase** formats.
6. **Pointer (%p)**:
    - Implement in `x_ptr.c`.
    - Ensure proper formatting as `0x...` with `NULL` checks.

### 3.2 **Testing for Mandatory Conversions**

- Write **unit tests** covering edge cases and typical scenarios for each conversion.
- **Comparison Script**: Build a script that compares `ft_printf` output against standard `printf`.

---

### **Phase 4: Bonus Features Implementation**

### 4.1 **Field Width, Precision, and Flags**

1. **Field Width and Precision**:
    - Parse width and precision modifiers in the **format string**.
    - Use precision to **truncate strings** or **pad numbers** based on specified values.
2. **Flags** (`0`, `#`, `+`, and space):
    - Implement flag handling with **compatibility checks** (e.g., `%-10.5d`, `%#x`, `%+d`).
    - Write **test cases** combining flags, width, and precision.

### 4.2 **Modular Restructuring for Bonus**

- Relocate bonus handling into `src/bonus/`.
- Reorganize the Makefile to ensure **separate compilation** for bonus features.

---

### **Phase 5: Testing, Optimization, and Norm Compliance**

1. **Comprehensive Testing**:
    - Expand tests to cover complex combinations of flags, width, and precision.
    - **Valgrind** testing to detect memory leaks and errors.
2. **Code Review and Optimization**:
    - Ensure each function adheres to the **42 Norm**:
        - Functions under 25 lines.
        - Avoid unnecessary global variables.
    - Refactor common code into **helper functions**.
3. **Documentation and Commenting**:
    - Comment complex logic, explaining **parameters and expected behavior**.
4. **Final Validation**:
    - **Final tests** to ensure compliance with both mandatory and bonus requirements.
    - Double-check **Git repository** for proper organization, commits, and submission readiness.

---

## **Summary of Steps**

### **Without Bonus**

1. **Phase 1**: Initial setup and Makefile.
2. **Phase 2**: Parsing and dispatcher setup.
3. **Phase 3**: Implement mandatory conversions.
4. **Phase 5**: Testing, code quality, and compliance.

### **With Bonus**

1. **Phase 1**: Initial setup, planning for bonus.
2. **Phases 2-4**: Core implementation and bonus integration.
3. **Phase 5**: Expanded testing, debugging, and review.