void	ft_ultimate_div_mod(int *a, int *b)
{
	int		c;
	int		d;

	c = *a;
	d = *b;
	*a = c / d;
	*b = c % d;
}
