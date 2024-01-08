#include "sort.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	sort_numbers(int *num1, int *num2, int *num3)
{
	if (*num1 > *num2)
		swap(num1, num2);
	if (*num2 > *num3)
		swap(num2, num3);
	if (*num1 > *num2)
		swap(num1, num2);
}

void	assign_lane(t_list *stack, int *top, int *mid, int *bot)
{
	int	sorted[3];
	int	i;

	i = 0;
	sorted[0] = stack->n_1;
	sorted[1] = stack->n_2;
	sorted[2] = stack->n_3;
	sort_numbers(&sorted[0], &sorted[1], &sorted[2]);
	while (i < 3)
	{
		if (sorted[i] == stack->n_1)
			*top = i + 1;
		else if (sorted[i] == stack->n_2)
			*mid = i + 1;
		else if (sorted[i] == stack->n_3)
			*bot = i + 1;
		i++;
	}
}

void	compare_swap(t_list *ref, int postition)
{
	int		n_1;
	int		n_2;
	t_stack	*stack;

	if (postition == 1 || postition == 3)
		stack = ref->a;
	else
		stack = ref->b;
	n_1 = stack->nb;
	n_2 = stack->next->nb;
	if (n_1 > n_2)
	{
		if (postition == 1 || postition == 3)
			do_sa(ref);
	}
	else if (n_1 < n_2)
	{
		if (postition == 2 || postition == 4)
			do_sb(ref);
	}
}
