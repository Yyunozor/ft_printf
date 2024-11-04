#include "../ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

void compare_output(const char *description, const char *format, ...)
{
    va_list args;
    int orig_len, ft_len;

    printf("\n📝 Test: %-30s", description);
    
    // Run printf
    printf("\n   🌐 Standard printf  : ");
    va_start(args, format);
    orig_len = vprintf(format, args);
    va_end(args);
    
    // Run ft_printf
    printf("   ➡️  ft_printf         : ");
    va_start(args, format);
    ft_len = ft_printf(format, args);
    va_end(args);

    // Display Result
    if (orig_len == ft_len)
        printf("\n   ✅ Length Match! [%d chars]\n", ft_len);
    else
        printf("\n   ❌ Mismatch! printf=%d, ft_printf=%d\n", orig_len, ft_len);

    printf("───────────────────────────────────────────────────────────────────\n");
}

void run_tests()
{
    printf("\n\n========= 🧪 ft_printf Comprehensive Test Suite 🧪 =========\n");

    // Character Tests
    printf("\n\n🔤 Character Tests\n───────────────────────────────────────────────────────");
    compare_output("Single Character", "%c", 'A');
    compare_output("Multiple Characters", "%c %c %c", 'A', 'B', 'C');
    compare_output("Padded Character", "%10c", 'Z');
    compare_output("Left-aligned Character", "%-10c", 'Z');

    // String Tests
    printf("\n\n💬 String Tests\n───────────────────────────────────────────────────────");
    compare_output("Simple String", "%s", "Hello, 42!");
    compare_output("Empty String", "%s", "");
    compare_output("NULL String", "%s", (char *)NULL);
    compare_output("Right Aligned String", "%20s", "Aligned right");
    compare_output("Left Aligned String", "%-20s", "Aligned left");
    compare_output("String Precision", "%.5s", "Precision");

    // Integer Tests
    printf("\n\n🔢 Integer Tests\n───────────────────────────────────────────────────────");
    compare_output("Positive Integer", "%d", 42);
    compare_output("Negative Integer", "%d", -42);
    compare_output("Positive with Sign", "%+d", 42);
    compare_output("Negative with Sign", "%+d", -42);
    compare_output("Padded Integer", "%10d", 42);
    compare_output("Left-aligned Integer", "%-10d", -42);
    compare_output("Zero-padded Integer", "%010d", 42);
    compare_output("Precision Integer", "%.5d", 42);
    compare_output("INT_MAX", "%d", INT_MAX);
    compare_output("INT_MIN", "%d", INT_MIN);

    // Pointer Tests
    printf("\n\n🔗 Pointer Tests\n───────────────────────────────────────────────────────");
    int num = 42;
    compare_output("Valid Pointer", "%p", &num);
    compare_output("NULL Pointer", "%p", NULL);

    // Unsigned Integer Tests
    printf("\n\n📈 Unsigned Integer Tests\n───────────────────────────────────────────────────────");
    compare_output("Zero Unsigned", "%u", 0);
    compare_output("UINT_MAX Unsigned", "%u", UINT_MAX);
    compare_output("Padded Unsigned", "%10u", 12345);
    compare_output("Left-aligned Unsigned", "%-10u", 12345);
    compare_output("Zero-padded Unsigned", "%010u", 12345);

    // Hexadecimal Tests
    printf("\n\n🔡 Hexadecimal Tests\n───────────────────────────────────────────────────────");
    compare_output("Lowercase Hex", "%x", 255);
    compare_output("Uppercase Hex", "%X", 255);
    compare_output("Prefixed Hex", "%#x", 255);
    compare_output("Prefixed Hex Zero", "%#x", 0);
    compare_output("Prefixed Uppercase Hex", "%#X", 255);
    compare_output("Hex with Padding", "%10x", 255);
    compare_output("Hex with Zero Padding", "%010x", 255);
    compare_output("Hex Precision", "%.5x", 255);
    compare_output("Hex Max Unsigned", "%x", UINT_MAX);

    // Percent Tests
    printf("\n\n💯 Percent Tests\n───────────────────────────────────────────────────────");
    compare_output("Literal Percent", "%%");
    compare_output("Percent with Padding", "%10%");
    compare_output("Left-aligned Percent", "%-10%");

    // Mixed Format Tests
    printf("\n\n🔀 Mixed Format Tests\n───────────────────────────────────────────────────────");
    char *str = "mixed";
    compare_output("Mixed types", "%d %s %p %x %%", 42, str, &num, 42);
    compare_output("Complex mixed", "%-10d %10s %20p %#x %%", -42, str, &num, 42);

    // Bonus Flags Tests
    printf("\n\n🎁 Bonus Flags Tests\n───────────────────────────────────────────────────────");
    compare_output("Width and Precision on Integer", "%10.5d", 42);
    compare_output("Alternate Form (#)", "%#x %#X", 42, 42);
    compare_output("Space and Sign", "% d %+d", 42, -42);
    compare_output("String with Precision", "%10.5s", "precision");
    compare_output("Left-aligned Precision", "%-10.5s", "precision");
    compare_output("Combined flags and Width", "%0+10.5d", 123);
    compare_output("Combined flags - and #", "%-#10x", 123);

    printf("\n========= 🧪 All Tests Completed 🧪 =========\n\n");
}

int main(void)
{
    run_tests();
    return 0;
}
