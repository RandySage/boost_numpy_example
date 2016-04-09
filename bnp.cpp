#include <boost/python.hpp>
#include "vector_to_nparray.h"

BOOST_PYTHON_MODULE(libbnp)
{
    import_array(); // numpy requires this
    using namespace boost::python;

    class_<test_wrap>("test_wrap")
        .add_property("values", +[](test_wrap& self) -> object {
                return wrap(self.values().data(),self.values().size());
            })
        ;
}
