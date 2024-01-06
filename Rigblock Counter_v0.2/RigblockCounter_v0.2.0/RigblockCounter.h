#pragma once

#include <Spore\BasicIncludes.h>
#include <Spore\UTFWin\IText.h>

#define RigblockCounterPtr intrusive_ptr<RigblockCounter>

class RigblockCounter 
	: public Object
	, public DefaultRefCounted
	, public App::IUpdatable
{
public:
	static const uint32_t TYPE = id("RigblockCounter");
	UILayoutPtr window = new UTFWin::UILayout();
	string16 rigblockNum;
	UTFWin::IText* displayer1 = nullptr, * displayer2 = nullptr;

	RigblockCounter();
	~RigblockCounter();
	int getColor(int rigblockNum, int complexity, int viewableFlag);

	int AddRef() override;
	int Release() override;
	void Update() override;
	void* Cast(uint32_t type) const override;
};
