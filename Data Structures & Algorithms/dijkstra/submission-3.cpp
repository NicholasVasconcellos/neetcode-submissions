class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {


        // Map of Vertex to it's edges : vertex --> [vertex, cost]
        unordered_map<int, vector<std::pair<int, int>>> edgeList;

        for(int i = 0; i < edges.size(); i++){
            // edges has [start, end, weight] 
            // map is start --> [end, weight], ...
            edgeList[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        }

        // Track Processed Vertices
        unordered_set<int> processed;

        // map of Cost to All Vertices -1 is flag for infinity
        unordered_map<int,int> costs;

        // Initit costs to -1 and 0 at source
        for(int i = 0; i < n; i++){
            if( i == src){
                costs[i] = 0;
            }
            else{
                costs[i] = -1;
            }
        }

        struct Compare{
            bool operator()(pair<int,int>& a, pair<int,int>&b){
                return a.second > b.second;
            }
        };

        // Priority Queue for Next Vertices, sorted by lowest path cost (idx, currCost)
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare > nextVertices; 

        nextVertices.push(make_pair(src,0));

        while(!nextVertices.empty()){
            int curr = nextVertices.top().first;

            // Mark Curr Vertex Processed and remove from queue
            processed.insert(curr);
            nextVertices.pop();

            // For Each Neighbour (Next)
            for(int i = 0; i < edgeList[curr].size(); i++){
                // get next neibhbour index
                int next = edgeList[curr][i].first;

                // get next neighbour edge cost
                int edgeCost = edgeList[curr][i].second;

                // total Cost = Cost up to Current + Edge Cost
                int totalCost = costs[curr] + edgeCost;

                // Update Cost if Better than current cost or new
                if(costs[next] == -1 || totalCost < costs[next]){
                    costs[next] = totalCost;
                    
                    // Push new Lower cost to queue
                    nextVertices.push(make_pair(next, costs[next]));
                }
                // if cost is higher don't need to add to queue
                // Can't mark processed here since we don't knwo when it'll be processed

            
            }
        }

        return costs;
    }
};
