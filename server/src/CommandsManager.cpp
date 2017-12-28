#include "../include/CommandsManager.h"
#include "../include/ThreadsManager.h"

CommandsManager::CommandsManager(ThreadsManager *threadsManager) : commandsMap(){
    gamesHandler=new GamesHandler();
    error = new ErrorCommand(gamesHandler);
    commandsMap["start"] = new StartCommand(gamesHandler);
    commandsMap["list_games"] = new ListGamesCommand(gamesHandler);
    commandsMap["join"] = new JoinCommand(threadsManager,gamesHandler);
}
void CommandsManager::executeCommand(string
                                     command, vector<string>* args) {
    if ( commandsMap.find(command) == commandsMap.end() ) { // not found
        this->error->execute(*args);
        cout<<"Command Error"<<endl;
    } else { // found
        commandsMap[command]->execute(*args);
    }
}
CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;

    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }

    delete error;
}
