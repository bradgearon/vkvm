#include "DisplayManager.h"

DisplayManager::DisplayManager(unique_ptr<IMonitorProvider> provider)
{
	_provider = move(provider);
}

void DisplayManager::LoadMonitors()
{
	_provider->GetMonitors();
}

void DisplayManager::ChangeOption(unsigned int index, 
	VCPOption option, unsigned int value)
{
	_provider->ChangeOption(index, option, value);
}

