#ifndef Command_h
#define Command_h
#define MAX_GAME_NAME_SIZE 50

#include <vector>
#include <string>
#include <cstdlib>
#include <sys/socket.h>
#include <unistd.h>
#include "../include/GamesHandler.h"

using namespace std;

class Command {
protected:
    GamesHandler *gamesHandler;

    Command(GamesHandler *gamesHandler_) {
        gamesHandler = gamesHandler_;
    }

public:
    virtual void execute(vector<string> args, int sid) = 0;

    virtual ~Command() {};

};

#endif

