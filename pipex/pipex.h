/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:07:41 by lalex             #+#    #+#             */
/*   Updated: 2022/03/02 15:45:41 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_PIPEX
# define H_PIPEX

	char	**split_args(char const *s);
	char	**ft_split(char const *s, char c);
	void	clean_strings(char **splitted);
	int		ft_isspace(int c);
	int		ft_isquote(int c);

#endif