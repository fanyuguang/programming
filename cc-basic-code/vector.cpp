#include <iostream>
#include <vector>

using namespace std;


void print(vector<vector<int> >& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {   
        for (int j = 0; j < matrix[0].size(); j++)
        {   
            cout << matrix[i][j] << " ";
        }   
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int> > matrix1(2, vector<int>(3));
    cout << "test: " << matrix1[0][0] << endl;
	print(matrix1);

    vector<vector<int> > matrix2(2, vector<int> (3, 2));
	print(matrix2);

    vector<vector<int> > matrix3 = {{1, 2, 3}, {4, 5, 6}};
	print(matrix3);

    vector<vector<int> > matrix4;
    for (int i = 0; i < 2; i++)
    {
        vector<int> vec = {1, 2, 3};
        matrix4.push_back(vec);
    }
    print(matrix4);

    return 0;
}
