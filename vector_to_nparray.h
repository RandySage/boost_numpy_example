/*
 * Note: this is substantially the example provided by 'max' at
 * http://stackoverflow.com/a/34023333/527489
 */
#ifndef VECTOR_TO_NPARRAY
#define VECTOR_TO_NPARRAY

// I found the deprecated API warnings distracting...
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION

#include <vector>
#include <numpy/ndarrayobject.h>
#include <boost/python.hpp>

// wrap c++ vector as numpy array
static boost::python::object wrap(double* data, npy_intp size) {
    using namespace boost::python;

    npy_intp shape[1] = { size }; // array size
    PyObject* obj =
        PyArray_New(&PyArray_Type, 1, shape, NPY_DOUBLE, // data type
                    NULL, data, // data pointer
                    0, NPY_ARRAY_CARRAY, // NPY_ARRAY_CARRAY_RO for readonly
                    NULL);
    handle<> array( obj );
    return object(array);
 }

#endif // VECTOR_TO_NPARRAY
