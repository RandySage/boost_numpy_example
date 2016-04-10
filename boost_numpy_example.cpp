#include <boost/python.hpp>
#include "vector_to_nparray.h"

class test_wrap {
public:
    std::vector<double> mValues;
    std::vector<double>* pvalues() {
        mValues.clear();
        for(double d_ = 0.0; d_ < 4; d_+=0.3)
        {
            mValues.push_back(d_);
        }
        return &mValues;
    }
};

BOOST_PYTHON_MODULE(libnbp)
{
    import_array(); // numpy requires this
    using namespace boost::python;

    // Thanks to Max for providing the initial example, on which this was based:
    //   http://stackoverflow.com/a/34023333/527489
    class_<test_wrap>("test_wrap")
        .add_property("values", +[](test_wrap& self) -> object {
                return wrap(self.pvalues()->data(),self.pvalues()->size());
            })
        ;
}
