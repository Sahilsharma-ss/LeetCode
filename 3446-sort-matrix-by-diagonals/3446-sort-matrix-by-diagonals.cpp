class Solution {
private:
    typedef vector<vector<int>> mat_t;

    struct diag_iterator {
        typedef ptrdiff_t difference_type;
        typedef int value_type;
        typedef int *pointer;
        typedef int &reference;
        typedef random_access_iterator_tag iterator_category;

        mat_t &grid;
        const int8_t bias;
        int8_t pos;

        diag_iterator(mat_t &g, const int8_t b) noexcept __attribute__((always_inline, hot)): grid(g), bias(b), pos(max(-bias, 0)) {}

        diag_iterator(mat_t &g, const int8_t b, const int8_t p) noexcept __attribute__((always_inline, hot)): grid(g), bias(b), pos(p) {}

        diag_iterator(const diag_iterator &it) noexcept __attribute__((always_inline, hot)): grid(it.grid), bias(it.bias), pos(it.pos) {}

        diag_iterator &operator=(const diag_iterator &it) noexcept __attribute__((always_inline, hot)) {
            // assert(&grid == &it.grid & bias == it.bias);
            pos = it.pos;
            return *this;
        }

        int &operator*() noexcept __attribute__((always_inline, hot)) {
            return grid[bias+pos][pos];
        }

        diag_iterator operator++() noexcept __attribute__((always_inline, hot)) {
            pos++;
            return *this;
        }

        diag_iterator operator--() noexcept __attribute__((always_inline, hot)) {
            pos--;
            return *this;
        }

        diag_iterator operator+(const int8_t o) const noexcept __attribute__((always_inline, hot)) {
            return diag_iterator(grid, bias, pos + o);
        }

        diag_iterator operator-(const int8_t o) const noexcept __attribute__((always_inline, hot)) {
            return diag_iterator(grid, bias, pos - o);
        }

        difference_type operator-(const diag_iterator &it) const noexcept __attribute__((always_inline, hot)) {
            // assert(&grid == &it.grid & bias == it.bias);
            return pos - it.pos;
        }

        bool operator==(const diag_iterator &it) const noexcept __attribute__((always_inline, hot)) {
            return &grid == &it.grid & bias == it.bias & pos == it.pos;
        }

        bool operator<(const diag_iterator &it) const noexcept __attribute__((always_inline, hot)) {
            return &grid == &it.grid & bias == it.bias & pos < it.pos;
        }
    };

public:
    static mat_t sortMatrix(mat_t &grid) noexcept __attribute__((hot)) {
        const int8_t n = grid.size();
        for (int8_t b = -1; 1 - b < n; b--) {
            const diag_iterator diag(grid, b);
            sort(diag, diag + (n + b));
        }
        for (int8_t b = 0; b + 1 < n; b++) {
            const diag_iterator diag(grid, b);
            sort(diag, diag + (n - b), greater());
        }
        return move(grid);
    }
};

const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();