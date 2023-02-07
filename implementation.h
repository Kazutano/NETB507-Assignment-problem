#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

#include <vector>

using namespace std;

class AssignmentProblem
{
public:
    AssignmentProblem();
    AssignmentProblem(int row, int col);
    ~AssignmentProblem();

    int at(int row, int col) const;
    void set(int row, int col, int value);
    void printMatrix();

    int getRows() const { return agents; }
    int getColumns() const { return tasks; }

    void setRows(int totalAgents) { this->agents = totalAgents; }
    void setColumns(int totalTasks) { this->tasks = totalTasks; }

    void firstStep();
    void secondStep();
    void thirdStep();

    int findSmallestInMatrix();
    int findSmallestInRow(int row);
    int findSmallestInColumn(int column);

    void subtractFromRow(int row, int smallestValue);
    void subtractFromColumn(int col, int smallestValue);

    void run();

    vector<vector<int>> getData() const { return matrix; }
    void setData(const vector<vector<int>> &data) { matrix = data; }

    int countZeros() const;
    int findZeroInRow(int row) const;
    void markZerosInRow(int row);
    void markZerosInColumn(int col);
    void markSingleZeroInRow(int row);

private:
    int agents;
    int tasks;
    vector<vector<int>> matrix;
};

#endif // IMPLEMENTATION_H