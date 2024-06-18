#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void SetZero(vector<vector<int>> &matrix)
{

    // int n = matrix.size();
    // int m = matrix[n].size();
    // int row [n] = {0};
    // int col [m] = {0};
    int n = matrix.size();
    if (n == 0)
        return;
    int m = matrix[0].size();

    vector<int> row(n, 0); // --> matrix[..][m]
    vector<int> col(m, 0); // --> matrix[n][..]

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {

                row[i] = -1;
                col[j] = -1;
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (row[i] == -1 || col[j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
void setZero(vector<vector<int>> &matrix)
{

    // int row[matrix.size()];
    // int col[matrix[0].size()];
    printf("came");
    int count = 1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (i==0 && matrix[i][j] == 0)
            {
                count = 0;
            }

            if (matrix[i][j] == 0 && i != 0 )
            {
                printf("came");
                matrix[i][0] =0;
                matrix[0][j] = 0;

            }
            /* code */
        }

        /* code */
    }
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1;j < matrix[i].size(); j++)
        { 
            if(matrix[i][0]==0 || matrix [0][j] ==0 ){
                matrix[i][j]=0;
            }
            /* code */
        }
        
        /* code */
    }
     if (matrix[0][0] == 0)
    {
        for (int i = 1; i < matrix.size(); i++)
        {
            matrix[i][0] = 0;
            /* code */
        }
        
    }
    if (count ==0) 
    {
        for (int i = 0; i < matrix[0].size(); i++)
        {
            matrix[0][i] = 0;
            /* code */
        }
        
    }
    

  
    
}
int main()
{
    string input;
    cout << "Enter the matrix in the format [[1,1,1],[1,0,1],[1,1,1]]: ";
    getline(cin, input);

    vector<vector<int>> matrix;
    vector<int> row;
    string number;

    for (char ch : input)
    {
        if (isdigit(ch) || ch == '-')
        {
            number += ch;
        }
        else if (ch == ',' || ch == ']')
        {
            if (!number.empty())
            {
                row.push_back(stoi(number)); // Convert the number and add to the current row
                number.clear();              // Clear the number string for the next number
            }
            if (ch == ']' && !row.empty())
            {
                matrix.push_back(row); // Add the current row to the matrix
                  // Clear the row for the next row
                row.clear();        
            }
        }
    }

    setZero(matrix);
    cout << "[";
    for (size_t i = 0; i < matrix.size(); i++)
    {
        cout << "[";
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < matrix.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
