#include <bits/stdc++.h>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

struct matrix
{
    int mt[2][3];
    int cnt = 0;
    bool operator<(const matrix a) const
    {
        for (int i = 0 ; i < 2 ; i++)
        {
            for (int j = 0 ; j < 3 ; j++)
            {
                if (this -> mt[i][j] < a.mt[i][j]) return 1;
            }
        }
        return 0;
    }
    matrix( int x1 , int y1 , int z1 , int x2 , int y2 , int z2 )
    {
        this -> mt[0][0] = x1;
        this -> mt[0][1] = y1;
        this -> mt[0][2] = z1;
        this -> mt[1][0] = x2;
        this -> mt[1][1] = y2;
        this -> mt[1][2] = z2;
    }
    matrix(){};
};

matrix trai( matrix a)
{
    matrix res = a;
    res.mt[0][0] = a.mt[1][0];
    res.mt[0][1] = a.mt[0][0];
    res.mt[1][1] = a.mt[0][1];
    res.mt[1][0] = a.mt[1][1];
    return res;
}

matrix phai ( matrix a )
{
    matrix res = a;
    res.mt[0][1] = a.mt[1][1];
    res.mt[0][2] = a.mt[0][1];
    res.mt[1][2] = a.mt[0][2];
    res.mt[1][1] = a.mt[1][2];
    return res;
}

istream &operator >> ( istream &is , matrix &a )
{
    for ( int i = 0 ; i < 2 ; i++ )
    {
        for ( int j = 0 ; j < 3; j++ )
        {
            is >> a.mt[i][j];
        }
    }
    return is;
}

ostream &operator >> ( ostream &os , matrix &a )
{   
    for ( int i = 0 ; i < 2 ; i++ )
    {
        for ( int j = 0 ; j < 3; j++ )
        {
            os << a.mt[i][j] << " ";
        }
        os << '\n';
    }
    return os;
}

int check ( matrix a , matrix b )
{
    for ( int i = 0 ; i < 2 ; i++ )
    {
        for ( int j = 0 ; j < 3; j++ )
        {
            if ( a.mt[i][j] != b.mt[i][j] ) return 0;
        }
    }
    return 1;
}

int bfs ( matrix a , matrix b )
{
    map<matrix , int> m;
    m[(matrix){ 0 , 0 , 0 , 0 , 0 ,0 }] = 1;
    m[(matrix){ 7 , 7 , 7 , 7 , 7 ,7 }] = 1;
    queue<matrix> q;
    q.push(a);
    while (!q.empty())
    {
        matrix tmp = q.front();
        q.pop();
        m[tmp] = 1;
        matrix tmp1 = trai(tmp);
        if ( m[tmp1] == 0 )
        {
            m[tmp1] = 1;
            tmp1.cnt = tmp.cnt + 1;
            q.push(tmp1);
            if ( check (tmp1 , b) == 1 ) return tmp1.cnt;
        }
        matrix tmp2 = phai(tmp);
        if ( m[tmp2] == 0 )
        {
            m[tmp2] = 1;
            tmp2.cnt = tmp.cnt + 1;
            q.push(tmp2);
            if ( check (tmp2 , b) == 1 ) return tmp2.cnt;
        }
    }
    return -1;
}

int main()
{
    matrix a , b;
    cin >> a >> b;
    cout << bfs(a , b);
    return 0;
}