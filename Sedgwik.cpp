 
C++ Programs from Algorithms 2nd edition
 
Copyright 1992. Addison-Wesley Publishing Company, Inc.
All Rights Reserved. 
 
 
--------------------------------
CHAPTER 1 Introduction   
 
 
--------------------------------
CHAPTER 2 C++ (and C)
 
#include 
int gcd(int u, int v)
  {
    int t;
    while (u > 0)
      {
        if (u < v) { t = u; u = v; v = t; }
        u = u - v;
      }
    return v;
   }
main()
  {
    int x, y;
    while (cin >> x && cin >> y)
      if (x>0 && y>0) cout << x << ' ' << y << ' ' 
                                << gcd(x,y) << '\n';
  }
 
--------------------------------
CHAPTER 3 Elementary Data Structures 
 
const int N = 1000;
main()
  {
    int i, j, a[N+1];
    for (a[1] = 0, i = 2; i <= N; i++) a[i] = 1;
    for (i = 2; i <= N/2; i++)
      for (j = 2; j <= N/i; j++) 
        a[i*j] = 0;
    for (i = 1; i <= N; i++)
      if (a[i]) cout << i << ' ';
    cout << '\n';
  }
 
    struct node 
      { int key; struct node *next; };
 
    struct node *head, *z;
    head = new node; z = new node;
    head->next = z; z->next = z;
 
struct node 
  { int key; struct node *next; };
main()
  { 
    int i, N, M; 
    struct node *t, *x;
    cin >> N >> M;
    t = new node; t->key = 1; x = t;
    for (i = 2; i <= N; i++)
      { 
        t->next = new node;
        t = t->next; t->key = i;
      }
    t->next = x;
    while (t != t->next)
      {
        for (i = 1; i < M; i++) t = t->next;
        cout << t->next->key << ' ';
        x = t->next; t->next = x->next;
        delete x;
      }
    cout << t->key << '\n';
  }
 
    key[x] = v; next[x] = next[t]; next[t] = x++;
 
class Stack 
  {
    private:
      itemType *stack;
      int p;
    public:
      Stack(int max=100) 
        { stack = new itemType[max]; p = 0; }
     ~Stack()
        { delete stack; }
      inline void push(itemType v)
        { stack[p++] = v; }
      inline itemType pop()
        { return stack[--p]; }
      inline int empty()
        { return !p; }
  };
 
    char c; Stack acc(50); int x;
    while (cin.get(c))
      {
        x = 0;
        while (c == ' ') cin.get(c);
        if (c == '+') x = acc.pop() + acc.pop();
        if (c == '*') x = acc.pop() * acc.pop();
        while (c>='0' && c<='9')
          { x = 10*x + (c-'0');  cin.get(c); }
        acc.push(x);
      }
   cout << acc.pop() << '\n';
 
    char c; Stack save(50);
    while (cin.get(c))
      {
        if (c == ')') cout.put(save.pop());
        if (c == '+') save.push(c);
        if (c == '*') save.push(c);
        while (c>='0' && c<='9') 
          { cout.put(c); cin.get(c); } 
        if (c != '(') cout << ' ';
      }
    cout << '\n';
 
class Stack 
  {
    public:
      Stack(int max); 
     ~Stack();
      void push(itemType v);
      itemType pop();
      int empty();
    private:
      struct node 
       { itemType key; struct node *next; };
      struct node *head, *z;
  };
 
Stack::Stack(int max) 
  {
    head = new node; z = new node;
    head->next = z;  z->next = z;
  }
Stack::~Stack() 
  { 
    struct node *t = head;
    while (t != z) 
      { head = t; t = t->next; delete head; }
  }
 
void Stack::push(itemType v) 
  {
    struct node *t = new node;
    t->key = v; t->next = head->next; 
    head->next = t;
  }
itemType Stack::pop()   
  {
    itemType x;
    struct node *t = head->next; 
    head->next = t->next; x = t->key;
    delete t; return x;
  }
int Stack::empty()
  { return head->next == z; }
 
void Queue::put(itemType v)
  {
    queue[tail++] = v;
    if (tail > size) tail = 0; 
  }
itemType Queue::get()
  { 
    itemType t = queue[head++];
    if (head > size) head = 0;
    return t;
  }
int Queue::empty()
  { return head == tail; }
 
 
--------------------------------
CHAPTER 4 Trees   
 
    struct node
      { char info; struct node *l, *r; };
    struct node *x, *z;
 
    char c; Stack stack(50);
    z = new node; z->l = z; z->r = z;
    while (cin.get(c))
      {
        while (c == ' ') cin.get(c);
        x = new node;
        x->info = c; x->l = z; x->r = z;
        if (c=='+' || c=='*') 
          { x->r = stack.pop(); x->l = stack.pop(); }
        stack.push(x);
      }
 
traverse(struct node *t)
  {
    stack.push(t);
    while (!stack.empty())
      {
        t = stack.pop(); visit(t);
        if (t->r != z) stack.push(t->r); 
        if (t->l != z) stack.push(t->l); 
      }
  }
 
traverse(struct node *t)
  {
    queue.put(t);
    while (!queue.empty())
      {
        t = queue.get(); visit(t);
        if (t->l != z) queue.put(t->l); 
        if (t->r != z) queue.put(t->r); 
      }
  }
 
 
--------------------------------
CHAPTER 5 Recursion   
 
int factorial(int N)
  {
    if (N == 0) return 1;
    return N * factorial(N-1);
  }
 
int fibonacci(int N)
  {
    if (N <= 1) return 1;
    return fibonacci(N-1) + fibonacci(N-2);
  }
 
const int max = 25;
int fibonacci(int N)
  {
    int i, F[max];
    F[0] = 1; F[1] = 1;
    for (i = 2; i <= max; i++) 
        F[i] = F[i-1] + F[i-2];
    return F[N];    
  }
 
rule(int l, int r, int h)
  {
    int m = (l+r)/2;
    if (h > 0)
      { 
        mark(m,h);
        rule(l,m,h-1);
        rule(m,r,h-1);
      }
  }
 
rule(0,8,3)
   mark(4,3 )
   rule(0,4,2)
      mark(2,2)
      rule(0,2,1)
         mark(1,1)
         rule(0,1,0)
         rule(1,2,0)
      rule(2,4,1)
         mark(3,1)
         rule(2,3,0)
         rule(3,4,0)
   rule(4,8,2)
      mark(6,2)
      rule(4,6,1)
         mark(5,1)
         rule(4,5,0)
         rule(5,6,0)
      rule(6,8,1)
         mark(7,1)
         rule(6,7,0)
 
rule(0,8,3)
   rule(0,4,2)
      rule(0,2,1)
         rule(0,1,0)
         mark(1,1)
         rule(1,2,0)
      mark(2,2)
      rule(2,4,1)
         rule(2,3,0)
         mark(3,1)
         rule(3,4,0)
   mark(4,3 )
   rule(4,8,2)
      rule(4,6,1)
         rule(4,5,0)
         mark(5,1)
         rule(5,6,0)
      mark(6,2)
      rule(6,8,1)
         rule(6,7,0)
         mark(7,1)
 
rule(int l, int r, int h)
  { 
    int i, j, t;
    for (i = 1,j = 1; i <= h; i++,j+=j)
      for (t = 0; t <= (l+r)/j; t++)
        mark(l+j+t*(j+j),i);
  }
 
star(int x, int y, int r)
  {
    if (r > 0)
      {
        star(x-r,y+r,r/2);
        star(x+r,y+r,r/2);
        star(x-r,y-r,r/2);
        star(x+r,y-r,r/2);
        box(x,y,r);
      }
  }
 
traverse(struct node *t)
  {
    if (t != z)
      {
        traverse(t->l);
        visit(t);
        traverse(t->r);
      }
  }
 
visit(struct node *t)
  { t->x = ++x; t->y = y; }
traverse(struct node *t)
  {
    y++;
    if (t != z)
      {
        traverse(t->l);
        visit(t);
        traverse(t->r)
      }
    y--;
  }
 
traverse(struct node *t)
  {
    if (t != z)
      {
        visit(t);
        traverse(t->l);
        traverse(t->r);
      }
  }
 
traverse(struct node *t)
  {
   l: if (t == z) goto x;
      visit(t);
      traverse(t->l);
      t = t->r;
      goto l;
   x: ;
  }
 
traverse(struct node *t)
  {
   l: if (t == z) goto s;
      visit(t);
      stack.push(t); t = t->l; goto l;
   r: t = t->r; goto l;
   s: if (stack.empty()) goto x;
      t = stack.pop(); goto r;
   x: ;
  }
 
