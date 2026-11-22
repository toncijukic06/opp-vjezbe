// Vjezba 6, zadatak 4: napisite klasu Board iznad main.

#include <iostream>

// ovdje napisite klasu Board
class Board
{
    int m_rows;
    int m_cols;
    char znak;
    char *niz;


public:
    Board(int r, int c, char z) : m_rows(r), m_cols(c), znak(z)
    {
        niz = new char[m_rows * m_cols];
        for (int k = 0; k < m_rows * m_cols; ++k)
        {
            niz[k] = ' ';
        }
    }

    Board(const Board &other)
    {
        m_rows = other.m_rows;
        m_cols = other.m_cols;
        znak = other.znak;
        niz = new char[m_rows * m_cols];
        for (int k = 0; k < m_rows * m_cols; ++k)
        {
            niz[k] = other.niz[k];
        }
    }

    ~Board()
    {
        delete[] niz;
    }

    void set(int i, int j, char pZnak)
    {
        if (i > 0 && i < m_rows - 1 && j > 0 && j < m_cols - 1)
        {
            niz[i * m_cols + j] = pZnak;
        }
    }

    char get(int i, int j) const
    {
        if (i >= 0 && i < m_rows && j >= 0 && j < m_cols)
        {
            return niz[i * m_cols + j];
        }
        return ' ';
    }

    int rows() const
    {
        return m_rows;
    }

    int cols() const
    {
        return m_cols;
    }

    void print() const
    {
        for (int i = 0; i < m_rows; ++i)
        {
            for (int j = 0; j < m_cols; ++j)
            {
                if (i == 0 || i == m_rows - 1 || j == 0 || j == m_cols - 1)
                {
                    std::cout << znak;
                }
                else
                {
                    std::cout << niz[i * m_cols + j];
                }
            }
            std::cout << '\n';
        }
    }
};

int main()
{
    Board b(4, 8, '#');
    b.set(1, 2, '@');
    Board copy = b; // copy konstruktor
    copy.set(2, 5, '*');
    copy.set(0, 0, '!'); // rub se ne mijenja
    b.print();
    copy.print();
    std::cout << copy.rows() << ' ' << copy.cols() << ' '
              << copy.get(2, 5) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    ########
    # @    #
    #      #
    ########
    ########
    # @    #
    #    * #
    ########
    4 8 *
*/