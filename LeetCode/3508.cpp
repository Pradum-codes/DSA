#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

struct PacketData {
    int source;
    int destination;
    int timestamp;
    
    bool operator==(PacketData const &other) const {
        return source == other.source
            && destination == other.destination
            && timestamp == other.timestamp;
    }
};

struct PacketHash {
    size_t operator()(PacketData const &p) const noexcept {
        // combine three ints; use a standard hash combination
        // You can use 64-bit and mixing
        size_t h1 = std::hash<long long>()(((long long)p.source) << 32 | (unsigned int)p.destination);
        size_t h2 = std::hash<long long>()( ((long long)p.timestamp) );
        // simple combine
        return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1<<6) + (h1>>2));
    }
};

class Router {
private:
    int memoryLimit;
    queue<PacketData> packetQueue;  // FIFO storage
    unordered_set<PacketData, PacketHash> uniquePackets;
    unordered_map<int, vector<int>> destTimestamps;  // for each destination, timestamps in added order
    unordered_map<int, int> destForwardedIdx;  // for each dest, how many have been forwarded/removed from front

public:
    Router(int memoryLimit_) : memoryLimit(memoryLimit_) {
        // initialize empty
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        PacketData pkt{source, destination, timestamp};
        // check duplicate
        if (uniquePackets.find(pkt) != uniquePackets.end()) {
            return false;
        }
        // if memory full, remove oldest
        if ((int)packetQueue.size() == memoryLimit) {
            forwardPacket();  // remove 1
        }
        // add new packet
        packetQueue.push(pkt);
        uniquePackets.insert(pkt);
        destTimestamps[destination].push_back(timestamp);
        // note: destForwardedIdx[destination] is implicitly 0 if not exists
        return true;
    }
    
    vector<int> forwardPacket() {
        if (packetQueue.empty()) {
            return {};  // empty vector
        }
        PacketData pkt = packetQueue.front();
        packetQueue.pop();
        uniquePackets.erase(pkt);
        // advance forwarded index for its destination
        int dest = pkt.destination;
        destForwardedIdx[dest] += 1;
        // return packet info
        return {pkt.source, pkt.destination, pkt.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps.find(destination);
        if (it == destTimestamps.end()) {
            return 0;
        }
        const vector<int> &tsVec = it->second;
        int forwarded = destForwardedIdx[destination];  // how many from front are no longer stored
        
        // find lower bound of startTime in tsVec[forwarded..end]
        auto lb = std::lower_bound(tsVec.begin() + forwarded, tsVec.end(), startTime);
        // find upper bound of endTime
        auto ub = std::upper_bound(tsVec.begin() + forwarded, tsVec.end(), endTime);
        return (int)(ub - lb);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    return 0;
}