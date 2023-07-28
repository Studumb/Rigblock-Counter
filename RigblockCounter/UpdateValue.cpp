#include "stdafx.h"
#include "UpdateValue.h"

UpdateValue::UpdateValue()
{
}


UpdateValue::~UpdateValue()
{
}

// For internal use, do not modify.
int UpdateValue::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int UpdateValue::Release()
{
	return DefaultRefCounted::Release();
}


// The method that receives the message. The first thing you should do is checking what ID sent this message...
bool UpdateValue::HandleMessage(uint32_t messageID, void* message)
{
	if (Editor.IsActive()) {
		wchar_t rignum[4];
		char16_t rigdisplay[4];
		swprintf_s(rignum, L"%d", Editor.GetEditorModel()->GetRigblocksCount());
		swprintf_s(reinterpret_cast<wchar_t*>(rigdisplay), 4, rignum);
		WindowManager.GetMainWindow()->FindWindowByID(id("rigDisplayer"))->SetCaption(rigdisplay);
	}
	return true;
}
