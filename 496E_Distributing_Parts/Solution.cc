#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

enum Type {
    NOTE,
    ACTOR,
    UNKNOWN
};

struct Range {
    int64_t start;
    int64_t end;
    int id;

    virtual Type getType() const {
        return UNKNOWN;
    }
};

struct Note: public Range {
    Type getType() const {
        return NOTE;
    }
};

struct Actor: public Range {
    int64_t k;
    Type getType() const {
        return ACTOR;
    }
};

struct RangePointerCmp {
    bool operator()(const Range *a, const Range *b) const {
        if (a->start < b->start) {
            return true;
        } else if (a->start == b->start) {
            if (a->getType() == ACTOR && b->getType() == NOTE) {
                return true;
            } else if (a->getType() == ACTOR && b->getType() == ACTOR) {
                return a->id < b->id;
            } else if (a->getType() == NOTE && b->getType() == ACTOR) {
                return false;
            } else {
                return a->id < b->id;
            }
        }
        return false;
    }
};

struct RangeByEndCmp {
    bool operator()(const Range *a, const Range *b) const {
        if (a->end < b->end) {
            return true;
        } else if (a->end == b->end) {
            if (a->getType() == ACTOR && b->getType() == NOTE) {
                return false;
            } else if (a->getType() == ACTOR && b->getType() == ACTOR) {
                return a->id < b->id;
            } else if (a->getType() == NOTE && b->getType() == ACTOR) {
                return true;
            } else {
                return a->id < b->id;
            }
        }
        return false;
    }
};

#define MAX 101000

int main(int argc, char *argv[]) {

    Note notes[MAX];
    Actor actors[MAX];
    int result[MAX] = {0};

    int m, n;
    scanf("%d", &n);
    for (int i=0; i < n; ++i) {
        scanf("%"SCNd64" %"SCNd64"", &notes[i].start, &notes[i].end);
        notes[i].id = i;
    }
    scanf("%d", &m);
    for (int i=0; i < m; ++i) {
        scanf("%"SCNd64" %"SCNd64" %"SCNd64"", &actors[i].start, &actors[i].end, &actors[i].k);
        actors[i].id = i;
    }
    vector<Range*> container;
    container.reserve(m+n);
    for (int i=0; i < n; ++i) {
        container.push_back(&notes[i]);
    }
    for (int i=0; i < m; ++i) {
        container.push_back(&actors[i]);
    }
    sort(container.begin(), container.end(), RangePointerCmp());
    multiset<Range*, RangeByEndCmp> actorSet;
    bool hasSol = true;
    for (int i=0; i < container.size(); ++i) {
        Range *cur = container[i];
        if (cur->getType() == ACTOR) {
            actorSet.insert(cur);
            // printf("{Actor, %"PRId64" %"PRId64" %"PRId64"}\n", cur->start, cur->end, ((Actor*)cur)->k);
        } else if (cur->getType() == NOTE) {
            // printf("{Note, %"PRId64" %"PRId64"}\n", cur->start, cur->end);
            // printf("Set size: %lu\n", actorSet.size());
            multiset<Range*, RangeByEndCmp>::iterator itr = actorSet.lower_bound(cur);
            if (itr == actorSet.end()) {
                hasSol = false;
                break;
            } else {
                Actor *actorPtr = (Actor*)(*itr);
                actorPtr->k--;
                result[cur->id] = actorPtr->id + 1;
                if (actorPtr->k == 0) {
                    actorSet.erase(itr);
                }
            }
        }
    }
    if (hasSol) {
        printf("YES\n");
        for (int i=0; i < n; ++i) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
