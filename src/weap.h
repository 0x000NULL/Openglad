\
#ifndef __WEAP_H
#define __WEAP_H

// Definition of WEAP class

#include "base.h"
#include "walker.h"

class weap : public walker
{
	public:
		weap(const PixieData& data);
		virtual ~weap();

		short act();
		short animate();
		short death(); // called on destruction
		short setxy(short x, short y);
		char  query_order()
		{
			return ORDER_WEAPON;
		}

		// Weapons-only related variables; use with care
		Sint32 do_bounce; // do we bounce?

};

#endif


