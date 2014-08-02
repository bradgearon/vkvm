#pragma once
class Display
{
public:
	Display(void* handle);
	const void* GetHandle();
private: 
	void* _handle;
};

