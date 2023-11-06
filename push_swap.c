#include "push_swap.h"

void	push_swap(char *nb)
{
	s_list	*sa;
	s_list	*sb;
	int		i;

	i = 0;
	sa = create_stack(nb);
	if (!sa)
		return ;
	sb = create_stack_b(sa->size);
	if (!sb)
		return ;
	display_stack(sa, 'a');
	display_stack(sb, 'b');
}
//int	main(int argc, char **argv)
int	main(void)
{
	//char	nb[1000] = ""; /*1*/
	//char	*nb = NULL; /*2*/
	//char	nb[1000] = "100"; /*3*/
	char	nb[1000] = "a"; /*4*/
	// char	nb[1000] = " 100 1000"; /*5*/
	// char	nb[1000] = "  100 1000"; /*5*/
	// char	nb[1000] = "100 1000 "; /*6*/
	// char	nb[1000] = "100 1000  "; /*6*/
	// char	nb[1000] = " 100 1000 "; /*7*/
	// char	nb[1000] = "  100 1000  "; /*7*/
	// char	nb[1000] = "100  1000"; /*8*/
	// char	nb[1000] = "1 2  3 4  5"; /*8*/
	// char	nb[1000] = "100a"; /*9*/
	// char	nb[1000] = "100b"; /*9*/
	// char	nb[1000] = "--100"; /*10*/
	// char	nb[1000] = "-100 --10000"; /*10*/
	// char	nb[1000] = "Phanuwat Vudthichai Rangsu n"; /*11*/

	printf("--- Input Number ---\n");
	push_swap(nb);
	return 0;
}

//Error condition for input
/*
1. empty string : ""
2. NULL address : NULL \\ result : segmentation fault
3. 1 number : "100"
4. 1 character : "a"
5. start with 'space' or 'double space' : " 100 1000" , "  100 1000"
6. end with 'space' or 'double space' : "100 1000 " , "100 1000  "
7. start and end with 'space' or 'double space' : " 100 1000 ", "  100 1000  "
8. contain double space : "100  1000", "1 2  3 4  5"
8. Value more than maximum- minimum int : "??"
9. string contain character : "100a", "100b"
10. negative number & double negative sign : "--100", "-100 --1000"
11. many character : "Phanuwat Vudthichai Rangsu n \t"
*/
