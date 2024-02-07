#ifndef PIPELINE_H
#define PIPELINE_H

#include <string>

class Pipeline {
public:
    Pipeline();
    void createPipeline(const std::string& source);
    void addInference(const std::string& model);
    void addRecording();
    void addStreaming(const std::string& destination);
};

#endif // PIPELINE_H
