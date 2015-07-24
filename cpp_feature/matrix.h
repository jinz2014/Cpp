#include <iostream>
#include <vector>
#include <cassert>

namespace matrix_primer {

  typedef std::vector<std::vector<int> > matrix;

  class Matrix {
    public:

      // constructor (hide the 2d matrix creation detail)
      Matrix(int row, int col) : row(row), col(col) {
        m = matrix(row, std::vector<int>(col));
      }

      Matrix(int row, int col, int v) : row(row), col(col) {
        m = matrix(row, std::vector<int>(col, v));
      }

      // copy constructor as a wrapper for the 
      // user defined matrix type, vector<vector<int> >
      Matrix(const matrix &m) {
        this->row = m.size();
        this->col = m[0].size();
        this->m = m;
      }

      int nrows() const {
        assert (row == m.size());
        return row;
      }

      int ncols() const {
        assert (col == m[0].size());
        return col;
      }

      // index-based initialization
      void indgen() {
        for (int i = 0; i < m.size(); i++) {
          for (int j = 0; j < m[i].size(); j++) {
            m[i][j] = i * m[0].size() + j;
          }
        }
      }

      // reset initialization
      void fill(int v) {
        for (int i = 0; i < m.size(); i++) {
          for (int j = 0; j < m[i].size(); j++) {
            m[i][j] = v;
          }
        }
      }

      // display the matrix
      void show() {
        for (int i = 0; i < m.size(); i++) {
          for (int j = 0; j < m[i].size(); j++) {
            std::cout << m[i][j];
            if (j < m[i].size() - 1)
             std::cout << " ";
          }
          std::cout << std::endl;
        }
      }

      void transpose() {
        row = m[0].size();
        col = m.size();

        // allocate transposed matrix
        Matrix t(row, col);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            t.m[i][j] = m[j][i];
          }
        }
        m = t.m;
      }

    friend Matrix operator+(const Matrix &m1, const Matrix &m2) {
      assert(m1.nrows() > 0 && m1.ncols() > 0);
      assert(m2.nrows() > 0 && m2.ncols() > 0);
      assert(m1.nrows() == m2.nrows());
      assert(m1.ncols() == m2.ncols());

      Matrix t(m1.nrows(), m1.ncols());

      for (int i = 0; i < m1.nrows(); i++) {
        for (int j = 0; j < m1.ncols(); j++) {
          t.m[i][j] = m1.m[i][j] + m2.m[i][j];
        }
      }
      return t;
    }

    friend Matrix operator*(const Matrix &m1, const Matrix &m2) {
      assert(m1.nrows() > 0 && m1.ncols() > 0);
      assert(m2.nrows() > 0 && m2.ncols() > 0);
      assert(m1.ncols() == m2.nrows());

      Matrix t(m1.nrows(), m2.ncols(), 0);

      for (int i = 0; i < m1.nrows(); i++) {
        for (int j = 0; j < m2.ncols(); j++) {
          for (int k = 0; k < m1.ncols(); k++) {
            t.m[i][j] += m1.m[i][k] * m2.m[k][j];
          }
        }
      }
      return t;
    }

    private:
      int row;
      int col;
      matrix m;
  };

  //extern void inverse(matrix &);
  extern bool error;
}
