#ifndef EX3_LISTGAMESCOMMAND_H
#define EX3_LISTGAMESCOMMAND_H


#include "Command.h"


class ListGamesCommand : public Command{
public:
    ListGamesCommand(GamesHandler *gamesHandler);

    virtual void execute(vector<string> args);
    virtual ~ListGamesCommand();


};


#endif //EX3_LISTGAMESCOMMAND_H
