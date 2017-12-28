#ifndef StartCommand_H
#define StartCommand_H
#include "Command.h"
class StartCommand: public Command {
public:
    StartCommand(GamesHandler *gamesHandler_);
    virtual void execute(vector<string> args);
    virtual ~StartCommand();
};
#endif
