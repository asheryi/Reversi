
#include <algorithm>
#include <iostream>
#include "../include/ThreadsManager.h"

void ThreadsManager::addThread(pthread_t thread) {
    pthread_mutex_lock(&threads_mutex);
    threads.push_back(thread);
    pthread_mutex_unlock(&threads_mutex);
}

void ThreadsManager::removeThread(pthread_t thread) {
    pthread_mutex_lock(&threads_mutex);
    threads.erase(remove(threads.begin(), threads.end(), thread), threads.end());
    pthread_mutex_unlock(&threads_mutex);
}

void ThreadsManager::killAllThreads() {
    pthread_mutex_lock(&threads_mutex);
    int threads_size = threads.size();
    for (int i = 0; i < threads_size; i++) {
        pthread_cancel(threads[i]);
    }

    pthread_mutex_unlock(&threads_mutex);
    pthread_mutex_destroy(&threads_mutex);

    threadPool.terminate();
}

void ThreadsManager::addTaskToThreadPool(Task *task) {
    threadPool.addTask(task);
}

ThreadsManager::ThreadsManager(int threadPoolSize) : threads_mutex(), threadPool(threadPoolSize) {

}


