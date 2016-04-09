#! /usr/bin/env python
import build.libnbp as nbp

test = nbp.test_wrap()
print("values has type %s" % test.values.__class__)
print("values has len %d" % len(test.values))
print("values is %s" % str(test.values))
