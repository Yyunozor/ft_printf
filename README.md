# **Ultimate Roadmap for `ft_printf` Project**

This roadmap is designed to structure your `ft_printf` project into actionable milestones, focusing on both mandatory and bonus objectives.

---

```
ft_printf_project/
├── Makefile                  ──> Builds the project and manages dependencies
├── ft_printf.h               ──> Header with prototypes, includes, and macros
├── libft/                    ──> Your libft folder (if allowed)
│   ├── Makefile              ──> Makefile for libft
│   ├── ft_*.c                ──> Libft source files
│   └── libft.h               ──> Header for libft with utilities
├── src/                      ──> Main source folder for ft_printf
│   ├── ft_printf.c           ──> Core parsing and dispatching logic
│   ├── conversions/          ──> Folder for individual conversion files
│   │   ├── x_char.c          ──> Handles %c and %%
│   │   ├── x_str.c           ──> Handles %s
│   │   ├── x_ptr.c           ──> Handles %p
│   │   ├── x_int.c           ──> Handles %d and %i
│   │   ├── x_uint.c          ──> Handles %u
│   │   ├── x_hex.c           ──> Handles %x and %X
│   │   └── x_mod.c           ──> Handles %%
│   └── bonus/                ──> Bonus handling files (if applicable)
├── obj/                      ──> Directory for compiled .o files
└── tests/                    ──> Testing folder
    ├── test_ft_printf.c      ──> Main test file for ft_printf
    └── test_cases/           ──> Optional structured test cases
        ├── test_mandatory.c  ──> Tests for mandatory part
        └── test_bonus.c      ──> Tests for bonus part (if applicable)

```

---

## **Phase 1: Project Setup & Understanding**

### 1.1 **Preparation**

- **Read and Analyze** the project requirements:
    - **Mandatory Conversions**: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`.
    - **Bonus Objectives**: Flags (`0.# +`), width, and precision.
- **Setup Repository**: Initialize Git repository as per 42 standards.
- **Organize Directory Structure** to accommodate modular development.

### 1.2 **Makefile Setup**

- Implement a `Makefile` with core rules:
    - `all`, `clean`, `fclean`, `re`, and `bonus` if applicable.
    - Set compilation flags `Wall -Wextra -Werror`.
    - **Test**: Run `make`, `make clean`, `make fclean`, `make re` to validate rules.

---

## **Phase 2: Core Structure of `ft_printf`**

### 2.1 **Implementing Core Parsing Logic**

- **Objective**: Build a robust parsing system in `ft_printf.c`:
    - Define the `ft_printf` prototype with variadic handling using `va_list`, `va_start`, `va_end`.
    - Design a loop to traverse the format string and identify `%` specifiers.
    - Develop a dispatch mechanism to route each specifier to appropriate handler functions.
- **Verify**: Write simple tests to ensure that format specifiers are correctly routed without actual conversions implemented.

---

## **Phase 3: Implementing Mandatory Conversions**

### 3.1 **Implement Conversions (Without Bonus)**

1. **Character (`%c`) and Percent (`%%`)**
    - Implement `%c` for single characters and `%%` for literal `%`.
    - **Test**: Include basic tests for characters and `%%` literals.
2. **String (`%s`)**
    - Implement `%s` for strings, handling `NULL` gracefully as `(null)`.
    - **Test**: Test cases with long, empty, and `NULL` strings.
3. **Integers (`%d` and `%i`)**
    - Implement `%d` and `%i` for signed integers.
    - **Test**: Positive, negative, and edge cases (e.g., `INT_MIN`, `INT_MAX`).
4. **Unsigned Integer (`%u`)**
    - Implement `%u` for unsigned integers.
    - **Test**: Cover values including `0` and `UINT_MAX`.
5. **Hexadecimal (`%x` and `%X`)**
    - Implement `%x` for lowercase and `%X` for uppercase hexadecimals.
    - **Test**: Mixed cases and correct letter casing.
6. **Pointer (`%p`)**
    - Implement `%p` for pointers, ensuring it formats as `0x...`.
    - **Test**: Valid pointers and `NULL`.

### 3.2 **Testing for Mandatory Conversions**

- Write unit tests to cover each conversion comprehensively.
- **Automate Testing**: Create a script to compare `ft_printf` output to standard `printf`.

---

## **Phase 4: Adding Bonus Functionality (Optional)**

### 4.1 **Implementing Field Width, Precision, and Flags**

1. **Field Width and Precision**
    - Implement parsing for field width and precision modifiers.
    - Ensure precision truncates strings and pads integers as specified.
2. **Flags (`0.# +` and Space)**
    - Implement flag handling with compatibility checks (e.g., `%-10.5d`, `%#x`, `%+d`).
    - **Test**: Combined cases of flags with width and precision.

### 4.2 **Re-structuring for Modularity**

- Modularize conversions by moving logic into individual files in `conversions/`:
    - Each file (e.g., `x_char.c`) handles a specific conversion.
    - Bonus handling in separate files in `bonus/`.

### 4.3 **Testing Bonus Features**

- **Expanded Testing**: Create comprehensive tests to cover flag, width, and precision combinations.
- **Memory Check**: Use `valgrind` to confirm no memory leaks or issues.

---

## **Phase 5: Code Quality and Optimization**

### 5.1 **Code Review and Norm Compliance**

- **Norminette**: Run Norminette on all files to ensure compliance.
- **Documentation**: Add comments for complex functions, detailing parameters and logic.
- **Function Optimization**: Refactor repetitive code into helper functions as needed.

### 5.2 **Final Testing and Validation**

- Ensure tests cover all edge cases:
    - Boundary values for integers and hexadecimals.
    - Combined flags, width, and precision.
- Re-run `valgrind` checks for memory leaks.

### 5.3 **Submission and Peer Review**

- **Git Repository Check**: Confirm all files are correctly named and committed.
- **Final Manual Review**: Double-check compliance with project requirements.

---

## **Roadmap Summary**

### **Without Bonus**

1. **Phase 1**: Setup and Makefile
2. **Phase 2**: Core Parsing and Dispatching Logic
3. **Phase 3**: Implement Mandatory Conversions
4. **Phase 5**: Code Quality, Testing, and Norm Compliance

### **With Bonus**

1. **Phase 1**: Initial Setup with Bonus Planning
2. **Phase 2-4**: Full Implementation of Core and Bonus Features
3. **Phase 5**: Advanced Testing, Debugging, and Final Review

---

This refined roadmap breaks down the project into focused, manageable steps, with an emphasis on testing, code quality, and modularity to guide you to a successful `ft_printf`. Good luck!