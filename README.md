# ft_printf

[![cboutier's 42 ft_printf Score](https://badge42.vercel.app/api/v2/cl1f9y1k8000609jsc4a29jay/project/2191487)](https://github.com/JaeSeoKim/badge42)

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

**HOW TO RUN THE PROGRAM:**  
`make`  
`./ft_printf`
