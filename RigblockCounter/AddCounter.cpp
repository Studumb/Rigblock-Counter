#include "stdafx.h"
#include "AddCounter.h"

AddCounter::AddCounter()
{
}

AddCounter::~AddCounter()
{
}

// For internal use, do not modify.
int AddCounter::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int AddCounter::Release()
{
	return DefaultRefCounted::Release();
}


bool AddCounter::HandleMessage(uint32_t messageID, void* message)
{
	if (Editor.IsActive()) {
		CounterUI->LoadByName(u"rigblockCounter");
		CounterUI->SetParentWindow(WindowManager.GetMainWindow()->FindWindowByID(0x330C1CA5));
		CounterUI->FindWindowByID(id("rigCounter"))->SetLocation(-110, 0);
	}
	return true;
}
