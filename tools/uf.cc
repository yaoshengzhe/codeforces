// A union-find algorithm implementation

int ufFind(int *uf, int x) {
    while (uf[x] != x) {
        int parent = uf[x];
        uf[x] = uf[parent];
        x = parent;
    }
    return x;
}

void ufUnion(int *uf, int x, int y) {
    int rootx = uf_find(uf, x);
    int rooty = uf_find(uf, y);
    if (rootx < rooty) {
        uf[rooty] = rootx;
    } else {
        uf[rootx] = rooty;
    }
}
