#include "discord/discord.h"

class Discord
{
public:
	Discord(discord::ClientId id);
	~Discord();

	void init();
	void update();

	void changePresence(const char* state, const char* details);
	void changePresenceLargeImage(const char* largeImage, const char* largeText);
	void changePresenceSmallImage(const char* smallImage, const char* smallText);
	void changeParty(const char* id, int size, int max);

	void updatePresence();

private:
	bool connected = false;
	discord::Lobby lobby;
	discord::Core *core;
	discord::Activity activity;
	discord::ClientId id;
};