// 4x4 matrix of integers
class Matrix {
    int** matrix;
    
public:
    Matrix() {
        matrix = new int*[4];
        
        for(int i = 0; i < 4; i++) {
            matrix[i] = new int[4];
        }
    }

    int get(int row, int col) {
        return matrix[row][col];
    }

    void set(int row, int col, int value) {
        matrix[row][col] = value;
    }
};