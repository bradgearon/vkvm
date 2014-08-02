#include "Common.h"
class WindowsMonitorProvider : public IMonitorProvider {

	bool CALLBACK getMonitorsCallback(HMONITOR monitorHandle, LPCRECT rectangle,
		MONITORENUMPROC enumerator, LPARAM data);

	vector<unique_ptr<Display>> _monitors;

public:
	void GetMonitors();
	void ChangeOption(unsigned int index, 
		VCPOption option, unsigned int value);
};