# **Roadmap for `ft_printf` Project**

---
```plaintext
ft_printf_project/
├── Makefile
├── ft_printf.h                 ──> Header file with function prototypes, structs, includes
├── libft/                      ──> Your libft folder (if authorized)
│   ├── Makefile                ──> Makefile for libft
│   ├── ft_*.c                  ──> Libft source files (if needed)
│   └── libft.h                 ──> Header for libft / contains utils functions
│   │   ├── ft_itoa_base.c      ──> Converts integers to base (hex conversions)
│   │   ├── ft_putnbr.c         ──> Prints a number (%d, %i)
│   │   ├── ft_putchar.c        ──> Prints a character (%c)
│   │   └── ft_putstr.c         ──> Prints a string (%s)
├── src/                        ──> Main source folder
│   ├── ft_printf.c             ──> Core ft_printf function (parsing, dispatching)
│   ├── conversions/            ──> Folder for conversion handling files
│   │   ├── x_char.c            ──> Handles %c and %%
│   │   ├── x_string.c          ──> Handles %s
│   │   ├── x_pointer.c         ──> Handles %p
│   │   ├── x_integer.c         ──> Handles %d and %i
│   │   ├── x_unsigned.c        ──> Handles %u
│   │   ├── x_hex.c             ──> Handles %x and %X
│   │   └── x_percent.c         ──> Handles %%
│   └── ft_printf_bonus.c       ──> Bonus parsing (if applicable)
└── tests/                      ──> Testing folder
	├── test_ft_printf.c        ──> Main test file for ft_printf
	└── test_cases/             ──> Organized test case files (optional)
		├── test_mandatory.c    ──> Tests for mandatory part
		└── test_bonus.c        ──> Tests for bonus part (if applicable)
```
### **1. Preparation and Setup**

- **Project Analysis**: Read and understand the project requirements carefully:
	- **Mandatory Conversions**: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.
	- **Bonus Features** (if planning to include them): Implement flags `0.# +`, field width, and precision under all conversions.
- **Set Up Repository**: Create your Git repository as per 42 standards.
- **Basic Directory Structure**: Organize your files for better modularity and clarity:
	- `ft_printf.c`: Core logic for `ft_printf`.
	- `ft_printf.h`: Header file with function prototypes and necessary includes.
	- `conversions/`: Folder for conversion-related files.
	- `Makefile`: Essential for compilation management.

---

### **Milestone 1: Basic Setup and Makefile**

- **Goal**: Set up the `Makefile` to handle compiling and cleaning.
	- Ensure `all`, `clean`, `fclean`, and `re` rules are included.
	- Compile with flags: `Wall -Wextra -Werror` to catch potential issues early.
	- **Verify**: Run `make`, `make clean`, `make fclean`, and `make re` to confirm it compiles without issues.

---

### **2. Core ft_printf Structure**

- **Objective**: Implement the foundational structure of `ft_printf` for parsing and dispatching based on format specifiers.
- **Steps**:
	- **Step 1**: Define the `ft_printf` prototype and set up basic variadic handling using `va_list`, `va_start`, and `va_end`.
	- **Step 2**: Implement a loop that iterates over the format string.
		- For each `%` encountered, call a function to parse the next character and identify the conversion type.
		- Implement a switch or dispatch structure to direct each conversion to its respective handler function.
- **Verify**: Add basic test cases to ensure `ft_printf` can identify and route conversions correctly without performing actual conversions yet.

---

### **3. Implementing Mandatory Conversions**

### **A. Without Bonus**

1. **Character (`%c`) and Percent (`%%`) Conversions**
	- Implement `%c` to print a single character.
	- Handle `%%` to print a literal `%`.
	- **Test**: Confirm handling of both single character inputs and format strings containing `%%`.
2. **String Conversion (`%s`)**
	- Implement `%s` to print a C-string.
	- Handle `NULL` strings gracefully by printing `(null)`.
	- **Test**: Edge cases like empty strings, long strings, and `NULL`.
