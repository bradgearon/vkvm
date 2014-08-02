#pragma once

#include "Common.h"

enum VCPOption : unsigned char {
	VCP_CHANGE_SOURCE = 0x60,
	VCP_POWER_MODE = 0xD6
};

class IMonitorProvider {
	

public:
	
	virtual void GetMonitors() = 0;

	virtual void ChangeOption(unsigned int index, 
		VCPOption option, unsigned int value) = 0;
};