#pragma once

#include <Spore\BasicIncludes.h>

#define AddCounterPtr intrusive_ptr<AddCounter>

class AddCounter 
	: public App::IMessageListener
	, public DefaultRefCounted
{
public:
	static const uint32_t TYPE = id("AddCounter");
	UTFWin::UILayout* CounterUI = new UTFWin::UILayout();

	AddCounter();
	~AddCounter();

	int AddRef() override;
	int Release() override;
	
	bool HandleMessage(uint32_t messageID, void* message) override;
};
