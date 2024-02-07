#include "InferenceEngine.h"
#include <opencv2/opencv.hpp>
#include <opencv2/dnn/dnn.hpp>

InferenceEngine::InferenceEngine() {}

void InferenceEngine::loadModel(const std::string& modelPath) {
    // Load the YOLOv8 model
    this->net = cv::dnn::readNet(modelPath);
}

void InferenceEngine::runInference(const cv::Mat& frame) {
    // Run inference on the frame
    cv::Mat blob;
    cv::dnn::blobFromImage(frame, blob, 1/255.0, cv::Size(416, 416), cv::Scalar(), true, false);
    this->net.setInput(blob);
    std::vector<cv::Mat> outputs;
    this->net.forward(outputs, this->net.getUnconnectedOutLayersNames());

    // Process outputs
    // TODO: Implement post-processing of outputs
}
