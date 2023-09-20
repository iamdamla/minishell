/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:50:50 by acaplat           #+#    #+#             */
/*   Updated: 2023/09/13 14:58:10 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_element(t_elem **head, char data)
{
	t_elem	*newelem;
	t_elem	*current;

	newelem = malloc(sizeof(t_elem));
	if (!newelem)
		return ;
	newelem->data = data;
	newelem->next = NULL;
	if (*head == NULL)
	{
		newelem->prev = NULL;
		*head = newelem;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = newelem;
	newelem->prev = current;
}

void	printlist(t_elem *head)
{
	t_elem	*current;

	current = head;
	while (current != NULL)
	{
		printf("%c", current->data);
		current = current->next;
	}
	printf("\n");
}

t_elem	*create_elem(char data)
{
	t_elem	*newelem;

	newelem = malloc(sizeof(t_elem));
	newelem->data = data;
	newelem->next = NULL;
	newelem->prev = NULL;
	return (newelem);
}

void	insert_after(t_elem *lst, char newdata)
{
	t_elem	*newelem;

	newelem = create_elem(newdata);
	{
		newelem->next = lst->next;
		if (lst->next != NULL)
		{
			lst->next->prev = newelem;
		}
		newelem->prev = lst;
		lst->next = newelem;
	}
}

void	processlist(t_elem *head, char targetchar, char newdata)
{
	t_elem	*current;

	current = head;
	while (current != NULL)
	{
		if (current->data == targetchar)
		{
			if (current->prev != NULL)
				insert_after(current->prev, newdata);
			if (current->next != NULL)
			{
				insert_after(current, newdata);
				current = current->next;
			}
		}
		current = current->next;
	}
}
