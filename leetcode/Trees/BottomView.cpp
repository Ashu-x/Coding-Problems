vector<int> bottomView(Node* root) {
    if(!root) return {};
    unordered_map<int,int> mp; // horizontal distance, node's data
    queue<pair<Node*, int>> q; // node, horizontal distance
    int minHd = 0, maxHd = 0;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front(); q.pop();
        Node* temp = p.first;
        int hd = p.second;
        mp[hd] = temp->data;
        minHd = min(minHd, hd);
        maxHd = max(amxHd, hd);
        if(temp->left) q.push({temp->left, hd-1});
        if(temp->right) q.push({temp->right, hd+1});
    }
    vector<int> res;
    for(int i=minHd; i<=maxHd; i++) res.push_back(mp[i]);
    return res;
}