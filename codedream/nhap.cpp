static struct PersistentSegtree {
        int numNode = 0;
        int root[N + 1];

        struct NODE {
            ll val;
            int ls, rs;
        } node[20 * N + 1]; // Không có lazy, mỗi truy vấn chỉ tốn log(N) node nên 20*N là đủ

        // Cập nhật 1 điểm (Point Update) tại vị trí `pos` cộng thêm `val`
        int updated(int preNode, int l, int r, int pos, ll val) {
            int curNode = ++numNode; 
            node[curNode] = node[preNode]; // Photocopy node cũ
            
            if (l == r) {
                node[curNode].val += val; // Cộng thêm (hoặc gán, XOR tùy bài)
                return curNode;
            }
            
            int mid = (l + r) >> 1;
            // Chỉ rẽ vào đúng 1 nhánh chứa vị trí pos
            if (pos <= mid) node[curNode].ls = updated(node[preNode].ls, l, mid, pos, val);
            else            node[curNode].rs = updated(node[preNode].rs, mid + 1, r, pos, val);
            
            node[curNode].val = node[node[curNode].ls].val + node[node[curNode].rs].val;
            return curNode;
        }

        // Truy vấn tổng đoạn [i, j]
        ll get(int id, int l, int r, int i, int j) {
            if (!id || i > j) return 0;
            if (l == i && r == j) return node[id].val;
            
            int mid = (l + r) >> 1;
            ll res = 0;
            // Cắt gọt i, j gọn gàng không lo rẽ nhầm
            if (i <= mid) res += get(node[id].ls, l, mid, i, min(mid, j));
            if (j > mid)  res += get(node[id].rs, mid + 1, r, max(mid + 1, i), j);
            
            return res;
        }
    } tree;