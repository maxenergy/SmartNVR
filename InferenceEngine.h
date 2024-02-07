#ifndef INFERENCEENGINE_H
#define INFERENCEENGINE_H

#include <string>
#include <opencv2/core/mat.hpp>

class InferenceEngine {
public:
    InferenceEngine();
    void loadModel(const std::string& modelPath);
    void runInference(const cv::Mat& frame);
};

#endif // INFERENCEENGINE_H