traverse(struct node *t)
  {
   l: while (t != z)
        {
          visit(t);
          stack.push(t->r); t = t->l;
        }
      if (stack.empty()) goto x;
      t = stack.pop(); goto l;
   x: ;
  }
 
traverse(struct node *t)
  {
    stack.push(t);
    while (!stack.empty())
      {
        t = stack.pop();
        while (t != z) 
          {  
            visit(t);
            stack.push(t->r); 
            t = t->l;
          }
      }
  }
 
traverse(struct node *t)
  {
    stack.push(t);
    while (!stack.empty())
      {
        t = stack.pop();
        if (t != z) 
          {  
            visit(t);
            stack.push(t->r); 
            stack.push(t->l);
          }
      }
  }
 
traverse(struct node *t)
  {
    stack.push(t);
    while (!stack.empty())
      {
        t = stack.pop(); visit(t);
        if (t->r != z) stack.push(t->r); 
        if (t->l != z) stack.push(t->l); 
      }
  }
 
 
--------------------------------
CHAPTER 6 Analysis of Algorithms 
 
 
--------------------------------
CHAPTER 7 Implementation of Algorithms 
 
 
--------------------------------
CHAPTER 8 Elementary Sorting Methods 
 
inline void swap(itemType a[], int i, int j)
  { itemType t = a[i]; a[i] = a[j]; a[j] = t; }
sort3(itemType a[], int N)
  {
    if (a[1] > a[2]) swap(a, 1, 2);
    if (a[1] > a[3]) swap(a, 1, 3);
    if (a[2] > a[3]) swap(a, 2, 3);
  }
const int maxN = 100;
main()
  {
    int N, i; itemType v, a[maxN+1];
    N = 0; while (cin >> v) a[++N] = v;
    a[0] = 0; 
    sort3(a, N);
    for (i = 1; i <= N; i++) cout << a[i] << ' ';
    cout << '\n';
  }
 
void selection(itemType a[], int N)
  { 
    int i, j, min;
    for (i = 1; i < N; i++)
      { 
        min = i;
        for (j = i+1; j <= N; j++) 
            if (a[j] < a[min]) min = j;
        swap(a, min, i);
      } 
  }
 
void insertion(itemType a[], int N)
  { 
    int i, j; itemType v;
    for (i = 2; i <= N; i++)
      { 
        v = a[i]; j = i;
        while (a[j-1] > v) 
          { a[j] = a[j-1]; j--; }  
        a[j] = v; 
      } 
  }
 
void bubble(itemType a[], int N)
  {
    int i, j;
    for (i = N; i >= 1; i--)
      for (j = 2; j <= i; j++)
        if (a[j-1] > a[j]) swap(a, j-1, j);
  }
 
void insertion(itemType a[], int p[], int N)
  { 
    int i, j; itemType v;
    for (i = 0; i <= N; i++) p[i] = i;
    for (i = 2; i <= N; i++)
      { 
        v = p[i]; j = i;
        while (a[p[j-1]] > a[v]) 
          { p[j] = p[j-1]; j--; }  
        p[j] = v; 
      } 
  }
 
void insitu(itemType a[], int p[], int N)
  { 
    int i, j, k; itemType t;
    for (i = 1; i <= N; i++) 
      if (p[i] != i)
        {
          t = a[i]; k = i;
          do
            { 
              j = k; a[j] = a[p[j]];
              k = p[j]; p[j] = j;
            }
          while (k != i);
          a[j] = t;
        } 
  }
 
void insertion(itemType a[], itemType *p[], int N)
  { 
    int i, j; itemType *v;
    for (i = 0; i <= N; i++) p[i] = &a[i];
    for (i = 2; i <= N; i++)
      { 
        v = p[i]; j = i;
        while (*p[j-1] > *v) 
          { p[j] = p[j-1]; j--; }
        p[j] = v; 
      } 
  }
 
void shellsort(itemType a[], int N)
  { 
    int i, j, h; itemType v;
    for (h = 1; h <= N/9; h = 3*h+1) ;
    for ( ; h > 0; h /= 3)
      for (i = h+1; i <= N; i += 1)
        { 
          v = a[i]; j = i;
          while (j>h && a[j-h]>v)
            { a[j] = a[j-h]; j -= h; }
          a[j] = v; 
        } 
  }
 
for (j = 0; j <  M; j++) count[j] = 0;
for (i = 1; i <= N; i++) count[a[i]]++;
for (j = 1; j <  M; j++) count[j] += count[j-1];
for (i = N; i >= 1; i--) b[count[a[i]]--] = a[i];
for (i = 1; i <= N; i++) a[i] = b[i];
 
 
--------------------------------
CHAPTER 9 Quicksort   
 
void quicksort(itemType a[], int l, int r)
  { 
    int i;
    if (r > l)
      { 
        i = partition(a, l, r);
        quicksort(a, l, i-1);
        quicksort(a, i+1, r);
      } 
  }
 
void quicksort(itemType a[], int l, int r)
  { 
    int i, j; itemType v;
    if (r > l)
      { 
        v = a[r]; i = l-1; j = r;
        for (;;)
          { 
            while (a[++i] < v) ;
            while (a[--j] > v) ;
            if (i >= j) break;
            swap(a, i, j);
          }
        swap(a, i, r);
        quicksort(a, l, i-1);
        quicksort(a, i+1, r);
      } 
  }
 
void quicksort(itemType a[], int l, int r)
  { 
    int i; Stack sf(50);
    for (;;)
      {
        while (r > l)
          { 
            i = partition(a, l, r);
            if (i-l > r-i)
              { sf.push(l); sf.push(i-1); l = i+1; }
            else
              { sf.push(i+1); sf.push(r); r = i-1; }
          } 
        if (sf.empty()) break;
        r = sf.pop(); l = sf.pop(); 
      }
  }
 
void select(itemType a[], int l, int r, int k)
  { 
    int i;
    if (r > l)
      { 
        i = partition(a, l, r);
        if (i > l+k-1) select(a, l, i-1, k);
        if (i < l+k-1) select(a, i+1, r, k-i);
      } 
  }
 
void select(itemType a[], int N, int k)
  { 
    int i, j, l, r; itemType v;
    l = 1; r = N;
    while (r > l)
      { 
        v = a[r]; i = l-1; j = r;
        for (;;)
          { 
            while (a[++i] < v) ;
            while (a[--j] > v) ;
            if (i >= j) break;
            swap(a, i, j);
          }
        swap(a, i, r);
        if (i >= k) r = i-1;
        if (i <= k) l = i+1;
      } 
  }
 
 
--------------------------------
CHAPTER 10 Radix Sorting  
 
class bitskey 
  {
    private:
      int x;
    public:
      bitskey& operator=(int i) 
          { x = i; return *this; }
      inline unsigned bits(int k, int j)
          { return (x >> k) & ~(~0 << j); }
  };
typedef bitskey itemType;
 
void radixexchange(itemType a[], int l, int r, int b)
  { 
    int i, j; itemType t;
    if (r>l && b>=0)
      { 
        i = l; j = r;
        while (j != i)
          { 
            while (!a[i].bits(b, 1) && ii) j--;
            swap(a, i, j);
          }
        if (!a[r].bits(b, 1)) j++;
        radixexchange(a, l, j-1, b-1);
        radixexchange(a, j, r, b-1);
      } 
  }
 
void straightradix(itemType a[], itemType b[], int N)
  {
    int i, j, pass, count[M-1];
    for (pass = 0; pass < w/m; pass++)
      {
        for (j = 0; j <  M; j++) count[j] = 0;
        for (i = 1; i <= N; i++) 
            count[a[i].bits(pass*m, m)]++;
        for (j = 1; j <  M; j++) 
            count[j] += count[j-1];
        for (i = N; i >= 1; i--)
            b[count[a[i].bits(pass*m, m)]--] = a[i];
        for (i = 1; i <= N; i++) a[i] = b[i];
      }
  }
 
 
--------------------------------
CHAPTER 11 Priority Queues  
 
class PQ
  {
    private:
      itemType *a;
      int N;
    public:
      PQ(int max) 
        { a = new itemType[max]; N = 0; }
     ~PQ()
        { delete a; }
      void insert(itemType v)
        { a[++N] = v; }
      itemType remove()
        {
          int j, max = 1; 
          for (j = 2; j <= N; j++)
            if (a[j] > a[max]) max = j;
          swap(a, max, N);
          return a[N--];
        }
  };
 
