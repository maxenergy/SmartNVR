#include "CameraManager.h"
#include <iostream>
#include <vector>

CameraManager::CameraManager() {}

void CameraManager::addCamera(const std::string& cameraId, const std::string& rtspUrl) {
    // Add a new camera with the given ID and RTSP URL
    cameras[cameraId] = rtspUrl;
}

void CameraManager::removeCamera(const std::string& cameraId) {
    // Remove the camera with the given ID
    cameras.erase(cameraId);
}

void CameraManager::listCameras() const {
    // List all cameras
    for (const auto& camera : cameras) {
        std::cout << "Camera ID: " << camera.first << ", RTSP URL: " << camera.second << std::endl;
    }
}
