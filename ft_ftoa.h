/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftoa.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 15:39:32 by jsaariko       #+#    #+#                */
/*   Updated: 2020/03/09 18:52:26 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FTOA_H
# define FT_FTOA_H

int	get_last_dec(double num, ssize_t precision);
int round_dec(int *last, int comp, double num, int prec);

#endif
