#pragma once

#include <Spore\BasicIncludes.h>

#define UpdateValuePtr intrusive_ptr<UpdateValue>

class UpdateValue 
	: public App::IMessageListener
	, public DefaultRefCounted
{
public:
	static const uint32_t TYPE = id("UpdateValue");

	UpdateValue();
	~UpdateValue();

	int AddRef() override;
	int Release() override;
	
	// This is the function you have to implement, called when a message you registered to is sent.
	bool HandleMessage(uint32_t messageID, void* message) override;
};
