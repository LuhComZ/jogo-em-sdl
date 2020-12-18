#include "discord/discord.h"

class Discord
{
public:
	Discord(discord::ClientId id);
	~Discord();

	void init();
	void update();

	void changePresence(const char* state, const char* details);
	void changePresenceAssets(const char* largeImage, const char* largeText,const char* smallImage, const char* smallText);
	void changeParty(const char* id, int size, int max);

	void updatePresence();

private:
	bool connected = false;
	discord::Lobby lobby;
	discord::Core *core;
	discord::Activity activity;
	discord::ClientId id;
};