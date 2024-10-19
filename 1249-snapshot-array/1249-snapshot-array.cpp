class SnapshotArray {
public:
    vector<map<int, int>> history;
    int id;

    SnapshotArray(int length) {
        history.resize(length);
        id = 0;
    }
    
    void set(int index, int val) {
        history[index][id] = val;
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        auto it = history[index].upper_bound(snap_id);

        if (it == history[index].begin()) {
            return 0;
        }

        --it;

        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */