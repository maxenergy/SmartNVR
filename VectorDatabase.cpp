#include "VectorDatabase.h"
#include <faiss/IndexFlat.h>

VectorDatabase::VectorDatabase() {
    this->index = new faiss::IndexFlatL2(256); // Assuming 256-dimensional vectors
}

void VectorDatabase::indexFeatureVectors(const std::vector<std::vector<float>>& vectors) {
    // Add vectors to the FAISS index
    for (const auto& vec : vectors) {
        this->index->add(1, vec.data());
    }
}

std::vector<std::string> VectorDatabase::searchSimilarVectors(const std::vector<float>& queryVec, size_t k) {
    std::vector<float> distances(k);
    std::vector<faiss::Index::idx_t> labels(k);
    this->index->search(1, queryVec.data(), k, distances.data(), labels.data());

    std::vector<std::string> results;
    for (size_t i = 0; i < k; ++i) {
        results.push_back(std::to_string(labels[i]));
    }
    return results;
}
    std::vector<float> distances(k);
    std::vector<faiss::Index::idx_t> labels(k);
    this->index->search(1, queryVec.data(), k, distances.data(), labels.data());

    std::vector<std::string> results;
    for (size_t i = 0; i < k; ++i) {
        results.push_back(std::to_string(labels[i]));
    }
    return results;
}
    std::vector<float> distances(k);
    std::vector<faiss::Index::idx_t> labels(k);
    this->index->search(1, queryVec.data(), k, distances.data(), labels.data());

    std::vector<std::string> results;
    for (size_t i = 0; i < k; ++i) {
        results.push_back(std::to_string(labels[i]));
    }
    return results;
}
    std::vector<float> distances(k);
    std::vector<faiss::Index::idx_t> labels(k);
    this->index->search(1, queryVec.data(), k, distances.data(), labels.data());

    std::vector<std::string> results(k);
    for (size_t i = 0; i < k; ++i) {
        results[i] = std::to_string(labels[i]);
    }
    return results;
}
    // Search the index for k nearest vectors
    std::vector<float> distances(k);
    std::vector<faiss::Index::idx_t> labels(k);
    faiss::Index::idx_t* labels = new faiss::Index::idx_t[k];
    float* distances = new float[k];
    this->index->search(1, queryVec.data(), k, distances, labels);
    std::vector<std::string> results(k);
    for(size_t i = 0; i < k; ++i) {
        results[i] = std::to_string(labels[i]);
    }
    delete[] labels;
    delete[] distances;
    return results;

    // Convert labels to actual vector IDs or some form of identifiers
    std::vector<std::string> results(k);
    for (size_t i = 0; i < k; ++i) {
        // Placeholder for converting labels to identifiers
        results[i] = std::to_string(labels[i]);
    }

    return results;
}
