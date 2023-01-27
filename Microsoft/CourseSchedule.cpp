class Solution {
public:

bool solveDFS(int i, vector<bool>&vis, vector<bool>&currVis, vector<int> adj[]){
    vis[i] = true; 
    currVis[i] = true;
    //curr and vis dono ko true kara

    vector<int> data=adj[i]; //adjacency list ka data laye, jaise i=0, ke liye adj[0] aya, jo tha 1

    for(auto it:data){
        if(!vis[it]){
            if(solveDFS(it, vis, currVis, adj)){
                return true;
            }
        }
        else if(vis[it] && currVis[it]){
            return true;
        }
    }

    currVis[i] = false;
    return false;

}
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int n=numCourses;
        vector<bool> vis(n, false); //visited wala vector 
        vector<bool> currVis(n,false);//currently visited wala vector

        vector<int> adj[n]; //adjacency list banayenge
        for(auto it:p){
            vector<int> data = it;
            int a = data[0]; //har ek pair ka first elem
            int b = data[1]; //har ek pair ka second elem
            adj[a].push_back(b); 
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){ //agar visited na hua
                if(solveDFS(i, vis, currVis, adj)){ //recursive func call
                    return false; //yaha basically cycle check kar rahe, agar mil gaya to false else to true hi
                }
            }
        }

        return true;

    }
};