// Explaination
/*
=========================================================
VISUALIZATION: HORIZONTAL DISTANCE (HD) & BFS QUEUE
=========================================================
 
 Axis:        -2  -1  0  +1  +2
 -----------------------------------------
 Level 0              1
                    /   \
 Level 1           2     3
                 /  \   /  \
 Level 2        4    5 6    7
 
 Node (HD):
 1 ( 0)
 2 (-1), 3 (+1)
 4 (-2), 5 ( 0), 6 ( 0), 7 (+2)

 BFS Queue Processing Order:
 1. Pop 1(HD:0)   -> mp[0] = 1
 2. Pop 2(HD:-1)  -> mp[-1] = 2
 3. Pop 3(HD:+1)  -> mp[1] = 3
 4. Pop 4(HD:-2)  -> mp[-2] = 4
 5. Pop 5(HD:0)   -> mp[0] conflict!
 6. Pop 6(HD:0)   -> mp[0] conflict!
 7. Pop 7(HD:+2)  -> mp[2] = 7

 TOP VIEW EXECUTION (Condition: if mp.find(hd) == mp.end()):
 - HD  0: 1 is recorded.
 - When 5 and 6 are popped at HD 0, they are ignored.
 - Result array (minHd to maxHd): [4, 2, 1, 3, 7]

 BOTTOM VIEW EXECUTION (Condition: mp[hd] = temp->data):
 - HD  0: 1 is recorded.
 - When 5 is popped at HD 0, mp[0] becomes 5.
 - When 6 is popped at HD 0, mp[0] becomes 6.
 - Result array (minHd to maxHd): [4, 2, 6, 3, 7]
=========================================================
*/

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

vector<int> topView(Node *root) {
        if(!root) return {};
        unordered_map<int,int> mp; // horizontal distance, node's data
        queue<pair<Node*, int>> q; // node, horizontal distance
        int minHd = 0, maxHd = 0;
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front(); q.pop();
            Node* temp = p.first;
            int hd = p.second;
            if(mp.find(hd) == mp.end() ) mp[hd] = temp->data;
            minHd = min(minHd, hd);
            maxHd = max(maxHd, hd);
            if(temp->left) q.push({temp->left, hd-1});
            if(temp->right) q.push({temp->right, hd+1});
        }
        vector<int> res;
        for(int i=minHd; i<=maxHd; i++) res.push_back(mp[i]);
        return res;   
}
