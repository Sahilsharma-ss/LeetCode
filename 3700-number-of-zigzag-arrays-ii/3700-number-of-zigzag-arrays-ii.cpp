
class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &a, Matrix &b)
    {
        int n = a.size();

        Matrix res(n, vector<long long>(n, 0));

        for(int i = 0; i < n; i++)
        {
            for(int k = 0; k < n; k++)
            {
                if(a[i][k] == 0) continue;

                for(int j = 0; j < n; j++)
                {
                    if(b[k][j] == 0) continue;

                    res[i][j] =
                    (res[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }

        return res;
    }

    Matrix power(Matrix &mat,long long exp)
    {
        int n = mat.size();

        if(exp == 0)
        {
            Matrix id(n, vector<long long>(n, 0));

            for(int i = 0; i < n; i++)
                id[i][i] = 1;

            return id;
        }

        if(exp == 1)
            return mat;

        Matrix half = power(mat, exp / 2);

        Matrix res = multiply(half, half);

        if(exp & 1)
            res = multiply(res, mat);

        return res;
    }

    int zigZagArrays(int n, int l, int r)
    {
        int m = r - l + 1;

        int sz = 2 * m;

        Matrix trans(sz, vector<long long>(sz, 0));

        for(int i = 0; i < m; i++)
        {
            for(int j = i + 1; j < m; j++)
            {
                trans[i][m + j] = 1;
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < i; j++)
            {
                trans[m + i][j] = 1;
            }
        }

        Matrix mat = power(trans, n - 1);

        long long ans = 0;

        for(int i = 0; i < sz; i++)
        {
            for(int j = 0; j < sz; j++)
            {
                ans = (ans + mat[i][j]) % MOD;
            }
        }

        return ans;
    }
};
