#include "Common.h"
#include "WindowsMonitorProvider.h"

namespace Callbacks {

	function <bool CALLBACK(HMONITOR, LPCRECT, MONITORENUMPROC, LPARAM)> callback;

	bool CALLBACK GetMonitorsCallback(
		HMONITOR monitorHandle, LPCRECT rectangle,
		MONITORENUMPROC enumerator, LPARAM data)
	{
		if (!callback) {
			return false;
		}

		return callback(monitorHandle, 
			rectangle, enumerator, data);
	}
};

void WindowsMonitorProvider::GetMonitors()
{
	using namespace placeholders;

	auto memberFn = &WindowsMonitorProvider::getMonitorsCallback;
	// i can has binded to this function and parameters
	Callbacks::callback = bind(memberFn, this, _1, _2, _3, _4);

	EnumDisplayMonitors(NULL, NULL, 
		(MONITORENUMPROC) Callbacks::GetMonitorsCallback, (const LPARAM) this);
}

bool WindowsMonitorProvider::getMonitorsCallback(
	HMONITOR monitorHandle, LPCRECT rectangle,
	MONITORENUMPROC enumerator, LPARAM data) {

	DWORD monitorCount;

	if (!GetNumberOfPhysicalMonitorsFromHMONITOR(
		monitorHandle, &monitorCount ) )
	{
		return false;
	}
	
	auto physicalMonitors = make_unique<PHYSICAL_MONITOR[]>(monitorCount);
	
	if (!GetPhysicalMonitorsFromHMONITOR(monitorHandle,
		monitorCount, (LPPHYSICAL_MONITOR) physicalMonitors.get() )) {
		return false;
	}
	
	for (auto i = 0; i < monitorCount; i++) {
		void* physicalMonitor = physicalMonitors[i].hPhysicalMonitor;
		auto display = make_unique<Display>(physicalMonitor);
		this->_monitors.emplace_back(display.release());
	}

	physicalMonitors.release();
	return true;
}

void WindowsMonitorProvider::ChangeOption(unsigned int display = 0, 
	VCPOption option = VCPOption::VCP_POWER_MODE, unsigned int value = 0)
{
	const auto handle = (HANDLE)this->_monitors[display]->GetHandle();
	SetVCPFeature(handle, option, (DWORD) value);
}