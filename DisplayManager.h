#pragma once

#include "Common.h"

class DisplayManager
{
public:
	DisplayManager(unique_ptr<IMonitorProvider> provider);
	void LoadMonitors();
	void ChangeOption(unsigned int index, enum VCPOption option, unsigned int value);
private:
	unique_ptr<IMonitorProvider> _provider;
};

