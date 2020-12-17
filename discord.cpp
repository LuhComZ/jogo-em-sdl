#include "discord.h"
#include <iostream>

Discord::Discord(discord::ClientId id)
{
	this->id = id;
	init();
}

Discord::~Discord()
{
	delete core;
}

void Discord::init()
{
	discord::Result result = discord::Core::Create(this->id, DiscordCreateFlags_NoRequireDiscord, &core);

	if (result == discord::Result::Ok)
	{
		core->SetLogHook(discord::LogLevel::Debug, [](discord::LogLevel level, const char *message) {
			std::cout << "level: " << (int)level << ". Message: " << message << std::endl;
		});
		connected = true;
	}
}

void Discord::update()
{
	if (connected)
	{
		core->RunCallbacks();
	}
	else
	{
		init();
	}
}

void Discord::changePresence(const char *state, const char *details)
{
	if (this->connected)
	{
		this->activity.SetState(state);
		this->activity.SetDetails(details);
	}
}

void Discord::changeParty(const char *id, int size, int max)
{
	if (this->connected)
	{
		auto party = this->activity.GetParty();
		party.SetId(id);
		party.GetSize().SetCurrentSize(size);
		party.GetSize().SetMaxSize(max);
	}
}

void Discord::changePresenceLargeImage(const char *largeImage, const char *largeText)
{
	if (this->connected)
	{
		auto assets = &this->activity.GetAssets();
		assets->SetLargeImage(largeImage);
		assets->SetLargeText(largeText);
	}
}

void Discord::changePresenceSmallImage(const char *SmallImage, const char *SmallText)
{
	if (this->connected)
	{
		auto assets = &this->activity.GetAssets();
		assets->SetSmallImage(SmallImage);
		assets->SetSmallText(SmallText);
	}
}

void Discord::updatePresence()
{
	if (this->connected)
	{
		std::cout << this->activity.GetAssets().GetLargeImage() << std::endl;
		this->core->ActivityManager().UpdateActivity(this->activity, [this](discord::Result result) {
			if (result != discord::Result::Ok)
			{
				this->connected = false;
			}
		});
	}
}