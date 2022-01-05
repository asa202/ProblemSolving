#include <vector>
using namespace std;
class Node{
	public:
	int jobID;
	vector<Node*> preReq;
	Node(int jobID);
};

Node::Node(int jobID){
	this->jobID = jobID;
	preReq = {};
}
class JobMap{
	public:
	vector<Node*> nodes;
	unordered_map<int, vector<int>> depedencyGraph;
	unordered_map<int, Node*> graph;
	vector<int> noPreq;
	JobMap(vector<int> jobs, vector<vector<int>> deps);
	void create_graph(vector<int> jobs,vector<vector<int>> deps);
	void fill_noPreq(vector<int> jobs);
};

JobMap::JobMap(vector<int> jobs, vector<vector<int>> deps){
	for(int jobID: jobs){
		Node* job = new Node(jobID);
		graph[jobID] = job;
		nodes.push_back(job);
	}
	create_graph(jobs, deps);
}

void JobMap::create_graph(vector<int> jobs, vector<vector<int>> deps){
	for(int i = 0 ; i < deps.size() ; i++){
		int jobID = deps[i][1];
		int dep = deps[i][0];
		graph[jobID]->preReq.push_back(graph[dep]);
		depedencyGraph[dep].push_back(jobID);
	}
	fill_noPreq(jobs);
}

void JobMap::fill_noPreq(vector<int> jobs){
	for(int i = 0; i < jobs.size() ; i++){
		int jobID = jobs[i];
		int no_of_preReq = graph[jobID]->preReq.size();
		if(no_of_preReq == 0){
			noPreq.push_back(jobID);
		}
	}
}
//O(j+d) time | O(j+d) space - where j is the number of jobs and d is the number of dependencies
vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
  // Write your code here.
	vector<int> retVector;
	JobMap* jM = new JobMap(jobs, deps);
	while(jM->nodes.size()!=0){
		if(jM->noPreq.size() == 0){
			return {};
		}
		int finalized_job = jM->noPreq.back();
		jM->noPreq.pop_back();
		retVector.push_back(finalized_job);
		vector<int> nodes_depOnFinalized = jM->depedencyGraph[finalized_job];
		for(int i : nodes_depOnFinalized){
			Node* dep_node = jM->graph[i];
			for(int j = 0 ; j < dep_node->preReq.size(); j++){
				if(dep_node->preReq[j]->jobID == finalized_job ){
					dep_node->preReq.erase(dep_node->preReq.begin()+j);
				}
			}
			if(dep_node->preReq.size() == 0){
				jM->noPreq.push_back(dep_node->jobID);
			}
		}
		for(int j = 0 ; j < jM->nodes.size(); j++){
				if(jM->nodes[j]->jobID == finalized_job ){
					jM->nodes.erase(jM->nodes.begin()+j);
				}
		}
	}
  return retVector;
}
