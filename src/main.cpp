#include "Common.h"
#include "WindowsMonitorProvider.h"

void main(string* args) {
	auto monitorProvider = make_unique<WindowsMonitorProvider>();
	auto displayManager = make_unique<DisplayManager>(move(monitorProvider));
	displayManager->LoadMonitors();	
	displayManager->ChangeOption(0, VCPOption::VCP_CHANGE_SOURCE, 0);
	displayManager->ChangeOption(1, VCPOption::VCP_CHANGE_SOURCE, 0);
	displayManager->ChangeOption(2, VCPOption::VCP_CHANGE_SOURCE, 0);

	displayManager->ChangeOption(0, VCPOption::VCP_CHANGE_SOURCE, 1);
	displayManager->ChangeOption(1, VCPOption::VCP_CHANGE_SOURCE, 1);
	displayManager->ChangeOption(2, VCPOption::VCP_CHANGE_SOURCE, 1);


}
