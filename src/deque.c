/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeha <daeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:40:25 by daeha             #+#    #+#             */
/*   Updated: 2024/03/30 23:05:48 by daeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/deque.h"

//sa 1 = pop(a, TOP) 1 = pop(a, TOP)
//sb
//ss
//pa push(a, pop(b, TOP), TOP)
//pb push(b, pop(a, TOP), TOP)
//ra 
//rb
//rr
//rra
//rrb
//rrr

void	push(t_stack *stack, t_node *node, e_pos pos)
{
	if (node == NULL)
		return ;
	if (stack->size == 0)
	{
		stack->bot = node;
		stack->top = node;
	}
	else
	{
		node->prev = stack->bot;
		node->next = stack->top;
		stack->bot->next = node;
		stack->top->prev = node;
		if (pos == TOP)
			stack->top = node;
		else
			stack->bot = node;
	}
	stack->size++;
}
t_node	*pop(t_stack *stack, e_pos pos)
{
	t_node *node;
	
	if (stack->size == 0)
		return (NULL);
	else
	{
		if (pos == TOP)
		{
			node = stack->top;
			stack->top = node->next;
		}
		else
		{
			node = stack->bot;
			stack->bot = node->prev;
		}
		stack->bot->next = stack->top;
		stack->top->prev = stack->bot;
	}
	stack->size--;
	return (node);
}

