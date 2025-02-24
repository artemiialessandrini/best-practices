

template <class T>
class Matrix {
   private:
    int rows, cols;
    T* pMatrix;

   public:
    Matrix(int Rows, int Cols) {
        rows = Rows;
        cols = Cols;
        pMatrix = new T[rows * cols];
    }

    Matrix(const Matrix& matrix) {
        rows = matrix.rows;
        cols = matrix.cols;

        pMatrix = new T[rows * cols];

        for (int i = 0; i < rows * cols; i++) {
            pMatrix[i] = matrix.pMatrix[i];
        }
    }

    T GetElement(int i, int j) const {
        return pMatrix[i * cols + j];
    }
    void setElement(int i, int j, T value) {
        pMatrix[i * cols + j] = value;
    }

    ~Matrix() {
        delete[] pMatrix;
    }
};