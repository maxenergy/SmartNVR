#ifndef VIDEOSUMMARY_H
#define VIDEOSUMMARY_H

#include <string>

class VideoSummary {
public:
    VideoSummary();
    void generateSummary(const std::string& videoPath);
    void adjustOverlayLevel(int level);
    void exportSummary(const std::string& outputPath);
};

#endif // VIDEOSUMMARY_H
