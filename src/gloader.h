
#ifndef __LOADER_H
#define __LOADER_H

// Definition of LOADER class

#include "base.h"

class loader
{
	public:
		loader();
		virtual ~loader(void);
		walker  *create_walker(char order, char family, screen  *screenp, bool cache_weapons = true);
		void set_derived_stats(walker* w, char order, char family);
		pixieN *create_pixieN(char order, char family);
		walker *set_walker(walker *ob, char order, char family);
		PixieData* graphics;
		signed char  ***animations;
		float  *stepsizes;
		Sint32  *lineofsight;
		
		float  hitpoints[200]; // hack for now
		char  *act_types;
		float  *damage;
		float  *fire_frequency;
};

#endif
