#include "push_swap.h"

void	push_swap(char *nb)
{
	
}
int	main(int argc, char **argv)
{

	return 0;
}

//Error condition for input
/*
1. empty string : "" ✘
2. NULL address : NULL ✘ result : segmentation fault
3. 1 number : "100" ✓
4. 1 character : "a" ✓
5. start with 'space' or 'double space' : " 100 1000" , "  100 1000" ✓
6. end with 'space' or 'double space' : "100 1000 " , "100 1000  " ✓
7. start and end with 'space' or 'double space' : " 100 1000 ", "  100 1000  " ✓
8. contain double space : "100  1000", "1 2  3 4  5" ✓
8. Value more than maximum- minimum int : "??" ✘
9. string contain character : "100a", "100b" ✓
10. negative number & double negative sign : "--100", "-100 --1000" ✓
11. many character : "Phanuwat Vudthichai Rangsu n \t" ✓
*/
