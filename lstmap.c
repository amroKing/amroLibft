t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	size_t	count;
	t_list	*initial;

	count = ft_lstsize(lst);
	initial = NULL;
	while (count--)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstdelone(new, del);
			return (initial);
		}
		ft_lstadd_back(&initial, new);
		new = new->next;
		lst = lst->next;
	}
	return (initial);
}
