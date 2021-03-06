#include "Service.h"
#include "pattern/Pattern.h"

std::string match(const std::shared_ptr<Pattern> pattern, const std::string& str)
{
	Strings strs;
	strs.push_back(str);
	Strings retStrs = pattern->apply(strs);
	if (retStrs.size() == 0) return "";

	int min = 0;
	for (int i = 1; i < retStrs.size(); i++)
	{
		if (retStrs[i].size() < retStrs[min].size()) min = i;
	}
	return str.substr(0, str.size() - retStrs[min].size());
}

std::string search(const std::shared_ptr<Pattern> pattern, const std::string& str)
{
	std::string result = "";
	for (int i = 0; i < str.size(); i++)
	{
		std::string substr = str.substr(i);
		result = match(pattern, substr);
		if (result != "")
		{
			break;
		}
	}
	return result;
}
