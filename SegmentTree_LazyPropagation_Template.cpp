// root is at 0
#define MAXSEG 1<<19 // MAXSEG >= 4N
int val[MAXSEG];
int lazy[MAXSEG]; // lazy propagation values
void build(int k, int nl, int nr) {
  if (nl == nr) {
    val[k] = arr[nl]; // arr[] is the original array
    return;
  }
  int nm = (nl+nr)/2;
  build(2*k+1, nl, nm);
  build(2*k+2, nm+1, nr);
  val[k] = val[2*k+1] + val[2*k+2];
}
void add(int k, int nl, int nr, int l, int r, int v);
void relax(int k, int nl, int nr) {
  int nm = (nl+nr)/2;
  add(2*k+1, nl, nm, nl, nm, lazy[k]);
  add(2*k+2, nm+1, nr, nm+1, nr, lazy[k]);
  lazy[k] = 0;
}
void add(int k, int nl, int nr, int l, int r, int v) {
    if(r < nl || l > nr) return;
    if (nl == nr) {
        val[k] += v * (nr - nl + 1); // update val using v here
        lazy[k] += v;
        return;
    }
    if (lazy[k]) relax(k, nl, nr);
    int nm = (nl+nr)/2;
    add(2*k+1, nl, nm, l, r, v);
    add(2*k+2, nm+1, nr, l, r, v);
    val[k] = val[2*k+1] + val[2*k+2];   // update val here
}
int get(int k, int nl, int nr, int l, int r) {
    if(r < nl || l > nr) return 0;
    if(l <= nl && nr <= r) return val[k];   // return answer here
    if (lazy[k]) relax(k, nl, nr);
    int nm = (nl+nr)/2, ans = 0;
    ans += get(2*k+1, nl, nm, l, r);    // combine answers of the two children here
    ans += get(2*k+2, nm+1, nr, l, r);
    return ans;
}
