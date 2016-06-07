/**
 * \file effects.h
 * \brief effect handling
 *
 * Copyright (c) 2007 Andi Sidwell
 * Copyright (c) 2014 Ben Semmler, Nick McConnell
 *
 * This work is free software; you can redistribute it and/or modify it
 * under the terms of either:
 *
 * a) the GNU General Public License as published by the Free Software
 *    Foundation, version 2, or
 *
 * b) the "Angband licence":
 *    This software may be copied and distributed for educational, research,
 *    and not for profit purposes provided that this copyright and statement
 *    are included in all such copies.  Other copyrights may also apply.
 */
#ifndef INCLUDED_EFFECTS_H
#define INCLUDED_EFFECTS_H

#include "object.h"

/* Types of effect */
typedef enum
{
	EF_NONE,
	#define EFFECT(x, a, b, c, d, e)	EF_##x,
	#include "list-effects.h"
	#undef EFFECT
	EF_MAX
} effect_index;

/*** Functions ***/

bool remove_all_curse(void);

void free_effect(struct effect *source);
bool effect_valid(struct effect *effect);
bool effect_aim(struct effect *effect);
const char *effect_info(struct effect *effect);
const char *effect_desc(struct effect *effect);
effect_index effect_lookup(const char *name);
int effect_param(int index, const char *type);
bool effect_do(struct effect *effect, struct object *obj, bool *ident,
			   bool aware, int dir, int beam, int boost);
void effect_simple(int index, const char* dice_string, bool *ident, int p_count, ...);

#endif /* INCLUDED_EFFECTS_H */
