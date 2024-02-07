#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <string>

class TaskManager {
public:
    TaskManager();
    void addVideoSource(const std::string& source);
    void startAnalysis();
    void searchSimilarImages(const std::string& imagePath);
};

#endif // TASKMANAGER_H
