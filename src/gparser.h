
#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <map>

class cfg_store
{
public:
    
	bool load_settings();
	void commandline(int &argc, char **&argv);
    bool save_settings();

    void apply_setting(const std::string& category, const std::string& setting, const std::string& value);
    std::string get_setting(const std::string& category, const std::string& setting);
	bool is_on(const std::string& category, const std::string& setting);

	std::map<std::string, std::map<std::string, std::string> > data;
};

extern cfg_store cfg;

#endif
