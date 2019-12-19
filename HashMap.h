#pragma once
#include<string>
#include<vector>
using namespace std;

int h(string s) {
    return s[0] - 'A';
}

template<typename Key, typename Value>
class HashMap {
    struct Pair {
        Key key;
        Value value;

        Pair(Key _key) {
            key = _key;
        }
    };

    vector<vector<Pair>> table;
public:
    HashMap() {
        table = vector<vector<Pair>>(26, {});
    }

    bool has_key(Key key) {
        return pair_of_key(key) != nullptr;
    }

    void remove(Key key) {
        if (has_key(key)) {
            int hash = h(key);

            for (int i = 0; i < table[hash].size(); i++) {
                if (table[hash][i].key == key) {
                    table[hash].erase(table[hash].begin() + i);
                    return;
                }
            }
        }
    }
    
    Value operator[](Key key) const {
        Pair* pair = pair_of_key(key);

        if (pair == nullptr) {
            cout << "You are stupid!\n";
            return Value();
        }
        else {
            return pair.value;
        }
    }

    Value& operator[](Key key) {
        Pair* pair = pair_of_key(key);

        if (pair == nullptr) {
            int hash = h(key);
            table[hash].push_back(Pair(key));
            return table[hash].back().value;
        }
        else {
            return pair->value;
        }
    }

private:
    Pair* pair_of_key(Key key) {
        vector<Pair>& pairs = vector_of_key(key);

        for (int i = 0; i < pairs.size(); i++) {
            if (pairs[i].key == key) {
                return &(pairs[i]);
            }
        }
        return nullptr;
    }

    vector<Pair>& vector_of_key(Key key) {
        return table[h(key)];
    }
};