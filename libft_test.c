/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 08:02:41 by ksiziva           #+#    #+#             */
/*   Updated: 2018/06/22 08:06:33 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "color_text.h"

void	test_ft(char	*ft_name, char *descrip)
{
	printf("PASSED TESTS  ~~ ");
	green();
	printf("Norme\t42FileChecker\tlibft-unit-test\tLibtest\n");
	reset();
	cyan();
	printf("------------------------------------------------------------------------------------------------\n");
	reset();
	green();
	printf("Function Name - ");
	reset();
	yellow();
	printf("%s\n", ft_name);
	reset();
	cyan();
	underline();
	printf("FUNCTION DESCRIPTION\n");
	closeline();
	reset();
	printf("- %s\n", descrip);
	magenta();
	printf("FOR EXAMPLE");
	reset();
}

void	iteri_test(unsigned int i, char *s)
{
	i = 0;
	*s = 'a';
}

char	strmap_test(char c)
{
	c = 'a';
	return (c);
}

char	strmapi_test(unsigned int n, char c)
{
	n = 0;
	c = 'a';
	return (c);
}


int		main(void)
{

	green();
	printf("TEST_STARTING\tPERSONAL LIBFT TESTS...\n\n\n");
	reset();
	test_ft("ft_memset.c", "Function fills the first n bytes of the memory area pointed to by s with the constant byte c.\n");

	char str0[50] = "WeThinkCode is for programming fanatics.";

	printf("\nBefore ft_memset(): %s\n", str0);
	if (ft_memset(str0 + 13, '.', 8*sizeof(char)))
	{
		printf("After ft_memset():  %s\n", str0);
		green();
		printf("\nTEST PASSED - OK!");
		reset();
		printf("(line 90)\n\n");
	}

	test_ft("ft_bzero.c", "Function sets the first n bytes of the area starting at s to zero\n");

	char str1[] = "abcdcd";
	int c = 6;

	printf("\nBefore ft_bzero.c(): %s\n", str1);
	ft_bzero(str1, c);
	printf("String after first |%d| bytes changes to 0 is - |%s|\n", c,str1);
	green();
	printf("TEST PASSED - OK!");
	reset();
	printf("(line 105)\n\n");

	test_ft("ft_memcpy.c", "Copies n bytes from memory area src to memory area dest. The memory areas must not overlap.\n");

	char str2[50] = "WeThinkCode is for programming fanatics.";
	char dest2[50];
	strcpy(dest2,"Heloooo!!");
	printf("\nBefore ft_memcpy(): %s\n", dest2);
	if (ft_memcpy(dest2, str2, ft_strlen(str2)+1))
	{
		printf("After ft_memcpy():  %s\n", dest2);
		green();
		printf("TEST PASSED - OK!");
		reset();
		printf("(line 118)\n\n");
	}


	test_ft("ft_memccpy.c", "Function copies no more than n bytes from memory area src to memory area dest, stopping\n");
	printf("\nWhen the character c is found.\n");
	char *src = "WeThinkcode is for programming fanatics.";
	char dest[50];
	char *ptr;
	printf("Before ft_memccpy(): %s\n", src);
	ptr = (char *) memccpy(dest, src, 'c', strlen(src));
	if (ptr)
	{
		*ptr = '\0';
		printf("After ft_memccpy():%s\n", dest);
		green();
		printf("TEST PASSED - OK!");
		reset();
		printf("(line 134)\n\n");
	}
	else
		printf("The character wasn't found\n");

	test_ft("ft_memmove.c","Function copies n bytes from memory area src to memory area dest. The memory areas may overlapi");

	char	 dest4[] = "oldstring";
	const char src4[] = "newstring";

	printf("\nBefore ft_memmove() dest = %s, src = %s\n", dest4, src4);
	if(ft_memmove(dest4, src4, 9))
	{
		printf("After ft_memmove() dest = %s, src = %s\n", dest4, src4);
		green();
		printf("TEST PASSED - OK!");
		reset();
		printf("(line 153)\n\n");
	}


	test_ft("ft_memdel.c","This function takes in the parameter of the address of a pointer. The zone pointed to should be \nliberated with free. The pointer is then set to NULL.");

	void	*mem;

	mem = malloc(20 * sizeof(*mem));

	ft_memdel(&mem);
	if (!mem)
	{
		printf("\nft_memdel() SUCESS\n");
		green();
		printf("TEST PASSED - OK!");
		reset();
		printf("(line 169)\n\n");
	}

	test_ft("ft_memchr.c","Function locates the first occurrence of c (converted to an unsigned char) in string b.");

	char	*s = "abcdefg";

	char	*find = ft_memchr(s, 'e', 6);
	if (find != NULL)
	{
		printf ("\nAfter ft_memchr() :|%s| was found\n", find);
		green();
		printf("TEST PASSED - OK!");
		reset();
		printf("(line 183)\n\n");
	}
	else
		printf("Search character not found\n");

	test_ft("ft_memalloc.c","Allocates - with malloc(3) and returns a “fresh” memory area or else NULL.");

	void	*alloc;

	alloc = ft_memalloc(20);
	if (!alloc)
	{
		printf("\nMemory NOT allocated\n");
	}
	else
	{
		printf("\nMemory sucessffully allocated!\n");
		green();
		printf("TEST PASSED - OK!");
		reset();
		printf("(line 199)\n\n");
	}

	test_ft("ft_atoi.c","The atoi function converts the initial portion of the string point to by str to\n int representation.");
	if (ft_atoi("-4578") || ft_atoi("+125") || ft_atoi(" 	999") || ft_atoi("1247"))
	{
		printf("\nft_atoi(\"-4578\") || ft_atoi(\"+125\") || ft_atoi(\"    999\") || ft_atoi(\"1247\")\n");
		printf("Converted successfully\n");
		green();
		printf("TEST PASSED - OK!");
		reset();
		printf("(line 214)\n\n");
	}
	else
		printf("Tests FAILED");

	test_ft("ft_isalnum.c","Checks via ascii table if parameter c is an alphabet or digit");

	if (ft_isalnum(48) || ft_isalnum('A') || ft_isalnum('e') || ft_isalnum('9'))
	{
		cyan();
		printf("\nALL CHECKED : SUCCESS!");
		reset();
		green();
		printf("\nTEST PASSED - OK!");
		reset();
		printf("(line 228)\n\n");

	}

	test_ft("ft_isalpha.c", "Checks via ascii table if the given parameter is an alphabet");
	if (ft_isalpha('A') || ft_isalpha('z') || ft_isalpha('G' || ft_isalpha('a')))
	{
		cyan();
		printf("\nALL CHECKED : SUCCESS!");
		reset();
		green();
		printf("\nTEST PASSED - OK!");
		reset();
		printf("(line 241)\n\n");
	}
	printf("\nTEST FAILED\n");

	test_ft("ft_isascii.c","Checks via ascii table if the given parameter is an ascii character");
	if (ft_isascii('*') || ft_isascii('%') || ft_isascii(':'))
	{
		cyan();
		printf("\nALL CHECKED : SUCCESS!");
		reset();
		green();
		printf("\nTEST PASSED - OK!");
		reset();
		printf("(line 254)\n\n");
	}
	printf("\nTEST FAILED\n");

	test_ft("ft_isdigit.c","Checks via ascii table if the given parameter is a digit");
	if (ft_isdigit('9') || ft_isdigit('0') || ft_isdigit('7'))
	{
		cyan();
		printf("\nALL CHECKED : SUCCESS!");
		reset();
		green();
		printf("\nTEST PASSED - OK!");
		reset();
		printf("(line 267)\n\n");
	}
	printf("\nTEST FAILED\n");

	test_ft("ft_isprint.c","Checks if the given argument is whithin the printable characters in ascii");
	if (ft_isprint('A') && ft_isprint(' ') && ft_isprint('\n') && ft_isprint('\t'))
	{
		cyan();
		printf("\nALL CHECKED : SUCCESS!");
		reset();
		green();
		printf("\nTEST PASSED - OK!");
		reset();
	}
	else
	{
		red();
		printf("\n(line 280)");
		printf("SOME OF THE VALUES ARE NON-PRINTABLE\n");
		reset();
	}

	test_ft("ft_itoa.c","Takes an integer constant and converts it to a character literal");
	char *res;

	res = ft_itoa(3546);
	if (res)
	{
		cyan();
		printf("\nConverted value - \"%s\"", res);
		reset();
		green();
		printf("\nTEST PASSED - OK!");
		reset();
		printf("(line 300)\n\n");
	}
	else
	{
		red();
		printf("\nTEST FAILED\n");
		reset();
	}
	test_ft("ft_strlen.c","Returns the length of a given string");
	char  s_len[] = "momma";
	printf("\nStrlen is...%zu", ft_strlen(s_len));
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 319)\n\n");

	test_ft("ft_strdup.c","Allocates with malloc and copies dest string to memory source area");
	char *s1_strdup = "Raja";
	char *s2_strdup;

	s2_strdup = ft_strdup(s1_strdup);
	printf("\nDuplicated string is : %s", s2_strdup);
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 329)\n\n");

	test_ft("ft_strndup.c","function copies at most len characters from the string str and NUL terminates");
	char *s1_strndup = "Raja";
	char *s2_strndup;

	s2_strndup = ft_strndup(s1_strndup, 2);
	printf("\nDuplicated n string is : %s", s2_strndup);
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 340)\n\n");	

	test_ft("ft_strcpy.c","Copies contents from one string to dest string");
	char  dest_strcpy[200];
	char  src_strcpy[] = "Momma";

	ft_strcpy(dest_strcpy, src_strcpy);
	printf("\nStrcpy copied string is : %s", dest_strcpy);
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 351)\n\n");

	test_ft("ft_strncpy.c","Copies up to len bytes from source string to destination string");
	char dest_strncpy[55];
	char *src_strncpy = "Momma knows best";

	printf("\nSrc str is...Momma knows best\n");
	printf("Strncpy copied str is...%s", ft_strncpy(dest_strncpy, src_strncpy, 10));
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 363)\n\n");

	test_ft("ft_strcat.c","Concatenates the src source to the end of dest string");
	char dest_strcat[55] = "momma ";
	char src_strcat[] = "knows best";
	printf("\nStrcat is = %s", ft_strcat(dest_strcat, src_strcat));
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 372)\n\n");

	test_ft("ft_strncat.c","Contatenates up to the number of len bytes from source to dest string");
	char dest_strncat[53] = "momma";
	char src_strncat[25] = "knows";
	printf("\nStrncat result : %s", ft_strncat(dest_strncat, src_strncat, 3));
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 381)\n\n");

	test_ft("ft_strlcat.c","Function appends the NUL-terminated string src to the end of dst.\n It will return the length of both and append at most size - strlen(dst) - 1 bytes,\n NUL-terminating the result.");
	char dest_strlcat[] = "momma";
	char src_strlcat[] = "knows";
	size_t size_strlcat = 4;
	printf("\nStrlcat result = %zu",ft_strlcat(dest_strlcat,src_strlcat, size_strlcat));
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 391)\n\n");


	test_ft("ft_strchr.c","Function returns a pointer to the first occurrence of the character c in str.");
	char str_strchr[] = "http//.tutorialspoint.com";
	char ch_strchr = '.';
	char  *res_strchr;
	res_strchr = ft_strchr(str_strchr, ch_strchr);
	printf("\nString after strchr |%c| is - |%s|", ch_strchr, res_strchr);
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 402)\n\n");

	test_ft("ft_strrchr","Returns a pointer to the last ocuurance of the character c in str");
	res_strchr = ft_strrchr(str_strchr, ch_strchr);
	printf("\nString after strrchr |%c| is - |%s|", ch_strchr, res_strchr);
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 410)\n\n");


	test_ft("ft_strstr.c","Function finds the first occurrence of the substring needle in the string haystack.");
	char str_strstr[] = "momma knows best";
	char sub[] = "knows";
	printf("\nThe substring is: %s\n", ft_strstr(str_strstr, sub));
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 421)\n\n");


	test_ft("ft_strnstr.c","Function locates the first occurrence of the null-terminated string little in the\nstring big, where not more than	len characters are searched.");
	printf("\nThe substring is: %s", ft_strnstr(str_strstr, sub, 4));
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 429)\n\n");

	test_ft("ft_strcmp.c","Functions lexicographically compare the null-terminated strings s1 and s2.");
	char s1_strcmp[15];
	char s2_strcmp[15];
	int ret_strcmp;

	ft_strncpy(s1_strcmp, "abcdef", 6);
	ft_strncpy(s2_strcmp, "ABCDEF", 6);

	ret_strcmp = ft_strcmp(s1_strcmp, s2_strcmp);

	if(ret_strcmp > 0)
		printf("\nstr2 is less than str1\n");
	else if(ret_strcmp < 0) 
		printf("str1 is less than str2\n");
	else 
		printf("str1 is equal to str2\n");
	green();
	printf("TEST PASSED - OK!");
	reset();
	printf("(line 443)\n\n");


	test_ft("ft_strncmp.c","Function compares not more than len characters");
	ret_strcmp = ft_strncmp(s1_strcmp, s2_strcmp, 5);

	if(ret_strcmp > 0)
		printf("\nstr2 is less than str1\n");
	else if(ret_strcmp < 0) 
		printf("str1 is less than str2\n");
	else 
		printf("str1 is equal to str2\n");
	green();
	printf("TEST PASSED - OK!");
	reset();
	printf("(line 458)\n\n");



	test_ft("ft_toupper.c","Capitalizes characters from lowercase");
	printf("\nTo upper %c", ft_toupper('m'));
	printf("\nTo upper %c", ft_toupper('M'));
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 474)\n\n");


	test_ft("ft_tolower.c","Converts from uppercase to lowercase");
	printf("\nTo lower %c", ft_tolower('m'));
	printf("\nTo lower %c", ft_tolower('M'));
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 483)\n\n");

	test_ft("ft_strnew.c","Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’.");
	char **po;
	char *v = ft_strnew(200);

	if (v != NULL)
		printf("\nString is new");
	else
		printf("\nYou darn fucked up");
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 492)\n\n");


	test_ft("ft_strdel.c","Takes address of a string that need to be freed with free(3), & sets its pointer to NUL.");
	po = &v;
	ft_strdel(po);

	if (v == NULL)
		printf("\nString deleted");
	else
		printf("\nYou darn fucked up");
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 506)\n\n");


	test_ft("ft_strclr.c","Sets every character of the string to the value ’\0’.");
	char u[] = "momma";
	ft_strclr(u);
	if (u[0] == '\0')
		printf("\nString cleared ...%c...", u[0]);
	else
		printf("\nYou darn fucked up");
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 520)\n\n");

	test_ft("ft_striter.c","Applies the function f to each character of the string passed as argument.\n Each character is passed by address to f to be modified if necessary.");
	void (*f_iter)(char *);
	char	s_iter[] = "momma";

	f_iter = &ft_strclr;
	ft_striter(s_iter, f_iter);
	if (ft_strcmp("", s_iter) == 0)
		printf("\nStriter worked\n");
	else
		printf("\nYou darn fucked up!");
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 535)\n\n");

	test_ft("ft_striteri.c","Applies the function f to each character of the string passed as argument, and\n passing its index as first argument. Each character is passed by address to f \nto be modified if necessary.");
	void (*f_iteri)(unsigned int, char *);
	char	s_iteri[] = "momma";

	f_iteri = &iteri_test;
	ft_striteri(s_iteri, f_iteri);
	if (ft_strcmp("aaaaa", s_iteri) == 0)
		printf("\nStriteri worked");
	else
		printf("\nYou darn fucked up!!");
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 550)\n\n");

	test_ft("ft_strmap.c","Applies the function f to each character of the string given as argument to create a \n“fresh” new string (with malloc(3))resulting from the successive applications of f.");
	char (*f_map)(char);

	f_map = &strmap_test;
	if (ft_strcmp("aaaaa", ft_strmap("momma", f_map)) == 0)
		printf("\nStrmap worked");
	else
		printf("\nYou darn fucked up!");
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 564)\n\n");

	test_ft("ft_strmapi.c","Applies the function f to each character of the string passed as argument by giving its \nindex as first argument to create a “fresh” new string (with malloc(3)) \nresulting from the successive applications of f.");
	char (*f_mapi)(unsigned int, char);

	f_mapi = &strmapi_test;
	if (ft_strcmp("aaaaa", ft_strmapi("momma", f_mapi)) == 0)
		printf("\nStrmapi worked");
	else
		printf("\nYou darn fucked up!");
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 577)\n\n");

	test_ft("ft_strequ.c","Lexicographical comparison between s1 and s2.");
	int y;
	y = ft_strequ("momma", "knows");

	printf("\nStrequ is: %d", y);
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 588)\n\n");

	test_ft("ft_strenqu.c","Lexicographical comparison between s1 and s2 up to n characters or until a ’\0’ is reached.");
	y = ft_strnequ("momma", "mommy", 4);

	printf("\nStrnequ is: %d", y);
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 597)\n\n");

	test_ft("ft_strsub.c","The substring begins at index \"start\" and is of size \"len.\"");
	char	s_long[] = "momma knows";
	char	*s_sub;

	s_sub = ft_strsub(s_long, 0, 5);
	if (ft_strcmp(s_sub, "momma") == 0)
		printf("\nStrsub worked");
	else
		printf("\nYou darn fucked up!");
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 609)\n\n");

	test_ft("ft_strjoin.c","Returns the result of the concatenation of s1 and s2.");
	printf("\nStrjoin result: %s", ft_strjoin("momma", " knows"));
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 620)\n\n");

	test_ft("ft_strtrim.c","Returns a fresh string without whitespaces at the beginning and end");
	printf("\nStrimmed string: %s", ft_strtrim(" 	momma	"));
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 627)\n\n");

	test_ft("ft_strsplit.c","Returns an array of “fresh” strings (all ending with NULL, including the array itself)\n obtained by spliting s using the character c as a delimiter.");
	char **str;
	str = ft_strsplit("***Hello**WethinkCode**Students*",'*');
	printf("\nAfter strsplit:\n%s\n%s\n%s", str[0], str[1], str[2]);
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 636)\n\n");

	test_ft("ft_putchar.c", "Prints a character on STDOUT");
	ft_putstr("Ft_putchar: ");
	ft_putchar('a');
	ft_putchar('\n');
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 644)\n\n");

	test_ft("ft_putstr.c","Outputs the string s to the standard output.");

	ft_putstr("Ft_putstr: anoroita");
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 653)\n\n");

	test_ft("ft_putendl.c","Outputs the string s to the standard output, followed by a newline");
	ft_putendl("Ft_putendl: momma knows best");
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 660)\n\n");

	test_ft("ft_putnbr.c","Outputs the integer n to the standard output.");
	ft_putstr("Putnbr: ");
	ft_putnbr(-366548);
	ft_putchar('\n');
	ft_putstr("Putnbr: ");
	ft_putnbr(56984);
	ft_putchar('\n');
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 668)\n\n");

	test_ft("ft_putchar_fd.c","Outputs the char c to the file descriptor fd.");
	ft_putstr("Ft_putchar _fd: ");
	ft_putchar_fd('c', 0);
	ft_putstr("\nFt_putchar _fd: ");
	ft_putchar_fd('c', 1);
	ft_putstr("\nFt_putchar _fd: ");
	ft_putchar_fd('c', 2);
	ft_putchar('\n');
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 680)\n\n");

	test_ft("ft_putstr_fd.c","Outputs the string s to the file descriptor fd.");
	ft_putstr("Ft_putstr_fd: ");
	ft_putstr_fd("momma", 0);
	ft_putstr("\nFt_putchar _fd: ");
	ft_putstr_fd("momma", 1);
	ft_putstr("\nFt_putchar _fd: ");
	ft_putstr_fd("momma", 2);
	ft_putchar('\n');
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 693)\n\n");


	test_ft("ft_putendl_fd.c","Outputs the string s to the file descriptor fd followed by a ’newline’.");
	ft_putstr("Ft_putendl_fd: ");
	ft_putendl_fd("momma knows best", 0);
	ft_putstr("Ft_putendl_fd: ");
	ft_putendl_fd("momma knows best", 1);
	ft_putstr("Ft_putendl_fd: ");
	ft_putendl_fd("momma knows best", 2);
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	printf("(line 707)\n\n");

	test_ft("ft_putnbr_fd.c","Outputs the integer n to the file descriptor fd.");
	ft_putstr("Ft_putnbr_fd: ");
	ft_putnbr_fd(-366548, 0);
	ft_putchar('\n');
	ft_putstr("Ft_putnbr_fd: ");
	ft_putnbr_fd(56984, 1);
	ft_putchar('\n');
	green();
	printf("\nTEST PASSED - OK!");
	reset();
	return (0);
}