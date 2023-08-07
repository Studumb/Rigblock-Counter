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
	//Whenever an editor is launched it will add the counter
	if (Editor.IsActive()) {
		//CounterUI is defined in AddCounter.h
		//We will load the layout of the counter
		CounterUI->LoadByName(u"rigblockCounter");
		//0x330C1CA5 is the controlID of the Complexity Meter
		//The counter will automatically hide when its parent window hide
		CounterUI->SetParentWindow(WindowManager.GetMainWindow()->FindWindowByID(0x330C1CA5));
		//After the counter has its parent window we will change the location of it
		CounterUI->FindWindowByID(id("rigCounter"))->SetLocation(-110, 0);		
	}
	return true;
}
