#include <bits/stdc++.h>

using namespace std;

// search_buckets provides two operations on an array:
// 1) set array[i] = x
// 2) count how many i in [start, end) satisfy array[i] < value
// Both operations take sqrt(N log N) time. Amazingly, because of the cache efficiency this is faster than the
// (log N)^2 algorithm until N = 2-5 million.
template<typename T>
struct search_buckets {
    // values are just the values in order. buckets are sorted in segments of BUCKET_SIZE (last segment may be smaller)
    int N, BUCKET_SIZE;
    vector<T> values, buckets;

    search_buckets(const vector<T> &initial = {}) {
        init(initial);
    }

    int get_bucket_end(int bucket_start) const {
        return min(bucket_start + BUCKET_SIZE, N);
    }

    void init(const vector<T> &initial) {
        values = buckets = initial;
        N = values.size();
        BUCKET_SIZE = 3 * sqrt(N * log(N + 1)) + 1;

        for (int start = 0; start < N; start += BUCKET_SIZE)
            sort(buckets.begin() + start, buckets.begin() + get_bucket_end(start));
    }

    int bucket_less_than(int bucket_start, T value) const {
        auto begin = buckets.begin() + bucket_start;
        auto end = buckets.begin() + get_bucket_end(bucket_start);
        return lower_bound(begin, end, value) - begin;
    }

    int less_than(int start, int end, T value) const {
        int count = 0;
        int bucket_start = start - start % BUCKET_SIZE;
        int bucket_end = min(get_bucket_end(bucket_start), end);

        if (start - bucket_start < bucket_end - start) {
            while (start > bucket_start)
                count -= values[--start] < value;
        } else {
            while (start < bucket_end)
                count += values[start++] < value;
        }

        if (start == end)
            return count;

        bucket_start = end - end % BUCKET_SIZE;
        bucket_end = get_bucket_end(bucket_start);

        if (end - bucket_start < bucket_end - end) {
            while (end > bucket_start)
                count += values[--end] < value;
        } else {
            while (end < bucket_end)
                count -= values[end++] < value;
        }

        while (start < end && get_bucket_end(start) <= end) {
            count += bucket_less_than(start, value);
            start = get_bucket_end(start);
        }

        assert(start == end);
        return count;
    }

    int prefix_less_than(int n, T value) const {
        return less_than(0, n, value);
    }

    void modify(int index, T value) {
        int bucket_start = index - index % BUCKET_SIZE;
        int old_pos = bucket_start + bucket_less_than(bucket_start, values[index]);
        int new_pos = bucket_start + bucket_less_than(bucket_start, value);

        if (old_pos < new_pos) {
            copy(buckets.begin() + old_pos + 1, buckets.begin() + new_pos, buckets.begin() + old_pos);
            new_pos--;
            // memmove(&buckets[old_pos], &buckets[old_pos + 1], (new_pos - old_pos) * sizeof(T));
        } else {
            copy_backward(buckets.begin() + new_pos, buckets.begin() + old_pos, buckets.begin() + old_pos + 1);
            // memmove(&buckets[new_pos + 1], &buckets[new_pos], (old_pos - new_pos) * sizeof(T));
        }

        buckets[new_pos] = value;
        values[index] = value;
    }
};

struct eng {
    int r1, r2, r3;
};

bool cmp(eng& e1, eng& e2) {
    return e1.r1 < e2.r1;
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n+1,n+n);
    search_buckets<int> buckets(v);

    vector<eng> engs(n);
    for(auto& i : engs) {
        cin >> i.r1 >> i.r2 >> i.r3;
    }
    sort(engs.begin(),engs.end(),cmp);

    int total = 0;
    for(auto i : engs) {
        // query
        if(buckets.less_than(0,i.r2,i.r3) == 0) {
            total++;
        }
        // modify
        buckets.modify(i.r2,i.r3);
    }
    cout << total << endl;
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        solve();
    }
}
