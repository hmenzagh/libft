/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:21:20 by hmenzagh          #+#    #+#             */
/*   Updated: 2016/12/01 13:33:04 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			psf_init(t_psf *db)
{
	db->psf_s[0] = load_i;
	db->psf_s[1] = load_s_char;
	db->psf_s[2] = load_short;
	db->psf_s[3] = load_ll;
	db->psf_s[4] = load_l;
	db->psf_s[5] = load_imax;
	db->psf_s[6] = load_sst;
	db->psf_u[0] = load_ui;
	db->psf_u[1] = load_u_char;
	db->psf_u[2] = load_ushort;
	db->psf_u[3] = load_ull;
	db->psf_u[4] = load_ul;
	db->psf_u[5] = load_uimax;
	db->psf_u[6] = load_st;
}
