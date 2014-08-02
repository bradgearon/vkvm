#ifdef _WIN32
	#pragma comment(lib, "dxva2.lib")
	#include <windows.h>
#include <LowLevelMonitorConfigurationAPI.h>
#endif

using namespace std;

#include <iostream>
#include <functional>
#include <array>
#include <string>
#include <memory>
#include <vector>

#include "Display.h"
#include "DisplayManager.h"
#include "IMonitorProvider.h"