3. **Integer Conversions (`%d` and `%i`)**
	- Implement `%d` and `%i` to handle signed integers.
	- Use helper functions for formatting and padding integers.
	- **Test**: Positive and negative values, minimum and maximum integer limits.
4. **Unsigned Integer Conversion (`%u`)**
	- Implement `%u` for unsigned decimal numbers.
	- Ensure correct handling of large values.
	- **Test**: Border cases like `0`, `UINT_MAX`.
5. **Hexadecimal Conversions (`%x` and `%X`)**
	- Implement `%x` (lowercase) and `%X` (uppercase) for hexadecimal formatting.
	- Use helper functions to convert and format hexadecimal numbers.
	- **Test**: Various values, checking for proper lowercase and uppercase formatting.
6. **Pointer Conversion (`%p`)**
	- Implement `%p` for pointers, formatting them as `0x...` hexadecimal.
	- Handle `NULL` pointers gracefully.
	- **Test**: Valid memory addresses and `NULL`.

### **B. With Bonus**

1. **Field Width and Precision**
	- Implement width and precision fields by parsing the format specifier.
	- Ensure that strings are truncated to precision and padded to width.
	- **Test**: Cases with combined width and precision for each data type.
2. **Flags ``, `0`, `#`, `+`, and Space**
	- Implement flags to adjust alignment, zero-padding, alternative form, and signs.
	- Ensure that these flags work together in various combinations.
	- **Test**: Combined cases such as `%-10.5d`, `%#x`, `%+d`, `% d`, and `%010x`.

---

### **4. Modularizing Code and Optimizing Memory Handling**

- **Objective**: Modularize the `ft_printf` code by creating a separate function for each conversion type, with well-defined responsibilities.
- **Steps**:
	- Move each conversion logic into its own function (e.g., `handle_char`, `handle_string`, `handle_int`).
	- Use helper functions to handle padding, sign management, and prefixing for hexadecimals.
	- Ensure each function manages its own memory allocations and deallocations where necessary.
- **Verify**: Check memory usage with tools like `valgrind` to ensure no memory leaks or unnecessary allocations.

---

### **5. Testing and Debugging**

- **Write a Test Suite**: Create a dedicated test file (`test_ft_printf.c`) with categorized test cases covering:
	- All specifiers, edge cases (large numbers, negatives, special characters).
	- Combined cases for width, precision, and flags (if doing bonus).
- **Automate Tests**: Use a script to compare `ft_printf` output against `printf` output.
- **Debugging**: Fix issues with edge cases, memory handling, and format specifier parsing.

---

### **6. Final Steps**

### **A. Without Bonus**

1. **Norm Compliance**: Run Norminette on all files and ensure full compliance.
2. **Documentation**: Add comments to functions for readability, focusing on parameter descriptions and logic explanations.
3. **Final Verification**: Re-run all tests, verify against the project requirements, and confirm memory management with `valgrind`.

### **B. With Bonus**

1. **Separate Bonus Files**: Move bonus functions into `_bonus.c` files as required.
2. **Makefile Bonus Rule**: Add a `bonus` rule to compile the bonus files.
3. **Comprehensive Testing**: Ensure the tests include all bonus combinations.
4. **Submit and Review**: Push to Git, double-check all files and paths, and verify naming.

---

### **Summary**

### **Without Bonus (Basic Roadmap)**

1. **Milestone 1**: Basic Setup and Makefile
2. **Milestone 2**: Core Structure of `ft_printf`
3. **Milestone 3**: Implement Mandatory Conversions
4. **Milestone 4**: Testing, Debugging, and Norm Compliance

### **With Bonus (Extended Roadmap)**

1. **Milestone 1**: Core Setup with Bonus Planning
2. **Milestone 2**: Full Implementation of Mandatory and Bonus Features
3. **Milestone 3**: Advanced Testing and Debugging
4. **Milestone 4**: Norm Compliance, Bonus File Setup, and Final Review

---
