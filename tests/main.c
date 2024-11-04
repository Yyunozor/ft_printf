#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

void test_char(void)
{
    printf("\n=== Character Tests ===\n");
    printf("Expected: %c\n", 'A');
    ft_printf("Got:      %c\n", 'A');
    printf("Expected: %c %c %c\n", 'A', 'B', 'C');
    ft_printf("Got:      %c %c %c\n", 'A', 'B', 'C');
}

void test_string(void)
{
    printf("\n=== String Tests ===\n");
    printf("Expected: %s\n", "Hello, 42!");
    ft_printf("Got:      %s\n", "Hello, 42!");
    printf("Expected: %s\n", "");
    ft_printf("Got:      %s\n", "");
    printf("Expected: %s\n", (char *)NULL);
    ft_printf("Got:      %s\n", (char *)NULL);
}

void test_pointer(void)
{
    int num = 42;
    void *ptr = &num;
    void *null_ptr = NULL;

    printf("\n=== Pointer Tests ===\n");
    printf("Expected: %p\n", ptr);
    ft_printf("Got:      %p\n", ptr);
    printf("Expected: %p\n", null_ptr);
    ft_printf("Got:      %p\n", null_ptr);
}

void test_integer(void)
{
    printf("\n=== Integer Tests ===\n");
    printf("Expected: %d\n", 42);
    ft_printf("Got:      %d\n", 42);
    printf("Expected: %d\n", -42);
    ft_printf("Got:      %d\n", -42);
    printf("Expected: %d\n", INT_MAX);
    ft_printf("Got:      %d\n", INT_MAX);
    printf("Expected: %d\n", INT_MIN);
    ft_printf("Got:      %d\n", INT_MIN);
}

void test_unsigned(void)
{
    printf("\n=== Unsigned Integer Tests ===\n");
    printf("Expected: %u\n", 0);
    ft_printf("Got:      %u\n", 0);
    printf("Expected: %u\n", UINT_MAX);
    ft_printf("Got:      %u\n", UINT_MAX);
}

void test_hexadecimal(void)
{
    printf("\n=== Hexadecimal Tests ===\n");
    printf("Expected: %x\n", 255);
    ft_printf("Got:      %x\n", 255);
    printf("Expected: %x\n", 0);
    ft_printf("Got:      %x\n", 0);
    printf("Expected: %X\n", 255);
    ft_printf("Got:      %X\n", 255);
}

void test_mixed_formats(void)
{
    printf("\n=== Mixed Format Tests ===\n");
    int num = 42;
    char *str = "Hello, mixed!";
    void *ptr = &num;

    printf("Expected: %d %s %p %x %%\n", num, str, ptr, num);
    ft_printf("Got:      %d %s %p %x %%\n", num, str, ptr, num);
}

void test_bonus_flags(void)
{
    printf("\n=== Bonus Flags Tests (if implemented) ===\n");
    // Width and precision on integers
    printf("Expected: %10d\n", 42);
    ft_printf("Got:      %10d\n", 42);
    // Flag #
    printf("Expected: %#x %#X\n", 42, 42);
    ft_printf("Got:      %#x %#X\n", 42, 42);
    // Flag +
    printf("Expected: %+d %+d\n", 42, -42);
    ft_printf("Got:      %+d %+d\n", 42, -42);
    // Flag space
    printf("Expected: % d % d\n", 42, -42);
    ft_printf("Got:      % d % d\n", 42, -42);
}

int main(void)
{
    printf("Running ft_printf tests...\n");

    test_char();
    test_string();
    test_pointer();
    test_integer();
    test_unsigned();
    test_hexadecimal();
    test_mixed_formats();
    test_bonus_flags();

    printf("\nAll tests completed.\n");
    return 0;
}