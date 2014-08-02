#include "Common.h"

Display::Display(void* handle) {
	_handle = handle;
}

const void* Display::GetHandle() {
	return _handle;
}