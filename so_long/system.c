#include "so_long.h"

void	game_over(t_hero *hero)
{
	ft_printf("\e[1;1H\e[2J");
	if (hero->status & STATUS_WON)
	{
		ft_printf("Congratulations! You've done it!\n");
		ft_printf("You earned %d xp and had %d hp left\n", hero->xp, hero->hp);
	}
	else if (hero->status & STATUS_DEAD)
	{
		ft_printf("Unfortunately, you hero is dead...\n");
		ft_printf("You earned %d xp\n", hero->xp);
		ft_printf("Better luck next time!\n");
	}
	else
	{
		ft_printf("Sorry to see you leave\n");
		ft_printf("It was a nice time together!\n");
		ft_printf("Goodbye!\n");
	}
}
