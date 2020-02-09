
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 03:05:36 by sscottie          #+#    #+#             */
/*   Updated: 2020/01/27 19:56:57 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int		go_find_shortcut(t_ps *all, int min_index, int max_index)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	all->a = all->head_b;
	while (all->a->num_index != min_index && all->a->num_index != max_index)
	{
		i++;
		all->a = all->a->next;
	}
	all->a = all->tail_b;
	while (all->a->num_index != min_index && all->a->num_index != max_index)
	{
		k++;
		all->a = all->a->prev;
	}
	if (i <= k)
		return (1);
	else
		return (2);
}

void	worse_but_works(t_ps *all)
{
	int	i;

	i = 0;
	while (i < all->total)
	{
		if (all->head_a->num_index == all->min)
		{
			ra(all);
			all->min++;
		}
		else if (all->head_a->num_index == all->max)
		{
			pb(all);
			rb(all);
			all->max--;
		}
		else
		{
			pb(all);
		}
		i++;
	}
	all->max = all->total - 1;
	all->mark_type = 0;
	while (all->size_b != 0)
	{
		if (all->mark_type == 0)
			all->mark_type = go_find_shortcut(all, all->min, all->max);
		if (all->head_b->num_index == all->max)
		{
			pa(all);
			all->max--;
			all->mark_type = 0;
		}
		else if (all->head_b->num_index == all->min)
		{
			pa(all);
			ra(all);
			all->min++;
			all->mark_type = 0;
		}
		else
		{
			if (all->mark_type == 1)
				rb(all);
			else if (all->mark_type == 2)
				rrb(all);
		}
	}
	final_rotate(all);
	// print_ps(all);
}

void	final_rotate(t_ps *all)
{
	int i;
	int	k;

	if (!check_is_sorted(all->head_a))
	{
		i = 0;
		k = 0;
		all->a = all->head_a;
		while (all->a->num_index != 0)
		{
			i++;
			all->a = all->a->next;
		}
		all->a = all->tail_a;
		while (all->a->num_index != 0)
		{
			k++;
			all->a= all->a->prev;
		}
		if (i <= k)
			while (!check_is_sorted(all->head_a))
				ra(all);
		else
			while (!check_is_sorted(all->head_a))
				rra(all);
	}
}

// static void swap ( int* a, int* b ) 
// { int t = *a; *a = *b; *b = t; } 

// t_stack *lastNode(t_stack *root) 
// { 
//     while (root && root->next) 
//         root = root->next; 
//     return root; 
// } 

// t_stack	*partition(t_stack *l, t_stack *h) 
// {
// 	// set pivot as h element 
// 	int	x; 
// 	// similar to i = l-1 for array implementation 
// 	t_stack *i;
// 	t_stack *j;
// 	x = h->num_index;
// 	i = l->prev;
// 	j = l;
// 	// Similar to "for (int j = l; j <= h- 1; j++)" 
// 	while (j != h)
// 	{
// 		if (j->num_index <= x)
// 		{
// 			// Similar to i++ for array
// 			i = (i == NULL) ? l : i->next;

// 			swap(&(i->num_index), &(j->num_index));
// 			j = j->next;
// 		}
// 	}
// 	i = (i == NULL) ? l : i->next; // Similar to i++
// 	swap(&(i->num_index), &(h->num_index));
// 	return (i);
// } 

// void _quickSort(t_stack* l, t_stack *h) 
// {
// 	t_stack *p;

//     if (h != NULL && l != h && l != h->next) 
//     { 
//         p = partition(l, h); 
//         _quickSort(l, p->prev); 
//         _quickSort(p->next, h); 
//     } 
// } 

// void quickSort(t_ps *all, t_stack *head) 
// { 
// 	t_stack	*h;

// 	h = lastNode(head);

//     _quickSort(head, h);
// } 

void	algo(t_ps *all, int br_n1)
{
	int	i;
	int turn;
	int	k;

	i = 0;
	k = 0;
	turn = all->size_a;
	while (i < turn && k <= all->total - br_n1)
	{
		if (all->head_a->num_index >= br_n1)
		{
			pb(all);
			k++;
			if (all->size_b >= 2 && all->head_b->num_index > all->head_b->next->num_index)
			{
				if (all->head_a->num_index < all->head_a->next->num_index)
					ss(all);
				else
					sb(all);
			}
		}
		else
		{
			ra(all);
		}
		i++;
	}
	// while (!check_is_sorted(all->head_b))
	// {
	// 	if (all->head_b->num_index > all->head_b->next->num_index)
	// 	{
	// 		if (all->head_a->num_index < all->head_a->next->num_index)
	// 				ss(all);
	// 			else
	// 				sb(all);
	// 	}
	// 	else
	// 	{
	// 		rb(all);
	// 	}
	// }
	if (all->size_a > 5)
		algo(all, br_n1 - 3);
	do_best_of_three(all);
	// // quickSort(all, all->head_a);
	// int i;
	// int	k;
	// int	l;
	// i = 0;
	// k = 0;
	// l = 0;
	
	// while (i <  all->total)
	// {
	// 	if (all->head_a->num_index <= br_n1)
	// 	{
	// 		l = 0;
	// 		pb(all);
	// 		// while (all->tail_a->num_index > all->head_b->num_index && all->head_a->num_index <= br_n2)
	// 		// {
	// 		// 	rra(all);
	// 		// 	l++;
	// 		// }
	// 		pa(all);
	// 		ra(all);
	// 		// while (--l >= 0)
	// 		// 	ra(all);
	// 	}
	// 	else if (all->head_a->num_index > br_n1 && all->head_a->num_index <= br_n2)
	// 	{
	// 		ra(all);
	// 		l = 0;
	// 		k = 0;
	// 		while (all->head_a->num_index > br_n1 && all->head_a->num_index <= br_n2)
	// 		{
	// 			pb(all);
	// 			l++;
	// 		}
	// 		while (all->tail_a->num_index <= br_n1)
	// 		{
	// 			rra(all);
	// 			k++;
	// 		}
	// 		while (--l >= 0)
	// 		{
	// 			pa(all);
	// 			ra(all);
	// 		}
	// 		while(--k >= 0)
	// 			ra(all);
	// 	}
	// 	else if (all->head_a->num_index > br_n2 && all->head_a->num_index <= br_n3)
	// 	{
	// 		if (all->head_b == NULL)
	// 			pb (all);
	// 		else if (all->head_a->num_index < all->head_b->num_index)
	// 		{
	// 			if (all->head_a->num_index < all->tail_b->num_index)
	// 			{
	// 				while ((all->head_a->num_index < all->tail_b->num_index) && all->head_a->num_index > br_n2 && all->head_a->num_index <= br_n3)
	// 				{
	// 					if ((all->head_a->next->num_index < all->head_a->num_index) && all->head_a->next->num_index > br_n2 && all->head_a->next->num_index <= br_n3)
	// 						sa(all);
	// 					if (all->head_a->num_index < all->tail_b->num_index)
	// 					{
	// 						pb(all);
	// 						rb(all);
	// 					}
	// 				}
	// 			}
	// 			else
	// 			{
	// 				l = 0;
	// 				while (all->head_a->num_index > all->tail_b->num_index)
	// 				{
	// 					rrb(all);
	// 					l++;
	// 				}
	// 				pb(all);
	// 				while (--l >= 0)
	// 				{
	// 					if (all->head_a->num_index > br_n2 && all->head_a->num_index <= br_n3)
	// 					{
	// 						if (all->head_a->num_index > all->head_b->num_index && all->head_a->num_index < all->tail_b->num_index)
	// 							pb(all);
	// 						else if (all->head_a->num_index > all->tail_b->num_index)
	// 						{
	// 							rrb(all);
	// 							l++;
	// 						}
	// 						else if (all->head_a->num_index < all->head_b->num_index && --l >= 0)
	// 							rb(all);
	// 					}
	// 					else
	// 						rb(all);
	// 				}
	// 			}
	// 		}
	// 		else
	// 			pb(all);
	// 	}
	// 	else if (all->head_a->num_index > br_n3)
	// 	{
	// 		l = 0;
	// 		if (all->head_b == NULL)
	// 			pb(all);
	// 		else if (all->head_a->num_index < all->head_b->num_index)
	// 		{
	// 			while ((all->head_a->num_index < all->head_b->num_index) && all->head_a->num_index > br_n3)
	// 			{
	// 				rb(all);
	// 				l++;
	// 			}
	// 			pb(all);
	// 			while (--l >= 0)
	// 			{
	// 				if ((all->head_a->num_index < all->head_b->num_index) && all->head_a->num_index > br_n3)
	// 				{
	// 					rb(all);
	// 					pb(all);
	// 					l++;
	// 				}
	// 				else if ((all->head_a->num_index > all->head_b->num_index && all->head_a->num_index < all->tail_b->num_index) && all->head_a->num_index > br_n3)
	// 					pb(all);
	// 				else
	// 					rrb(all);
	// 			}
	// 		}
	// 		else
	// 			pb(all);
	// 	}
	// 	i++;
	// }
	// if (all->total / 30 > br_n1)
	// 	algo(all, br_n1 / 2, br_n2 / 2, br_n3 / 2);
}

void	do_best_of_three(t_ps *all)
{
	if (all->head_a->num_index < all->head_a->next->num_index)
	{
		if (all->head_a->num_index > all->head_a->next->next->num_index)
			rra(all);	
		else
		{
			sa(all);
			ra(all);
		}
	}
	else
	{
		if (all->head_a->num_index > all->head_a->next->next->num_index)
		{
			if (all->head_a->next->num_index > all->head_a->next->next->num_index)
			{
				sa(all);
				rra(all);
			}
			else
				ra(all);

		}
		else
			sa(all);
	}
}

void	do_for_middle(t_ps *all)
{
	int	i;

	i = 0;
	all->min = 0;
	while (all->size_a > 3)
	{
		if (all->head_a->num_index > 2)
			pb(all);
		else
			ra(all);
	}
	do_best_of_three(all);
	while (all->size_b != 0)
	{
		if (all->head_b->num_index == all->max)
		{
			pa(all);
			all->max--;
		}
		else if (all->head_b->next->num_index == all->max)
		{
			sb(all);
			pa(all);
			all->max--;
		}
		else if (all->tail_b->num_index == all->max)
		{
			rrb(all);
			pa(all);
			all->max--;
		}
	}
	if (all->total - all->min <= all->total - all->max)
		while (all->head_a->num_index != 0)
			rra(all);
	else
		while (all->head_a->num_index != 0)
			ra(all);
	// print_ps(all);
}