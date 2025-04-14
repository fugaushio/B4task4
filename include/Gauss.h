#ifdef GAUSS_H
#define GAUSS_H

#include <vector>

class Gauss {
    public:
        Gauss(const vector(double)& data);
        void gauss();
    
    private:
        vector(double) data_;
}
#endif //GAUSS_H