#include <QVector>
#include <iostream>
#include <vector>
#include <cstring>

void step1(QVector<QVector<int> > &costMatrix, QVector<int> &rowCover, QVector<int> &colCover) {
    int rowCount = costMatrix.size();
    int colCount = costMatrix[0].size();

    for (int i = 0; i < rowCount; ++i) {
        int minValue = costMatrix[i][0];
        for (int j = 1; j < colCount; ++j) {
            if (costMatrix[i][j] < minValue) {
                minValue = costMatrix[i][j];
            }
        }
        for (int j = 0; j < colCount; ++j) {
            costMatrix[i][j] -= minValue;
        }
    }

    for (int i = 0; i < rowCount; ++i) {
        rowCover[i] = 0;
    }
    for (int j = 0; j < colCount; ++j) {
        colCover[j] = 0;
    }
}

void AssignmentProblem::secondStep() {
    vector<int> smallestElements;
    for(int i = 0; i < tasks; i++) {
        int smallestElement = findSmallestInColumn(i, matrix);
        smallestElements.push_back(smallestElement);
        subtractFromColumn(i, smallestElement);
    }
}

void AssignmentProblem::subtractFromColumn(int col, int smallestElement) {
    for(int i = 0; i < tasks; i++) {
        matrix[i][col] = matrix[i][col] - smallestElement;
    }
}

void AssignmentProblem::step3() {
    int coveringRows = 0;
    int coveringCols = 0;
    while(coveringRows < agents && coveringCols < tasks) {
        //this matrix will be used to store the 0 elements
        vector<vector<int>> zeroMatrix(agents, vector<int>(tasks, 0));
        int markedZeros = markZeros(zeroMatrix);

        if(markedZeros == coveringRows) {
            makeMoreZeros(coveringRows, coveringCols, zeroMatrix);
        } else {
            coveringRows = markedZeros;
            coveringCols = 0;
        }
    }
}


using namespace std;

const int MAX = 1005;
int n, m, cost[MAX][MAX], row[MAX], col[MAX];
bool vis[MAX];

bool find(int u)
{
    for(int v = 1; v <= m; v++)
    {
        if(cost[u][v] == 0 && !vis[v])
        {
            vis[v] = true;
            if(!col[v] || find(col[v]))
            {
                row[u] = v;
                col[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungarian()
{
    int ans = 0;
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);

    for(int u = 1; u <= n; u++)
    {
        memset(vis, false, sizeof vis);
        if(find(u)) ans++;
    }

    return ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> cost[i][j];

    cout << hungarian() << endl;

    return 0;
}

void HungarianAlgorithm::step5()
{
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!c[i])
        {
            k = i;
            break;
        }
    }

    for (int i = k + 1; i <= n; i++)
    {
        if (!c[i] && fx[i] < fx[k])
        {
            k = i;
        }
    }

    int h = fx[k] + 1;
    fx[k] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (c[i])
        {
            fx[i] -= h;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!c[i])
        {
            fy[i] += h;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!c[i])
        {
            for (int j = 1; j <= n; j++)
            {
                if (c[j])
                {
                    fx[j] = max(fx[j], e[i][j] - fy[i]);
                }
            }
        }
    }
}
