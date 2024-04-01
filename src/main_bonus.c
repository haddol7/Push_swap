/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeha <daeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:02:49 by daeha             #+#    #+#             */
/*   Updated: 2024/04/01 18:20:16 by daeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	leaks(void)
{
	system("leaks checker");
}

void	terminate(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	check_stack_sorted_free(t_total *stack)
{
	int		is_sorted;

	is_sorted = 1;
	if (stack->b.size != 0)
	{
		while (stack->b.size > 0)
			free(pop(&stack->b, BOT));
		is_sorted = 0;
	}
	while (stack->a.size > 0)
	{
		if (stack->a.size > 1 && stack->a.top->val > stack->a.top->next->val)
			is_sorted = 0;
		free(pop(&stack->a, TOP));
	}
	if (is_sorted == 0)
		ft_printf("KO");
	else
		ft_printf("OK");
}

int main(int argc, char **argv)
{
	t_total	stack;
	t_node	*temp;
	char	*command;
	int		is_eof;

	atexit(leaks);
	if (argc <= 1)
		return (1);
	ft_memset(&stack, 0, sizeof(t_total));
	stack.size = put_value_in_stack_a(argc, argv, &stack.a);
	check_elem_dup(stack.a);
	is_eof = 0;
	while (!is_eof)
	{
		command = get_next_line(0);
		is_eof = command_to_stack(&stack, command);
		if (command != NULL)
			free(command);
	}
	check_stack_sorted_free(&stack);
	return (0);
}




