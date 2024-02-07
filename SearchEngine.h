#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <string>
#include <vector>

class SearchEngine {
public:
    struct SearchRule {
        std::string type;
        std::string value;
    };

    SearchEngine();
    void searchByRules(const std::vector<SearchRule>& rules);
    void searchByFeatures(const std::vector<std::string>& features);
    void searchByText(const std::string& text);
};

#endif // SEARCHENGINE_H
