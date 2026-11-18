static struct PersistentSegtree {
        int numNode = 0;
        int root[N + 1];
        int startNode = 0; 

        struct NODE {
            int val;
            bool flip;     // Chỉ cần duy nhất 1 cờ lật
            int ls, rs;
        } node[60 * N + 1]; // Bộ nhớ giảm xuống chỉ còn 60*N là dư sức

        // Hàm Smart Clone chặn sinh node rác
        int clone(int id) {
            if (id > startNode) return id; 
            int newId = ++numNode;
            node[newId] = node[id];
            return newId;
        }

        // Áp dụng lệnh Lật
        void apply_flip(int id, int l, int r) {
            node[id].val = (r - l + 1) - node[id].val; // Đảo ngược số lượng bit 1
            node[id].flip ^= 1;
        }

        // Đẩy Lazy xuống 2 con
        void push(int id, int l, int r) {
            if (!node[id].flip || l == r) return;
            
            int mid = (l + r) >> 1;
            node[id].ls = clone(node[id].ls);
            node[id].rs = clone(node[id].rs);
            
            apply_flip(node[id].ls, l, mid);
            apply_flip(node[id].rs, mid + 1, r);
            
            node[id].flip = false; // Xóa cờ ở cha
        }

        // --- HÀM 1: ĐẢO ĐOẠN 0/1 ---
        int update_flip(int id, int l, int r, int i, int j) {
            id = clone(id);
            if (l == i && r == j) {
                apply_flip(id, l, r);
                return id;
            }
            push(id, l, r);
            
            int mid = (l + r) >> 1;
            if (i <= mid) node[id].ls = update_flip(node[id].ls, l, mid, i, min(mid, j));
            if (j > mid)  node[id].rs = update_flip(node[id].rs, mid + 1, r, max(mid + 1, i), j);
            
            node[id].val = node[node[id].ls].val + node[node[id].rs].val;
            return id;
        }

        // --- HÀM 2: CẬP NHẬT 1 ĐIỂM (Gán giá trị v tại pos) ---
        int update_point(int id, int l, int r, int pos, int v) {
            id = clone(id);
            if (l == r) {
                node[id].val = v;      // Gán thẳng giá trị mới (0 hoặc 1)
                node[id].flip = false; // Xóa cờ lật (nếu có) vì giá trị đã bị ghi đè
                return id;
            }
            push(id, l, r);
            
            int mid = (l + r) >> 1;
            // Chỉ rẽ 1 nhánh duy nhất chứa pos
            if (pos <= mid) node[id].ls = update_point(node[id].ls, l, mid, pos, v);
            else            node[id].rs = update_point(node[id].rs, mid + 1, r, pos, v);
            
            node[id].val = node[node[id].ls].val + node[node[id].rs].val;
            return id;
        }

        // --- HÀM 3: TRUY VẤN TỔNG ĐOẠN ---
        ll get(int id, int l, int r, int i, int j) {
            if (!id || i > j) return 0;
            if (l == i && r == j) return node[id].val;
            
            int mid = (l + r) >> 1;
            ll res = 0;
            if (i <= mid) res += get(node[id].ls, l, mid, i, min(mid, j));
            if (j > mid)  res += get(node[id].rs, mid + 1, r, max(mid + 1, i), j);
            
            // Dừng sớm: Lật ngược lại đáp án nếu đi qua node đang có cờ Lật
            if (node[id].flip) return (j - i + 1) - res;
            
            return res;
        }

        // --- GỌI TỪ HÀM MAIN ---
        // 1. Lật đoạn:
        // startNode = numNode; root[newVer] = update_flip(root[oldVer], 1, n, l, r);
        
        // 2. Cập nhật 1 điểm:
        // startNode = numNode; root[newVer] = update_point(root[oldVer], 1, n, pos, val);

    } tree;