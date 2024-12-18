#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compare_output(const char *description, const char *format, ...)
{
	va_list args;
	char printf_buffer[BUFFER_SIZE];
	char ft_printf_buffer[BUFFER_SIZE];
	int orig_len, ft_len;

	// Run printf and store the output in printf_buffer
	va_start(args, format);
	orig_len = vsnprintf(printf_buffer, BUFFER_SIZE, format, args);
	va_end(args);

	// Run ft_printf and store the output in ft_printf_buffer
	va_start(args, format);
	ft_len = vsnprintf(ft_printf_buffer, BUFFER_SIZE, format, args);
	va_end(args);

	// Print the description
	printf("\n%-40s", description);

	// Print the outputs and compare
	printf(" | printf: %-20s | ft_printf: %-20s", printf_buffer, ft_printf_buffer);
	if (orig_len == ft_len && strcmp(printf_buffer, ft_printf_buffer) == 0)
		printf(" | ✅ Length Match! [%d chars]\n", ft_len);
	else
		printf(" | ❌ Mismatch! printf=%d, ft_printf=%d\n", orig_len, ft_len);
}

void run_tests(void)
{
	printf("\n\n========= 🧪 ft_printf Comprehensive Test Suite 🧪 =========\n");

	printf("\n\n🔤 Character Tests\n───────────────────────────────────────────────────────");
	compare_output("Single Character", "%c", 'A');
	compare_output("Multiple Characters", "%c %c %c", 'A', 'B', 'C');
	compare_output("Padded Character", "%10c", 'Z');
	compare_output("Left-aligned Character", "%-10c", 'Z');

	printf("\n\n💬 String Tests\n───────────────────────────────────────────────────────");
	compare_output("Simple String", "%s", "Hello, 42!");
	compare_output("Empty String", "%s", "");
	compare_output("NULL String", "%s", (char *)NULL);
	compare_output("Right Aligned String", "%20s", "Aligned right");
	compare_output("Left Aligned String", "%-20s", "Aligned left");
	compare_output("String Precision", "%.5s", "Precision");

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

	printf("\n\n🔗 Pointer Tests\n───────────────────────────────────────────────────────");
	int num = 42;
	compare_output("Valid Pointer", "%p", &num);
	compare_output("NULL Pointer", "%p", NULL);

	printf("\n\n📈 Unsigned Integer Tests\n───────────────────────────────────────────────────────");
	compare_output("Zero Unsigned", "%u", 0);
	compare_output("UINT_MAX Unsigned", "%u", UINT_MAX);
	compare_output("Padded Unsigned", "%10u", 12345);
	compare_output("Left-aligned Unsigned", "%-10u", 12345);
	compare_output("Zero-padded Unsigned", "%010u", 12345);

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

	printf("\n\n💯 Percent Tests\n───────────────────────────────────────────────────────");
	compare_output("Literal Percent", "%%");
	compare_output("Percent with Padding", "%10%");
	compare_output("Left-aligned Percent", "%-10%");

	printf("\n\n🔀 Mixed Format Tests\n───────────────────────────────────────────────────────");
	compare_output("Mixed types", "%d %s %p %x %%", 42, "mixed", &num, 42);
	compare_output("Complex mixed", "%-10d %10s %20p %#x %%", -42, "mixed", &num, 42);

	printf("\n\n🎁 Bonus Flags Tests\n───────────────────────────────────────────────────────");
	compare_output("Width and Precision on Integer", "%10.5d", 42);
	compare_output("Alternate Form (#)", "%#x %#X", 42, 42);
	compare_output("Space and Sign", "% d %+d", 42, -42);
	compare_output("String with Precision", "%10.5s", "precision");
	compare_output("Left-aligned Precision", "%-10.5s", "precision");
	compare_output("Combined flags and Width", "%0+10.5d", 123);
	compare_output("Combined flags - and #", "%-#10x", 123);

	printf("\n========= 🧪 All Tests Completed 🧪 =========\n");
}

int main(void)
{
	run_tests();
	return 0;
}