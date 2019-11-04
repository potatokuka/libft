/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmains.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:15:51 by greed          #+#    #+#                */
/*   Updated: 2019/10/30 18:05:21 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void	memset_test(int c, int len)
{
	int		i;
	void	*a;
	void	*b;

	printf("memset\nIN: %d %c\n", len, c);
	a = (void*)malloc(len);
	ft_memset(a, c, len);
	printf("FT: %s\n", a);
	b = (void*)malloc(len);
	memset(b, c, len);
	printf("CC: %s\n", b);
}

void	bzero_test(int n)
{
	int		i;
	void	*a;
	void	*b;

	a = (void*)malloc(n);
	memset(a, 68, n);
	printf("bzero\nIN: %s\n", a);
	ft_bzero(a, n);
	printf("FT: %s\n", a);
	b = (void*)malloc(n);
	memset(b, 68, n);
	bzero(b, n);
	printf("CC: %s\n", b);
}

void	memcpy_test(const void *src, int n)
{
	int		i;
	void	*a;
	void	*b;

	printf("memcpy\nIN: %s\n", src);
	a = (void*)malloc(n);
	printf("FT: %s\n", ft_memcpy(a, src, n));
	b = (void*)malloc(n);
	printf("CC: %s\n", memcpy(b, src, n));
}

void	memccpy_test(const void *src, int c, int n)
{
	int		i;
	void	*a;
	void	*b;
	void	*temp;

	printf("memccpy\nIN: %s %c\n", src, (char)c);
	a = (void*)malloc(n);
	if ((temp = ft_memccpy(a, src, c, n)))
		printf("FT: %c\n", *(char*)(temp - 1));
	else
		printf("FT: NULL\n");
	printf("FT: %s\n", a);
	b = (void*)malloc(n);
	if ((temp = memccpy(b, src, c, n)))
		printf("CC: %c\n", *(char*)(temp - 1));
	else
		printf("CC: NULL\n");
	printf("CC: %s\n", b);
}

void	memmove_test_string(const void *src, int n)
{
	int		i;
	void	*a;
	void	*b;

	printf("memmove\nIN: %s\n", src);
	a = (void*)malloc(n);
	printf("FT: %s\n", ft_memmove(a, src, n));
	b = (void*)malloc(n);
	printf("CC: %s\n", memmove(b, src, n));
}

void	memmove_test_array(void)
{
	int		arr1[] = {0, 1, 2, 3, 4, 5, 6, 7};
	int		arr2[] = {0, 1, 2, 3, 4, 5, 6, 7};
	int		*a1;
	int		*a2;
	int		i;

	printf("memmove\nIN: ");
	i = 0;
	while (i < 8)
	{
		printf("%d", arr1[i]);
		if (i < 7)
			printf(", ");
		i++;
	}
	printf("\n");
	a1 = &arr1[0];
	a2 = &arr1[1];
	ft_memmove(a1, a2, 7);
	printf("FT: ");
	i = 0;
	while (i < 8)
	{
		printf("%d", arr1[i]);
		if (i < 7)
			printf(", ");
		i++;
	}
	printf("\n");

	a1 = &arr2[0];
	a2 = &arr2[1];
	memmove(a1, a2, 7);
	printf("CC: ");
	i = 0;
	while (i < 8)
	{
		printf("%d", arr2[i]);
		if (i < 7)
			printf(", ");
		i++;
	}
	printf("\n");
}

void	memchr_test(const void *src, int c, int n)
{
	int		i;
	void	*a;
	void	*b;

	printf("memchr\nIN: %s\n", src);
	a = (void*)malloc(n);
	printf("FT: %s\n", ft_memchr(src, c, n));
	printf("CC: %s\n", memchr(src, c, n));
}

void	memcmp_test(const void *s1, const void *s2, int n)
{
	printf("memcmp\nIN: %s %s\n", s1, s2);
	printf("FT: %d\n", ft_memcmp(s1, s2, n));
	printf("CC: %d\n", memcmp(s1, s2, n));
}

void	strlen_test(const char *s)
{
	printf("strlen\nIN: %s\n", s);
	printf("FT: %zu\n", ft_strlen(s));
	printf("CC: %lu\n", strlen(s));
}

void	strlcpy_test(const char *s)
{
	char	*a;
	char	*b;
	int		size = 6;

	printf("strlcpy\nIN: %s\n", s);
	a = (char*)malloc(size);
	printf("FT: %zu %s\n", ft_strlcpy(a, s, size), a);
	b = (char*)malloc(size);
	printf("CC: %lu %s\n", strlcpy(b, s, size), b);
}

void	strlcat_test(const char *s)
{
	char	*a;
	char	*b;
	int		size = 8;

	printf("strlcat\nIN: %s\n", s);
	a = (char*)malloc(size);
	a[0] = 'a';
	a[1] = 'b';
	printf("FT: %zu %s\n", ft_strlcat(a, s, size), a);
	b = (char*)malloc(size);
	b[0] = 'a';
	b[1] = 'b';
	printf("CC: %lu %s\n", strlcat(b, s, size), b);
}

void	strchr_test(const char *s, int c)
{
	char	*temp;

	printf("strchr\nIN: %s %c\n", s, (char)c);
	if ((temp = ft_strchr(s, c)))
		printf("FT: %s\n", temp);
	else
		printf("FT: NULL\n");
	if ((temp = strchr(s, c)))
		printf("CC: %s\n", temp);
	else
		printf("CC: NULL\n");
}

void	strrchr_test(const char *s, int c)
{
	char	*temp;

	printf("strrchr\nIN: %s %c\n", s, (char)c);
	if ((temp = ft_strrchr(s, c)))
		printf("FT: %s\n", temp);
	else
		printf("FT: NULL\n");
	if ((temp = strrchr(s, c)))
		printf("CC: %s\n", temp);
	else
		printf("CC: NULL\n");
}

void	strnstr_test(const char *h, const char *s, int c)
{
	char	*temp;

	printf("strnstr\nIN: %s %s\n", h, s);
	if ((temp = ft_strnstr(h, s, c)))
		printf("FT: %s\n", temp);
	else
		printf("FT: NULL\n");
	if ((temp = strnstr(h, s, c)))
		printf("CC: %s\n", temp);
	else
		printf("CC: NULL\n");
}

void	strncmp_test(const void *s1, const void *s2, int n)
{
	printf("strncmp\nIN: %s %s\n", s1, s2);
	printf("FT: %d\n", ft_strncmp(s1, s2, n));
	printf("CC: %d\n", strncmp(s1, s2, n));
}

void	atoi_test(const char *str)
{
	printf("atoi\nIN: %s\n", str);
	printf("FT: %d\n", ft_atoi(str));
	printf("CC: %d\n", atoi(str));
}

void	isalpha_test(char c)
{
	printf("isalpha\nIN: %c\n", c);
	printf("FT: %d\n", ft_isalpha(c));
	printf("CC: %d\n", isalpha(c));
}

void	isdigit_test(char c)
{
	printf("isdigit\nIN: %c\n", c);
	printf("FT: %d\n", ft_isdigit(c));
	printf("CC: %d\n", isdigit(c));
}

void	isalnum_test(char c)
{
	printf("isalnum\nIN: %c\n", c);
	printf("FT: %d\n", ft_isalnum(c));
	printf("CC: %d\n", isalnum(c));
}

void	isascii_test(char c)
{
	printf("isascii\nIN: %c\n", c);
	printf("FT: %d\n", ft_isascii(c));
	printf("CC: %d\n", isascii(c));
}

void	isprint_test(char c)
{
	printf("isprint\nIN: %c\n", c);
	printf("FT: %d\n", ft_isprint(c));
	printf("CC: %d\n", isprint(c));
}

void	toupper_test(char c)
{
	printf("toupper\nIN: %c\n", c);
	printf("FT: %c\n", ft_toupper(c));
	printf("CC: %c\n", toupper(c));
}

void	tolower_test(char c)
{
	printf("tolower\nIN: %c\n", c);
	printf("FT: %c\n", ft_tolower(c));
	printf("CC: %c\n", tolower(c));
}

void	strdup_test(char *src)
{
	printf("strdup\nIN: %s\n", src);
	printf("FT: %s\n", ft_strdup(src));
	printf("CC: %s\n", strdup(src));
}

void	substr_debug(char const *s, unsigned int start, size_t len)
{
	printf("substr\nIN: %s %d %lu\n", s, start, len);
	printf("FT: %s\n", ft_substr(s, start, len));
}

void	strjoin_debug(char const *s1, char const *s2)
{
	printf("strjoin\nIN: %s %s\n", s1, s2);
	printf("FT: %s\n", ft_strjoin(s1, s2));
}

void	strtrim_debug(char *s1, char const *set)
{
	printf("strtrim\nIN: %s %c\n", s1, *set);
	printf("FT: %s\n", ft_strtrim(s1, set));
}

void	split_debug(char const *s, char c)
{
	int		i = 0;
	char	**arr;

	printf("split\nIN: %s %c\n", s, c);
	printf("FT:\n");
	arr = ft_split(s, c);
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	printf("\n");
}

void	itoa_debug(int n)
{
	printf("itoa\nIN: %d\n", n);
	printf("FT: %s\n", ft_itoa(n));
}

char	strmapi_func(unsigned int n, char c)
{
	return (c + 1);
}

void	strmapi_debug(char const *s, char (*f)(unsigned int, char))
{
	printf("strmapi\nIN: %s\n", s);
	printf("FT: %s\n", ft_strmapi(s, f));
}

int		main(void)
{
	memset_test(67, 5);
	memset_test(67, 0);
	memset_test(500, 0);
	bzero_test(5);
	bzero_test(0);
	memcpy_test("2tictacs", 9);
	memcpy_test("", 0);
	memccpy_test("3tictacs", 'c', 9);
	memccpy_test("3tictacs", '4', 9);
	memccpy_test("", ' ', 0);
	memmove_test_string("4tictacs", 9);
	memmove_test_string("", 0);
	memmove_test_array();
	memchr_test("5tictacs", 'c', 9);
	memcmp_test("hello", "hello", 5);
	memcmp_test("hello", "hellO", 5);
	memcmp_test("", "", 0);
	strlen_test("6tictacs");
	strlen_test("");
	strlcpy_test("tic");
	strlcpy_test("tictac");
	strlcat_test("");
	strlcat_test("2tac");
	strlcat_test("3tac4me");
	strchr_test("sentence", 'e');
	strchr_test("", 'e');
	strchr_test("sentence", 'q');
	strrchr_test("sentence", 'n');
	strrchr_test("", 'e');
	strrchr_test("sentence", 'q');
	strnstr_test("haystack", "sta", 9);
	strnstr_test("haystack", "ack", 9);
	strnstr_test("", "ack", 9);
	strnstr_test("ticstack", "", 9);
	strncmp_test("hello", "hello", 5);
	strncmp_test("hello", "hellO", 5);
	strncmp_test("", "", 0);
	atoi_test("-+100");
	atoi_test("-1020");
	atoi_test("+-12300");
	atoi_test("2147483647");
	atoi_test("-2147483648");
	isalpha_test('a');
	isalpha_test('2');
	isdigit_test('a');
	isdigit_test('2');
	isalnum_test('a');
	isalnum_test('2');
	isalnum_test('&');
	isascii_test(0);
	isascii_test(127);
	isprint_test(31);
	isprint_test(32);
	isprint_test(127);
	toupper_test('a');
	toupper_test('D');
	tolower_test('a');
	tolower_test('D');
	//no way to test malloc block size
	strdup_test("3tictac minimum entry");
	strdup_test("");
	substr_debug("This is my lovely string", 2, 8);
	strjoin_debug("Add one tic tac", "with another tictac");
	strjoin_debug("", "");
	const char a = 'a';
	const char *ptr = &a;
	strtrim_debug("aaaaawoawzaaa", ptr);
	strtrim_debug("woawz", ptr);
	strtrim_debug("aaaaaaa", ptr);
	split_debug("wowthisocouldbeosploit", 'o');
	split_debug("oooooooooo", 'o');
	split_debug("1ooooo2oooo4o", 'o');
	itoa_debug(__INT_MAX__);
	itoa_debug(-2147483648);
	itoa_debug(1020);
	char (*f)(unsigned int, char) = &strmapi_func;
	strmapi_debug("23tictac is too many for me, i want 22tictac", f);
	strmapi_debug("", f);

	printf("ft_put*\n");
	ft_putchar_fd('a', 1);
	printf("\n");
	ft_putendl_fd("litty titty string", 1);
	ft_putstr_fd("anotha one", 1);
	printf("\n");
	ft_putnbr_fd(__INT_MAX__, 1);
	printf("\n");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
}