#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int a = 9834;
	int b = 60000000267;
	char *format = "%5x0\n";
	char *format2 = "%#upXo\n";
	char *format3 = "%#016.5uxo\n";
	char *format4 = "%#uXo\n";

	printf("%d\n", printf("%p\n", a));
	ft_printf("%d\n", ft_printf("%p\n", a));
	printf("%d\n", printf("%p\n", b));
	ft_printf("%d\n", ft_printf("%p\n", b));
	printf("%d\n", printf("%12.8uox\n", -99900000999));
	ft_printf("%d\n", ft_printf("%12.8uox\n", -99900000999));
	printf("%d\n", printf("%lld\n", -9223372036854775807));
	ft_printf("%d\n", ft_printf("%lld\n", -9223372036854775807));

	printf("%d\n", printf("%lu\n", -42));
	ft_printf("%d\n", ft_printf("%lu\n", -42));

	printf("%d\n",  ft_printf("%lu\n", 4294967296));
	ft_printf("%d\n",  ft_printf("%lu\n", 4294967296));

	printf("%d\n", printf("%#18.15ox\n", -999));
	ft_printf("%d\n", ft_printf("%#18.15ox\n", -999));
	printf("%d\n", printf("%#12.8uox\n", -999999));
	ft_printf("%d\n", ft_printf("%#12.8uox\n", -999999));
	printf("%d\n",  printf("@moulitest: %5.o %5.0o\n", 0, 0));
	ft_printf("%d\n",  ft_printf("@moulitest: %5.o %5.0o\n", 0, 0));

	printf("%d\n",  printf("|%+d|\n", 0));
	ft_printf("%d\n",  ft_printf("|%+d|\n", 0));

	printf("%d\n", printf("%llx\n", 9223372036854775808));
	ft_printf("%d\n", ft_printf("%llx\n", 9223372036854775808));

	printf("%d\n", printf("%#llx\n", 9223372036854775807));
	ft_printf("%d\n", ft_printf("%#llx\n", 9223372036854775807));
	printf("%d\n", printf("|%-#6o|\n", 2500));
	ft_printf("%d\n", ft_printf("|%-#6o|\n", 2500));

	printf("%d\n", printf(format, 101));
	ft_printf("%d\n",ft_printf(format, 101));
	printf("%d\n", printf(format, -42));
	ft_printf("%d\n", ft_printf(format, -42));
	printf("%d\n", printf(format2, 12));
	ft_printf("%d\n", ft_printf(format2, 12));
	printf("%d\n", printf(format2, -100));
	ft_printf("%d\n", ft_printf(format2, -100));
	printf("%d\n", printf(format2, 90));
	ft_printf("%d\n", ft_printf(format2, 90));
	printf("%d\n", printf(format3, 0));
	ft_printf("%d\n", ft_printf(format3, 0));
	printf("%d\n", printf(format4, -45976));
	ft_printf("%d\n", ft_printf(format4, -45976));
	printf("%d\n",printf(format, "hello"));
	ft_printf("%d\n",ft_printf(format, "hello"));
	return 0;
}

// % <flags> <min_field> <.> <precision> <conversion_flags> <conversion>
//   +-# 0     NUMBER          NUMBER        l ll h hh L     diouxXfcspb