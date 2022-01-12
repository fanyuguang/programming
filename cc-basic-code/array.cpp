#include <iostream>

using namespace std;


void array_ops(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


void two_dim_array_ops1(int two_dim_array[2][3], int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            cout << two_dim_array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void two_dim_array_ops2(int** two_dim_array, int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            cout << two_dim_array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main()
{
    // Array ops
    int array1[3];
    array1[0] = 1;
    array1[1] = 2;
    array1[2] = 3;
    // int array1[3] = {1, 2, 3};
    // int array1[] = {1, 2, 3};
    array_ops(array1, 3);

    // int* array2 = new int[3];
    // array2[0] = 1;
    // array2[1] = 2;
    // array2[2] = 3;
    // array_ops(array2, 3);
    int* array2 = new int[]{1, 2, 3};
    delete [] array2;


    // Two dim array ops
    cout << endl << endl;
    int two_dim_array1[2][3];
    two_dim_array1[0][0] = 1;
    two_dim_array1[0][1] = 2;
    two_dim_array1[0][2] = 3;
    two_dim_array1[1][0] = 4;
    two_dim_array1[1][1] = 5;
    two_dim_array1[1][2] = 6;
    // int two_dim_array1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // int two_dim_array1[][3] = {{1, 2, 3}, {4, 5, 6}};
    two_dim_array_ops1(two_dim_array1, 2, 3);

    int** two_dim_array2 = new int*[2];
    for (int i = 0; i < 2; i++)
    {
        two_dim_array2[i] = new int[3];
        two_dim_array2[i][0] = 1 + i * 3;
        two_dim_array2[i][1] = 2 + i * 3;
        two_dim_array2[i][2] = 3 + i * 3;
    }
    two_dim_array_ops2(two_dim_array2, 2, 3);
    for(int i = 0; i < 2; i++)
    {
        delete [] two_dim_array2[i];
    }
    delete [] two_dim_array2;

    return 0;
}

