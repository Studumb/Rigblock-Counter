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
		//We have to convert from int to wchar_t
		swprintf_s(rignum, L"%d", Editor.GetEditorModel()->GetRigblocksCount());
		//Then cast the value to rigdisplay[4]
		swprintf_s(reinterpret_cast<wchar_t*>(rigdisplay), 4, rignum);
		/*The reason we have to do two steps above because in order to display the value we must change the caption of the window
		but the caption use UNICODE so we have to use char16_t */
		//This line below will find the counter and change its caption
		WindowManager.GetMainWindow()->FindWindowByID(id("rigDisplayer"))->SetCaption(rigdisplay);
	}
	return true;
}
