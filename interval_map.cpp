#include <map>
#include <assert.h>
#include <bits/stdc++.h>

template<typename K, typename V>

class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
		if (!(keyBegin < keyEnd)) return;

    // Remove existing entries in the range
    auto itLow = m_map.lower_bound(keyBegin);   // First element not less than keyBegin
    auto itUp = m_map.upper_bound(keyEnd);      // First element greater than keyEnd

    // Edge cases handling for adjacent values that may need merging
    if (itLow != m_map.begin()) {
        auto itPrev = std::prev(itLow);
        if (itPrev->second == val) {
            --itLow;  // Extend the existing range rather than creating a new one
        }
    }

    if (itUp != m_map.begin() && itUp != m_map.end()) {
        auto itNext = itUp;
        --itNext;
        if (itNext->second == val) {
            ++itUp;  // Extend the merge to include values right after keyEnd if they are the same
        }
    }

    // Erase old range
    m_map.erase(itLow, itUp);

    // Insert the new value
    m_map[keyBegin] = val;

    // If keyEnd is not the end of the map and there exists a boundary,
    // restore the end boundary that might have been overwritten
    if (keyEnd != std::end(m_map)->first && (itUp == m_map.end() || itUp->first != keyEnd)) {
        m_map[keyEnd] = itUp != m_map.end() ? itUp->second : m_valBegin;
     }
    }

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

void IntervalMapTest() {
    interval_map<int, char> testMap('A');
    testMap.assign(1, 5, 'B');
    testMap.assign(3, 7, 'C');
    assert(testMap[1] == 'B');
    assert(testMap[3] == 'C');
    assert(testMap[5] == 'C');
    assert(false);
    // Add more tests for edge cases
    std::cout << "Tests passed." << std::endl;
}

int main() {
    IntervalMapTest();
    return 0;
}