void PQ::upheap(int k)
  {
    itemType v;
    v = a[k]; a[0] = itemMAX;
    while (a[k/2] <= v)
      { a[k] = a[k/2]; k = k/2; }
    a[k] = v;
  }
void PQ::insert(itemType v)
  { a[++N] = v;  upheap(N); }
 
void PQ::downheap(int k)
  {
    int j; itemType v;
    v = a[k];
    while (k <= N/2)
      {
        j = k+k;
        if (j= a[j]) break;
        a[k] = a[j]; k = j;
      }
    a[k] = v;
  }
 
itemType PQ::remove()
  {
    itemType v = a[1];
    a[1] = a[N--];
    downheap(1);
    return v;
  }
 
itemType PQ::replace(itemType v)
  {
    a[0] = v;
    downheap(0);
    return a[0];
  }
 
void heapsort(itemType a[], int N)                           
  {
    int i; PQ heap(N);
    for (i = 1; i <= N; i++) heap.insert(a[i]);    
    for (i = N; i >= 1; i--) a[i] = heap.remove();    
  }
 
void heapsort(itemType a[], int N)
  {
    int k;
    for (k = N/2; k >= 1; k--) 
        downheap(a, N, k);
    while (N > 1)
      { swap(a, 1, N); downheap(a, --N, 1); }
  }
 
class PQ
  {
    private:
      itemType *a; int *p, *info;
      int N;
    public:
      PQ(int size)
        { a = new itemType[size]; 
          p = new int[size];
          info = new int[size]; N = 0; }
     ~PQ()
        { delete a; delete p; delete info; }
      void insert(int x, itemType v)
        { a[++N] = v; p[x] = N; info[N] = x; }
      void change(int x, itemType v)
        { a[p[x]] = v; }
      int remove() // remove smallest
        {
          int j, min = 1; 
          for (j = 2; j <= N; j++)
            if (a[j] < a[min]) min = j;
          swap(a, min, N); swap(info, min, N);
          p[info[min]] = min;
          return info[N--];
        }
      int empty()
        { return (N <= 0); }
  };
 
PQ::PQ(itemType *array, int size) 
  { 
    int k;
    p = new itemType[size]; q = new itemType[size]; 
    a = array; N = size; 
    for (k = 1; k <= N; k++) { p[k] = k; q[k] = k; }
    for (k = N/2; k >= 1; k--) downheap(k);
  }
 
void PQ::downheap(int k)
  {
    int j, v;
    v = p[k];
    while (k <= N/2)
      {
        j = k+k;
        if (j=a[p[j]]) break;
        p[k] = p[j]; q[p[j]] = k; k = j;
      }
    p[k] = v; q[v] = k;
  }
 
 
--------------------------------
CHAPTER 12 Mergesort   
 
i = 1; j = 1;
a[M+1] = itemMAX; b[N+1] = itemMAX;
for (k = 1; k <= M+N; k++)
  c[k] = (a[i]key <= b->key)
        { c->next = a; c = a; a = a->next; }
      else
        { c->next = b; c = b; b = b->next; }
    while (c != z);
    c = z->next; z->next = z;
    return c;
  }
 
