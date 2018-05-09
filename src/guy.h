
#ifndef __GUY_H
#define __GUY_H

#include "base.h"
#include "stats.h"

// Holds attributes for characters.
// Used to store character data in SaveData's team_list.
// Used as walker::myguy in-game for various attribute-dependent effects for walkers who are on the player team.
class guy
{
	public:
		guy ();
		guy (int whatfamily);
		guy (const guy& copy);
		~guy();
		Sint32 query_heart_value(); // how much are we worth?
		walker* create_walker(screen* myscreen);
		walker* create_and_add_walker(screen* myscreen);
		void upgrade_to_level(short level, bool set_xp = true);
		void set_level_number(short level);
		short get_level() const;
		
        float get_hp_bonus() const;
        float get_mp_bonus() const;
        float get_damage_bonus() const;
        float get_armor_bonus() const;
        float get_speed_bonus() const;
        float get_fire_frequency_bonus() const;
        
		void update_derived_stats(walker* w);

		char name[12];
		char family;  // our family
		short strength;
		short dexterity;
		short constitution;
		short intelligence;
		short armor;
		Uint32 exp;
		short kills;       // version 3+
		Sint32 level_kills;  // version 3+
		Sint32 total_damage; // version 4+  // This will not be exact after changing damage to floating point, but binary serialization of floats is messy.
		Sint32 total_hits;   // version 4+
		Sint32 total_shots;  // version 4+
		short teamnum;     // version 5+
		
		// Stats for the last battle
		float scen_damage;
		short scen_kills;
		float scen_damage_taken;
		float scen_min_hp;
		short scen_shots;
		short scen_hits;
        
        // In ID for comparing old guys with their duplicated counterparts after battle
        int id;
        
    protected:
        short level;
};

#endif

