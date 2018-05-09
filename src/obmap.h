#ifndef __OBMAP_H
#define __OBMAP_H

// Definition of OBMAP class

#include "base.h"
#include <map>
#include <list>

class obmap
{
	public:
		obmap();
		~obmap();
		short query_list(walker  *ob, short x, short y);
		short remove(walker  *ob);  // This goes in walker's destructor
		short add(walker  *ob, short x, short y);  // This goes in walker's constructor
		short move(walker  *ob, short x, short y);  // This goes in walker's setxy
		std::list<walker*>& obmap_get_list(short x, short y); //Returns the list at x,y for fnf
		short obmapres;
		size_t size() const;
		void draw();
		
		std::map<std::pair<short, short>, std::list<walker*> > pos_to_walker;
		std::map<walker*, std::list<std::pair<short, short> > > walker_to_pos;
		
	private:
		short hash(short y);
		short unhash(short y);
};

#endif
