#ifndef VECTORDATABASE_H
#define VECTORDATABASE_H

#include <string>
#include <vector>

class VectorDatabase {
public:
    VectorDatabase();
    void indexFeatureVectors(const std::vector<std::vector<float>>& vectors);
    std::vector<std::string> searchSimilarVectors(const std::vector<float>& vector);
};

#endif // VECTORDATABASE_H
