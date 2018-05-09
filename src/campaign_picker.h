
 
#ifndef _CAMPAIGN_PICKER_H__
#define _CAMPAIGN_PICKER_H__

#include "screen.h"
#include <map>
#include <string>

struct CampaignResult
{
    std::string id;
    int first_level;
    
    CampaignResult()
        : first_level(1)
    {}
};

CampaignResult pick_campaign(SaveData* save_data, bool enable_delete = false);

int load_campaign(const std::string& campaign, std::map<std::string, int>& current_levels, int first_level = 1);

#endif
