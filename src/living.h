
#ifndef __LIVING_H
#define __LIVING_H

// Definition of LIVING class

#include "base.h"
#include "walker.h"

class living : public walker
{
	public:
		living(const PixieData& data);
		virtual ~living();
		short          act();
		short          check_special(); // determine if we should do special ..
		short          collide(walker  *ob);
		short          do_action(); // perform overriding action
		walker*        do_summon(char whatfamily, unsigned short lifetime);
		short          facing(short x, short y);
		void           set_difficulty(Uint32 whatlevel);
		short          shove(walker  *target, short x, short y);
		char           query_order()
		{
			return ORDER_LIVING;
		}
		virtual bool walk(float x, float y);
	protected:
		short act_random();
};

#endif

