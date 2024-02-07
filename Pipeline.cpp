#include "Pipeline.h"
#include <gst/gst.h>
#include <gst/app/gstappsrc.h>
#include <string>

Pipeline::Pipeline() {
    gst_init(nullptr, nullptr);
    GstElement *pipeline = gst_pipeline_new("pipeline");
}

void Pipeline::createPipeline(const std::string& source) {
    // Implementation for creating a GStreamer pipeline
    GstElement *sourceElement = gst_element_factory_make("uridecodebin", "source");
    g_object_set(G_OBJECT(sourceElement), "uri", source.c_str(), NULL);

    // Connect to the pad-added signal
    g_signal_connect(sourceElement, "pad-added", G_CALLBACK(&Pipeline::onPadAdded), this);

    gst_bin_add(GST_BIN(this->pipeline), sourceElement);
}

void Pipeline::addInference(const std::string& modelPath) {
    // Implementation for adding an inference model to the pipeline
    GstElement *inferenceElement = gst_element_factory_make("inferencebin", "inference");
    g_object_set(G_OBJECT(inferenceElement), "model-path", modelPath.c_str(), NULL);

    gst_bin_add(GST_BIN(this->pipeline), inferenceElement);
}

void Pipeline::addRecording(const std::string& outputPath) {
    // Implementation for adding recording to the pipeline
    GstElement *recordingElement = gst_element_factory_make("filesink", "recording");
    g_object_set(G_OBJECT(recordingElement), "location", outputPath.c_str(), NULL);

    gst_bin_add(GST_BIN(this->pipeline), recordingElement);
}

void Pipeline::addStreaming(const std::string& destination) {
    // Implementation for adding streaming to the pipeline
    GstElement *streamingElement = gst_element_factory_make("rtmpsink", "streaming");
    g_object_set(G_OBJECT(streamingElement), "location", destination.c_str(), NULL);

    gst_bin_add(GST_BIN(this->pipeline), streamingElement);
}

void Pipeline::onPadAdded(GstElement *src, GstPad *new_pad, Pipeline *self) {
    // Handle the pad-added signal to link the decodebin pads with the rest of the pipeline
    GstPad *sink_pad = gst_element_get_static_pad(self->pipeline, "sink");
    if (gst_pad_is_linked(sink_pad)) {
        gst_object_unref(sink_pad);
        return;
    }

    GstPadLinkReturn ret = gst_pad_link(new_pad, sink_pad);
    if (GST_PAD_LINK_FAILED(ret)) {
        g_warning("Failed to link pads");
    }
    gst_object_unref(sink_pad);
}
