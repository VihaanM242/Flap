
#include <bits/stdc++.h>
using namespace std;

int getCurrentTimeStamp(){
	return 0;
}

template <typename K, typename V>
class CacheStore
{
	unordered_map<K, pair<V, int>> _mep;
	public:
	void Add(K key, V value, int ttl) {
		if(_mep.find(key) == _mep.end()) {
			int expirationTime = getCurrentTimeStamp() + ttl;
			_mep[key] = {value, expirationTime};
		}
		else {
		}
	}
	
	bool Get(K key, V* out) {
		int currentTime = getCurrentTimeStamp();
		if(_mep.find(key) == _mep.end()) {
			out = NULL;
			return 0;
		}
		else {
			pair<V, int> cur = _mep[key];
			if (cur.second < currentTime) {
				out = NULL;
				return 0;
			}
			else {
				*out = cur.first;
				return 1;
			}
		}
	}
};

int main() {
	CacheStore<string, int> M;
	M.Add("Flap", 1, 10);
	M.Add("Flap.inc", 2, 100);
	int* res = new int;
	if(M.Get("Flap", res)) cout << *res << endl;
	if(M.Get("Flap.inc", res)) cout << *res << endl;
	
	return 0;
}
