#ifndef CLIENT_SIDE_ENGINE_H
#define CLIENT_SIDE_ENGINE_H

#include <memory>
#include <string>
#include <vector>

struct IndexResult {
    double executionTime;
    long totalBytesRead;
};

struct DocPathFreqPair {
    std::string documentPath;
    long wordFrequency;
};

struct SearchResult {
    double excutionTime;
    std::vector<DocPathFreqPair> documentFrequencies;
};

class ClientProcessingEngine {
    // TO-DO keep track of the connection (socket)
    // TO-DO keep track of the client ID

    public:
        // constructor
        ClientProcessingEngine();

        // default virtual destructor
        virtual ~ClientProcessingEngine() = default;

        IndexResult indexFolder(std::string folderPath);
        
        SearchResult search(std::vector<std::string> terms);
        
        long getInfo();

        void connect(std::string serverIP, std::string serverPort);
        
        void disconnect();
};

#endif
