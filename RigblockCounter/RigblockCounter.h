#pragma once

#include <Spore\BasicIncludes.h>

virtual_detour(Editor_OnEnter__detour, Editors::cEditor, App::IGameMode, bool()) {
	bool detoured();
};

virtual_detour(Editor_OnExit__detour, Editors::cEditor, App::IGameMode, bool()) {
	bool detoured();
};

member_detour(Editor_SetActiveMode__detour, Editors::cEditor, bool(Editors::Mode, bool)) {
	bool detoured(Editors::Mode mode, bool);
};

virtual_detour(Editor_Update__detour, Editors::cEditor, App::IGameMode, void(float, float)) {
	void detoured(float delta1, float delta2);
};