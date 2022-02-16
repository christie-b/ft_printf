# ft_printf

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/cboutier/ft_printf)](https://github.com/JaeSeoKim/badge42)

Validated on June 15th, 2021

100/100

The goal of this project is to recode the printf() function.

The prototype of ft_printf() is: int ft_printf(const char *, ...);

Here are the requirements:

• Don’t implement the buffer management of the original printf().

• Your function has to handle the following conversions: cspdiuxX%

Specifier | Meaning... |
--- | --- |
**d or i** | int |
**u** | unsigned int |
**x** | hexadecimal number (lowercase) |
**X** | hexadecimal number (uppercase) |
**p** | pointer (= an address) |
**c** | 1 character |
**s** | string |
**%** | print a '%' |

printf width and precision were also implemented, as well as the return value, which is the number of characters it prints.
