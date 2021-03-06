
#include "../include/Server.h"
#include <fstream>

using namespace std;

bool getConnectionDetails(int *port);

#define THREAD_POOL_SIZE 5

int main() {
    ThreadsManager *threadsManager = new ThreadsManager(THREAD_POOL_SIZE);
    ClientHandler *clientHandler = new ClientHandler(threadsManager);
    int port;
    if (getConnectionDetails(&port)) {
        Server server(port, clientHandler, threadsManager);
        try {
            server.start();
        } catch (const char *msg) {
            cout << "Cannot start server. Reason: " << msg << endl;
            exit(-1);
        }
    }
    threadsManager->killAllThreads();

    delete clientHandler;
    delete threadsManager;

}

/**
* Reading from the configurations file the port of server.
* @param port - pointer to the port variable.
* @return true if the file exists otherwise false.
*/
bool getConnectionDetails(int *port) {
    string port_;
    ifstream configFile("configFileServer");
    if (configFile.is_open()) {
        getline(configFile, port_);
        configFile.close();
    } else {
        cout << "Error: config file is missing!" << endl;
        return false;
    }
    sscanf(port_.c_str(), "%d", port);
    return true;
}

