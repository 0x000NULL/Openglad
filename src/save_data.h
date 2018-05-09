#ifndef _SAVE_DATA_H__
#define _SAVE_DATA_H__

#include "SDL.h"
#include <string>
#include <map>
#include <set>
#include <list>

class guy;
class walker;

#define MAX_TEAM_SIZE 24 //max # of guys on a team

class SaveData
{
public:
    
    std::string save_name;
    std::string current_campaign;
    short scen_num;
    std::map<std::string, std::set<int> > completed_levels;
    std::map<std::string, int> current_levels;
    Uint32 score;
    Uint32 m_score[4];
    Uint32 totalcash;
    Uint32 m_totalcash[4];
    Uint32 totalscore;
    Uint32 m_totalscore[4];
    short my_team;
    // Guys used for training and stuff.  After a mission, the team is picked from the LevelData's oblist for saving.
    guy* team_list[MAX_TEAM_SIZE];
    unsigned char team_size;
    unsigned char numplayers; //numviews
    short allied_mode;
    
    SaveData();
    ~SaveData();
    
    void reset();
    
    void update_guys(std::list<walker*>& oblist);  // Copy team from the guys in an oblist
    bool load(const std::string& filename);
    bool save(const std::string& filename);
    
    bool is_level_completed(int level_index) const;
    int get_num_levels_completed(const std::string& campaign) const;
    void add_level_completed(const std::string& campaign, int level_index);
    void reset_campaign(const std::string& campaign);
};

#include "walker.h"

#endif
