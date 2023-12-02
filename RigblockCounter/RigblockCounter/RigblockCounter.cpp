#include "stdafx.h"
#include "RigblockCounter.h"

RigblockCounter::RigblockCounter()
{
}

RigblockCounter::~RigblockCounter()
{
}

int RigblockCounter::getColor(int currentComplexity, int editorComplexity, int viewableFlag)
{
	double color = (editorComplexity - currentComplexity) / (editorComplexity / viewableFlag);
	return (int)color;
}

// For internal use, do not modify.
int RigblockCounter::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int RigblockCounter::Release()
{
	return DefaultRefCounted::Release();
}

void RigblockCounter::Update()
{
	//Check if any editors is running
	if (Editor.IsActive()) {
		//Add the counter
		if (WindowManager.GetMainWindow()->FindWindowByID(id("rigCounter")) == nullptr)
			window->LoadByName(u"rigblockCounter");
		//0x330C1CA5 is the controlID of the Complexity Meter
		//The counter uses it as an anchored window
		if (WindowManager.GetMainWindow()->FindWindowByID(0x330C1CA5) != nullptr) {
			window->SetParentWindow(WindowManager.GetMainWindow()->FindWindowByID(0x330C1CA5));
			window->FindWindowByID(id("rigCounter"))->SetLocation(-150, 0);
		}
		else {
			window->FindWindowByID(id("rigCounter"))->AddWinProc(new UTFWin::SimpleLayout(UTFWin::kAnchorTop | UTFWin::kAnchorRight));
			window->FindWindowByID(id("rigCounter"))->SetArea({ -150, 10, 0, 0 });
			//Normally, the counter will be hidden along with the complexity meter when we switch modes
			//But in case there no complexity meter, we will have to hide the counter ourselves
			if (Editor.IsMode(Editors::Mode::BuildMode))
				window->FindWindowByID(id("rigCounter"))->SetFlag(UTFWin::kWinFlagVisible, true);
			else
				window->FindWindowByID(id("rigCounter"))->SetFlag(UTFWin::kWinFlagVisible, false);
		}
		//Update the value shown on the counter
		rigblockNum.assign_convert(to_string(Editor.GetEditorModel()->GetRigblocksCount()));
		window->FindWindowByID(id("rigDisplayer"))->SetCaption(rigblockNum.c_str());
		//Change color of the number depend on the complexity meter color
		displayer1 = object_cast<UTFWin::IText>(window->FindWindowByID(id("rigDisplayer")));
		displayer2 = object_cast<UTFWin::IText>(window->FindWindowByID(id("numRigLeft")));
		auto color = getColor(Editors::GetEditor()->mpEditorLimits->GetValue(1), Editor.mComplexityLimit, Editor.mViewableComplexityFlags);
		//debug
		App::ConsolePrintF("%d", getColor(Editors::GetEditor()->mpEditorLimits->GetValue(1), Editor.mComplexityLimit, Editor.mViewableComplexityFlags));
		App::ConsolePrintF("%d %d %d", Editors::GetEditor()->mpEditorLimits->GetValue(1), Editor.mComplexityLimit, Editor.mViewableComplexityFlags);
	}
	//In case the counter is still visible after any editors are no longer running
	else
		if (WindowManager.GetMainWindow()->FindWindowByID(id("rigCounter")) != nullptr)
			WindowManager.GetMainWindow()->RemoveWindow(WindowManager.GetMainWindow()->FindWindowByID(id("rigCounter")));
}

// You can extend this function to return any other types your class implements.
void* RigblockCounter::Cast(uint32_t type) const
{
	CLASS_CAST(Object);
	CLASS_CAST(RigblockCounter);
	return nullptr;
}