void mergesort(itemType a[], int l, int r)
  {
    int i, j, k, m;
    if (r > l)
      {
        m = (r+l)/2;
        mergesort(a, l, m);  
        mergesort(a, m+1, r);
        for (i = m+1; i > l; i--) b[i-1] = a[i-1];
        for (j = m; j < r; j++) b[r+m-j] = a[j+1];
        for (k = l; k <= r; k++)
          a[k] = (b[i]next != z)
      {
        a = c; b = c->next->next->next;
        while (b != z)
          { c = c->next; b = b->next->next; }
        b = c->next; c->next = z;
        return merge(mergesort(a), mergesort(b));
      }
    return c;
  }
 
struct node *mergesort(struct node *c)
  {
    int i, N;
    struct node *a, *b, *head, *todo, *t;
    head = new node;
    head->next = c; a = z;
    for (N = 1; a != head->next; N = N+N) 
      {
        todo = head->next; c = head;
        while (todo != z)
          {
            t = todo; a = t; 
            for (i = 1; i < N; i++) t = t->next;
            b = t->next; t->next = z; t = b; 
            for (i = 1; i < N; i++) t = t->next;
            todo = t->next; t->next = z;
            c->next = merge(a, b);
            for (i = 1; i <= N+N; i++) c = c->next;
          }
      }
    return head->next;
  }
 
 
--------------------------------
CHAPTER 13 External Sorting  
 
 
--------------------------------
CHAPTER 14 Elementary Searching Methods 
 
class Dict
  {
    private:
      struct node
        { itemType key; infoType info; };
      struct node *a;
      int N;
    public:
      Dict(int max)
        { a = new node[max]; N = 0; }
     ~Dict()
        { delete a; }
      infoType search(itemType v);
      void insert(itemType v, infoType info);
  };
infoType Dict::search(itemType v) // Sequential 
  { 
    int x = N+1;
    a[0].key = v; a[0].info = infoNIL;
    while (v != a[--x].key) ;
    return a[x].info;
  }
void Dict::insert(itemType v, infoType info) 
  { a[++N].key = v; a[N].info = info; }
 
class Dict
 {
   private:
     struct node
       { itemType key; infoType info; 
         struct node *next; 
         node(itemType k, infoType i, struct node *n)
           { key = k; info = i; next = n; };
       };
     struct node *head, *z;
   public:
     Dict(int max) 
       {
         z = new node(itemMAX, infoNIL, 0);
         head = new node(0, 0, z);
       }
    ~Dict();
     infoType search(itemType v);
     void insert(itemType v, infoType info); 
 };
 
infoType Dict::search(itemType v) // Sorted list 
  {
    struct node *t = head;
    while (v > t->key) t = t->next;
    return (v = t->key) ? t->info : z->info;
  }
 
void Dict::insert(itemType v, infoType info) 
  {
    struct node *x, *t = head;
    while (v > t->next->key) t = t->next;
    x = new node(v, info, t->next); 
    t->next = x;
  }
 
infoType Dict::search(itemType v) // Binary search 
  { 
    int l = 1; int r = N; int x;
    while (r >= l)
      {
        x = (l+r)/2;
        if (v == a[x].key) return a[x].info;
        if (v <  a[x].key) r = x-1; else l = x+1;
      }
    return infoNIL;
  }
 
class Dict
  {
    private:
      struct node
        { itemType key; infoType info;
          struct node *l, *r; 
          node(itemType k, infoType i, 
               struct node *ll, struct node *rr)
            { key = k; info = i; l = ll; r = rr; };
        };
      struct node *head, *z;
    public:
      Dict(int max)
        { z = new node( 0, infoNIL, 0, 0);
          head = new node(itemMIN, 0, 0, z); }
     ~Dict();
      infoType search(itemType v);
      void insert(itemType v, infoType info);
  };
 
infoType Dict::search(itemType v) 
  {
    struct node *x = head->r;
    z->key = v;
    while (v != x->key)
      x = (v < x->key) ? x->l : x->r;
    return x->info;
  }
 
void Dict::insert(itemType v, infoType info) 
  {
    struct node *p, *x;
    p = head; x = head->r;
    while (x != z)
      { p = x; x = (v < x->key) ? x->l : x->r; }
    x = new node(v, info, z, z);
    if (v < p->key) p->l = x; else p->r = x;
  }
 
void Dict::treeprint(struct node *x)
  {
    if (x != z)
      {
        treeprint(x->l);
        printnode(x);
        treeprint(x->r);
      }
  }
 
void Dict::remove(itemType v)   
  {
    struct node *c, *p, *x, *t;
    z->key = v;
    p = head; x = head->r;
    while (v != x->key)
      { p = x; x = (v < x->key) ? x->l :  x->r; }
    t = x;
    if (t->r == z) x = x->l;
    else if (t->r->l == z) { x = x->r; x->l = t->l; }
    else
      {
        c = x->r; while (c->l->l != z) c = c->l;
        x = c->l; c->l = x->r;
        x->l = t->l; x->r = t->r;
      }
    delete t;
    if (v < p->key) p->l = x; else p->r = x;
  }
 
 
--------------------------------
CHAPTER 15 Balanced Trees  
 
void Dict::insert(itemType v, infoType info) 
  {
    x = head; p = head; g = head;
    while (x != z)
      { 
        gg = g; g = p; p = x; 
        x = (v < x->key) ? x->l :  x->r; 
        if (x->l->b && x->r->b) split(v);
      }
    x = new node(v, info, 1, z, z);
    if (v < p->key) p->l = x; else p->r = x;
    split(v); head->r->b = black;
  }
 
struct node *rotate(itemType v, struct node *y)
  {
    struct node *c, *gc;
    c = (v < y->key) ? y->l : y->r;
    if (v < c->key)
      { gc = c->l; c->l = gc->r; gc->r = c; }
    else
      { gc = c->r; c->r = gc->l; gc->l = c; }
    if (v < y->key) y->l = gc; else y->r = gc;
  return gc;
  }
 
void split(itemType v)
  {
    x->b = red; x->l->b = black; x->r->b = black;
    if (p->b)
      {
        g->b = red;
        if (vkey != vkey) p = rotate(v, g);
        x = rotate(v, gg);
        x->b = black;
      }
  }
 
      Dict(int max)
        { 
          z = new node( 0, infoNIL, black, 0, 0);
          z->l = z; z->r = z;
          head = new node(itemMIN, 0, black, 0, z); 
        }
 
 
--------------------------------
CHAPTER 16 Hashing   
 
unsigned stringkey::hash(int M)
  {
    int h; char *t = v;
    for (h = 0; *t; t++) 
        h = (64*h + *t) % M;
    return h;
  }
 
Dict::Dict(int sz)
  { 
    M = sz;
    z = new node; z->next = z; z->info = infoNIL;
    heads = new node*[M];
    for (int i = 0; i < M; i++) 
      { heads[i] = new node; heads[i]->next = z; }
  }
 
class Dict
  {
    private:
      struct node
        { itemType key; infoType info; 
          node() { key = " "; info = infoNIL; }
        };
      struct node *a;
      int M;
    public:
      Dict(int sz)
        { M = sz; a = new node[M]; }
      int search(itemType v);
      void insert(itemType v, infoType info)
        {
          int x = v.hash(M); 
          while (a[x].info != infoNIL) x = (x+1) % M;
          a[x].key = v; a[x].info = info; 
        }
  };
 
 
--------------------------------
CHAPTER 17 Radix Searching  
 
infoType Dict::search(itemType v) // Digital tree
  { 
    struct node *x = head;
    int b = itemType::maxb;
    z->key = v;
    while (v != x->key)
      x = (v.bits(b--, 1)) ? x->r : x->l;
    return x->info;
  }
 
void Dict::insert(itemType v, infoType info)
  {
    struct node *p, *x = head;
    int b = itemType::maxb;
    while (x != z)
      { 
        p = x; 
        x = (v.bits(b--, 1)) ? x->r : x->l; 
      }
    x = new node;
    x->key = v; x->info = info; x->l = z; x->r = z;
    if (v.bits(b+1, 1)) p->r = x; else p->l = x;
  }
 
infoType Dict::search(itemType v)  // Patricia tree 
  {
    struct node *p, *x;
    p = head; x = head->l;
    while (p->b > x->b)
      { 
        p = x; 
        x = (bits(v, x->b, 1)) ? x->r : x->l; 
      }
    if (v != x->key) return infoNIL;
    return x->info;
  }
 
void Dict::insert(itemType v, infoType info)
  {
    struct node *p, *t, *x;
    int i = maxb;
    p = head; t = head->l;
    while (p->b > t->b)
     { p = t; t = (bits(v, t->b, 1)) ? t->r : t->l; }
    if (v == t->key) return;
    while (bits(t->key, i, 1) == bits(v, i, 1)) i--;
    p = head; x = head->l;
    while (p->b > x->b  && x->b > i) 
     { p = x; x = (bits(v, x->b, 1)) ? x->r : x->l; }
    t = new node;
    t->key = v; t->info = info; t->b = i;
    t->l = (bits(v, t->b, 1)) ? x : t;
    t->r = (bits(v, t->b, 1)) ? t : x;
    if (bits(v, p->b, 1)) p->r = t; else p->l = t;
  }
 
 
--------------------------------
CHAPTER 18 External Searching  
 
 
--------------------------------
CHAPTER 19 String Searching  
 
int brutesearch(char *p, char *a)
  {
    int i, j, M = strlen(p), N = strlen(a);
    for (i = 0, j = 0; j < M && i < N; i++, j++)
      if (a[i] != p[j]) { i -= j-1; j = -1; }
    if (j == M) return i-M; else return i;
  }
 
int kmpsearch(char *p, char *a)
  {
    int i, j, M = strlen(p), N = strlen(a);
    initnext(p);
    for (i = 0, j = 0; j < M && i < N; i++, j++)
      while ((j >= 0) && (a[i] != p[j])) j = next[j];
    if (j == M) return i-M; else return i;
  }
 
initnext(char *p)
  {
    int i, j, M = strlen(p);
    next[0] = -1;
    for (i = 0, j = -1; i < M; i++, j++, next[i] = j)
      while ((j >= 0) && (p[i] != p[j])) j = next[j];
  }
 
int kmpsearch(char *a)
  {
    int i = -1;
sm: i++;
s0: if (a[i] != '1') goto sm; i++;
s1: if (a[i] != '0') goto s0; i++;
s2: if (a[i] != '1') goto s0; i++;
s3: if (a[i] != '0') goto s1; i++;
s4: if (a[i] != '0') goto s2; i++;
s5: if (a[i] != '1') goto s0; i++;
s6: if (a[i] != '1') goto s1; i++;
s7: if (a[i] != '1') goto s1; i++;
    return i-8;
  }
 
next[i] = (p[i] == p[j]) ? next[j] : j
 
int mischarsearch(char *p, char *a)
  {
    int i, j, t, M = strlen(p), N = strlen(a);
    initskip(p);
    for (i = M-1, j = M-1; j > 0; i--, j--)
      while (a[i] != p[j])
        {
          t = skip[index(a[i])];
          i += (M-j > t) ? M-j : t; 
          if (i >= N) return N;
          j = M-1;
        }
    return i;  
  }
 
const int q = 33554393;
const int d = 32;
int rksearch(char *p, char *a)
  {
    int i, dM = 1, h1 = 0, h2 = 0;
    int M = strlen(p), N = strlen(a);
    for (i = 1; i < M; i++) dM = (d*dM) % q;
    for (i = 0; i < M; i++) 
      {
        h1 = (h1*d+index(p[i])) % q;
        h2 = (h2*d+index(a[i])) % q;
      }
    for (i = 0; h1 != h2; i++)
      {
        h2 = (h2+d*q-index(a[i])*dM) % q;
        h2 = (h2*d+index(a[i+M])) % q;
        if (i > N-M) return N;
      }
    return i;
  }
 
 
--------------------------------
CHAPTER 20 Pattern Matching  
 
const int scan = -1;
int match(char *a)
  {
    int n1, n2; Deque dq(100);
    int j = 0, N = strlen(a), state = next1[0];
    dq.put(scan);
    while (state)
      {
        if (state == scan) { j++; dq.put(scan); }
        else if (ch[state] == a[j]) 
            dq.put(next1[state]);
        else if (ch[state] == ' ')
          {
            n1 = next1[state]; n2 = next2[state];
            dq.push(n1); if (n1 != n2) dq.push(n2);
          }
        if (dq.empty() || j==N) return 0; 
        state = dq.pop();
      }
    return j;
  }
 
 
--------------------------------
CHAPTER 21 Parsing   
 
expression()
  {  
    term();
    if (p[j] == '+') 
      { j++;  expression(); }
  }
 
term()
  {
    factor();
    if ((p[j] == '(') || letter(p[j])) term();
  }
 
factor()
  {
    if (p[j] == '(')
      {
        j++; expression();
        if (p[j] == ')') j++; else error();
      }
    else if (letter(p[j])) j++; else error();
    if (p[j] == '*') j++;
  }
 
expression
   term
      factor
         (
         expression
            term
               factor   A   *
               term
                  factor   B
            +
            expression
               term
                  factor   A
                  term
                     factor   C
         )
      term
         factor   D
                  
badexpression();
  {
    if (letter(p[j])) j++; else
      {
        badexpression();
        if (p[j] == '+') { j++; term(); }
        else error();
      }
  }

 
int expression()
  {  
    int t1,t2,r;
    t1 = term(); r = t1;
    if (p[j] == '+') 
      {
        j++; state++;
        t2 = state; r = t2; state++;
        setstate(t2, ' ', expression(), t1);
        setstate(t2-1, ' ', state, state);
      }
    return r;
  }
 
int term()
  {
    int t, r;
    r = factor();
    if ((p[j] == '(') || letter(p[j])) t = term();
    return r;
  }
 
int factor()
  {
    int t1, t2, r;
    t1 = state;
    if (p[j] == '(')
      {
        j++; t2 = expression();
        if (p[j] == ')') j++; else error();
      }
    else if (letter(p[j])) 
      {
        setstate(state, p[j], state+1, state+1);
        t2 = state; j++; state++;
      }
    else error();
    if (p[j] != '*') r = t2; else
      {
        setstate(state, ' ', state+1, t2);
        r = state; next1[t1-1] = state;
        j++; state++;
      }
    return r;
  }
 
void matchall(char *a)
  {
    j = 0; state = 1;
    next1[0] = expression();
    setstate(0, ' ', next1[0], next1[0]);
    setstate(state, ' ', 0, 0);
    while (*a) cout << match(a++) << ' '; 
    cout << '\n';
  }
 
 
--------------------------------
CHAPTER 22 File Compression  
 
  for (i = 0; i <= 26; i++) count[i] = 0;
  for (i = 0; i  <  M; i++) count[index(a[i])]++;
 
  for (i = 0; i <= 26; i++)
      if (count[i]) pq.insert(count[i], i);
  for ( ; !pq.empty(); i++)
    {
      t1 = pq.remove(); t2 = pq.remove();
      dad[i] = 0; dad[t1] = i; dad[t2] = -i;
      count[i] = count[t1] + count[t2];
      if (!pq.empty()) pq.insert(count[i], i); 
    }
 
for (k = 0; k <= 26; k++)
  {
    i = 0; x = 0; j = 1;
    if (count[k])
      for (t=dad[k]; t; t=dad[t], j+=j, i++)
        if (t < 0) { x += j; t = -t; }
    code[k] = x; len[k] = i;
  }
 
for (j = 0; j < M; j++)
    for (i = len[index(a[j])]; i > 0; i--)
        cout << ((code[index(a[j])] >> i-1) & 1);
 
 
--------------------------------
CHAPTER 23 Cryptology   
 
 
--------------------------------
CHAPTER 24 Elementary Geometric Methods 
 
struct point { int x, y; char c; };
struct line { struct point p1, p2; };
struct point polygon[Nmax];
 
int ccw(struct point p0, 
        struct point p1, 
        struct point p2 )
  {
    int dx1, dx2, dy1, dy2;
    dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
    dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;
    if (dx1*dy2 > dy1*dx2) return +1;
    if (dx1*dy2 < dy1*dx2) return -1;
    if ((dx1*dx2 < 0) || (dy1*dy2 < 0)) return -1;
    if ((dx1*dx1+dy1*dy1) < (dx2*dx2+dy2*dy2)) 
                                        return +1;
    return 0;
  }
 
int intersect(struct line l1, struct line l2)
  {
    return ((ccw(l1.p1, l1.p2, l2.p1)
            *ccw(l1.p1, l1.p2, l2.p2)) <= 0)
        && ((ccw(l2.p1, l2.p2, l1.p1)
            *ccw(l2.p1, l2.p2, l1.p2)) <= 0);
  }
 
float theta(struct point p1, struct point p2)
  {
    int dx, dy, ax, ay;
    float t;
    dx = p2.x - p1.x; ax = abs(dx);
    dy = p2.y - p1.y; ay = abs(dy);
    t = (ax+ay == 0) ? 0 : (float) dy/(ax+ay);
    if (dx < 0) t = 2-t; else if (dy < 0) t = 4+t;
    return t*90.0;
  }
 
int inside(struct point t, struct point p[], int N)
  {
    int i, count = 0, j = 0;
    struct line lt,lp;
    p[0] = p[N]; p[N+1] = p[1];
    lt.p1 = t; lt.p2 = t; lt.p2.x = INT_MAX;
    for (i = 1; i <= N; i++)
      {
        lp.p1= p[i]; lp.p2 = p[i];
        if (!intersect(lp,lt))
          {
            lp.p2 = p[j]; j = i;
            if (intersect(lp,lt)) count++;
          }
      }
    return count & 1;
  }
 
 
--------------------------------
CHAPTER 25 Finding the Convex Hull
 
int wrap(point p[], int N)
  {
    int i, min, M;
    float th, v;
    for (min = 0, i = 1; i < N; i++)
      if (p[i].y < p[min].y) min = i;
    p[N] = p[min]; th = 0.0;
    for (M = 0; M < N; M++)
      {
        swap(p, M, min);
        min = N; v = th; th = 360.0;
        for (i = M+1; i <= N; i++)
          if (theta(p[M], p[i]) > v)
            if (theta(p[M], p[i]) < th)
              { min = i; th = theta(p[M], p[min]); }
        if (min == N) return M;
      }
  }
 
int grahamscan(point p[], int N)
  {
    int i, min, M;
    for (min = 1, i = 2; i <= N; i++)
      if (p[i].y < p[min].y) min = i;
    for (i = 1; i <= N; i++)
      if (p[i].y == p[min].y)
        if (p[i].x > p[min].x) min = i;
    swap(p, 1, min);
    shellsort(p, N);
    p[0] = p[N];
    for (M = 3, i = 4; i <= N; i++)
      {
        while (ccw(p[M], p[M-1], p[i]) >= 0) M--;
        M++; swap(p, i, M);
      }
    return M;
  }
 
 
--------------------------------
CHAPTER 26 Range Searching  
 
int range(int v1, int v2)
  { return ranger(head->r, v1, v2); }
int ranger(struct node *t, int v1, int v2)
  {
    int tx1, tx2, count = 0;
    if (t == z) return 0;
    tx1 = (t->key >= v1);
    tx2 = (t->key <= v2);
    if (tx1) count += ranger(t->l, v1, v2);
    if (tx1 && tx2) count++;
    if (tx2) count += ranger(t->r, v1, v2);
    return count;
  }
 
class Range
  {
    private:
      struct node 
        { struct point p; struct node *next; };
      struct node *grid[maxG][maxG];
      struct node *z;
    public:
      Range();
      void insert(struct point p);
      int search(rect range);
  };
Range::Range()
  {
    int i, j;
    z = new node; 
    for (i = 0; i <= maxG; i++)
      for (j = 0; j <= maxG; j++)
          grid[i][j] = z;
  }
void Range::insert(struct point p)
  {
    struct node *t = new node;
    t->p = p; t->next = grid[p.x/size][p.y/size];
    grid[p.x/size][p.y/size] = t;
  }
 
int Range::search(struct rect range) // Grid method
 {
  struct node *t;
  int i, j, count = 0;
  for (i = range.x1/size; i <= range.x2/size; i++)
    for (j = range.y1/size; j <= range.y2/size; j++)
      for (t = grid[i][j]; t != z; t = t->next)
        if (insiderect(t->p, range)) count++;
  return count;
  }
 
class Range
  {
    private:
      struct node 
        { struct point p; struct node *l, *r; };
      struct node *z, *head;
      struct point dummy;
      int searchr(struct node *t, 
                      struct rect range, int d);
    public:
      Range();
      void insert(struct point p);
      int search(rect range);
  };
 
void Range::insert(struct point p) // 2D tree
  {
    struct node *f, *t; int d, td;
    for (d = 0, t = head; t != z; d !=d)
      {
        td = d ? (p.x < t->p.x) : (p.y < t->p.y);
        f = t; t = td ? t->l : t->r;
      }
    t = new node; t->p = p; t->l = z; t->r = z;
    if (td) f->l = t; else f->r = t;
  }
 
int Range::search(struct rect range) // 2D tree
  { return searchr(head->r, range, 1); }
int Range::searchr(struct node *t, 
                       struct rect range, int d)
 {
  int t1, t2, tx1, tx2, ty1, ty2, count = 0;
  if (t == z) return 0;
  tx1 = range.x1 < t->p.x; tx2 = t->p.x <= range.x2;
  ty1 = range.y1 < t->p.y; ty2 = t->p.y <= range.y2;
  t1 = d ? tx1 : ty1; t2 = d ? tx2 : ty2;
  if (t1) count += searchr(t->l, range, !d);
  if (insiderect(t->p, range)) count++;
  if (t2) count += searchr(t->r, range, !d);
  return count;
 }
 
 
--------------------------------
CHAPTER 27 Geometric Intersection  
 
Dict Xtree(Nmax), Ytree(Nmax);
struct line lines[Nmax];
int count = 0;
int intersections()
  {
    int x1, y1, x2, y2, N;
    for (N = 1; cin >> x1 >> y1 >> x2 >> y2; N++)
      {
        lines[N].p1.x = x1; lines[N].p1.y = y1;
        lines[N].p2.x = x2; lines[N].p2.y = y2;
        Ytree.insert(y1, N);
        if (y2 != y1) Ytree.insert(y2, N);
      }
    Ytree.traverse();
    return count;
  }
 
void Dict::visit(itemType v, infoType info)
  {
    int t, x1, x2, y1, y2;
    x1 = lines[info].p1.x; y1 = lines[info].p1.y;
    x2 = lines[info].p2.x; y2 = lines[info].p2.y;
    if (x2 < x1) { t = x2; x2 = x1; x1 = t; }
    if (y2 < y1) { t = y2; y2 = y1; y1 = t; }
    if (v == y1) 
        Xtree.insert(x1, info);
    if (v == y2)
      {
        Xtree.remove(x1, info);
        count += Xtree.range(x1, x2);
      }
  }
 
 
--------------------------------
CHAPTER 28 Closest-Point Problems  
 
int comp(struct node *t)
  { return (pass == 1) ? t->p.x : t->p.y; }
struct node *merge(struct node *a, struct node *b)
  {
    struct node *c; 
    c = z;
    do
      if (comp(a) < comp(b)) 
        { c->next = a; c = a; a = a->next; }
      else
        { c->next = b; c = b; b = b->next; }
    while (c != z);
    c = z->next; z->next = z;
    return c;
  }
 
check(struct point p1, struct point p2)
  {
    float dist;
    if ((p1.y != z->p.y) && (p2.y != z->p.y))
      {
        dist = sqrt((p1.x-p2.x)*(p1.x-p2.x)
                   +(p1.y-p2.y)*(p1.y-p2.y));
        if (dist < min)
          { min = dist; cp1 = p1; cp2 = p2; };
      }
  }
 
struct node *sort(struct node *c, int N)
  {
    int i;
    struct node *a, *b;
    float middle;
    struct point p1, p2, p3, p4;
    if (c->next == z) return c;
    a = c;
    for (i = 2; i <= N/2; i++) c = c->next;
    b = c->next; c->next = z;
    if (pass == 2) middle = b->p.x;
    c = merge(sort(a, N/2), sort(b, N-(N/2)));
    if (pass == 2)
      {
        p1 = z->p; p2 = z->p; p3 = z->p; p4 = z->p;
        for (a = c; a != z; a = a->next)
          if (fabs(a->p.x - middle) < min)
            {
              check(a->p, p1);
              check(a->p, p2);
              check(a->p, p3);
              check(a->p, p4);
              p1 = p2; p2 = p3; p3 = p4; p4 = a->p;
            }
      }
    return c;
  }
 
z = new node; z->p.x = max; 
              z->p.y = max; z->next = z;
h = new node; h->next = readlist();
min = max;
pass = 1; h->next = sort(h->next, N);
pass = 2; h->next = sort(h->next, N);
 
 
--------------------------------
CHAPTER 29 Elementary Graph Algorithms 
 
int V, E; 
int a[maxV][maxV];
 
void adjmatrix()
  {
    int j, x, y;
    cin >> V >> E;
    for (x = 1; x <= V; x++)
      for (y = 1; y <= V; y++) a[x][y] = 0;
    for (x = 1; x <= V; x++) a[x][x] = 1;
    for (j = 1; j <= E; j++)
      {
        cin >> v1 >> v2;
        x = index(v1); y = index(v2);
        a[x][y] = 1; a[y][x] = 1;
      }
  }
 
struct node
  { int v; struct node *next; };
int V, E;
struct node *adj[maxV], *z;
 
void adjlist()
  {
    int j, x, y; struct node *t;
    cin >> V >> E;
    z = new node;  z->next = z;
    for (j = 1; j <= V; j++) adj[j] = z;
    for (j = 1; j <= E; j++)
      {
        cin >> v1 >> v2;
        x = index(v1); y = index(v2);
        t = new node; 
          t->v = x; t->next = adj[y]; adj[y] = t;
        t = new node;
          t->v = y; t->next = adj[x]; adj[x] = t;
      }
  }
 
void search()
  {
    int k;
    for (k = 1; k <= V; k++) val[k] = unseen;
    for (k = 1; k <= V; k++) 
      if (val[k] == unseen) visit(k);
  }
 
void visit(int k) // DFS, adjacency lists
  {
    struct node *t;
    val[k] = ++id;
    for (t = adj[k]; t != z; t = t->next)
      if (val[t->v] == unseen) visit(t->v);
  }
 
void visit(int k) // DFS, adjacency matrix
  {
    int t;
    val[k] = ++id;
    for (t = 1; t <= V; t++) 
      if (a[k][t] != 0)
        if (val[t] == unseen) visit(t);
  }
 
Stack stack(maxV);
void visit(int k) // non-recursive DFS, adj lists
  {
    struct node *t;
    stack.push(k);
    while (!stack.empty())
      {
        k = stack.pop(); val[k] = ++id;
        for (t = adj[k]; t != z; t = t->next)
          if (val[t->v] == unseen) 
            { stack.push(t->v); val[t->v] = -1; }
      }
  }
 
Queue queue(maxV);
void visit(int k) // BFS, adjacency lists
  {
    struct node *t;
    queue.put(k);
    while (!queue.empty())
      {
        k = queue.get(); val[k] = ++id;
        for (t = adj[k]; t != z; t = t->next)
          if (val[t->v] == unseen) 
            { queue.put(t->v); val[t->v] = -1; }
      }
  }
 
 
--------------------------------
CHAPTER 30 Connectivity   
 
int visit(int k) // DFS to find articulation points
  {
    struct node *t; 
    int m, min;
    val[k] = ++id; 
    min = id;
    for (t = adj[k]; t != z; t = t->next)
      if (val[t->v] == unseen) 
        {
          m = visit(t->v);
          if (m < min) min = m;
          if (m >= val[k]) cout << name(k);
        }
      else if (val[t->v] < min) min = val[t->v];
    return min;
  }
 
class EQ
  {
    private:
      int *dad;
    public:
      EQ(int size);
      int find(int x, int y, int doit);
  };     
 
int EQ::find(int x, int y, int doit)
  { 
    int i = x, j = y;
    while (dad[i] > 0) i = dad[i];
    while (dad[j] > 0) j = dad[j];
    if (doit && (i != j)) dad[j] = i;
    return (i != j);
  }
 
int EQ::find(int x, int y, int doit)
  { 
    int t, i = x, j = y;
    while (dad[i] > 0) i = dad[i];
    while (dad[j] > 0) j = dad[j];
    while (dad[x] > 0) 
      { t = x; x = dad[x]; dad[t] = i; }
    while (dad[y] > 0) 
      { t = y; y = dad[y]; dad[t] = j; }
    if (doit && (i != j)) 
      if (dad[j] < dad[i])
        { dad[j] += dad[i] - 1; dad[i] = j; }
      else
        { dad[i] += dad[j] - 1; dad[j] = i; }
    return (i != j);
  }
 
 
--------------------------------
CHAPTER 31 Weighted Graphs  
 
PQ pq(maxV);
visit(int k) // PFS, adjacency lists
  {
    struct node *t;
    if (pq.update(k, -unseen) != 0) dad[k] = 0;
    while (!pq.empty())
      {
        id++; k = pq.remove(); val[k] = -val[k];
        if (val[k] == -unseen) val[k] = 0;
        for (t = adj[k]; t != z; t = t->next)
          if (val[t->v] < 0) 
            if (pq.update(t->v, priority))
              { 
                val[t->v] = -(priority); 
                dad[t->v] = k; 
              }
      }
  }
 
 
void kruskal()
 {
  int i, m, V, E;
  struct edge
    { char v1, v2; int w; };
  struct edge e[maxE];
  PQ pq(maxE); EQ eq(maxE);
  cin >> V >> E;
  for (i = 1; i <= E; i++)
      cin >> e[i].v1 >> e[i].v2 >> e[i].w;
  for (i = 1; i <= E; i++)
      pq.insert(i, e[i].w);
  for (i = 0; i < V-1; )
    {
      if (pq.empty()) break; else m = pq.remove(); 
      if (eq.find(index(e[m].v1),index(e[m].v2),1))
        { cout << e[m].v1 << e[m].v2 << ' '; i++; };
    }
 }
 
void search() // PFS, adjacency matrix
  {
    int k, t, min = 0;
    for (k = 1; k <= V; k++) 
      { val[k] = unseen; dad[k] = 0; }
    val[0] = unseen-1;
    for (k = 1; k != 0; k = min, min = 0)
      {
        val[k] = -val[k];
        if (val[k] == -unseen) val[k] = 0;
        for (t = 1; t <= V; t++)
          if (val[t] < 0)
            {
              if (a[k][t] && (val[t] < -priority))
                { val[t] = -priority; dad[t] = k; }
              if (val[t] > val[min]) min = t;
            }
        }
  }
 
 
--------------------------------
CHAPTER 32 Directed Graphs  
 
for (k = 1; k <= V; k++)
  {
    id = 0;
    for (j = 1; j <= V; j++) val[j] = 0;
    visit(k);
    cout >> '\n';
  }
 
for (y = 1; y <= V; y++)
  for (x = 1; x <= V; x++)
    if (a[x][y])
      for (j = 1; j <= V; j++)
        if (a[y][j]) a[x][j] = 1;
 
for (y = 1; y <= V; y++)
 for (x = 1; x <= V; x++) 
  if (a[x][y])
   for (j = 1; j <= V; j++) 
    if (a[y][j] > 0)
     if (!a[x][j] || (a[x][y]+a[y][j] < a[x][j]))
      a[x][j] = a[x][y] + a[y][j];
 
Stack stack(maxV);
int visit(int k) // DFS to find strong components
  {
    struct node *t; int m, min;
    val[k] = ++id; min = id;
    stack.push(k);
    for (t = adj[k]; t != z; t = t->next)
      {
        m = (!val[t->v]) ? visit(t->v) : val[t->v];
        if (m < min) min = m;
      }
    if (min == val[k])
      {
        do
          {
            m = stack.pop(); cout << m;
            val[m] = V+1;
          }
        while (m != k);
        cout << '\n';
      }
    return min;        
  }
 
 
--------------------------------
CHAPTER 33 Network Flow  
 
  priority = -flow[k][t];
  if (size[k][t] > 0) priority += size[k][t];
  if (priority > val[k]) priority = val[k];
 
for (;;)
  {
    if (!search(1,V)) break;
    y = V; x = dad[V];
    while (x != 0)
      {
        flow[x][y] = flow[x][y]+val[V];
        flow[y][x] = -flow[x][y];
        y = x; x = dad[y];
      }
  }
 
 
--------------------------------
CHAPTER 34 Matching   
 
for (m = 1; m <= N; m++)
  {
    for (s = m; s != 0;)
      {
        next[s]++; w = prefer[s][next[s]];
        if (rank[w][s] < rank[w][fiancee[w]])
          { t = fiancee[w]; fiancee[w] = s; s = t; }
      }
  }
 
 
--------------------------------
CHAPTER 35 Random Numbers  
 
a[0] = seed;
for (i = 1; i <= N; i++)
  a[i] = (a[i-1]*b+1) % m;
 
#include 
const int  m = 100000000;
const int m1 = 10000;
int mult(int p, int q)
  {
    int p1, p0, q1, q0;
    p1 = p/m1; p0 = p%m1;
    q1 = q/m1; q0 = q%m1;
    return (((p0*q1+p1*q0) % m1)*m1+p0*q0) % m;
  }
class Random
  {
    private:
      int a;
    public:
      Random(int seed)
        { a = seed; }
      int next()
        { const int  b = 31415821;
          a = (mult(a, b) + 1) % m; 
          return a; 
        }
  };
main()
  {
    int i, N; Random x(1234567);
    cin >> N;
    for (i = 1; i <= N; i++) 
        cout << x.next() << ' '; 
    cout << '\n';
  }

 
      int badnext(int r)
        { const int  b = 31415821;
          a = (mult(a, b) + 1) % m;
          return a % r;
        }
 
      int next(int r)
        { const int  b = 31415821;
          a = (mult(a, b) + 1) % m;
          return ((a/m1)*r)/m1;
        }
 
class Random
  {
    private:
      int a[55], j;
    public:
      Random(int seed);
      int next(int r)
        {
          j = (j+1) % 55;
          a[j] = (a[(j+23) % 55]+a[(j+54) % 55]) % m;
          return ((a[j]/m1)*r)/m1;
        }
  };
 
Random:: Random(int seed)
  { const int  b = 31415821;
    a[0] = seed;
    for (j = 1; j <= 54; j++)
    a[j] = (mult(a[j-1], b) + 1) % m;
  }
 
float chisquare(int N, int r)
  {
    int i, t, f[rmax]; Random x(1234567);
    for (i = 0; i < r; i++) f[i] = 0;
    for (i = 0; i < N; i++) f[x.next(r)]++;
    for (i = 0, t = 0; i < r; i++) t += f[i]*f[i];
    return (float) ((r*t/N) - N);
  }
 
 
--------------------------------
CHAPTER 36 Arithmetic   
 
for (i = 0; i < N; i++) r[i] = p[i]+q[i];
 
for (i = 0; i < 2*N-1; i++) r[i] = 0;
for (i = 0; i < N; i++)
  for (j = 0; j < N; j++)
    r[i+j] += p[i]*q[j];
 
struct node *add(struct node *p, struct node *q)
  {
    struct node *t;
    t = z; z->c = 0;
    while ((p != z) && (q != z))
      {
        t->next = new node;
        t = t->next; t->c = p->c + q->c;
        p = p->next; q = q->next;
      }
    t->next = z; t = z->next; z->next = z;
    return t;
  }
 
struct node 
  { int c; int j; struct node *next; };
 
struct node *insert(struct node *t, int c, int j)
  {
    t->next = new node;
    t = t->next; t->c = c; t->j = j;
    return t;
  }
 
struct node *add(struct node *p, struct node *q)
  {
    struct node *t;
    t = z; z->c = 0; z->j = maxN;
    while ((p !=z) || (q != z))
      {
        if ((p->j == q->j) && ((p->c + q->c) != 0))
          {
            t = insert(t, p->c+q->c, p->j);
            p = p->next; q = q->next;
          }
        else if (p->j < q->j)
          { t = insert(t, p->c, p->j); p = p->next; }
        else if (q->j < p->j)
          { t = insert(t, q->c, q->j); q = q->next; }
      }
    t->next = z; t = z->next; z->next = z;
    return t;
  }
 
y = p[N];
for (i = N-1; i >= 0; i--) y = x*y + p[i];
 
float *mult(float p[], float q[], int N)
  {
    float pl[N/2], ql[N/2], ph[N/2], qh[N/2], 
          t1[N/2], t2[N/2];
    float r[2*N-2], rl[N], rm[N], rh[N];
    int i, N2;
    if (N == 1) 
      { r[0] = p[0]*q[0]; return (float *) r; }
    for (i = 0; i < N/2; i++)
      { pl[i] = p[i]; ql[i] = q[i]; }
    for (i = N/2; i < N; i++)
      { ph[i-N/2] = p[i]; qh[i-N/2] = q[i]; }
    for (i = 0; i < N/2; i++) t1[i] = pl[i]+ph[i];
    for (i = 0; i < N/2; i++) t2[i] = ql[i]+qh[i];
    rm = mult(t1, t2, N/2);
    rl = mult(pl, ql, N/2);
    rh = mult(ph, qh, N/2);
    for (i = 0; i < N-1; i++) r[i] = rl[i];
    r[N-1] = 0;
    for (i = 0; i < N-1; i++) r[N+i] = rh[i];
    for (i = 0; i < N-1; i++)
      r[N/2+i] += rm[i] - (rl[i]+rh[i]);
    return (float *) r;
  }
 
  for (i = 0; i < N; i++) 
    for (j = 0; j < N; j++)
      for (k = 0, r[i][j] = 0; k < N; k++) 
        r[i][j] += p[i][k]*q[k][j];
 
 
--------------------------------
CHAPTER 37 Gaussian Elimination  
 
for (i = 1;  i <= N; i++)
  for (j = i+1; j <= N; j++)
    for (k = N+1; k >= i; k--)
      a[j][k] -= a[i][k]*a[j][i]/a[i][i];
 
eliminate()
  {
    int i, j, k, max;
    float t;
    for (i = 1; i <= N; i++)
      {
        max = i;
        for (j = i+1; j <= N; j++)
          if (abs(a[j][i]) > abs(a[max][i])) max = j;
        for (k = i; k <= N+1; k++)
          { t = a[i][k]; 
                a[i][k] = a[max][k]; 
                          a[max][k] = t; }
        for (j = i+1; j <= N; j++)
          for (k = N+1; k >= i; k--)
            a[j][k] -= a[i][k]*a[j][i]/a[i][i];
      }
  }
 
substitute()
  {
    int j, k;
    float t;
    for (j = N; j >= 1; j--)
      {
        t = 0.0;
        for (k = j+1; k <= N; k++) t += a[j][k]*x[k];
        x[j] = (a[j][N+1]-t)/a[j][j];
      }
  }
 
    for (i = 1; i < N; i++)
      {
        a[i+1][N+1] -= a[i][N+1]*a[i+1][i]/a[i][i];
        a[i+1][i+1] -= a[i][i+1]*a[i+1][i]/a[i][i];
      }
    for (j = N; j >= 1; j--)
      x[j] = (a[j][N+1]-a[j][j+1]*x[j+1])/a[j][j];
 
 
--------------------------------
CHAPTER 38 Curve Fitting  
 
makespline(float x[], float y[], int N)
  {
    for (i = 2; i < N; i++) d[i] = 2*(x[i+1]-x[i-1]);
    for (i = 1; i < N; i++) u[i] = x[i+1]-x[i];
    for (i = 2; i < N; i++)
      w[i] = 6.0*((y[i+1]-y[i])/u[i]
                  -(y[i]-y[i-1])/u[i-1]);
    p[1] = 0.0; p[N] = 0.0;
    for (i = 2; i < N-1; i++)
      {
        w[i+1] = w[i+1] - w[i]*u[i]/d[i];
        d[i+1] = d[i+1] - u[i]*u[i]/d[i];
      }
    for (i = N-1; i > 1; i--)
      p[i] = (w[i]-u[i]*p[i+1])/d[i];
  }
 
float f(float x)
  { return x*x*x - x; }
float eval(float v)
  {
    float t; int i = 1;
    while (v > x[i+1]) i++;
    t = (v-x[i])/u[i];
    return t*y[i+1]+(1-t)*y[i] + 
        u[i]*u[i]*(f(t)*p[i+1]+f(1-t)*p[i])/6.0;
  }
 
for (i = 1; i <= M; i++) 
  for (j = 1; j <= M+1; j++) 
    {
      t = 0.0;
      for (k = 1; k <= N; k++) 
        t += f[i][k]*f[j][k];
      a[i][j] = t;
    }
 
 
--------------------------------
CHAPTER 39 Integration   
 
for (i = N; i > 0; i--) p[i] = p[i-1]/i; p[0] = 0;
 
double intrect(double a, double b, int N)
  {
    int i; double r = 0; double w = (b-a)/N;
    for (i = 1; i <= N; i++) r += w*f(a-w/2+i*w);
    return r;
  }
 
double inttrap(double a, double b, int N)
  {
    int i; double t = 0; double w = (b-a)/N;
    for (i = 1; i <= N; i++) 
      t += w*(f(a+(i-1)*w)+f(a+i*w))/2;
    return t;
  }
 
double intsimp(double a, double b, int N)
  {
    int i; double s = 0; double w = (b-a)/N;
    for (i = 1; i <= N; i++) 
      s += w*(f(a+(i-1)*w) + 
              4*f(a-w/2+i*w) + 
              f(a+i*w))/6;
    return s;
  }
 
double adapt(double a, double b)
  {
    double x = intsimp(a, b, 10);
    if (fabs(x - intsimp(a, b, 5)) > tolerance) 
      return adapt(a, (a+b)/2) + adapt((a+b)/2, b);
    return x;
   }
 
 
--------------------------------
CHAPTER 40 Parallel Algorithms  
 
 
--------------------------------
CHAPTER 41 The Fast Fourier Transform
 
eval(p, outN, 0);
eval(q, outN, 0);
for (i = 0; i <= outN; i++) r[i] = p[i]*q[i];
eval(r, outN, 0);
for (i = 1; i <= N; i++)
  { t = r[i]; r[i] = r[outN+1-i]; r[outN+1-i] = t; }
for (i = 0; i <= outN; i++) r[i] = r[i]/(outN+1);
 
eval(complex p[], int N, int k)
  {
    int i, j;
    if (N == 1)
      {
        p0 = p[k]; p1 = p[k+1];
        p[k] = p0+p1; p[k+1] = p0-p1;
      }
    else
      {
        for (i = 0; i <= N/2; i++)
          {
            j = k+2*i;
            t[i] = p[j]; t[i+1+N/2] = p[j+1];
          }
        for (i = 0; i <= N; i++) p[k+i] = t[i];
        eval(p, N/2, k);
        eval(p, N/2, (k+1+N)/2);
        j = (outN+1)/(N+1);
        for (i = 0; i <= N/2; i++)
          {
            p0 = w[i*j]*p[k+(N/2)+1+i];
            t[i] = p[k+i]+p0; 
            t[i+(N/2)+1] = p[k+i]-p0;
          }
        for (i = 0; i <= N; i++) p[k+i] = t[i];
      }
  }
 
 
--------------------------------
CHAPTER 42 Dynamic Programming  
 
for (j = 1; j <= N; j++)
  {
    for (i = 1; i <= M; i++)
      if (i >= size[j])
        if (cost[i] < cost[i-size[j]]+val[j])
          {
            cost[i] = cost[i-size[j]]+val[j];
            best[i] = j;
          }
  }
 
for (i = 1; i <= N; i++)
  for (j = i+1; j <= N; j++) cost[i][j] = INT_MAX;
for (i = 1; i <= N; i++) cost[i][i] = 0;
for (j = 1; j < N; j++)
  for (i = 1; i <= N-j; i++)
    for (k = i+1; k <= i+j; k++)
      {
        t = cost[i][k-1]+cost[k][i+j]
                             +r[i]*r[k]*r[i+j+1];
        if (t < cost[i][i+j])
          { cost[i][i+j] = t; best[i][i+j] = k; }
      }
 
order(int i, int j)
  {
    if (i == j) cout >> name(i); else
      {
        cout >> '(';
        order(i, best[i][j]-1); order(best[i][j], j);
        cout >> ')';
      }
  }
 
for (i = 1; i <= N; i++) 
  for (j = i+1; j <= N+1; j++) cost[i][j] = INT_MAX;
for (i = 1; i <= N; i++) cost[i][i] = f[i];
for (i = 1; i <= N+1; i++) cost[i][i-1] = 0;
for (j = 1; j <= N-1; j++)
  for (i = 1; i <= N-j; i++)
    {
      for (k = i; k <= i+j; k++)
        {
          t = cost[i][k-1]+cost[k+1][i+j];
          if (t < cost[i][i+j])
            { cost[i][i+j] = t; best[i][i+j] = k; }
        }
      for (k = i; k <= i+j; cost[i][i+j] += f[k++]) ;
    }
 
 
--------------------------------
CHAPTER 43 Linear Programming  
 
pivot(int p, int q)
  {
    int j, k;
    for (j = 0; j <= N; j++)
      for (k = M+1; k >= 1; k--)
        if (j!=p && k!=q)
          a[j][k] = a[j][k]-a[p][k]*a[j][q]/a[p][q];
    for (j = 0; j <= N; j++) 
      if (j != p) a[j][q] = 0;
    for (k = 1; k <= M+1; k++) 
      if (k != q) a[p][k] = a[p][k]/a[p][q];
    a[p][q] = 1;
  }
 
for (;;)
  {
    for (q = 0; (q<=M+1) && (a[0][q]>=0); q++) ;
    for (p = 0; (p<=N+1) && (a[p][q]<=0); p++) ;
    if (q>M || p>N) break;
    for (i = p+1; i <= N; i++)
      if (a[i][q] > 0)
        if (a[i][M+1]/a[i][q] < a[p][M+1]/a[p][q]) 
          p = i;
    pivot(p,q);
  }
 
 
--------------------------------
CHAPTER 44 Exhaustive Search  
 
visit(int k)
  { 
    int t;
    val[k] = ++id;
    for (t = 1; t <= V; t++)
      if (a[k][t])
        if (val[t] == 0) visit(t);
    id--; val[k] = 0;
  }
 
visit(int k)
  {
    int t;
    val[k] = ++id;
    if (id == V) writeperm();
    for (t = 1; t <= V; t++)
      if (val[t] == 0) visit(t);
    id--; val[k] = 0;
  }
 
 
--------------------------------
CHAPTER 45 NP-Complete Problems  
 
