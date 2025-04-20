#include "stdafx.h"
#include "RigblockCounter.h"

UILayoutPtr counter;
string16 rigblockNum;

//Add the counter
bool Editor_OnEnter__detour::detoured() {
	counter = new UTFWin::UILayout();
	counter->LoadByName(u"rigblockCounter");
	counter->FindWindowByID(id("rigCounter"))->AddWinProc(new UTFWin::SimpleLayout(UTFWin::kAnchorTop | UTFWin::kAnchorRight));
	counter->FindWindowByID(id("rigCounter"))->SetArea({ -300, 10, 0, 0 });
	return original_function(this);
}

//Remove when exit editors
bool Editor_OnExit__detour::detoured() {
	WindowManager.GetMainWindow()->RemoveWindow(WindowManager.GetMainWindow()->FindWindowByID(id("rigCounter")));
	return original_function(this);
}

//Hide the counter when change mode
bool Editor_SetActiveMode__detour::detoured(Editors::Mode mode, bool) {
	if (mode == Editors::Mode::BuildMode)
		counter->FindWindowByID(id("rigCounter"))->SetFlag(UTFWin::kWinFlagVisible, true);
	else
		counter->FindWindowByID(id("rigCounter"))->SetFlag(UTFWin::kWinFlagVisible, false);
	return original_function(this, mode, true);
}

//Update the value shown on the counter
void Editor_Update__detour::detoured(float delta1, float delta2) {
	rigblockNum.assign_convert(to_string(Editor.GetEditorModel()->GetRigblocksCount()));
	if (WindowManager.GetMainWindow()->FindWindowByID(id("rigDisplayer")) != nullptr)
		WindowManager.GetMainWindow()->FindWindowByID(id("rigDisplayer"))->SetCaption(rigblockNum.c_str());
	original_function(this, delta1, delta2);
}